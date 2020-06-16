class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int mE=nums[0];
        
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==mE)
                count++;
            else
                count--;
            if(count==0)
                mE=nums[i+1];
        }
        return mE;
    }
};
