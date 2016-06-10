#include<iostream>
using namespace std;

int nPower3By2(int n){
	int i=1, j;
	int count = 0;
	int sum = 0;
	for (i = 0; i <n; i++){
		j = 0;
		while(sum<i){
			sum = sum + j;
			j++;
			count++;
		}			
	}
	return count;
}

int main(int argc, char const *argv[]) {
	int n = 6;
	cout << nPower3By2(n) << endl;
}
