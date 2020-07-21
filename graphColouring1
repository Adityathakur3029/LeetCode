class Solution {
private:
    enum color{uncoloured, red, blue};
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //graph is presrented in adjancy list
        
        //lets mark every node as uncoloured first
        int N=graph.size();
        vector<color> visited(N,uncoloured); //keep track of visited nodes
        
        //check for every node using DFS
        for(int i=0;i<N;i++){
            if(!visited[i]){                  // if not visited node
                if(!dfs(i,graph,visited,0))     // dfs will return false if it cannot assign any colour to node
                    return false;             //hence not bipartite and will return false
            }
        }
        return true;                          // checked for every node return true
    }
    
    bool dfs(int i, vector<vector<int>>& graph, vector<color>& visited,int turn){
        if(visited[i]==uncoloured){
            visited[i]= turn? blue : red;        
            for(auto neighbour: graph[i]){
                if(visited[neighbour]==visited[i])
                    return false;
                if(!dfs(neighbour,graph,visited, turn^1))
                    return false;
            }
        }
        return true;
    }
};
