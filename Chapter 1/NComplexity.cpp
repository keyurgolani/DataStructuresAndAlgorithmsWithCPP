#include<iostream>
using namespace std;

int orderN(int n) {
	int count = 0;
	for(int i = 1; i < n; i++) {
		count++;
	}
}

int main(int argc, char const *argv[]) {
	int n = 19;
	cout << orderN(n) << endl;
}
