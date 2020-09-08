#ifndef JUGG
#define JUGG
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct State {
    int A;
    int B;
    int cost;
    State* from;
    string op;
    State(int a, int b, int c, State* f, string op);
    //priority_queue <State*> neighbors;
};



class Jug {
    public:
        Jug(int,int,int,int,int,int,int,int,int);
        ~Jug();

        //solve is used to check input and find the solution if one exists
        //returns -1 if invalid inputs. solution set to empty string.
        //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
        //returns 1 if solution is found and stores solution steps in solution string.
        int solve(string &solution);
        void solver(State* s);
    private:
        //anything else you need
        int CA;
        int CB;
        int Goal;
        int CFA;
        int CFB;
        int CEA;
        int CEB;
        int CAB;
        int CBA;
};

#endif