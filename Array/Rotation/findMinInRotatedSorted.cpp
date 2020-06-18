class Solution {
public:
    int findMin(vector<int>& nums) {
        return nums[(search(nums,0,nums.size()-1)+1)%nums.size()];
    }
    
    int search(vector<int>&  nums, int l, int r){
        if(r<=l)
            return l;
        int mid=l+(r-l)/2;
        if(nums[mid]>nums[mid+1])
            return mid;
        if(nums[mid]>=nums[l])
            return search(nums,mid+1,r);
        else
            return search(nums,l,mid-1);
        
    }
};
