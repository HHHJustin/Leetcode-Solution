/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root){return root;}
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// give the root of a binary tree
// and invert the tree, and return its root.
/* ex :  4
        / \
       2   7
      / \ / \
     1  3 6  9 
    / \           
   x   x .....
 
use recursive method -> 
base condition :  
condition 1: if root == 0: return -1;
condition 2: 


*/
