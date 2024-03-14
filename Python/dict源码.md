## Python中列表的底层实现
每个列表中的元素个数可以不一样：所以这是一个变长对象
可以对列表中的元素进行添加、删除、修改等操作，所以这是一个可变对象

创建一个列表，这里是通过Python/C API创建的
>>> lst = [1, 2, 3, 4]
>>> lst
[1, 2, 3, 4]

往列表尾部追加一个元素，此时是在本地操作的，返回值为None
但是列表被改变了
>>> lst.append(5)
>>> lst
[1, 2, 3, 4, 5]

从尾部弹出一个元素，会返回弹出的元素
>>> lst.pop()
5
此时列表也会被修改
>>> lst
[1, 2, 3, 4]
另外在pop的时候还可以指定索引，弹出指定的元素
>>> lst.pop(0)
1
>>> lst
[2, 3, 4]

也可以在指定位置插入一个元素
>>> lst.insert(0, 'x')
>>> lst
['x', 2, 3, 4]

通过extend在尾部追加多个元素
>>> lst.extend([7, 8, 9])
>>> lst
['x', 2, 3, 4, 7, 8, 9]

查找指定元素第一次出现的位置
>>> lst.index(3)
2

计算某个元素在列表中出现的次数
>>> lst.count(3)
2

翻转列表
>>> lst.reverse()
>>> lst
[9, 8, 7, 4, 3, 2, 'x']

根据元素的值删除第一个出现的元素
>>> lst.remove(4)
[9, 8, 7, 3, 2, 'x']

清空列表
>>> lst.clear()
>>> lst
[]
>>>

## 列表的内部结构--PyListObject

typedef struct {
    PyObject_VAR_HEAD
    PyObject **ob_item;
    Py_ssize_t allocated;
} PyListObject;

PyObject_VAR_HEAD: 变长对象的公共头部信息

ob_item：一个二级指针，指向一个PyObject *类型的指针数组，这个指针数组保存的便是对象的指针，而操作底层数组都是通过ob_item来进行操作的。

allocated：容量, 我们知道列表底层是使用了C的数组, 而底层数组的长度就是列表的容量

列表之所以要有容量的概念，是因为列表可以动态添加元素，但是底层的数组在创建完毕之后，其长度却是固定的

PyTypeObject PyList_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "list",
    sizeof(PyListObject),
    0,
    (destructor)list_dealloc,                   /* tp_dealloc */
    0,                                          /* tp_vectorcall_offset */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_as_async */
    (reprfunc)list_repr,                        /* tp_repr */
    0,                                          /* tp_as_number */
    &list_as_sequence,                          /* tp_as_sequence */
    &list_as_mapping,                           /* tp_as_mapping */
    //......
};

## 自动扩容

static int
list_resize(PyListObject *self, Py_ssize_t newsize)
{   //参数self就是列表啦，newsize指的元素在添加之后的ob_size
    //比如列表的ob_size是5，那么在append的时候发现容量不够，所以会扩容，那么这里的newsize就是6
    //如果是extend添加3个元素，那么这里的newsize就是8
    //当然list_resize这个函数不仅可以扩容，也可以缩容，假设列表原来有1000个元素，这个时候将列表清空了
    //那么容量肯定缩小，不然会浪费内存，如果清空了列表，那么这里的newsize显然就是0
    
    //items是一个二级指针，显然是用来指向指针数组的
    PyObject **items;
    //新的容量，以及对应的内存大小
    size_t new_allocated, num_allocated_bytes;
    //获取原来的容量
    Py_ssize_t allocated = self->allocated;
	
    //如果newsize达到了容量的一半，但还没有超过容量, 那么意味着newsize、或者新的ob_size和容量是匹配的，所以不会变化
    if (allocated >= newsize && newsize >= (allocated >> 1)) {
        assert(self->ob_item != NULL || newsize == 0);
        //只需要将列表的ob_size设置为newsize即可
        Py_SIZE(self) = newsize;
        return 0;
    }

    //走到这里说明容量和ob_size不匹配了，所以要进行扩容或者缩容。
    //因此要申请新的底层数组，申请多少个?这里给出了公式,一会儿我们可以通过Python进行测试
    new_allocated = (size_t)newsize + (newsize >> 3) + (newsize < 9 ? 3 : 6);
    //显然容量不可能无限大，是有范围的，当然这个范围基本上是达不到的
    if (new_allocated > (size_t)PY_SSIZE_T_MAX / sizeof(PyObject *)) {
        PyErr_NoMemory();
        return -1;
    }
	
    //如果newsize为0，那么容量也会变成0，假设将列表全部清空了，容量就会变成0
    if (newsize == 0)
        new_allocated = 0;
    
    //我们说数组中存放的都是PyObject *, 所以要计算内存
    num_allocated_bytes = new_allocated * sizeof(PyObject *);
    //申请相应大小的内存，将其指针交给items
    items = (PyObject **)PyMem_Realloc(self->ob_item, num_allocated_bytes);
    if (items == NULL) {
        //如果items是NULL, 代表申请失败
        PyErr_NoMemory();
        return -1;
    }
    //然后让ob_item = items, 也就是指向新的数组, 此时列表就发生了扩容或缩容
    self->ob_item = items;
    //将ob_size设置为newsize, 因为它维护列表内部元素的个数
    Py_SIZE(self) = newsize;
    //将原来的容量大小设置为新的容量大小
    self->allocated = new_allocated;
    return 0;
}

## append 追加元素
static PyObject *
list_append(PyListObject *self, PyObject *object)
{	
    //显然调用的app1是核心, 它里面实现了添加元素的逻辑
    //Py_RETURN_NONE是一个宏，表示返回Python中的None, 因为list.append返回的就是None
    if (app1(self, object) == 0)
        Py_RETURN_NONE;
    return NULL;
}

static int
app1(PyListObject *self, PyObject *v)
{	//self是列表，v是要添加的对象
    
    //获取列表的长度
    Py_ssize_t n = PyList_GET_SIZE(self);
    assert (v != NULL);
    //如果长度已经达到了限制，那么无法再添加了, 会抛出OverflowError
    if (n == PY_SSIZE_T_MAX) {
        PyErr_SetString(PyExc_OverflowError,
            "cannot add more objects to list");
        return -1;
    }
	
    //还记得这个list_resize吗? self就是列表, n + 1就是newsize，或者说新的ob_size
    //会自动判断是否要进行扩容, 当然里面还有重要的一步，就是将列表的ob_size设置成newsize、也就是这里的n + 1
    //因为append之后列表长度大小会变化，而ob_size则要时刻维护这个大小
    if (list_resize(self, n+1) < 0)
        return -1;
	
    //因为v作为了列表的一个元素，所以其指向的对象的引用计数要加1
    Py_INCREF(v);
    //然后调用PyList_SET_ITEM，这是一个宏，它的作用就是设置元素的，我们下面会看这个宏长什么样
    //原来的列表长度为n, 里面的元素的最大索引是n - 1，那么追加的话就等于将元素设置在索引为n的地方
    PyList_SET_ITEM(self, n, v);
    return 0;
}

//我们说PyList_SET_ITEM是用来设置元素的，设置在什么地方呢？显然是设置在底层数组中
//PyList_SET_ITEM一个宏,除了这个宏之外，还有很多其它的宏，它们位于Inlcude/listobject.h中
#define PyList_GET_ITEM(op, i) (((PyListObject *)(op))->ob_item[i])
#define PyList_SET_ITEM(op, i, v) (((PyListObject *)(op))->ob_item[i] = (v))
#define PyList_GET_SIZE(op)    (assert(PyList_Check(op)),Py_SIZE(op))
//这些宏的作用是啥，一目了然

## 创建PyListObject

PyObject *
PyList_New(Py_ssize_t size)
{	
    //声明一个PyListObject *对象
    PyListObject *op;
#ifdef SHOW_ALLOC_COUNT
    static int initialized = 0;
    if (!initialized) {
        Py_AtExit(show_alloc);
        initialized = 1;
    }
#endif
	
    //如果size小于0，直接抛异常
    if (size < 0) {
        PyErr_BadInternalCall();
        return NULL;
    }
    //缓存池是否可用，如果可用
    if (numfree) {
        //将缓存池内对象个数减1
        numfree--;
        //从缓存池中获取
        op = free_list[numfree];
        //设置引用计数
        _Py_NewReference((PyObject *)op);
#ifdef SHOW_ALLOC_COUNT
        count_reuse++;
#endif
    } else {
        //不可用的时候，申请内存
        op = PyObject_GC_New(PyListObject, &PyList_Type);
        if (op == NULL)
            return NULL;
#ifdef SHOW_ALLOC_COUNT
        count_alloc++;
#endif
    }
    //如果size小于等于0，ob_item设置为NULL
    if (size <= 0)
        op->ob_item = NULL;
    else {
        //否则的话，创建一个指定容量的指针数组，然后让ob_item指向它
        //所以是先创建PyListObject对象, 然后创建底层数组, 最后通过ob_item建立联系
        op->ob_item = (PyObject **) PyMem_Calloc(size, sizeof(PyObject *));
        if (op->ob_item == NULL) {
            Py_DECREF(op);
            return PyErr_NoMemory();
        }
    }
    //设置ob_size和allocated，然后返回op
    Py_SIZE(op) = size;
    op->allocated = size;
    _PyObject_GC_TRACK(op);
    return (PyObject *) op;
}

static void
list_dealloc(PyListObject *op)
{
    Py_ssize_t i;
    PyObject_GC_UnTrack(op);
    Py_TRASHCAN_SAFE_BEGIN(op)
    if (op->ob_item != NULL) {
        i = Py_SIZE(op);
        //将底层数组中每个指针指向的对象的引用计数都减去1
        while (--i >= 0) {
            Py_XDECREF(op->ob_item[i]);
        }
      	//然后释放底层数组所占的内存
        PyMem_FREE(op->ob_item);
    }
    //判断缓冲池里面PyListObject对象的个数，如果没满，就添加到缓存池
    //注意：我们看到执行到这一步的时候, 底层数组已经被释放掉了
    if (numfree < PyList_MAXFREELIST && PyList_CheckExact(op))
        free_list[numfree++] = op;
    else
        //否则的话再释放掉PyListObject对象所占的内存
        Py_TYPE(op)->tp_free((PyObject *)op);
    Py_TRASHCAN_SAFE_END(op)
}

