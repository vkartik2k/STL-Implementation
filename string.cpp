#include<iostream>
using namespace std;

class String {
    char * buffer;
    int len;
    int capacity;
public:
    String() {
        buffer = new char[2];
        capacity = 2;
        len = 0;
    }
    
    String(int n) {
        buffer = new char[n];
        capacity = 1 + (len  = n);
        for(int i=0; i<len; i++) buffer[i] = 0;
    }

    String(const char str[]) {
        len = 0;
        for(len=0; str[len]!=0; len++);
        buffer = new char[len];
        capacity = len + 1;
        for(int i=0; i<len; i++) buffer[i] = str[i];
    }

    String(const String &s2) {
        len = s2.len;
        capacity = s2.capacity+1;
        buffer = new char[capacity];
        for(int i=0; i<len; i++) buffer[i] = s2.buffer[i];
        buffer[len] = 0;
    }

    void operator=(const String &s2 ) { 
        len = s2.len;
        capacity = s2.capacity;
        buffer = new char[capacity];
        for(int i=0; i<len; i++) buffer[i] = s2.buffer[i];
    }

    void operator=(const char str[]) {
        len = 0;
        for(len=0; str[len]!=0; len++);
        buffer = new char[len];
        capacity = len + 1;
        for(int i=0; i<len; i++) buffer[i] = str[i];
    }

    void push_back(char val) {
        if(len>=capacity) {
            char * buffer2 = new char[(int)(1.5*capacity)];
            for(int i=0; i<len; i++) buffer2[i] = buffer[i];
            delete[] buffer;
            capacity = (int)(1.5*capacity);
            buffer = buffer2;
        }
        buffer[len++] = val;
        buffer[len] = 0;
    }

    void pop_back() {
        len--;
        if(len*2 < capacity) {
            char* buffer2 = new char[len];
            for(int i=0; i<len; i++) buffer2[i] = buffer[i];
            delete[] buffer;
            capacity = len;
            buffer = buffer2;
        }
        buffer[len] = 0;
    }

    void resize(int newSize) {
        len = newSize;
        if(len*2 < capacity) {
            char* buffer2 = new char[len+1];
            for(int i=0; i<len; i++) buffer2[i] = buffer[i];
            delete[] buffer;
            capacity = len+1;
            buffer = buffer2;
        }
        buffer[len] = 0;
    }

    char at(int index) {
        if(index >=0 && index<len) return buffer[index];
        else throw "Invalid Index";
    }

    char &operator[](int index) {
        if(index >=0 && index<len) return buffer[index];
        else throw "Invalid Index";
    }

    bool empty() {
        return !len;
    }

    int size() {
        return len;
    }
};

void print(String s) {
    for(int i=0; i<s.size(); i++) cout<<s[i];
    cout<<endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    String s1("Hello");
    s1 = "Jo";
    s1.push_back('a');
    String s2 = s1;
    print(s2);
}