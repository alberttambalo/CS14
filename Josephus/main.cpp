#include "nameList.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;




int main(int argc, char* argv[]){
    ifstream inFS;
    string nameToPF;
    int k = 0;
    int Valn = 0;
    int start;

    if(argc != 2){
        return 1;
    }

    cout << "Opening file " << argv[1] << "." << endl;
    inFS.open(argv[1]);

    if(!inFS.is_open()){
        cout << "could not open file" << argv[1] << "." << endl;
       return 1; 
    }

    NameList list1;
    while(inFS >> nameToPF){
        list1.PushBack(nameToPF);
        ++Valn;
    }
    cout << "n = " << Valn << endl;
    cout << "enter value for k: " << endl;
    cin >> k;
    cout << "start from: " << endl;
    cin >> start;
    cout << list1.Josephus(k, list1, start) << " wins.";
}