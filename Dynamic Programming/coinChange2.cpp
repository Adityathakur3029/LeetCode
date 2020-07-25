class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> aux(n,vector<int>(amount+1,-1));
        return calculate(coins,n-1,amount,aux);
    }
    
    int calculate(vector<int>& coins,int n,int amount,vector<vector<int>>& aux){
        if(amount==0)
            return 1;
        if(n<0)
            return 0;
        
        if(aux[n][amount]!=-1)
            return aux[n][amount];
            
            
        if(coins[n]>amount)
            aux[n][amount]=calculate(coins,n-1,amount,aux);
        else
            aux[n][amount]= calculate(coins,n-1,amount,aux)+calculate(coins,n,amount-coins[n],aux);
        return aux[n][amount];
    }
};

//bottom up
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        if(amount==0)
            return 1;
        if(m==0)
            return 0;
        int dp[m][amount+1];
        dp[0][0] = 1;
        for(int i = 1;i <= amount;i++){
            dp[0][i] = i%coins[0]==0 ? 1 : 0;
        }
        for(int i = 1;i < m;i++){
            dp[i][0] = 1;
            for(int j = 1;j <= amount;j++){
                if(coins[i] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i]];
                }
            }
        }
        return dp[m-1][amount];
    }
};
