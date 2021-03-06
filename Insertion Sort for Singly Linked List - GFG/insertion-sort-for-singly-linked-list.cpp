// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




 // } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    
    Node* insertionSort(struct Node* head_ref)
    {
      struct Node* temp = head_ref;
      while(temp->next != NULL)
      {
          struct Node* pivot = temp->next;
          struct Node* start = head_ref;
          if(pivot->data < start->data){
              temp -> next = pivot->next;
              pivot->next = start;
              head_ref = pivot;
              continue;
          }
          while(start -> next ->data < pivot->data && start!= temp)
          start = start->next;
          
          if(start == temp)
            temp = temp->next;
        else{
            temp->next = pivot->next;
            pivot->next = start->next;
            start->next = pivot;
        }
      }
         return head_ref;
    }
    
};

// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}  // } Driver Code Ends