bool dfs(int i,int start,vector<vector<int>>& graph, vector<bool>& visited){
        
        visited[i]=true;                                 //mark node as visited
        for(int neighbour:graph[i]){                     
            if(!visited[neighbour]){                     //if neighbour is already visited means either cycle or neighbour is parent node
                if(!dfs(neighbour,i,graph,visited)){
                    return false;
                }
            }
            else if(neighbour!=start){                  //check if it is parent or not
                return false;
            }
        }
        return true;
    }
