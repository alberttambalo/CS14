#include <iostream>
#ifndef STACK
#define STACK
#define MAX_SIZE 20
using namespace std;

template <class T>
class stack {
    private:
        T data[MAX_SIZE] = {};
        int size;
    public:
        stack(){
            size = 0;
        }
        void push(T val){
            if(size < MAX_SIZE){
                data[size] = val;
                ++size;
            } else {
                throw overflow_error("Called push on full stack.");
            }
        }
        T pop(){
            T val;
            if(size < 1){
                throw underflow_error("Called pop on empty stack.");
            } else {
                val = data[size - 1];
                --size;

            }
            return val;
        }
        T top(){
            T val;
            if(size < 1){
                throw underflow_error("Called top on empty stack.");
            } else {
                val = data[size - 1];
            }
            return val;
        }
        bool empty(){
            if(size == 0){
                return true;
            } else {
                return false;
            }
        }
};



#endif



