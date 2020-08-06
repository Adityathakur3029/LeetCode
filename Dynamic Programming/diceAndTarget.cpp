class Solution {
private:
    int mod=1000000007;
    //vector<vector<int>> aux(d+1,vector<int>(target+1,-1));
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> aux(d+1,vector<int>(target+1,-1));
        return calculate(d,f,target,aux);
    }
    
    int calculate(int d,int f, int target,vector<vector<int>>& aux){
        if(d*f<target || target<d)
            return 0;
        if(d==1)
            return target<=f?1:0;
        
        if(aux[d][target]!=-1)
            return aux[d][target];
        else{
            aux[d][target]=0;
            for(int i=1;i<=f;i++){
                aux[d][target]+= calculate(d-1,f,target-i,aux);
                aux[d][target]%=mod;
            }
        }
        return aux[d][target];
    }
    
 
 
class Solution {
private:
    int mod=1000000007;
     
public:    
        int numRollsToTarget(int d, int f, int target) {
        int m=pow(10,9)+7;
        int **dp= new int*[d+1];
        for(int i=0;i<=d;i++){
            dp[i]=new int[target+1];
            for(int j=0;j<=target;j++)
                dp[i][j]=0;
        }
            
            
        
        dp[0][0]=1;
            for(int i=1;i<=d;i++){
                for(int j=1;j<=target;j++){
                    for(int k=1;k<=f;k++){
                        if(k<=j)
                            dp[i][j]=(dp[i][j]+dp[i-1][j-k])%m;
                    }
                }
            }
        return dp[d][target];
    } 
};
