//
// Created by Y on 2024/3/3.
//
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
//
//
//注意：
//
//你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
//你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
#include <queue>
#include <vector>
using namespace std;
class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;
    MyStack() {

    }

    void push(int x) {
        queue2.push(x);
        while (!queue1.empty())
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        swap(queue1,queue2);
    }

    int pop() {
        int r = queue1.front();
        queue1.pop();
        return r;
    }

    int top() {
        int r = queue1.front();
        return r;
    }

    bool empty() {
        return queue1.empty();
    }
};