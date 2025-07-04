#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node*& head, Node*& tail, int val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

int same_to_same(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val != temp2->val) {
            return 0;
        } 
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 != NULL || temp2 != NULL) {
        return 0;
    }

    return 1;
}
int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    int val;
    while (cin >> val && val != -1) {
        insert_at_tail(head1, tail1, val);
    }

    while (cin >> val && val != -1) {
        insert_at_tail(head2, tail2, val);
    }

    if (same_to_same(head1, head2) == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
