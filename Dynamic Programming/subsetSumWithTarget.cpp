class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=0;
        for(auto i: nums)
            total_sum+=i;
        if(total_sum%2!=0)                   //total sum is odd
            return false;                    
        
        int target=total_sum/2;              //subset sum with target value
        int n=nums.size();
        vector<vector<int>> aux(n,vector<int>(target+1,-1));
        
        return calculate(nums,n-1,target,aux);        
    }
    
    bool calculate(vector<int>& nums,int n, int target,vector<vector<int>>& aux){
        if(target==0)                       
            return true;
        if(target<0)
            return false;
        if(n<0 && target!=0)
            return false;
        if(aux[n][target]!=-1)
            return aux[n][target]==1;
        else
            aux[n][target]=(calculate(nums,n-1,target,aux) || calculate(nums,n-1,target-nums[n],aux))? 1 : 0;
        return aux[n][target]==1;
    }
};


//bottom up
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=0;
        for(auto i: nums)
            total_sum+=i;
        if(total_sum%2!=0)                   //total sum is odd
            return false;                    
        
        int target=total_sum/2;              //subset sum with target value
        int n=nums.size();
        vector<vector<bool>> aux(n+1,vector<bool>(target+1,false));
        
        for(int i=0;i<n;i++)
            aux[i][0]=true;
        
        for(int i=1;i<=target;i++)
            aux[0][i]=false;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]>j)
                    aux[i][j]=aux[i-1][j];
                else{
                    aux[i][j]=aux[i-1][j] || aux[i-1][j-nums[i-1]];
                }
            }
        }
        return aux[n][target];        
    }
};



