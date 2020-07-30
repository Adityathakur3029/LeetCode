class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l=0;
        int r=0;
        int res=INT_MIN;
        int canFlip=K;
        
        
        while(r<A.size()){                          
            if(A[r]==0)
                canFlip--;
            
            while(canFlip<0){                      //k flips are done now unset the first flip
                if(A[l]==0)
                    canFlip++;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};
