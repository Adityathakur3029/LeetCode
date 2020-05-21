class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        
        for(auto i: t)
            mp[i]++;
        
        int result=INT_MAX;
        int start=0;
        int end=0;
        int required=mp.size();
        int got=0;
        
        unordered_map<char,int> m;
        
        int l=0;
        int r=0;
        while(r<s.length()){
            m[s[r]]++;
            if(mp[s[r]]){
                if(mp[s[r]]==m[s[r]])
                    got++;
            }
            
            while(l<=r && got==required){
                if(r-l+1<result){
                    result=r-l+1;
                    start=l;
                    end=r;
                }
                m[s[l]]--;
                if(mp[s[l]]){
                    if(m[s[l]]<mp[s[l]])
                        got--;
                }
                l++;
            }
            r++;
        }
        if(result==INT_MAX) return "";
        cout<<start<<":"<<end<<"  ";
        return s.substr(start,end-start+1);
    }
    
};
