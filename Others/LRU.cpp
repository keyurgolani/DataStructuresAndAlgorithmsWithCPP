#include<iostream>
using namespace std;

//LRU - Least Recently Used Element

int TABLE_SIZE = 10;

template <class T>
class Node {
private:
  T data;
  Node * nextNode;

public:
  Node() {
    this -> data = NULL;
    this -> nextNode = NULL;
  }

  Node(T data) {
    this -> data = data;
    this -> nextNode = NULL;
  }

  Node * getNext() {
    return this -> nextNode;
  }

  void setNext(Node * nextNode) {
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
  Node<U> * head;
  int length;

public:
  LinkedList() {
    this -> head = NULL;
    this -> length = 0;
  }

  Node<U> * getHead() {
    return this -> head;
  }

  void setHead(Node<U> * node) {
    this -> head = node;
  }

  int getLength() {
    return this -> length;
  }

  void setLength(int length) {
    this -> length = length;
  }

  void insertAtBeginning(Node<U> * node) {
    node -> setNext(this -> head);
    this -> head = node;
    length++;
  }

  Node<U> * pop(U data) {
    Node<U> * currentNode = getHead();
    Node<U> * returnNode;
    if (currentNode != NULL) {
      while(currentNode -> getNext() != NULL) {
        if(currentNode -> getNext() -> getData() == data) {
          returnNode = currentNode -> getNext();
          currentNode -> setNext(currentNode -> getNext() -> getNext());
        }
        currentNode = currentNode -> getNext();
      }
    }
    return returnNode;
  }

};

template <class V>
class LRU {
private:
  LinkedList<V> * LRUArray;
  int latestIndex;

public:
  LRU() {
    this -> LRUArray = new LinkedList<V>[TABLE_SIZE];
  }

  void add(V data) {
    int key = hashFunction(data);
    LRUArray[key].insertAtBeginning(new Node<V>(data));
  }

  void use(V data) {
    int key = hashFunction(data);
    Node<V> * currentNode = LRUArray[key].pop(data);
    LRUArray[key].insertAtBeginning(currentNode);
    latestIndex = key;
  }

  V getLRU() {
    return LRUArray[latestIndex].getHead() -> getData();
  }
};

template <typename W>
int hashFunction(const W * data) const {
  static const int shift = (int)findLog2(1 + sizeof(W));
  data = (int)(data) >> shift;
  return (data % TABLE_SIZE);
}

int findLog2(int size) {
  int returnValue = 0;
  for(int i = 1; i < size; i = i*2) {
    returnValue++;
  }
  return returnValue;
}

int main(int argc, char const *argv[]) {
  LRU<int> * lru = new LRU<int>();
  // lru -> add(3);
  // lru -> add(5);
  // lru -> add(24);
  // cout << lru -> getLRU();
  // lru -> use(5);
  // cout << lru -> getLRU();
  return 0;
}
