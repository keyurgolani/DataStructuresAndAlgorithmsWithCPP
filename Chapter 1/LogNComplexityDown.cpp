#include<iostream>
using namespace std;

int logNDown(int n) {
  int count = 0;
  for(int i = n; i > 0; i = i/2) {
    count ++;
  }
  return count;
}

int main(int argc, char const *argv[]) {
  int n = 19;
  cout << logNDown(n) << endl;
  return 0;
}
