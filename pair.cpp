#include<iostream>
using namespace std;

template<typename T1, typename T2> class Pair {
public:
	T1 first;
	T2 second;
	Pair(T1 first, T2 second) {
		this->first = first;
		this->second = second;
	}

	Pair(const Pair<T1, T2> &p2) {
		first = p2.first;
		second = p2.second;
	}

	void swap(Pair<T1, T2> &p2) {
		T1 temp1 = first;
		first = p2.first;
		p2.first = temp1;
		T2 temp2 = second;
		second = p2.second;
		p2.second = temp2;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    Pair<int, int> p1(12,13);
    Pair<int, int> p2 = p1;
    cout<<p2.first<<" "<<p2.second<<endl;
    p2.first = 14;
    p2.second = 15;
    p1.swap(p2);
    cout<<p1.first<<" "<<p1.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;

    return 0;
}