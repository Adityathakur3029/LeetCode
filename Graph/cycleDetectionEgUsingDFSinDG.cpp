class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N= graph.size();
        vector<int> color(N,0);
        vector<int> result;
        for(int i=0;i<N;i++){
            if(dfs(i,graph,color))
                result.push_back(i);
        }
        return result;
    }
    
    bool dfs(int i,vector<vector<int>>& graph, vector<int>& color){
        if(color[i]!=0){
            if(color[i]==2)
                return true;
            else
                return false;
        }
        
        color[i]=1;
        for(int neighbour: graph[i]){
            if(color[neighbour]==2)
                continue;
            if(!dfs(neighbour,graph,color))
                return false;
        }
        color[i]=2;
        return true;
    }
};
