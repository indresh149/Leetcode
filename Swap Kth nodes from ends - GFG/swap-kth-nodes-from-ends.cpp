// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if (K > num)
	return head;
	
Node *pre_kth_from_head = NULL;
Node *kth_from_head = head;

for (int i = 1; i < K; ++i)
{
	pre_kth_from_head = kth_from_head;
	kth_from_head = kth_from_head->next;
}
	
//cout << (pre_kth_from_head ? pre_kth_from_head->data : -1) << " ";
//cout << (kth_from_head ? kth_from_head->data : -1) << " ";

Node *pre_kth_from_tail = NULL;
Node *kth_from_tail = head;
Node *tail = kth_from_head->next;

while (tail)
{
	pre_kth_from_tail = kth_from_tail;
	kth_from_tail = kth_from_tail->next;
	tail = tail->next;
}

//cout << (pre_kth_from_tail ? pre_kth_from_tail->data : -1) << " ";
//cout << (kth_from_tail ? kth_from_tail->data : -1) << endl;

if (pre_kth_from_tail == NULL)
{
	swap(pre_kth_from_tail, pre_kth_from_head);
	swap(kth_from_tail, kth_from_head);
}

if (pre_kth_from_head == NULL)
{
	kth_from_tail->next = kth_from_head->next;
	pre_kth_from_tail->next = kth_from_head;
	kth_from_head->next = NULL;
	head = kth_from_tail;
}
else
{
	pre_kth_from_head->next = pre_kth_from_tail->next;
	pre_kth_from_tail->next = kth_from_head;
	
	Node *tmp = kth_from_tail->next;
	kth_from_tail->next = kth_from_head->next;
	kth_from_head->next = tmp;
}

return head;
    
}
