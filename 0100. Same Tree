/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    // base case
    if(p == NULL && q == NULL){return true;}
    // condition 1
    if((p == NULL && q != NULL) || (p != NULL && q == NULL)){return false;}
    // condition 2
    if(p->val != q->val){return false;}
    // condition 3 (check node left and node right sun)
    if(!isSameTree(p->left,q->left)){return false;}
    if(!isSameTree(p->right,q->right)){return false;}
    return true;
}

// give the roots of two binary trees "p" and "q" -> check two trees if the same.
// if they are structually identical and the nodes have the same value -> same tree.

/*
       recursive method :

       The base case is the condition to stop the recursion
       base case: 
         1               1 
        / \             / \
       2   3           2   3
      / \ / \         / \ / \
     X <- check      X <- check    if both == NULL : return true.
      
      condition 1: 

         1               1 
        / \             / \
       1   X <- check  X   1 <- check   if one is NULL but another is not NULL : return false.

      condition 2: 

         1               1 
        / \             / \
       1   2 <- check  1   3 <- check   if both value are different : return false.
       
      condition 3: 

         1 <- check      1 <- check 
        / \             / \
       1   2           1   3        check the left and right suns of the node.

*/
