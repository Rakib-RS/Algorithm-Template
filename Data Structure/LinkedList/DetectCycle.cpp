#include<iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
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

bool isLoopDetected(Node* head) {
    Node* first = head;
    Node* second = head;
    while(first != NULL && first->next != NULL) {
        //move first reference by 2 nodes
        first = first->next->next;
        //move second reference by 1 node
        second = second->next;

        //if two reference meet there is loop;
        if (first == second) {
            return  true;
        }
    }
    return false;
}

int main() {
    Node* head =  new Node(1);
    Node* two = new Node(2);
    
    Node* three = new Node(3);
    Node* four = new Node(4);

    // 1 -> 2 -> 3 -> 4 // 4 -> 2 (loop)

    head->next = two;
    two->next = three;
    three->next = four;

    four->next = two;
    
    cout<< "loop exist: " << (isLoopDetected(head) ? "yes" : "no") <<endl;
    return 0;
}