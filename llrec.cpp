#include "llrec.h"


void addToBack(Node*& head, Node*& node) {
    if (head == nullptr) {
        head = node;
        node->next = nullptr;
        return;
    }
    if(head->next == nullptr){
        node->next = nullptr;
        head->next = node;
    }else{
        addToBack(head->next, node);
    }

}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head == nullptr) {
        return;
    }

    Node* nextNode = head->next;

    if(head->val <= pivot) {
        addToBack(smaller, head);
    }else {
        addToBack(larger, head);
    }

    head = nextNode;

    llpivot(head, smaller, larger, pivot);
}

