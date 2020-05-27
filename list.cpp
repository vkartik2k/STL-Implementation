#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T> * next, * prev;
    Node(T data){
        this->data = data;
        prev = next = NULL;
    }
};

template<typename T> class List{
	Node<T> *head;
	Node<T> *tail;
	int len;
public:
	List(){
		head = tail = NULL;
		len = 0;
	}

	~List() {
		while(tail) {
			Node<T> * temp = tail;
			tail = tail->prev;
			delete temp;
		}
	}

	class iterator {
		Node<T> * _curr;
	public:
		iterator(Node<T> * ptr) : _curr(ptr) {}

		iterator &operator++() {
			_curr = _curr->next;
			return *this;
		}

		iterator &operator--() {
			_curr = _curr->prev;
			return *this;
		}

		T &operator*() {
			return _curr->data;
		}

		bool operator==(const iterator &second) const {
			return _curr == second._curr;
		}

		bool operator!=(const iterator &second) const {
			return _curr != second._curr;
		}
	};
	
	int size() {
		return len;
	}
	bool empty() {
		return !len;
	}
	
	void push_back(T data) {
		Node<T> *newNode = new Node<T>(data);
		if(!head) head = tail = newNode;
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = tail->next;
		}
		len++;
	}
	void push_front(T data) {
		Node<T> *newNode = new Node<T>(data);
		if(!head) head = tail = newNode;
		else {
			head->prev = newNode;
			newNode->next = head;
			head = head->prev;
		}
		len++;
	}
	void pop_back() {
		if(head) {
			Node<T>* temp = tail;
			tail = tail->prev;
			delete temp;
			if(!tail) head = NULL;
			else tail->next = NULL;
			len--;
		}
	}

	void pop_front() {
		if(head) {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			if(!head) tail = NULL;
			else head->prev = NULL;
			len--;
		}
	}

	iterator begin() {
		return iterator(head);
	}
	iterator end() {
		return iterator(tail);
	}

	// Not part of STL 
	void debug() {
		Node<T> * curr = head;
		while(curr) {
			cout<<curr->data<<" ";
			curr = curr->next;
		}
		cout<<endl;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
	List<int> l1;
	cout<<"head"<<endl;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_front(3);
	l1.pop_back();
	List<int> :: iterator it = l1.begin();
	auto it2 = l1.end();
	++it;
	cout<<(it!=it2)<<endl;
	cout<<l1.size()<<endl;
	l1.debug();

	delete &l1;
}