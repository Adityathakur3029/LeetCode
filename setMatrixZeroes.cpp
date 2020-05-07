class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=(int)matrix.size();
        int n=(int)matrix[0].size();
        
        bool flag=false;
        bool col=false;
        bool row=false;
        
        if(matrix[0][0]==0)
            flag=true;
        if(!flag){
            for(int i=0;i<m;i++){
                if(matrix[i][0]==0){
                    row=true;
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(matrix[0][i]==0){
                    col=true;
                    break;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
        }
        
        
        for(int i=m-1;i>=1;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j]=0;
            }
        }
        
        
        
        
       if(flag){
            for(int i=0;i<m;i++)
                matrix[i][0]=0;
            for(int i=0;i<n;i++)
                matrix[0][i]=0;
            
      
        }
        if(row){
            for(int i=0;i<m;i++)
                matrix[i][0]=0;
           
        }
        
        if(col){
            for(int i=0;i<n;i++)
                matrix[0][i]=0;
            
           
        }
        
    }
};
