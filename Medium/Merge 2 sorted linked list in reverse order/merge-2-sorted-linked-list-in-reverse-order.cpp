//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    Node* reversell(Node* head){
        Node* prev=NULL,*curr=head;
        while(curr){
            Node* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        if(!node1){
            return reversell(node2);
        }
        if(!node2){
            return reversell(node1);
        }
        if(node2->data < node1->data){
            return mergeResult(node2,node1);
        }
        Node* ans=node1;
        Node* temp1=node1,*temp2=node2;
        while(temp1 && temp1->next && temp2){
            Node* forward=temp1->next;
            if(temp2->data <= forward->data){
                // cout<<forward->data<<endl;
                // cout<<temp2->data<<endl;
                temp1->next=temp2;
                Node* forward2=temp2->next;
                temp2->next=forward;
                temp2=forward2;
            }
            temp1=temp1->next;
        }
        if(temp2){
            temp1->next=temp2;
        }
        ans = reversell(ans);
        // temp1->next=NULL;
        return ans;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends