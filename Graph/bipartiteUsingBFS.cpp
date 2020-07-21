class Solution {
private:
    enum color{red,blue,uncoloured};
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int> visited(N,-2);   //keep tracknof visited nodes
        queue<pair<int,int>> q;              //pair of node and color
        int turn=0;                          //take 0 as red
        
        for(int i=0;i<N;i++){               
            if(visited[i]==-2){             //if not visited
                q.emplace(i,turn);          
                visited[i]=turn; 
                while(!q.empty()){
                    turn= turn ^ 1;         //change colour for next level in BFS
                    int size=q.size();
                    while(size--){          //check only to upper level(parents)
                        auto temp=q.front();
                        q.pop();
                        for(auto neighbour: graph[temp.first]){
                            if(visited[neighbour]!=-2){             //already coloured
                                if(visited[neighbour] != turn)      //colour clashes means not bipartite
                                    return false;
                                else
                                    continue;                       // do not push that node in queue
                            }
                            visited[neighbour]=turn;
                            q.emplace(neighbour,turn);
                        }
                    }
                }
            }
            
        }
        return true;
    }
};
