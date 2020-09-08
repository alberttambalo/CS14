#include <string>
#include <iostream>
using namespace std;
#include "Jug.h"



int main(){

//Jug head(3, 5, 4, 1, 2, 3, 4, 5, 6);
    {
        string solution;
    Jug head(3, 5, 4, 1, 1, 1, 1, 1, 1);
    if (head.solve(solution) != 1) {
        cout << "Error 3" << endl;
    }
        // cout << "found" << endl;
        cout << solution << endl << endl;
    }
    {
    string solution;
    Jug head( 3, 5, 4, 1, 1, 1, 1, 1, 2);         
    if(head.solve(solution) != 1) {
        cout << "Error 3" << endl;
    }
        // cout << "found2" << endl;
        cout << solution << endl;
    }

}