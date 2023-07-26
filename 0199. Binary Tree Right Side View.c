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

void getrightnode(struct TreeNode* node, int level, int* output, int *maxlevel){
    if(node == NULL){return;}
    if(output[level] == INT_MIN){output[level] = node->val;}
    if(level > (*maxlevel)){(*maxlevel) = level;}
    getrightnode(node->right, level + 1, output, maxlevel);
    getrightnode(node->left, level + 1, output, maxlevel);
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    int *output = (int *)malloc(sizeof(int) * 101);
    for(int i=0;i<101;i++){output[i] = INT_MIN;}
    int level = 0;
    int maxlevel = 0, *p = &maxlevel;
    if(root!=NULL){getrightnode(root, level, output, p);*returnSize = *p + 1;}
    else{*returnSize=0;}
    return output;
}

// give 1 root of 1 binary tree, imagine yourself standing on the right side
// return the values of the nodes you can see ordered from top to bottom.

/*
    ex :  1 -> 
         / \
        2   3 ->
         \  
          5 -> 

    construct 1 integer array -> the array size is the tree maximum depth == [0, 100] 
    We check the root if NULL first

    and use the recursive method.

    condition 1:       if the root have right and left sun -> we will choose the right sun first
         1 <- node     so we init the output array = INT_MIN; let level record the level of node.
        / \            if(output[level] != INT_MIN): represent that has right side node be choosen.
       2   3           else(output[level] == INT_MIN): first right side node -> output[level] = node -> val; 
       
    condition 2:       if node == NULL -> return;

    recursive condition:
    getrightnode(root->right, level)
    getrightnode(root->left, level)

*/
