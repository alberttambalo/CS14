#include"AVLTree.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;


AVLTree::AVLTree(){
    root = nullptr;
}

void AVLTree::insert(const string &newString){
    Node* temp = new Node();
    temp->Setstr(newString);
    if(root == nullptr){
        root = temp;
        root->Setleft(nullptr);
        root->Setright(nullptr);
        root->Setpar(nullptr);
    } else {
        Node* curr = root;
        while(curr != nullptr){
            if(temp->Getstr() < curr->Getstr()){
                if(curr->Getleft() == nullptr){
                    curr->Setleft(temp);
                    temp->Setleft(nullptr);
                    temp->Setright(nullptr);
                    temp->Setpar(curr);
                    break;
                } else {
                    curr = curr->Getleft();
                }
            } else if(temp->Getstr() > curr->Getstr()){
                if(curr->Getright() == nullptr){
                    curr->Setright(temp);
                    temp->Setleft(nullptr);
                    temp->Setright(nullptr);
                    temp->Setpar(curr);
                    break;
                } else {
                    curr = curr->Getright();
                }
            } else {
                return;
            }
        }
        //cout << "out";
        //Node* up = curr;
        
        // while (up != nullptr){
        //     cout << "huh";
        //     up->Setbf(balanceFactor(up));
        //     up = up->Getpar();
        // }
        update(root);
        rebalance(curr);
    }
}
void AVLTree::update(Node* n){
    if(n == nullptr){
        return;
    }
    update(n->Getleft());
    n->Setbf(balanceFactor(n));
    //cout << balanceFactor(n) << " ";
    update(n->Getright());
}

void AVLTree::rebalance(Node* n){
    Node* curr = n;
    while(curr != nullptr){
        //cout << " " << curr->Getstr() << " ";
        if(curr->Getbf() == -2){
            //cout << "rotating";
            if(curr->Getright()->Getleft() == nullptr){
                //cout << "rr";
                RR(curr);
                //cout << "dun1";
                break;
            } else {
                //cout << "rl";
                RL(curr);
                update(root);
                RR(curr);
                //cout << "dun2";
                break;

            }
        } else if (curr->Getbf() == 2){
            if(curr->Getleft()->Getright() == nullptr){
                //cout << "LL";
                LL(curr);
                break;
            } else {
                LR(curr);
                update(root);
                LL(curr);
                //cout << "LR";
                break;
            }
        }   
        curr = curr->Getpar();
    }
    //cout << "update";
    update(root);
}

void AVLTree::RR(Node* n){
//cout << n->Getstr() << "RR";
    Node* A = n;
    Node* B = n->Getright();
    //Node* C = n->Getright()->Getright();
    if(A != root){
        if(A->Getpar()->Getright() == A){
            A->Getpar()->Setright(B);
            B->Setpar(A->Getpar());
        } else {
            A->Getpar()->Setleft(B);
            B->Setpar(A->Getpar());
        }
    } else {
        root = B;
        B->Setpar(nullptr);
    }
    if(B->Getleft()){
        A->Setright(B->Getleft());
        B->Getleft()->Setpar(A);
    } else {
        A->Setright(nullptr);
    }
    B->Setleft(A);
    A->Setpar(B);
}

void AVLTree::LL(Node *n){
    //cout << n->Getstr() << "LL";
    Node* A = n;
    Node* B = n->Getleft();
    //Node* C = n->Getleft()->Getleft();
    //cout << "137";
    if(A != root){
        //cout << "139";
        if(A->Getpar()->Getright() == A){
            A->Getpar()->Setright(B);
            B->Setpar(A->Getpar());
        } else {
            A->Getpar()->Setleft(B);
            B->Setpar(A->Getpar());
        }
        //cout << "147";
    } else {
        root = B;
        B->Setpar(nullptr);
    }
    //cout <<"150";
    if(B->Getright() != nullptr){
        A->Setleft(B->Getright());
        B->Getright()->Setpar(A);
    } else {
        A->Setleft(nullptr);
    }
    //cout << "155";
    B->Setright(A);
    A->Setpar(B);
}

void AVLTree::LR(Node *n){
    //cout << n->Getstr() << "LR";
    Node* A = n;
    Node* B = n->Getleft();
    Node* C = n->Getleft()->Getright();
    A->Setleft(C);
    C->Setpar(A);
    B->Setpar(C);
    if(C->Getleft()){
        C->Getleft()->Setpar(B);
        B->Setright(C->Getleft());
    } else {
        B->Setright(nullptr);
    }
    C->Setleft(B);
    B->Setpar(C);

}

void AVLTree::RL(Node* n){
    //cout << n->Getstr() << "RL";
    Node* A = n;
    Node* B = n->Getright();
    Node* C = n->Getright()->Getleft();
    A->Setright(C);
    C->Setpar(A);
    if(C->Getright()){
        C->Getright()->Setpar(B);
        B->Setleft(C->Getright());
    } else {
        B->Setleft(nullptr);
    }
    C->Setright(B);
    B->Setpar(C); 

}


int AVLTree::balanceFactor(Node* n){
    int l = getHeight(n->Getleft());
    int r = getHeight(n->Getright());
    // if(!(n->Getleft())){
    //     l = 0;
    // }
    // if(!(n->Getright())){
    //     r = 0;
    // }
    // << " " << l-r << " ";
    return l - r;
}

int AVLTree::getHeight(Node* n){
    if(n == nullptr){
        return 0;
    }
    int lh = getHeight(n->Getleft());
    int rh = getHeight(n->Getright());
    if(lh>rh){
        return lh+1;
    } else {
        return rh+1;
    }
}


void AVLTree::printBalanceFactors(){
    update(root);
    print(root);
    cout << endl;
    //cout << "pbf";
}
void AVLTree::print(Node* n){
    if(n == nullptr){
        return;
    }
    print(n->Getleft());
    cout << n->Getstr() << "(" << n->Getbf() << "), ";
    print(n->Getright());
}




void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->Getleft()){
            visualizeTree(outFS,n->Getleft());
            outFS<<n->Getstr() <<" -> " <<n->Getleft()->Getstr()<<";"<<endl;    
        }

        if(n->Getright()){
            visualizeTree(outFS,n->Getright());
            outFS<<n->Getstr() <<" -> " <<n->Getright()->Getstr()<<";"<<endl;    
        }
    }
}
