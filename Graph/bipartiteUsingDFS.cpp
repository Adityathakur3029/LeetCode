class Solution {
private:
    enum color{red, blue, uncoloured};
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //graph is presrented in adjancy list
        
        //lets mark every node as uncoloured first
        int N=graph.size();
        vector<color> visited(N,uncoloured); //keep track of visited nodes
        
        //check for every node using DFS
        for(int i=0;i<N;i++){
            if(visited[i]==uncoloured){                  // if not visited node
                if(!dfs(i,graph,visited,0))     // dfs will return false if it cannot colour any one node
                    return false;             //hence not bipartite and will return false
            }
        }
        return true;                          // checked for every node return true
    }
    
    bool dfs(int i, vector<vector<int>>& graph, vector<color>& visited,int turn){
        if(visited[i]!=uncoloured){          //if already colored
            if(visited[i] != turn)           //if already coloured clashed with the new assigned color
                return false;                
            else
                return true;
        }
        else{                                 //if not coloured 
            visited[i]=turn? blue : red;      // assign color
        
            for(auto neighbour: graph[i]){
                if(!dfs(neighbour,graph,visited, turn^1)) // check for neighbours
                    return false;                         // as soon as any of the neighbour return false
            }
        }
        return true;
    }
};
