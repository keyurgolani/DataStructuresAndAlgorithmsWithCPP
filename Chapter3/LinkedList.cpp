#include<iostream>
#include<string>
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

  ListNode<U> * getLast() {
    ListNode<U> * currentNode = this -> getHead();
    if(currentNode == NULL) {
      return NULL;
    }
    while(currentNode -> getNext() != NULL) {
      currentNode = currentNode -> getNext();
    }
    return currentNode;
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

  void insert(ListNode<U> * listNode, int position) {
    if(position > this -> length) {
      position = length;
    }
    if(position > 0 && this -> getHead() != NULL) {
      ListNode<U> * currentNode = this -> getHead();
      for (int i = 0; i < position - 2; i++) {
        currentNode = currentNode -> getNext();
      }
      listNode -> setNext(currentNode -> getNext());
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

  bool remove(int position) {
    if(position > this -> length) {
      position = length;
    }
    if(position == 1) {
      this -> removeFromBegin();
    }
    if(position > 1 && this -> getHead() != NULL) {
      ListNode<U> * currentNode = this -> getHead();
      for (int i = 0; i < position - 2; i++) {
        currentNode = currentNode -> getNext();
      }
      ListNode<U> * deleteNode = currentNode -> getNext();
      currentNode -> setNext(deleteNode -> getNext());
      length--;
      delete(deleteNode);
    }
    return false;
  }

  void removeFromBegin() {
    ListNode<U> * deleteNode = this -> getHead();
    this -> setHead(this -> getHead() -> getNext());
    length--;
    delete(deleteNode);
  }

  void removeFromEnd() {
    ListNode<U> * currentNode = this -> getHead();
    if(currentNode == NULL) {
      return;
    }
    if(currentNode -> getNext() == NULL) {
      this -> setHead(NULL);
      delete(currentNode);
    }
    while(currentNode -> getNext() -> getNext() != NULL) {
      currentNode = currentNode -> getNext();
    }
    ListNode<U> * deleteNode = currentNode -> getNext();
    currentNode -> setNext(NULL);
    length--;
    delete(deleteNode);
  }

  bool removeMatch(ListNode<U> * listNode) {
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

  bool removeMatch(U data) {
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

  string toString() {
    string listString = "[";
    ListNode<U> * currentNode = this -> getHead();
    while(currentNode != NULL) {
      listString = listString.append(to_string(currentNode -> getData()));
      if(currentNode -> getNext() != NULL) {
        listString = listString.append(", ");
      }
      currentNode = currentNode -> getNext();
    }
    listString = listString.append("]");
    return listString;
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
  linkedList -> insert(new ListNode<int>(32), 5);
  linkedList -> print();
  linkedList -> removeFromBegin();
  linkedList -> print();
  linkedList -> removeFromEnd();
  linkedList -> print();
  cout << linkedList -> getLast() -> getData() << endl;
  linkedList -> remove(8);
  linkedList -> print();
  cout << linkedList -> toString() << endl;
  return 0;
}
