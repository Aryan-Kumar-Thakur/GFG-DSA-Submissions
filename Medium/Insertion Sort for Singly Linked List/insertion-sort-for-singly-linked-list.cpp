//{ Driver Code Starts
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
    void insert(Node* &anshead,Node* newNode){
        Node* prev=NULL;
        Node* curr=anshead;
        while(curr && curr->data < newNode->data){
            prev=curr;
            curr=curr->next;
        }
        if(prev==NULL){
            newNode->next=anshead;
            anshead=newNode;
        }
        else{
            newNode->next=curr;
            prev->next=newNode;
        }
    }
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        Node* temp=head_ref;
        Node* anshead=NULL;
        while(temp){
            Node* newNode=new Node(temp->data);
            insert(anshead,newNode);
            temp=temp->next;
        }
        return anshead;
    }
    
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends