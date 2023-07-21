/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check(struct TreeNode *, struct TreeNode *);

bool isSymmetric(struct TreeNode* root){
    if(!root){return true;}
    return check(root->left,root->right);
}

bool check(struct TreeNode *a, struct TreeNode *b){
    if(a==NULL && b==NULL){return true;}
    if(a==NULL || b==NULL){return false;}
    if(a->val != b->val){return false;}
    return check(a->left, b->right) && check(a->right, b->left);
}

// give the root of 1 binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

/*
                1 <- root
              /   \
            2       2      -> check (root->left) == (root->right)
          /   \   /   \
         3     4 4     3   -> check (root->left->left) == (root->right->right) && (root->left->right) == (root->right->left)

            2       2      
          /   \   /   \
         3     4 4     3   
 check 1 ^             ^ check 1

            2       2      
          /   \   /   \
         3     4 4     3   
       check 2 ^ ^ check 2

         3     4 4     3 
        / \           / \
   1 > X   X         X   X < 1 

         3     4 4     3 
        / \           / \
       X   X < 2 2 > X   X 

         3   4   4   3 
            / \ / \
       3 > X  X X  X < 3

         3   4   4   3 
            / \ / \
           X  X X  X 
              ^ ^
              4 4 ......

         base condition:
         condition 1: both are NULL -> return true;
            2       2      
          /   \   /   \
         3     4 4     3 
        / \           / \
   * > X   X         X   X < * 
         
         condition 2: one is NULL and another is not -> return false;
         condition 3: if both val are diff -> return false;

         recursive condition: check(root->left, root->right) && check(root->right)
*/
