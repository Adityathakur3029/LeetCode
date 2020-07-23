class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;    
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses,0);
        makeGraph(prerequisites,graph,inDegree);        //returns graph and inDegree array as indegree of each node
        queue<int> q;
        
        
    
        
        for(int i=0;i<numCourses;i++){                 //push nodes with 0 indegree in queue
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();                       //pick node with 0 indegree
            q.pop();
            for(int neighbour: graph[node]){          //now remove the edges ie decrease the indegree by 1 of its neighbours
                inDegree[neighbour]--;
                if(inDegree[neighbour]==0)            //after removing the edge if it becomes 0 then push
                    q.push(neighbour);
            }
            result.push_back(node);
        }
        
        if(result.size()!=numCourses)
            return {};
        
        return result;
    }
    
   
    
    void makeGraph(vector<vector<int>>& prerequisites,vector<vector<int>>& graph,vector<int>& inDegree){
        for(auto i: prerequisites){
            graph[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
        }
    }
    
    
    
};
