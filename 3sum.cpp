class Solution {
    private: 
    vector<int> twoSum(int i, int j, int target,vector<int> nums){
        vector<int> ans;
        int sum=0;
        while(i<j){
            sum=nums[i]+nums[j];
            if(sum==target){
                if(ans.size()>0){                           
                    if(ans[ans.size()-1]==nums[j]){         //this is to remove duplicates
                        i++; j--; continue;}
                }
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                i++;
                j--;
            }
            else if(sum>target)
                j--;
            else
                i++;
        }
        if(ans.size()>0)                         //if no combination size will be zero
            return ans;
        return {-1,-1};                          //if no such pair exist
    }
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)                                            //base cases
            return{};
        
        sort(nums.begin(),nums.end());                    //sort the given array
        
        vector<vector<int>> result;                       //output vector
        
        for(int i=0; i<n; i++){
            if(nums[i]>0)                                 //break when we reach on +ve elements bcoz sum cannot be
                break;                                    //for three +ve elements
            if(i>0 && nums[i]==nums[i-1]) continue;       //for duplicates continue as we dont want repetition
            
            int start=i+1;                                //two iterators pointing at next element and last
            int end=n-1;
            
            vector<int> check = twoSum(start,end,-1*nums[i],nums); //multiply by -1 is imp 
            
            if(check[1]!=-1){                              //if we got one or more combinations 
                for(int j=0; j<check.size();j=j+2){        //insert trio in the result 
                    result.push_back({nums[i],check[j],check[j+1]});
                }
            }
        }
        return result;
    }
};
