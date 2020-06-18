class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return searchhelper(nums,0,nums.size()-1,target);
    }
    
    bool searchhelper(vector<int>& nums, int l, int r, int target){
        if(l>r)
            return false;
        if(l==r){
            if(nums[l]==target)
                return true;
            return false;
        }
        int mid=l+(r-l)/2;
        if(nums[mid]==target)
            return true;
        if(nums[l]<nums[mid]){
            if(nums[mid]>target && nums[l]<=target)
                return searchhelper(nums,l,mid-1,target);
            else
                return searchhelper(nums,mid+1,r,target);
        }
        else if(nums[r]>nums[mid]){
            if(nums[mid]<target && nums[r]>=target)
                return searchhelper(nums,mid+1,r,target);
            else
                return searchhelper(nums,l,mid-1,target);
        }
        else{
            bool rightside=searchhelper(nums,mid+1,r,target);
            bool leftside=searchhelper(nums,l,mid-1,target);
            return rightside | leftside;
        }
    }
    
};
