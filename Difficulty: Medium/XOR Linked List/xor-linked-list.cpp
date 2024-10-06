//{ Driver Code Starts
#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> getList(struct Node *head);

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        struct Node *head = NULL;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            head = insert(head, number);
        }

        vector<int> vec = getList(head);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    // Code here
    struct Node*temp=new Node(data);
    if(head==NULL){
        head=temp;
        return head;
    }
    
    temp->npx=head;
    if(head->npx!=NULL){
        head->npx=XOR(head->npx,temp);
    }
    else{
        head->npx=temp;
    }
    
    head=temp;
    return head;
}

vector<int> getList(struct Node *head) {
    // Code here
     vector<int>ans;
    struct Node*prev=NULL;
    struct Node*temp=head;
    while(temp){
        struct Node*t=temp;
        ans.push_back(temp->data);
        if(prev){
            temp=XOR(temp->npx,prev);
        }
        else{
            temp=temp->npx;
        }
        prev=t;
    }
    
    return ans;
}
