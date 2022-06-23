// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node *head=NULL,*temp=NULL;
    
    Node *reverse(Node* head){
        Node *curr=head,*prev=NULL,*nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void helper(int a,int b,int &c){
        int val=a+b+c;
           if(val>=10){
                val-=10;
                c=1;
            }
            else{
                c=0;
            }
            
            if(!head){
                head=new Node(val);
                temp=head;
            }
            else{
               temp->next=new Node(val);
               temp=temp->next;
            }
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* f, struct Node* s)
    {
        head=NULL,temp=NULL;
        Node *a=reverse(f);
        Node *b=reverse(s);
        int c=0;
        while(a&&b){
            helper(a->data,b->data,c);
            a=a->next;
            b=b->next;
        }
        while(a){
            helper(a->data,0,c);
            a=a->next;
        }
        while(b){
            helper(0,b->data,c);
            b=b->next;
        }
        if(c==1){
            temp->next=new Node(c);
        }
        Node *ans=reverse(head);
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends