#include<iostream>
using namespace std;

template<typename T> class vector {
    T * buffer;
    int len;
    int capacity;
public:
    vector() {
        buffer = new T[2];
        capacity = 2;
        len = 0;
    }
    
    vector(int n, T defaultVal = 0) {
        buffer = new T[n];
        capacity = len = n;
        for(int i=0; i<len; i++) buffer[i] = defaultVal;
    }

    class iterator {
        T * _curr;
    public:
        iterator(T * ptr) : _curr(ptr) {}

        iterator &operator++() {
            _curr++;
            return *this;
        }

        iterator &operator--() {
            _curr--;
            return *this;
        }

        T &operator*() {
            return *_curr;
        }

        bool operator==(const iterator &second) const {
            return *_curr == *second._curr;
        }

        bool operator!=(const iterator &second) const {
            return *_curr != *second._curr;
        }
    };

    void push_back(T val) {
        if(len>=capacity) {
            T * buffer2 = new T[(int)(1.5*capacity)];
            for(int i=0; i<len; i++) buffer2[i] = buffer[i];
            delete[] buffer;
            capacity = (int)(1.5*capacity);
            buffer = buffer2;
        }
        buffer[len++] = val;
    }

    void pop_back() {
        len--;
        if(len*2 < capacity) {
            T * buffer2 = new T[len];
            for(int i=0; i<len; i++) buffer2[i] = buffer[i];
            delete[] buffer;
            capacity = len;
            buffer = buffer2;
        }
    }

    void resize(int newSize) {
        len = newSize;
        if(len*2 < capacity) {
            T * buffer2 = new T[len];
            for(int i=0; i<len; i++) buffer2[i] = buffer[i];
            delete[] buffer;
            capacity = len;
            buffer = buffer2;
        }
    }

    T at(int index) {
        if(index >=0 && index<len) return buffer[index];
        else throw "Invalid Index";
    }

    T &operator[](int index) {
        if(index >=0 && index<len) return buffer[index];
        else throw "Invalid Index";
    }

    bool empty() {
        return !len;
    }

    int size() {
        return len;
    }

    iterator begin() {
        return iterator(buffer);
    }
    iterator end() {
        return iterator(buffer+len);
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    v.pop_back();
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    cout<<v.empty()<<endl;
}