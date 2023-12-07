//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LRUCache
{
    private:
    Node* anshead = new Node(-1, -1);
    Node* anstail = new Node(-1, -1);
    int n;
    unordered_map<int, Node*> mp;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        n=cap;
        anshead->next=anstail;
        anstail->prev=anshead;
    }
    
    void insert(Node* newNode){
        Node* temp=anshead->next;
        anshead->next=newNode;
        temp->prev=newNode;
        newNode->next=temp;
        newNode->prev=anshead;
    }
    
    void deletenode(Node* del){
        Node* temp1=del->prev;
        Node* temp2=del->next;
        temp1->next=temp2;
        temp2->prev=temp1;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* delnode=mp[key];
        int ans=delnode->val;
        deletenode(delnode);
        insert(delnode);
        mp[key]=anshead->next;
        return ans;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here   
        Node* newNode= new Node(key,value);
        if(mp.find(key)!=mp.end()){
            Node* delnode=mp[key];
            mp.erase(key);
            deletenode(delnode);
        }
        else if(mp.size()==n){
            mp.erase(anstail->prev->key);
            deletenode(anstail->prev);
        }
        insert(newNode);
        mp[key]=anshead->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends