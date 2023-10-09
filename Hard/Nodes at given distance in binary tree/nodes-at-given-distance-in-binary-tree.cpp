//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
  Node* getRef(Node* root, int target)
    {
        if(root==NULL || root->data == target)
            return root;
        Node *left= getRef(root->left,target);
        Node *right= getRef(root->right, target);
        if(left!=NULL)
        return left;
        if(right!=NULL)
        return right;
    }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        map<Node*,Node*> mp1;
        map<Node*,bool> mp2;
        mp1[root]=root;
        // mp2[root]=0;
        // int lvl=1;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
                Node* ele=q.front();
                // int curr=q.front().second;
                q.pop();
                if(ele->left){
                    mp1[ele->left]=ele;
                    // mp2[ele->left->data]=lvl;
                    q.push(ele->left);
                }
                if(ele->right){
                    mp1[ele->right]=ele;
                    // mp2[ele->right->data]=lvl;
                    q.push(ele->right);
                }
            }
        // mp2[root]=0;
        root = getRef(root,target);
        queue<Node*> qu;
        qu.push(root);
        mp2[root]=1;
        int curr=0;
        while(!qu.empty()){
            int x=qu.size();
             if(curr++ == k){
                    break;
                }
            while(x--){
                Node* ele=qu.front();
                qu.pop();
                if(ele->left && !mp2[ele->left]){
                    qu.push(ele->left);
                    mp2[ele->left] = true;
                }
                if(ele->right && !mp2[ele->right]){
                    qu.push(ele->right);
                    mp2[ele->right] = true;
                }
                if(mp1[ele] && !mp2[mp1[ele]]){
                    qu.push(mp1[ele]);
                    mp2[mp1[ele]]=true;
                }
            }
        }
         vector<int> ans;
        while(!qu.empty()){
            Node * ele=qu.front();
            qu.pop();
            ans.push_back(ele->data);
        }
        // inorder(ans,root,target,k,mp1,mp2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends