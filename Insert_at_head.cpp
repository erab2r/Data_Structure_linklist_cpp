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
void insert_at_head(Node* &head,int val){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;

}
void print_link_list(Node* head){
    Node*temp = head;
    while (temp != NULL)
    {   
         cout << temp->val << endl;
        temp = temp->next;
    }
   
}
int main(){
    Node* head = new Node(20);
    Node* a = new Node(30);
    Node* b = new Node(40);

    head->next = a;
    a->next = b;
    insert_at_head(head,50);
    insert_at_head(head,60);
    insert_at_head(head,70);
    insert_at_head(head,80);
    print_link_list(head);
    
    return 0;
}