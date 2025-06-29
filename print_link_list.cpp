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
int main(){
    Node* head = new Node(20);
    Node* a = new Node(40);
    Node* b = new Node(80);
    Node* c = new Node(120);

    head->next = a;
    a->next = b;
    b->next = c;

    while (head != NULL)
    {
        cout << head->val <<endl;
        head = head->next;
    }
    return 0;  
}