#include<iostream>
using namespace std;

int nLogN(int n) {
	int count = 0;
	for(int i = n; i > 0; i = i/2) {
		for(int j = 1; j < n; j++) {
			count++;
		}
	}
	return count;
}

int main(int argc, char const *argv[]) {
	int n = 19;
	cout << nLogN(n) << endl;
}
