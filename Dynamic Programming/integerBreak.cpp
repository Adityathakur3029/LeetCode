class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return calculate(n,dp);
    }
    
    int calculate(int n,vector<int>& dp){
        if(n<=1)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        else{
            for(int i=1;i<n;i++){
                dp[n]=max(dp[n] ,max(i*calculate(n-i,dp), i*(n-i)));
            }
        }
        return dp[n];
    }
};


//bottom-up
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=0;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],max(j*dp[i-j],j*(i-j)));
            }
        }
        return dp[n];
    }
};
