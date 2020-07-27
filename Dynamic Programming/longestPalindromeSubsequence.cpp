class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())
            return 0;
        const int n=s.length();
        vector<vector<int>> aux(n,vector<int>(n,0));
        
        return calculate(s,0,n-1,aux);        
    }
    
    int calculate(string& s,int i,int j,vector<vector<int>>& aux){
        if(i==j)
            return 1;
        if(s[i]==s[j] && i+1==j)
            return 2;
        if(aux[i][j])
            return aux[i][j];
        if(s[i]==s[j])
            aux[i][j]=2+calculate(s,i+1,j-1,aux);
        else
            aux[i][j]=max(calculate(s,i+1,j,aux),calculate(s,i,j-1,aux));
        return aux[i][j];
    }
};


//bottom up
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())
            return 0;
        const int n=s.length();
        vector<vector<int>> aux(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
            aux[i][i]=1;
        
        for(int col=1;col<n;col++){
            for(int i=0;i<n-col;i++){
                int j=i+col;
                if((j-i+1)==2)
                    aux[i][j]=1+(s[i]==s[j]);
                else{
                    if(s[i] == s[j])
                        aux[i][j] = aux[i+1][j-1] + 2;
                    else
                        aux[i][j] = max(aux[i+1][j], aux[i][j-1]);
                }
                
            }
        }
        return aux[0][n-1];
    }
};
