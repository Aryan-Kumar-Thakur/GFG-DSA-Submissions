//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    void cofactor(vector<vector<int> > &matrix,vector<vector<int>> &temp,int R,int C, int n){
        int i=0,j=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(r!=R && c!=C){
                    temp[i][j]=matrix[r][c];
                    j++;
                    if(j==n-1){
                        j=0;
                        i++;
                    }
                }
            }
        }
    }
    int solve(vector<vector<int> > matrix, int n){
        if(n==1){
            return matrix[0][0];
        }
        if(n==2){
            return (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]);
        }
        int sign=1;
        int ans=0;
        vector<vector<int>> temp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            cofactor(matrix,temp,0,i,n);
            ans+=sign*matrix[0][i]*solve(temp,n-1);
            sign*= -1;
        }
        return ans;
    }
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        return solve(matrix,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends