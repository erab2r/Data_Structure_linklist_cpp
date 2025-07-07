#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_tail(Node* &head,Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
void print_max_value(Node* head) {
    int max_val = INT_MIN;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val > max_val) {
            max_val = temp->val;
        }
        temp = temp->next;
    }
    cout << max_val << endl;
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    int val;

    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_at_tail(head1, tail1, val);
    }
       while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_at_tail(head2, tail2, val);
    }

      print_max_value(head);

    return 0;
}
