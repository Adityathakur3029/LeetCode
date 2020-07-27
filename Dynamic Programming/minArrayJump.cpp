class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return calculate(nums,n-1,dp);
    }
    
    int calculate(vector<int>& nums,int n,vector<int>& dp){
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(i+nums[i]>=n){
                int sub_res=1+calculate(nums,i,dp);
                if (sub_res != INT_MAX) 
                    dp[n] = min(dp[n], sub_res);
            }            
        }
        return dp[n];
    }
};

//bottom-up

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        
        if (nums[0] == 0 && n>1) 
            return -1;
    
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(j+nums[j]>=i && nums[j]!=INT_MAX){
                    dp[i] = min(dp[i], dp[j] + 1);
                    break;
                }
                    
            }
        }
        if(dp[n-1]==INT_MAX)
            return -1;
        return dp[n-1];
    }
};



