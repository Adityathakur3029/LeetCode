//leaf nodes to zero and value of root should be sum of left subtree+sum of right subtree


int toSumTree(node *Node)  
{  
    // Base case  
    if(Node == NULL)  
    return 0;  
  
    // Store the old value  
    int old_val = Node->data;  
  
    // Recursively call for left and 
    // right subtrees and store the sum as  
    // new value of this node  
    Node->data = toSumTree(Node->left) + toSumTree(Node->right);  
  
    // Return the sum of values of nodes 
    // in left and right subtrees and  
    // old_value of this node  
    return Node->data + old_val;  
}
