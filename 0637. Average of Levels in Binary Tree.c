/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sumlevelnode(struct TreeNode* node, double* sum, int *number, int level, int *maxlevel){
    if(node == NULL){
        return;
    }
    number[level]++;
    if(level > (*maxlevel)){(*maxlevel) = level;}
    sum[level] += node->val;
    sumlevelnode(node->left, sum, number, level + 1, maxlevel);
    sumlevelnode(node->right, sum, number, level + 1, maxlevel);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    double a[3] = {0.0};
    double *sum = (double *)calloc(sizeof(double), 1000);
    int *number = (int *)calloc(sizeof(int), 1000);
    int maxlevel = 0;
    int *maxpointer = &maxlevel;
    sumlevelnode(root, sum, number, 0, maxpointer);
    *returnSize = (double *)(maxlevel + 1);
    for(int i=0;i<*returnSize;i++){
        sum[i] /= number[i];
    }
    return sum;
}

// give 1 root of a binary tree.
// return the average value of the nodes on each level in the form of 1 array.
// Answer with 10^-5 of the actual answer will be accepted.

/*
        3       level 1 -> has 2^0 nodes at most
       / \  
      9   20    level 2 -> has 2^1 nodes at most
         /  \
         15  7  level 3 -> has 2^2 nodes at most

        3       use 2 array -> 1 save the sum of node and 1 save the number of node.      
       / \      sum = [], number = [] 
      9   20    use recursive method.
         /  \   base condition 1: if(node == NULL){return;}
         15  7                 2: sum[i] += node.val -> we can get all sum of nodes

*/
