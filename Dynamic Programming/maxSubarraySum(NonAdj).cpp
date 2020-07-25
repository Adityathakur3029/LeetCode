class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1)
            return 0;
        int n=nums.size();
        vector<int> dp(n,0);
        return calculate(nums,n-1,dp);
    }
    
    int calculate(vector<int>& nums,int n,vector<int>& dp){
        if(n==0)
            return nums[0];
        if(n==1)
            return max(nums[0],nums[1]);
        if(dp[n])
            return dp[n];
        dp[n]= max(nums[n]+calculate(nums,n-2,dp), calculate(nums,n-1,dp));
        return dp[n];
    }
};


//bottom up
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        int base1= nums[0];
        int base2= max(nums[0],nums[1]);
        int sum;
        for(int i=2;i<nums.size();i++){
            sum=max(base1+nums[i],base2);
            base1=base2;
            base2=sum;
        }
        return sum;
    }
};


public static int maxSumSubSeqNonContagious(int a[]){
	int max_include[] = new int[a.length];
	int max_exclude[] = new int[a.length];
	max_include[0] = a[0];
	max_exclude[0] = Integer.MIN_VALUE;
	int max = a[0];
	
	for(int i = 1; i<a.length; i++){
		max_include[i] = Math.max(max_exclude[i-1]+a[i], a[i]);
		max_exclude[i] = Math.max(max_include[i-1], max_exclude[i-1]);
		max = Math.max(max_include[i], max_exclude[i]);
	}
	
	return max;
}
