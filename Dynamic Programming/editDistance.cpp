class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>> aux(m+1,vector<int>(n+1,-1));
        
        return calculate(word1,word2,m,n,aux);
    }
    
    int calculate(string& word1,string& word2,int m,int n,vector<vector<int>>& aux){
        
        if(m==0)                                                                    //string1 is empty we need n cost to change it into a string of len n
            return n;
        if(n==0)                                                                   //string2 is empty we need m cost to make a string of m len empty
            return m;
        if(aux[m][n]!=-1)
            return aux[m][n];
        if(word1[m-1]==word2[n-1]){
            aux[m][n]= calculate(word1,word2,m-1,n-1,aux);
        }
        else
            aux[m][n]= 1+ min(calculate(word1,word2,m-1,n,aux),min(calculate(word1,word2,m,n-1,aux),calculate(word1,word2,m-1,n-1,aux)));  //first is del, 2 is insert, 3 is replace
        return aux[m][n];
    }
};

//Bottom up 

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<m+1;i++)
            dp[i][0]=i;
        
        for(int j=0;j<n+1;j++)
            dp[0][j]=j;
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
        }
        return dp[m][n];
    }
};
