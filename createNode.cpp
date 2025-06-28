#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
};
int main(){
    Node a,b,c;
    a.val = 10;
    b.val = 30;
    c.val = 50;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    cout << a.val <<endl;
    cout <<a.next->val <<endl;
    cout << a.next->next->val << endl;
}


