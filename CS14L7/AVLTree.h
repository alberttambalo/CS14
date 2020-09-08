#ifndef AVLTree_h
#define AVLTree_h
#include <string>
#include <iostream>
using namespace std;
#include "Node.h"


class AVLTree {
    private: 
        Node* root;
        void rebalance(Node* n);
        void LL(Node* n);
        void LR(Node* n);
        void RR(Node* n);
        void RL(Node* n);
        void visualizeTree(ofstream &, Node* n);
        int getHeight(Node* n);
        void print(Node*n);
        void update(Node* n);
    public: 
        AVLTree();
        void insert(const string &);
        int balanceFactor(Node*);
        void printBalanceFactors();
        void visualizeTree(const string &);
};
#endif