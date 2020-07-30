class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
            
        vector<int> mp1(26,0);
        for(auto i: s1){
            mp1[i-'a']++;
        }
        
        vector<int> mp2(26,0);  
        int n=s1.length();
        for(int i=0;i<n;i++){
            mp2[s2[i]-'a']++;
        }
        
        int left=0;
        int right=n;
        
        while(right<s2.length()){
            if(mp1==mp2)
                return true;
            mp2[s2[right]-'a']++;
            mp2[s2[left]-'a']--;            
            left++;
            right++;
        }
        
        if(mp1==mp2)
            return true;
        return false;
    }
};
