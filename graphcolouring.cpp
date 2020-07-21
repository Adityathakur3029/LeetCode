class Solution {
private:
    enum color{uncolored, blue , red};
    
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<unordered_set<int>> graph(N+1);
        for(auto i: dislikes){
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        
        vector<color> visited(N+1,uncolored);
        
        for(int i=1; i<=N ; i++){
            if(visited[i]==uncolored && !colorGraph(graph,i,visited,0))
                return false;
        }
        return true;
    }
    
    bool colorGraph(vector<unordered_set<int>>& graph,int i,vector<color>& visited,int turn){
        if(visited[i]==uncolored){
            visited[i]= turn==0? red : blue;
        
            for(auto neigh: graph[i]){
                if(visited[neigh]==visited[i])
                    return false;
                colorGraph(graph,neigh,visited,turn ^ 1);
            }
        }
        return true;
    }
    
};
