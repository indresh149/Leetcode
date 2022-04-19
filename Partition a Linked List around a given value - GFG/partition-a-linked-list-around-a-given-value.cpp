// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    Node *lt = NULL, *et = NULL, *gt = NULL;
    Node *t = head;
    Node *llt, *let, *lgt;
    while(t!=NULL){
        Node *node = t;
        if(node->data < x){
            if(lt == NULL){
                lt = llt = node;
            }
            else{
                llt->next = node;
                llt = llt->next;
            }
        }
        else if(node->data == x){
            if(et == NULL){
                et = let = node;
            }
            else{
                let->next = node;
                let = let->next;
            }
        }
        else{
            if(gt == NULL){
                gt = lgt = node;
            }
            else{
                lgt->next = node;
                lgt = lgt->next;
            }
        }
        t = t->next;
        node->next = NULL;
    }
    if(lt == NULL && et == NULL)
        head = gt;
    else if(lt!=NULL && et == NULL && gt!=NULL){
        head = lt;
        llt->next = gt;
    }
    else if(lt == NULL && et != NULL){
        head = et;
        let->next = gt;
    }
    else{
        head = lt;
        llt->next = et;
        let->next = gt;
    }
    
    return head;
}