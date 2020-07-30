class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l=0;
        int r=0;
        int length=0;
        unordered_map<char,int> mp;         
        int maxfreq=0;
        bool flag=1;
        int res=0;
        
        while(r<s.length()){
            if(flag){                                   //maxfreq 
                mp[s[r]]++;
                maxfreq=max(maxfreq,mp[s[r]]);       
                length++;
            }
            
            if(valid(maxfreq,length,k)){                //can perform k operations or not
                res=max(res,length);
                flag=1;
                r++;
            }
            
            else{                                       //if not reduce size of window
                if(mp[s[l]]==maxfreq){
                    mp[s[l]]--;
                    maxfreq=0;
                    for(auto i:mp){
                        maxfreq=max(maxfreq,i.second);
                    }
                }
                else
                    mp[s[l]]--;
                if(mp[s[l]]==0)
                    mp.erase(s[l]);
                length--;
                flag=0;
                l++;
            }
        }
        return res;
    }
    
    bool valid(int maxfreq, int length, int k){
        if(length-maxfreq<=k)
            return true;     
        return false;
    } 
};
