class Solution {
private:

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N=edges.size();
        vector<vector<int>> graph(N+1);
        vector<bool> visited(N+1,false);
        
        unordered_set<int> s;
        
        vector<int> result(2);
        
        for(auto i:edges){
            
            if(s.find(i[0])!=s.end()){
                
                if(s.find(i[1])!=s.end()){
                    graph[i[0]].push_back(i[1]);
                    graph[i[1]].push_back(i[0]);
                    if(!dfs(i[1],i[0],graph,visited)){
                        result=i;
                        graph[i[0]].pop_back();
                        graph[i[1]].pop_back();
                    }
                        
                    
                    continue;
                }
                graph[i[0]].push_back(i[1]);
                graph[i[1]].push_back(i[0]);
                s.insert(i[1]);
                continue;
            }
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            s.insert(i[0]);
            s.insert(i[1]);
        }
        return result;
    }
    
    bool dfs(int i,int start,vector<vector<int>>& graph, vector<bool>& visited){
        
        visited[i]=true;                                 
        for(int neighbour:graph[i]){
            if(!visited[neighbour]){
                if(!dfs(neighbour,i,graph,visited)){
                    visited[i]=false;                             //remark as unvisited
                    return false;
                }
            }
            else if(neighbour!=start){
                visited[i]=false;                                 //remark as unvisited
                return false;
            }
        }
        visited[i]=false;               //remark as unvisited
        return true;
    }

};
