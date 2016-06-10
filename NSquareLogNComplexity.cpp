#include<iostream>
using namespace std;

int nSquareLogN(int n){
	int count = 0;
	for (int i = 1; i<n;i = i *2){
		for (int j = 1; j<n;j++){
			for (int k = 1; k<n;k++){
				count ++;
			}
		}
	}
	return count;
}

int nSquareLogN2(int n){
	int count = 0;
	for (int i = 1; i<n;i = i+1 ){
		for (int j = 1; j<n;j = j*2){
			for (int k = 1; k<n;k = k + 1){
				count ++;
			}
		}
	}
	return count;
}

int nSquareLogN3(int n){
	int count = 0;
	for (int i = 1; i<n;i++){
		for (int j = 1; j<n;j++){
			for (int k = 1; k<n;k =  k *2){
				count ++;
			}
		}
	}
	return count;
}

int main(int argc, char const *argv[]) {
	int n = 9;
	cout << nSquareLogN(n) << endl;
	cout << nSquareLogN2(n) << endl;
	cout << nSquareLogN3(n) << endl;
}
