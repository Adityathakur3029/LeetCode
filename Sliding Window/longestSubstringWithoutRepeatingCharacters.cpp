class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=0;
        if(s.length()==0)
            return 0;
        unordered_map<char,int> mp;
        int right=0;
        int left=0;
        while(left<s.length() && right<s.length()){
            if(!mp[s[right]]){
                mp[s[right++]]++;
                result=max(result,right-left);
            }
            else{
                mp.erase(s[left++]);
            }
        }
        return result;
    }
};
