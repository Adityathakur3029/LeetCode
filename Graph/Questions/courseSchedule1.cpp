class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<int> visited(numCourses,0);
        vector<bool> onPath(numCourses,false);
        
        vector<vector<int>> graph= makeGraph(numCourses,prerequisites);
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                if(!calculate(graph,i,visited))
                    return false;
        }
        
        return true;
    }
    
    bool calculate(vector<vector<int>>& graph,int i,vector<int>& visited){
        if(visited[i]!=0){
            if(visited[i]==2)
                return true;
            else
                return false;
        } 
        visited[i]=1;
        for(int neighbour: graph[i]){
            if(visited[neighbour]==2)
                continue;
            if(!calculate(graph,neighbour,visited))
                return false;
        }
        visited[i]=2;
        return true;
    }
    
    
    vector<vector<int>> makeGraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto i: prerequisites){
            graph[i[1]].push_back(i[0]);
        }
        return graph;
    }
    
    
};
