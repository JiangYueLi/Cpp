//
// Created by Y on 2024/3/18.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> WordSet(wordList.begin(),wordList.end());
        if(WordSet.find(endWord) == WordSet.end()) return 0;

        unordered_map<string,int> visitmap;

        queue<string> que;
        que.push(beginWord);
        visitmap.insert(pair<string,int>(beginWord,1));

        while (!que.empty())
        {
            string word = que.front();
            que.pop();
            int path = visitmap[word];
            for(int i = 0;i<word.size();i++)
            {
                string newword = word;
                for(int j =0; j < 26 ; j++)
                {
                    newword[i] = 'a' + j;
                    if(newword == endWord) return path+1;
                    if(WordSet.find(newword)!=WordSet.end() &&
                    visitmap.find(newword) == visitmap.end())
                    {
                        visitmap.insert(pair<string,int>(newword,path+1));
                        que.push(newword);
                    }
                }
            }
        }
        return 0;
    }
};