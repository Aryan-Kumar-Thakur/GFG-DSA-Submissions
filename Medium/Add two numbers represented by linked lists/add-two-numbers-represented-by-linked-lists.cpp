//{ Driver Code Starts
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
    struct Node* reverse(struct Node* num1){
        struct Node* head=num1;
        struct Node* prev=NULL;
        while(head){
            struct Node* forward=head->next;
            head->next=prev;
            prev=head;
            head=forward;
        }
        return prev;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        while(num1 && num1->data==0){
            num1=num1->next;
        }
        while(num2 && num2->data==0){
            num2=num2->next;
        }
        if(!num1 && !num2){
            struct Node* ans = new Node(0);
            return ans;
        }
        if(!num1){
            return num2;
        }
        if(!num2){
            return num1;
        }
        num1=reverse(num1);
        num2=reverse(num2);
        struct Node* anshead=new Node(-1);
        struct Node* anstail=anshead;
        int carry=0;
        struct Node *temp1=num1, *temp2=num2;
        while(temp1 && temp2){
            int sum=temp1->data+temp2->data+carry;
            anstail->next=new Node(sum%10);
            carry=sum/10;
            temp1=temp1->next;
            temp2=temp2->next;
            anstail=anstail->next;
        }
        while(temp1){
            int sum=temp1->data+carry;
            anstail->next=new Node(sum%10);
            carry=sum/10;
            temp1=temp1->next;
            anstail=anstail->next;
        }
        while(temp2){
            int sum=temp2->data+carry;
            anstail->next=new Node(sum%10);
            carry=sum/10;
            temp2=temp2->next;
            anstail=anstail->next;
        }
        while(carry){
            anstail->next=new Node(carry%10);
            carry/=10;
            anstail=anstail->next;
        }
        anshead=anshead->next;
        anshead=reverse(anshead);
        // while(anshead->data==0 && anshead){
        //     anshead=anshead->next;
        // }
        // if(!anshead){
        //     anshead=new Node(0);
        // }
        return anshead;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends