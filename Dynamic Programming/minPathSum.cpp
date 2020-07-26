class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> aux(m,vector<int>(n,INT_MAX));
        return calculate(grid,m-1,n-1,aux);
        
    }
    
    int calculate(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& aux){
        if(m==0 && n==0)
            return grid[m][n];
        if(aux[m][n]!=INT_MAX)
            return aux[m][n];
        if(n==0)
            aux[m][n]= grid[m][n]+ calculate(grid,m-1,n,aux);
        else if(m==0)
            aux[m][n]= grid[m][n]+ calculate(grid,m,n-1,aux);
        else
            aux[m][n]= grid[m][n]+min(calculate(grid,m-1,n,aux),calculate(grid,m,n-1,aux));
        return aux[m][n];
    }
};



//bottom up
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=1;i<m;i++)
            grid[i][0]+=grid[i-1][0];
        
        for(int i=1;i<n;i++)
            grid[0][i]+=grid[0][i-1];
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
        }
        return grid[m-1][n-1];
    }
};
