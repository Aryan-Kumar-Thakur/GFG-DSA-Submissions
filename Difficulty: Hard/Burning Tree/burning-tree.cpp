//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
    Node* createmapping(Node* root,int target,map<Node*,Node*> &nodetoparent){
        queue<Node*> q;
        q.push(root);
        nodetoparent[root]=NULL;
        Node* res;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp->data==target){ 
                res=temp;
            }
            if(temp->left){
                q.push(temp->left);
                nodetoparent[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                nodetoparent[temp->right]=temp;
            }
        }
        return res;
    }
    int burning(Node* root,map<Node*,Node*> &nodetoparent){
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root]=1;
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            bool flag=0;
            for(int i=0;i<n;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    flag=1;
                    q.push(temp->left);
                    visited[temp->left]=1;
                }
                if(temp->right && !visited[temp->right]){
                    flag=1;
                    q.push(temp->right);
                    visited[temp->right]=1;
                }
                if(nodetoparent[temp] && !visited[nodetoparent[temp]]){
                    flag=1;
                    q.push(nodetoparent[temp]);
                    visited[nodetoparent[temp]]=1;
                }
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;
        
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //3 step to solve this
        //create a mapping of node to its parents
        //find the target node
        //burn the tree
        map<Node*,Node*> nodetoparent;
        Node* targetnode=createmapping(root,target,nodetoparent);
        int ans=burning(targetnode,nodetoparent);
        return ans;
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends