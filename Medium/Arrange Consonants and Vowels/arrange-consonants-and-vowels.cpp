//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
    public:
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    struct Node* arrangeCV(Node *head)
    {
       //Code here
       if(!head){
           return head;
       }
       struct Node* anshead=new Node(' ');
       struct Node* anstail=anshead;
       struct Node* temp=head;
       struct Node* prev=NULL;
       map<char,int> mp;
       mp['a']=1;
       mp['e']=1;
       mp['i']=1;
       mp['o']=1;
       mp['u']=1;
       while(temp){
           if(mp.find(temp->data)!=mp.end()){
               anstail->next=new Node(temp->data);
               anstail=anstail->next;
               if(prev==NULL){
                   head=head->next;
                   temp=head;
               }
               else{
                   prev->next=temp->next;
                   delete(temp);
                   temp=temp->next;
               }
           }
           else{
               prev=temp;
               temp=temp->next;
           }
       }
       anstail->next=head;
       return anshead->next;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends