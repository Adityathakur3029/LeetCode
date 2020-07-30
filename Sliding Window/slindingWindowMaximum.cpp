class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int mE=findMax(nums,0,k);
        result.push_back(mE);
        
        for(int i=0;i<nums.size()-k;i++){
            if(nums[i]<mE){
                if(nums[i+k]>mE){
                    mE=nums[i+k];
                }
            }
            else{
                mE=findMax(nums,i+1,i+k+1);
            }
            result.push_back(mE);
            
        }
        return result;
    }
    
    int findMax(vector<int> A,int l, int r){
        int maxm=INT_MIN;
        for(int i=l;i<r;i++)
            maxm=max(maxm,A[i]);
        return maxm;
    }
};




//2nd priority_queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        for(int i=0;i<k;i++)
            q.emplace(nums[i],i);
        vector<int> result;
        
        for(int i=k;i<nums.size();i++){
            result.push_back(q.top().first);
            while(!q.empty() && q.top().second<=i-k)                     
                q.pop();
            q.emplace(nums[i],i);
        }
        result.push_back(q.top().first);
        
        return result;
        
    }
};

//3rd multiset
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> w;
        for(int i=0;i<k;i++)
            w.insert(nums[i]);
        vector<int> result;
        
        for(int i=k;i<nums.size();i++){
            result.push_back(*w.rbegin());
            w.erase(w.find(nums[i-k]));
            w.insert(nums[i]);
        }
        result.push_back(*w.rbegin());
        return result;
        
    }
};

//4 deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[i]>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        vector<int> result;
        
        for(int i=k;i<nums.size();i++){
            result.push_back(nums[q.front()]);
            while(!q.empty() && q.front()<=i-k)                          //we will work on index so that we can maintain window size
                q.pop_front();
            while(!q.empty() && nums[i]>=nums[q.back()])
                q.pop_back();
           
            q.push_back(i);
        }
        result.push_back(nums[q.front()]);
        return result;
        
    }
};
