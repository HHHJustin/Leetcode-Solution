/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void check(struct TreeNode* root, int value, int* p){
    root->val = value + 1;
    if(!(root->left) && !(root->right)){
        if(root->val > *p){*p = (*root).val;}  
    }
    else{
        if(root->left){
            check(root->left, root->val, p);
        }
        if(root->right){
            check(root->right, root->val, p);
        }
    }
    
}

int maxDepth(struct TreeNode* root){
    int max_depth = 1;
    int *p = &max_depth;
    if(!root){return 0;}
    if(!root->left && !root->right){
        return 1;
    }
    if(root->left){
        check(root->left, 1, p);
        }
    if(root->right){
        check(root->right, 1, p);
    }
    return max_depth;
}

// give the root of binary tree, return its maximum depth.
// maxinum depth = the number of the nodes along the longest path from the root node down to the farthest leaf node.

/*              3  root
               / \
              9   20
                  / \
                 15  7
max_depth: record the max depth of seen nodes. 
recursive solution:
max_depth: record the max depth number
use *p point the max_depth address
each node value = depth
*/

/*   only need to check the leaf depth
            9   no sun: check the depth if > max_depth max_depth = the depth of the leaf
           / \
          x   x
*/

/*              3  
               / \
              9   20 <- if(left\right) left\right.value = value (depth) + 1, check left\right 
                  / \
                 15  7
*/
