#include "nameList.h"
#include <cstdlib>
#include <iostream>
using namespace std;

NameList::NameList(){
    head = nullptr;
    tail = nullptr;
}

void NameList::PushBack(string name){
    NameNode* newNode = new NameNode(name);
    if(head == nullptr){
        head = newNode;
        tail=newNode;
        newNode->next = tail;
        newNode->prev = head;
    } else if(head->next == tail){
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    } else{
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev = newNode;
        newNode->prev->next = newNode;
    }
}

void NameList::RemoveNameAt(string name){
    NameNode* curr = head;
    do{
        if(curr->name == name){
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            delete curr;
            return;
        }
        curr = curr->next;
    } while(curr != head);
    return;
}

string NameList::Josephus(int k, NameList list, int start){
    NameNode* curr = head;
    NameNode* next1 = nullptr;
    for(unsigned i = 0; i < start-1; ++i){
        curr = curr->next;
    }
    while (head->next != tail){
        for(unsigned i = 0; i < k-1; ++i){
            curr = curr->next;
        }
        next1 = curr->next;
        if(next1->name == curr->name){
            return curr->name;
        }
        cout << "execute " << curr->name << endl; 
        list.RemoveNameAt(curr->name);
        curr = next1;
    }
    return "error";
    //cout << "STOP" << endl;
    //return curr->name;
}