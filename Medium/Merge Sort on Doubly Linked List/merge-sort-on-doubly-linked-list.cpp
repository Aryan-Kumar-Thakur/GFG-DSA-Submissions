//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
    struct Node* merge(struct Node* a,struct Node* b){
        struct Node* anshead=new Node(-1);
        struct Node* anstail=anshead;
        while(a && b){
            if(a->data <= b->data){
                anstail->next=a;
                a->prev=anstail;
                a=a->next;
                anstail=anstail->next;
            }
            else{
                anstail->next=b;
                b->prev=anstail;
                b=b->next;
                anstail=anstail->next;
            }
        }
        while(a){
            anstail->next=a;
            a->prev=anstail;
            a=a->next;
            anstail=anstail->next;
        }
        while(b){
            anstail->next=b;
            b->prev=anstail;
            b=b->next;
            anstail=anstail->next;
        }
        struct Node* res=anshead->next;
        res->prev=NULL;
        return res;
    }
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(!head || !head->next){
            return head;
        }
        struct Node* fast=head;
        struct Node* slow=head;
        struct Node* temp=NULL;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        slow->prev=NULL;
        struct Node* a=sortDoubly(head);
        struct Node* b=sortDoubly(slow);
        return merge(a,b);
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends