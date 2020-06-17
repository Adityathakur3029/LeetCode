// general approach for k majority elements

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        return majorityEle(nums,3);
    }
    
    vector<int> majorityEle(vector<int> & nums, int k){
        vector<int> res(k-1,0);                      //result
        vector<int> count(k-1,0);
        
        for(auto x: nums){
            bool find=false;
            bool flag=false;
            for(int i=0; i<k-1; i++){          //check if ele is in result
                if(res[i]==x){
                    count[i]++;                //increase freq in counter vector
                    find=true;
                    flag=true;
                    break;
                }
            }
            if(!find){
                for(int i=0; i<k-1; i++){
                    if(count[i]==0){           // if res vec is not fully filled
                        count[i]++;
                        res[i]=x;
                        flag=true;
                        break;
                    }    
                }
            }
            if(!flag){                        //if both are filled and new element is found
                for(int i=0; i<k-1; i++){
                    count[i]--;
                }
            }
        }
        
        //clear the counters
        for(int i=0; i<k-1; i++)
            count[i]=0;
        
        //set counters with correct frequency
        
        for(auto x:nums){
            for(int i=0; i<k-1; i++){
                if(res[i]==x){
                    count[i]++;
                    break;
                }
            }
        }
        
        vector<int> ans;
        for(int i=0; i<k-1; i++){
            if(count[i]> nums.size()/k)
                ans.push_back(res[i]);
        }
        
        return ans;
    }
};
