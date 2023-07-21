/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *convert(int left, int right, int *nums){
    if(left > right){return NULL;}
    int median = (left + right) / 2;
    struct TreeNode* node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = nums[median];
    node->left = convert(left, median - 1, nums);
    node->right = convert(median + 1, right, nums);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize == 0){return NULL;}
    return convert(0, numsSize - 1, nums);

}

// give 1 integer array nums where the elements are sorted in ascending order,
// convert it to 1 height-balanced binary search tree.

/*

step 1:
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10] -> we can use divide and conquer method to solve.
      ^ left         ^ median       ^ right  -> first -> find the median in the array : median = (right + left) / 2 = 5   
    construct a TreeNode as root
                5
               / \
step 2:
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10] -> then find the root.leftsun and root.rightsun -> convert (left, median - 1), (median + 1, right)
      ^ left      ^ right                   : (0 + 4) / 2 = 2                                         0       4            6           10
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
                        ^ left      ^ right : (6 + 10) / 2 = 8    
                5
               / \
              2   8 


step 3:
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10] -> then find the root.leftsun and root.rightsun -> convert (left, median - 1), (median + 1, right)
 left ^  ^ right                   : (0 + 1) / 2 = 0                                                  0        1             3        4 
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
          left ^  ^ right : (3 + 4) / 2 = 3    

                5
               / \
              2   8 
             / \
            0   3
step 4:
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10] -> then find the root.leftsun and root.rightsun -> convert (left, median - 1), (median + 1, right)
                   left ^  ^ right   : (6 + 7) / 2 = 6                                                6      7               9        10
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
                            left ^  ^ right : (9 + 10) / 2 = 9    

                5
               / \
              2   8 
             / \ / \
            0  3 6  9

step 5:
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10] -> then find the root.leftsun and root.rightsun -> convert (left, median - 1), (median + 1, right)
            -> right > left ->return FULL                                                              0       -1             1        1 
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    left ^ right : (1 + 1) / 2 = 1     

                5
               / \
              2   8 
             / \ / \
            0  3 6  9
             \
              1
step 6:
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10] -> then find the root.leftsun and root.rightsun -> convert (left, median - 1), (median + 1, right)
            -> right > left ->return FULL                                                             3       2             4        4 
ex : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    left ^ right : (1 + 1) / 2 = 1     

                5
               / \
              2   8 
             / \ / \
            0  3 6  9
             \  \
              1  4  .....
              
*/
