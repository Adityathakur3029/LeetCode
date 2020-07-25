class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>> aux(m,vector<int>(n,0));
        return calculate(text1,text2,m-1,n-1,aux);
    }
    
    int calculate(string& text1, string text2, int m,int n,vector<vector<int>>& aux){
        if(m<0 || n<0){
            return 0;
        }
        
        if(aux[m][n])
            return aux[m][n];
        if(text1[m]==text2[n]){
            aux[m][n]=1+calculate(text1,text2,m-1,n-1,aux);
        }
        else
            aux[m][n]= max(calculate(text1,text2,m-1,n,aux),calculate(text1,text2,m,n-1,aux));
        return aux[m][n];
    }
};

//bottom-up
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};
