#include<iostream>
using namespace std;

int squareRootN(int n){
	int i=1;
	int sum = 0;
	while(sum<n){
		sum = sum + i;
		i++;
	}
	return i-1;
}

int main(int argc, char const *argv[]) {
	int n = 6;
	cout << squareRootN(n) << endl;
}
