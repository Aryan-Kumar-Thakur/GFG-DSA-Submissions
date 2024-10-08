//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class dsu{
    public:
    vector<int> size;
    vector<int> parent;
    dsu(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findulparent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findulparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findulparent(u);
        int ulp_v=findulparent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            swap(ulp_u,ulp_v);
        }
        size[ulp_u]+=size[ulp_v];
        parent[ulp_v]=ulp_u;
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        unordered_map<string,int> mp;
        int n=accounts.size();
        dsu ds(n);
        int par=0;
        for(vector<string> &x: accounts){
            for(int i=1;i<x.size();++i){
                string mail=x[i];
                if(mp.find(mail)!=mp.end()){
                    ds.unionbysize(par,mp[mail]);
                }else{
                    mp[mail]=par;
                }
            }
            par++;
        }
        vector<string> mergedMail[n];
        for(auto it:mp){
            string mail=it.first;
            int parnode=ds.findulparent(it.second);
            mergedMail[parnode].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; ++i){
            if(mergedMail[i].size() == 0)continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &x : mergedMail[i]){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends