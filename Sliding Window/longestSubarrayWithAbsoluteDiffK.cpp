class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> largest;
        deque<int> smallest;
        
        int l=0;
        int r=0;
        int res=0;
        
        while(r<nums.size()){
            while(!largest.empty() && nums[largest.back()]<=nums[r])
                largest.pop_back();
            largest.push_back(r);
            
            while((!smallest.empty() && nums[smallest.back()]>=nums[r]))
                smallest.pop_back();
            smallest.push_back(r);
            
            while(nums[largest.front()]-nums[smallest.front()]>limit){
                if(l==largest.front())
                    largest.pop_front();
                if(l==smallest.front())
                    smallest.pop_front();
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};
