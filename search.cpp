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

int find_index(Node* head, int x) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == x) return index;
        temp = temp->next;
        index++;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Node* head = NULL;
        Node* tail = NULL;
        int val;
        while (true) {
            cin >> val;
            if (val == -1) break;
            insert_at_tail(head, tail, val);
        }

        int x;
        cin >> x;
        int result = find_index(head, x);
        cout << result << endl;
    }

    return 0;
}
