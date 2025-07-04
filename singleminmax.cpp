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

void insert_at_tail(Node* &head, Node* &tail, int val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

int find_max_min(Node* head) {
    if (head == NULL) {
        return 0;
    } 

    int mx = head->val;
    int mn = head->val;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->val > mx) mx = temp->val;
        if (temp->val < mn) mn = temp->val;
        temp = temp->next;
    }

    return mx - mn;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        insert_at_tail(head, tail, val);
    }
    int different = find_max_min(head);
    cout << different << endl;

    return 0;
}
