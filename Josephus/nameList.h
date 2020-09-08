#ifndef NAMELIST_H
#define NAMELIST_H
#include <iostream>
#include <string>
using namespace std;


struct NameNode {
    string name;
    NameNode *prev;
    NameNode *next;
    NameNode(string name) : name(name), prev(0), next(0) {}
};


class NameList {
    private:
        NameNode* tail;
        NameNode* head;
    
    public:
        NameList();
        string Josephus(int k, NameList list, int start);
        void PushBack(string name);
        void RemoveNameAt(string name);
};

#endif