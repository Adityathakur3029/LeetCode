class Solution {
public:
    unordered_map<int,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        return dfs(node);
    }
    
    Node* dfs(Node* node){
        if(mp[node->val])
            return mp[node->val];
        Node* parent = new Node(node->val);
        mp[node->val] = parent;
        for(auto child : node->neighbors){
            Node* temp = dfs(child);
            parent->neighbors.push_back(temp);
        }
        return parent;
    }
};





//BFS

Node* cloneGraph(Node* node) {
        if(!node)return NULL;
       unordered_map<Node*,Node*> map;
        Node* copy=new Node(node->val);    //We create a new node with the nodes value
        map[node]=copy;                    //We store it in the map so it will help get get access to tha element in o(1) time
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node* t=q.front();
            q.pop();
            for(Node* x:t->neighbors)     //We explore all of its neighbors to make copies of edges and its adjacent nodes
            {
                if(!map.count(x))        //This is to make sure we dont visit the node multiple times
                {
                    map[x]=new Node(x->val);   //We create the new nodes
                    q.push(x);
                }
                map[t]->neighbors.push_back(map[x]);   //This the creation of edges
            }
            
        }
        return copy;
    }
