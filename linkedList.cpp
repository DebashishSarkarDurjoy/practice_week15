#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T> *next;
    
    Node (T data) {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node<int> *head, int newData) {
    Node<int> *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new Node<int>(newData);
}

void insertAtHead(Node<int> *head, int newData) {
    Node<int> *temp = head->next;
    
    head->next = new Node<int>(newData);
    head->next->next = temp;
}

void insertInMiddle(Node<int> *head, int newData, int pos) {
    if (pos == 0) {
        insertAtHead(head, newData);
        return ;
    }

    Node<int> *temp = head;
    Node<int> *prev = NULL;
    for (int jump = 1; jump <= pos-1; jump++) {
        prev = temp;
        temp = temp->next;
    }

    Node<int> *newNode = new Node<int>(newData);
    newNode->next = temp;
    prev->next = newNode;
    
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node<int> *head, int data) {
    Node<int> *temp = head;

    Node<int> *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // assuming the node is found
    if (temp != NULL) prev->next = temp->next;

}

int main(void) {
    Node<int> *head = new Node<int>(0); 

    for (int i = 1; i <= 10; i++) {
        insert(head, i);
    }

    print(head);

    // deleteNode(head, 12);
    // insertInMiddle(head, 23, 2);
    
    print(head);

    return 0;
}