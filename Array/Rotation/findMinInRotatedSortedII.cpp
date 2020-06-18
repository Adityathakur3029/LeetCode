class Solution {
public:
    int findMin(vector<int>& nums) {
        return nums[search(nums,0,nums.size()-1)];
    }
    
    int search(vector<int>& nums, int l, int r){
        if(l==r)
            return l;
        int mid=l+(r-l)/2;
        if(nums[mid]>nums[r])
            return search(nums,mid+1,r);
        else if(nums[mid]<nums[r])
            return search(nums,l,mid);
        else{
            int leftside=search(nums,l,mid);
            int rightside=search(nums,mid+1,r);
            return nums[rightside]<nums[leftside] ? rightside : leftside;
        }
    }
};
