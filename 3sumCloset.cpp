class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long result=INT_MAX;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int s=i+1;
            int e=n-1;
            while(s<e){
                long sum=nums[i]+nums[s]+nums[e];
                if(sum<target){
                    if(abs(result-target)>abs(sum-target))
                        result=sum;
                    s++;
                }
                else if(sum>target){
                    if(abs(result-target)>abs(sum-target))
                        result=sum;
                    e--;
                }
                else
                    return target;
            }
        }
        return result;
    }
};
