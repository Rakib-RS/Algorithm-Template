#include<iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
    Node() {
        this->value = 0;
        this->next = NULL;
    }
};

void addNode(Node* head, Node* newNode) {
    // at the end
    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(Node* head) {
    while(head != NULL) {
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    Node* head =  new Node();
    head->value = 1;
    head->next = NULL;

    Node* newNode = new Node();
    newNode->value = 2;
    addNode(head, newNode);
    printList(head);
    return 0;
}