class Solution {
private:
    unordered_set<char> s={'a','e','i','o','u'};
public:
    int maxVowels(string s, int k) {
        int l=0;
        int r=0;
        int count=0;
        int res=0;
        
        for(r;r<k;r++){
            if(isvowel(s[r]))
                count++;
        }
        res=count;
        while(r<s.length()){
            if(isvowel(s[r++]))
                count++;
            if(isvowel(s[l++]))
                count--;
            res=max(res,count);
        }
        
        return res;
        
    }
    
    
    bool isvowel(char c){
        if(s.count(c))
            return true;
        return false;
    }
};
