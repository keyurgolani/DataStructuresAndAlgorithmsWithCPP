#include<iostream>
using namespace std;

template <class T>
class ListNode {
private:
  T data;
  ListNode * nextNode;

public:
  ListNode() {
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
    listNode -> setNext(this -> getHead());
    this -> head = listNode;
    length++;
  }

  void insertAtEnd(ListNode<U> * listNode) {
    if(this -> length > 0 && this -> getHead() != NULL) {
      ListNode<U> * currentNode = this -> getHead();
      for (int i = 0; i < length - 1; i++) {
        currentNode = currentNode -> getNext();
      }
      currentNode -> setNext(listNode);
    } else {
      this -> setHead(listNode);
    }
    length++;
  }

  void print() {
    ListNode<U> * currentNode = this -> getHead();
    while(currentNode != NULL) {
      cout << currentNode -> getData();
      if(currentNode -> getNext() != NULL) {
        cout << " --> ";
      }
      currentNode = currentNode -> getNext();
    }
    cout << endl;
    cout << "Size: " << length << endl;
  }

  bool search(U data) {
    ListNode<U> * currentNode = this -> getHead();
    while(currentNode != NULL) {
      if(currentNode -> getData() == data) {
        return true;
      }
      currentNode = currentNode -> getNext();
    }
    return false;
  }

  bool remove(ListNode<U> * listNode) {
    ListNode<U> * currentNode = this -> getHead();
    ListNode<U> * deleteNode;
    if(currentNode == NULL) return false;
    if(currentNode == listNode) {
      deleteNode = currentNode;
      this -> setHead(deleteNode -> getNext());
      delete(deleteNode);
      length--;
      return true;
    }
    while(currentNode -> getNext() != NULL) {
      if(currentNode -> getNext() == listNode) {
        deleteNode = currentNode -> getNext();
        currentNode -> setNext(deleteNode -> getNext());
        delete(deleteNode);
        length--;
        return true;
      }
      currentNode = currentNode -> getNext();
    }
    return false;
  }

  bool remove(U data) {
    ListNode<U> * currentNode = this -> getHead();
    ListNode<U> * deleteNode;
    if(currentNode == NULL) return false;
    if(currentNode -> getData() == data) {
      deleteNode = currentNode;
      this -> setHead(deleteNode -> getNext());
      delete(deleteNode);
      length--;
      return true;
    }
    while(currentNode -> getNext() != NULL) {
      if(currentNode -> getNext() -> getData() == data) {
        deleteNode = currentNode -> getNext();
        currentNode -> setNext(deleteNode -> getNext());
        delete(deleteNode);
        length--;
        return true;
      }
      currentNode = currentNode -> getNext();
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  cout << "Hello World!" << endl;
  LinkedList<int> * linkedList = new LinkedList<int>();
  ListNode<int> * listNode = new ListNode<int>(25);
  linkedList -> insertAtEnd(new ListNode<int>(1));
  linkedList -> insertAtBeginning(new ListNode<int>(5));
  linkedList -> insertAtEnd(listNode);
  linkedList -> insertAtEnd(new ListNode<int>(2));
  linkedList -> insertAtEnd(new ListNode<int>(11));
  linkedList -> insertAtEnd(new ListNode<int>(15));
  linkedList -> insertAtBeginning(new ListNode<int>(55));
  linkedList -> insertAtBeginning(new ListNode<int>(21));
  linkedList -> insertAtEnd(new ListNode<int>(65));
  linkedList -> print();
  if(linkedList -> search(25)) {
    cout << "25 Exists" << endl;
  } else {
    cout << "25 Not Found" << endl;
  }
  if(linkedList -> search(71)) {
    cout << "71 Exists" << endl;
  } else {
    cout << "71 Not Found" << endl;
  }
  if(linkedList -> remove(listNode)) {
    cout << "Delete Successful" << endl;
  } else {
    cout << "Node Not Found" << endl;
  }
  if(linkedList -> remove(new ListNode<int>(33))) {
    cout << "33 Delete Successful" << endl;
  } else {
    cout << "33 Node Not Found" << endl;
  }
  if(linkedList -> remove(21)) {
    cout << "21 Delete Successful" << endl;
  } else {
    cout << "21 Node Not Found" << endl;
  }
  if(linkedList -> remove(33)) {
    cout << "33 Delete Successful" << endl;
  } else {
    cout << "33 Node Not Found" << endl;
  }
  linkedList -> print();
  return 0;
}
