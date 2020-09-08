#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ctime>
using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    unsigned min = index;
    for(unsigned i = index; i < vals.size(); ++i){
        if(vals.at(min) > vals.at(i)){
            min = i;
        }
    }
    return min;
}


template<typename T>
void selection_sort(vector<T> &vals){
    T temp;
    for(unsigned k = 0; k < vals.size(); ++k){

        unsigned mindex = min_index(vals,k);
        if(mindex != k){
            temp = vals.at(k);
            vals.at(k) = vals.at(mindex);
            vals.at(mindex) = temp;
        }
    }
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T>
T getElement(vector<T> vals, int index){
    int sz = vals.size();
    if(index > sz - 1 || index < 0){
        throw out_of_range("out of range exception occured");
    }
    return vals.at(index);// included in at function

}




int main(){
    //SELECTIONSORT AND MIN INDEX TESTING HARNESS

    vector<int> v;
    srand(343);
    v.push_back(rand());
    v.push_back(rand());
    v.push_back(rand());
    v.push_back(5);
    v.push_back(rand());
    v.push_back(rand());
    cout << "Pushing back" << endl;
    for(unsigned i = 0; i < v.size(); ++i){
        cout << v.at(i) << ",";
    }
    cout << endl;
    cout << "Find minimum index" << endl;
    cout << min_index(v, 0);
    cout << endl;
    cout << "Running Selection Sort" << endl;
    selection_sort(v);
    for(unsigned i = 0; i < v.size(); ++i){
        cout << v.at(i) << ",";
    }
    cout << endl;

    //PART 2

    try{
     srand(time(0));
     vector<char> values = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getElement(values,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
        }
    }
    catch(std::out_of_range& excpt){
        cout << excpt.what() << endl;
    }

    
    return 0;


}