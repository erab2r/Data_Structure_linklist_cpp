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
void insert_at_tail(Node* &head,int val){
   Node* newnode = new Node(val);
   if(head == NULL ){
    head = newnode;
    return;
   }
    Node*temp = head;
       while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;


}
void print_link_list(Node* head){
    Node*temp = head;
       while (temp != NULL)
    {
        cout << temp->val <<endl;
        temp = temp->next;
    }
}
int main(){
    Node* head = NULL;
   
    insert_at_tail(head,80);
    print_link_list(head);
    
    return 0;
}