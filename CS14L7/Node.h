#ifndef Node_h
#define Node_h
#include<string>
#include<iostream>
using namespace std;

class Node {
    private:
        string str;
        int bf;
        Node* par;
        Node* left;
        Node* right;
    public:
        Node();
        string Getstr();
        void Setstr(string s);
        int Getbf();
        void Setbf(int i);
        Node* Getpar();
        void Setpar(Node* p);
        Node* Getleft();
        void Setleft(Node* t);
        Node* Getright();
        void Setright(Node* t);

};   
#endif
