class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(!root)
            return root;
        q.push(root);
        
        while(!q.empty()){
            q.push(NULL);
            int size=q.size();
            while(size--){
                Node* curr=q.front();
                q.pop();
                if(curr){
                    curr->next=q.front();
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                
                }
            }
        }
        return root;
    }
};




//recursive
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        unordered_map<int,Node*> mp;
        helper(root,mp,0);
        return root;
    }
    
    void helper(Node* root, unordered_map<int,Node*>& mp, int level){
        if(mp[level]){
            mp[level]->next=root;
            mp[level]=root;
        }
        else
            mp[level]=root;
        if(root->left) helper(root->left,mp,level+1);
        if(root->right) helper(root->right,mp,level+1);
    }
};


//for perfect binary tree
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        if(!root->left && !root->right)
            return root;
        else{
            root->left->next=root->right;
            if(root->next){
                root->right->next=root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};
