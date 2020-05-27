#include<iostream>
using namespace std;

template<typename T>
class stack{
    T * arr;
    int len = 0;
    int capacity;
public:
    stack(){
        capacity = 1000;
        arr = new int[capacity];
        len = 0;
    }
    int size() {
        return len;
    }
    bool empty() {
        return !len;
    }
    void push(T data){
        for(int i = len;i>0;i--) arr[i] = arr[i-1];
        arr[0] = data;
        len++;
    }
    void pop(){
        if(len==0) return;
        for(int i=0;i<len-1;i++) arr[i] = arr[i+1];
        len--;
    }
    T top(){
        return arr[0];
    }
    // Not part of STL
    void debug(){
        for(int i=0;i<len;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main() {
    stack<int> myStack;
    cout<<myStack.size()<<endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout<<myStack.top()<<endl;
    myStack.pop();
    cout<<myStack.size()<<endl;
    cout<<myStack.top()<<endl;
    myStack.pop();
    cout<<myStack.size()<<endl;
    cout<<myStack.top()<<endl;
    myStack.pop();
    cout<<myStack.size()<<endl;
}