class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) { 
        int N= graph.size();
        vector<int> color(N,0);                                   //0 as white, 1 as brown , 2 as black  , brown for going fwd black means while coming back
        vector<int> result;
        for(int i=0;i<N;i++){
            if(dfs(i,graph,color))                               //demand of question
                result.push_back(i);
        }
        return result;
    }
    
    bool dfs(int i,vector<vector<int>>& graph, vector<int>& color){
        if(color[i]!=0){                                        // already coloured(brown or black)
            if(color[i]==2)                                     //already black coloured
                return true;
            else                                                // brown coloured
                return false;
        }
        
        color[i]=1;                                             //colour curr node as brown
        for(int neighbour: graph[i]){                            
            if(color[neighbour]==2)                             //already black
                continue;
            if(!dfs(neighbour,graph,color))                     //any of neighbour return false means cycle exists for any neighboour
                return false;
        }
        color[i]=2;                                             //all well colour black
        return true;
    }
};
