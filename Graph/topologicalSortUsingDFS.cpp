void topologicalsort(int i,vector<vector<int>>& graph,vector<bool>& visited,stack<int>& s){
        visited[i]=true;                                              
        for(int neighbour:graph[i]){                                  
            if(!visited[neighbour]){
                topologicalsort(neighbour,graph,visited,s);
            }
        }
        s.push(i);                                              //elements with 0 neighbour will get pushed first
    }
    


//############ eg in question ###############
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;    
        vector<vector<int>> graph(numCourses);
        makeGraph(prerequisites,graph);
        stack<int> s;
        vector<int> visited(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0)
                if(!topologicalsort(i,graph,visited,s))                                
                    return{};
        }
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        
        return result;
    }
    
    
    //0 as white, 1 as brown, 2 as black 
    //we are checking wheather we can apply topological sort also in this and if yes then applying
    bool topologicalsort(int i,vector<vector<int>>& graph,vector<int>& visited,stack<int>& s){
        if(visited[i]!=0){                            //if already coloured(black or brown)
            if(visited[i]==2)                         //if black
                return true;
            else                                      //if brown
                return false;
        }
        
        visited[i]=1;                                 //colour as brown first
        for(int neighbour:graph[i]){
            if(visited[neighbour]==2)                 //if already black coloured
                continue;
            if(!topologicalsort(neighbour,graph,visited,s))  //if any neighbour returns false means cycle
                    return false;
        }
        visited[i]=2;                                      //colour as black
        s.push(i);                                         //push
        return true;
    }
    
    void makeGraph(vector<vector<int>>& prerequisites,vector<vector<int>>& graph){
        for(auto i: prerequisites){
            graph[i[1]].push_back(i[0]);
        }
    }
};
