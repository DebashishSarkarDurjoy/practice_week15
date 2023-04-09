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

    temp->next = new Node(newData);
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

    deleteNode(head, 12);

    print(head);

    return 0;
}