#include<iostream>
using namespace std;

template<typename T> class Node{
public:
    T data;
    Node<T> * next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

template<typename T> class queue{
    Node<T> * head = NULL;
    Node<T> * tail = NULL;
    int len = 0;
public:
    queue(){
        len = 0;
    }
    bool empty(){
        return !len;
    }
    int size() {
        return len;
    }
    void push(T data){
        if(head){
            Node<T> * temp = new Node<T>(data);
            tail->next = temp;
            tail = temp;
        }
        else{
            head = new Node<T>(data);
            tail = head;
        }
        len++;
    }
    void pop(){
        if(len==0) return;
        Node<T> * temp = head;
        head = head->next;
        delete temp;
        len--;
    }
    T front(){
        return head->data;
    }
    // Not part of STL
    void debug(){
        Node<T> * temp = head;
        for(int i=0;i<len;i++){
            cout<<temp->data<<" ";
            temp= temp->next;
        }
        cout<<endl;
    }
};

int main() {
    queue<int> myQueue;
    cout<<myQueue.size()<<endl;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.debug();
    myQueue.pop();
    myQueue.debug();
    myQueue.pop();
    myQueue.debug();
    myQueue.pop();
    myQueue.debug();
}