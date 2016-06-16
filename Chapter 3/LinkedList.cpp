#include<iostream>
using namespace std;

template <class T>
class ListNode {
private:
  T data;
  ListNode * nextNode;

public:
  ListNode() {
    this -> data = NULL;
    this -> nextNode = NULL;
  }

  ListNode(T data) {
    this -> data = data;
    this -> nextNode = NULL;
  }

  ListNode * getNext() {
    return this -> nextNode;
  }

  void setNext(ListNode * nextNode) {
    this -> nextNode = nextNode;
  }

   T getData() {
     return this -> data;
   }

   void setData(T data) {
     this -> data = data;
   }

};

template <class U>
class LinkedList {
private:
  ListNode<U> * head;
  int length;

public:
  LinkedList() {
    this -> head = NULL;
    this -> length = 0;
  }

  ListNode<U> * getHead() {
    return this -> head;
  }

  void setHead(ListNode<U> * listNode) {
    this -> head = listNode;
  }

  int getLength() {
    return this -> length;
  }

  void setLength(int length) {
    this -> length = length;
  }

  void insertAtBeginning(ListNode<U> * listNode) {
    listNode.setNext(this -> head);
    this -> head = listNode;
    length++;
  }

  void insertAtEnd(ListNode<U> * listNode) {
    //TODO: Finish this function and then proceed to the next functions
  }
};

int main(int argc, char const *argv[]) {
  cout << "Hello World!" << endl;
  return 0;
}
