class Solution {
public:
    int climbStairs(int n) {
        vector<int> aux(n+1,-1);
        return calculate(n,aux);
    }
    
    int calculate(int n,vector<int>& aux){
        if(n<=2)
            return n;
        if(aux[n]!=-1)
            return aux[n];
        else
            aux[n]=calculate(n-1,aux)+calculate(n-2,aux);
        return aux[n];
    }
};

//bottom up generalised if a person can climb at most m stairs at one time

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==0)
            return 1;
        vector<int> dp(n);
        dp[0]=1;
        dp[1]=2;
        
        for(int i=2;i<n;i++){
            dp[i]=0;
            for(int j=1;j<=2 && j<=i;j++){                              //here 2 can be replaced by m
                dp[i]+=dp[i-j];
            }
        }
        return dp[n-1];
    }
};


//O(n) for generalised using sliding window
//somewhat tricky to handle yet easy to understand
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==0)
            return 1;
        vector<int> dp(n+1);
        dp[0]=1;
        int temp=0;
        for(int i=1;i<=n;i++){
            int s=i-2-1;
            int e=i-1;
            if(s>=0){
                temp-=dp[s];
            }
            temp+=dp[e];
            dp[i]=temp;
        }
        return dp[n];
    }
};
