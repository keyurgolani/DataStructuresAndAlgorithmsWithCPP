#include<iostream>
using namespace std;

int logNUp(int n) {
  int count = 0;
  for(int i = 1; i < n; i = i*2) {
    count ++;
  }
  return count;
}

int main(int argc, char const *argv[]) {
  int n = 19;
  cout << logNUp(n) << endl;
  return 0;
}
