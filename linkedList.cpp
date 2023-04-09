#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node* next;
    
    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node* head, int newData) {
    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new Node(newData);
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main(void) {
    Node *head = new Node(0); 

    for (int i = 1; i <= 10; i++) {
        insert(head, i);
    }

    print(head);

    return 0;
}