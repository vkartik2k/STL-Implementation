#include<iostream>
#include<vector>
using namespace std;

class priority_queue {
    vector<int> * v;
    int length;
    public:
    priority_queue() {
         v = new vector<int>();
         length = 0;
    }
    
    priority_queue(vector<int> v1) {
        int size1 = v1.size();
        for(int i=0 ; i<size1; i++) {
            this->push(v1[i]);
        }
    }
    
    int size() {
        return this->length;
    }
    
    bool empty() {
        return length>0 ? false : true;
    }
    
    int top() {
        return v->at(0);
    }
    
    void push(int data) {
        v->push_back(data);
        length++;
        int i = length-1;
        while(i>0) {
            int parent = (i-1)/2;
            if(v->at(parent) > v->at(i)) {
                swap(v->at(parent), v->at(i));
            }
            else break;
            i = parent;
        }
    }
    
    void pop() {
        swap(v->at(0), v->at(length-1));
        int i = 0;
        length--;
        while(i<length) {
            int left = i*2 + 1;
            int right = left + 1;
            if(left<length && right<length && (v->at(i) > v->at(left) || v->at(i) > v->at(right))) {
                if(v->at(left) > v->at(right)) {
                    swap(v->at(right), v->at(i));
                    i = right;
                }
                else {
                    swap(v->at(left), v->at(i));
                    i = left;
                }
            }
            else if(left<length && v->at(i) > v->at(left)) {
                swap(v->at(left), v->at(i));
                i = left;
            }
            else break;
        }
    }
    // Not part of STL
    void debug() {
        for(int i=0; i<length; i++) cout<<v->at(i)<<" ";
        cout<<endl;
    }
};

int main() {
    priority_queue pq;
    pq.push(10);
    pq.push(20);
    pq.pop();
    return 0;
}