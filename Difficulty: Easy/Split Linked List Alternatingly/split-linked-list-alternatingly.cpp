//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        if(!head){
            return {head,head};
        }
        if(!head->next){
            return {head,NULL};
        }
        vector<Node*> ans;
        Node* temp=head->next->next;
        Node* oddh=new Node(head->data);
        Node* oddt=oddh;
        Node* evenh=new Node(head->next->data);
        Node* event=evenh;
        bool f=1;
        while(temp){
            Node* x=new Node(temp->data);
            if(f){
                oddt->next=x;
                oddt=x;
                f=0;
            }
            else{
                event->next=x;
                event=x;
                f=1;
            }
            temp=temp->next;
        }
        return {oddh,evenh};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends