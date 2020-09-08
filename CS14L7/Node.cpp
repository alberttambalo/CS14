#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

Node::Node(){
    str = "";
    bf = 0;
    par = nullptr;
    left = nullptr;
    right = nullptr;
}

string Node::Getstr(){
    return str;
}

void Node::Setstr(string s){
    str = s; 
}

int Node::Getbf(){
    return bf;
}

void Node::Setbf(int i){
    bf = i;
}

Node* Node::Getpar(){
    return par;
}

void Node::Setpar(Node* p){
    par = p;
}

Node* Node::Getleft(){
    return left;
}

void Node::Setleft(Node* t){
    left = t;
}

Node* Node::Getright(){
    return right;
}

void Node::Setright(Node* t){
    right = t;
}




