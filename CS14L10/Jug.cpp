#include <iostream>
using namespace std;
#include "Jug.h"
#include <unordered_map>
#include <vector>
#include <queue>

Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA){
    CA = Ca;
    CB = Cb;
    Goal = N;
    CFA = cfA;
    CFB = cfB;
    CEA = ceA;
    CEB = ceB;
    CAB = cpAB;
    CBA = cpBA;

}

Jug::~Jug(){}


vector<State*> visited;
string ans = "";

int Jug::solve(string &solution){
    if(this->CA > this->CB || this->CA <= 0 || this->Goal > this->CB || this->CB > 1000){
        solution = "";
        return -1;
    }
    visited.clear();
    ans = "";
    State* start = new State(0,0,0, nullptr, "");
    visited.push_back(start);

    this->solver(start);
    solution =  ans;
    if(solution == ""){
        return 0;
    }
    return 1;
}

void Jug::solver(State* s){
    // cout << s->A << "," << s->B << endl;
    // cout << CA;
    if(s->A == 0 && s->B == Goal){
        // cout <<  "cost = " << s->cost <<  endl;

        State* curr = s;
        //cout << s->op;
        vector<string> ra;
        while(true){
            if(curr != nullptr){
                // cout << curr->A << "," << curr->B << endl;
                //cout << curr->op;
                //cout << curr->op;
                ra.push_back(curr->op);
                
            } else if(curr == nullptr){
                for(int i = ra.size()-1; i >= 0; --i){
                    ans+=ra.at(i);
                }
                ans += "success ";
                ans += to_string(s->cost);
                // cout << "last";
                // visited.clear();
                return;
            }
            curr = curr->from;
        }
        return;
    }
    for(unsigned i = 1; i <= 6; ++i){
        if(i == 1){

            //cout << "i = " << i << " ";
            if(s->A != CA){
                // cout << "FA" << endl;
                //cout << ".";
                bool found = false;
                for(unsigned j = 0; j < visited.size(); j++ ){
                    if(visited.at(j)->A == CA && visited.at(j)->B == s->B){
                        if(visited.at(j)->cost > s->cost + CFA){
                            visited.at(j)->cost = s->cost+CFA;
                            visited.at(j)->from = s;
                            visited.at(j)->op = "fill A\n";
                            
                        }
                        found = true;
                        //cout << "found";
                    }
                }
                // cout << found;
                if(!found){
                    //cout << CA;
                    State* n = new State(CA, s->B, s->cost + CFA, s, "fill A\n");
                    visited.push_back(n);
                    solver(n);
                }
            }
            continue;
        } else if(i == 2){
            if(s->B != CB){
                // cout << "FB" << endl;
                bool found = false;
                for(unsigned j = 0; j < visited.size(); j++){
                    if(visited.at(j)->B == CB && visited.at(j)->A == s->A){
                        if(visited.at(j)->cost > s->cost + CFB){
                            visited.at(j)->cost = s->cost+CFB;
                            visited.at(j)->from = s;
                            visited.at(j)->op = "fill B\n";
                        }
                        found = true;
                    }
                }
                if(!found){
                    State* n = new State(s->A, CB, s->cost + CFB, s, "fill B\n");
                    visited.push_back(n);
                    solver(n);
                }
            }
            continue;
        } else if(i == 3){
            if(s->A > 0){
                // cout << "EA" << endl;
                bool found = false;
                for(unsigned j = 0; j < visited.size(); j++){
                    if(visited.at(j)->B == s->B && visited.at(j)->A == 0){
                        if(visited.at(j)->cost > s->cost + CEA){
                            visited.at(j)->cost = s->cost+CEA;
                            visited.at(j)->from = s;
                            visited.at(j)->op = "empty A\n";
                        }
                        found = true;
                    }
                }
                if(!found){
                    State* n = new State(0, s->B, s->cost + CEA, s, "empty A\n");
                    visited.push_back(n);
                    solver(n);
                }
            }
            continue;
        } else if(i == 4){
            if(s->B > 0){
                // cout << "EB" << endl;
                bool found = false;
                for(unsigned j = 0; j < visited.size(); j++){
                    if(visited.at(j)->A == s->A && visited.at(j)->B == 0){
                        if(visited.at(j)->cost > s->cost + CEB){
                            visited.at(j)->cost = s->cost+CEB;
                            visited.at(j)->from = s;
                            visited.at(j)->op = "empty B\n";
                        }
                        found = true;
                    }
                }
                if(!found){
                    State* n = new State(s->A, 0, s->cost + CEB, s, "empty B\n");
                    visited.push_back(n);
                    solver(n);
                }
            }
            continue;
        } else if(i == 5){
            if(s->B < CB && s->A != 0){
                int Aval = 0;
                int Bval = 0;
                if(s->A + s->B > CB){
                    Aval = (s->A + s->B) - CB;
                    Bval = CB;
                } else{
                    Aval = 0;
                    Bval = s->A + s->B;
                }
                // cout << "AB" << endl;
                bool found = false;
                for(unsigned j = 0; j < visited.size(); j++){
                    if(visited.at(j)->A == Aval && visited.at(j)->B == Bval){
                        if(visited.at(j)->cost > s->cost + CAB){
                            visited.at(j)->cost = s->cost+CAB;
                            visited.at(j)->from = s;
                            visited.at(j)->op = "pour A B\n";
                        }
                        found = true;
                    }
                }

                if(!found){
                    State* n = new State(Aval, Bval, (s->cost + CAB), s, "pour A B\n");
                    visited.push_back(n);
                    solver(n);
                }     
            }
            continue;
        } else if(i == 6){
            if(s->A < CA && s->B != 0){
                int Aval = 0;
                int Bval = 0;
                if(s->A + s->B > CA){
                    int Aval = CA;
                    int Bval = (s->A + s->B) - CA;
                    int CVal = Aval + Bval;
                    if (CVal == -10000){
                        cout << "chsid";
                    }
                } else{
                    int Aval = s->A + s->B;
                    int Bval = 0;
                    int CVal = Aval + Bval;
                    if (CVal == -10000){
                        cout << "chsid";
                    }
                }


                // cout << "BA" << endl;
                bool found = false;
                for(unsigned j = 0; j < visited.size(); j++){
                    if(visited.at(j)->B == Bval && visited.at(j)->A == Aval){
                        if(visited.at(j)->cost > s->cost + CBA){
                            visited.at(j)->cost = s->cost+CBA;
                            visited.at(j)->from = s;
                            visited.at(j)->op = "pour B A\n";
                        }
                        found = true;
                        //cout << found;
                    } 
                    
                }
                if(!found){
                    
                    State* n = new State(Aval,Bval, (s->cost + CBA), s, "pour B A\n");
                    visited.push_back(n);
                    solver(n);
                }     
            }
            continue;
        }
        return;
    }
}

State::State(int a, int b, int c, State* f, string opp){
    A = a;
    B = b;
    from = f;
    cost = c;
    op = opp;
}