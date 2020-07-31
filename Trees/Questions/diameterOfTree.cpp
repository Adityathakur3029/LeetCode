class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        else{
            int leftDiameter=diameterOfBinaryTree(root->left);
            int rightDiameter=diameterOfBinaryTree(root->right);
            int diameterWithRoot=Depth(root->left)+Depth(root->right);
            return max(leftDiameter,max(rightDiameter,diameterWithRoot));
        }
    }
    int Depth(TreeNode* root){
        if(!root)
            return 0;
        else{
            int leftDepth=Depth(root->left);
            int rightDepth=Depth(root->right);
            return max(leftDepth, rightDepth)+1;
        }
    }
};





//better one
class Solution {
public:
    struct s{
        int height;
        int dia;
    };
    int diameterOfBinaryTree(TreeNode* root) {
        s obj;
        return helper(root,obj).dia;
    }
    
    s helper(TreeNode* root,s& obj){
        if(!root)
            return{0,0};
        s objLeft=helper(root->left,obj);
        s objRight=helper(root->right,obj);
        return{max(objLeft.height,objRight.height)+1,max(max(objLeft.dia,objRight.dia),objLeft.height+objRight.height)};
    }
};
