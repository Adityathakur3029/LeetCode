class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0;
        int r=0;
        int len=0;
        while(r<s.length()){
            
            maxCost=maxCost-(abs(s[r]-t[r]));
            
            while(l<=r && maxCost<0){
                maxCost=maxCost+(abs(s[l]-t[l]));
                l++;
            }
            
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
