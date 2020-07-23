class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N=rooms.size();
        vector<bool> visited(N,false);
        
        dfs(0,rooms,visited);
        
        for(auto i:visited){
            if(!i)
                return false;
        }
        return true;
    }
    
    void dfs(int i,vector<vector<int>>& rooms,vector<bool>& visited){
        if(!visited[i]){
            visited[i]=true;
            for(int neighbour:rooms[i])
                dfs(neighbour,rooms,visited);
        }
    }
};
