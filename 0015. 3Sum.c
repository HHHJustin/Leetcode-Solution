/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a,const void *b) {
    return *((int*) a) - *((int*) b);
} 

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);
    // construct a output matrix -> maybe need numsSize * numsSize 
    int **output = (int **)malloc(sizeof(int *) * numsSize * numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    // init *returnSize
    *returnSize = 0;
    int left,right;
    for(int i=0;i<numsSize-2;i++){
        if(i!=0 && nums[i]==nums[i-1]){continue;}
        left = i+1;
        right = numsSize - 1;
        while(left < right){
            if(nums[i] + nums[left] + nums[right] > 0){right--;}
            else if(nums[i] + nums[left] + nums[right] < 0){left++;}
            else{
                (*returnColumnSizes)[(*returnSize)] = 3;
                (output)[(*returnSize)] = (int *)malloc(sizeof(int) * 3);
                (output)[(*returnSize)][0] = nums[i];
                (output)[(*returnSize)][1] = nums[left];
                (output)[(*returnSize)][2] = nums[right];
                (*returnSize)++;
                left++;
                while(left < right && nums[left]==nums[left-1]){left++;}
            }
        }
    }
    return output;
}

// give 1 integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// -> i != j, i != k, j != k. -> nums[i] + nums[j] + nums[k] == 0.

// construct a matrix "output" -> save the triplets 
// ex: [-1, 0, 1, 2, -1, -4] -> sort the array 
// -> [-4, -1, -1, 0, 1, 2]        
//      ^ i ^ left       ^ right   while(left < right) left = i + 1; right = numsSize - 1;
//                                 check if nums[i] + nums[left] + nums[right] == 0
//                                 nums[i] + nums[left] + nums[right] == -3 < 0 -> need increase -> left++
// -> [-4, -1, -1, 0, 1, 2]
//      ^ i     ^ left   ^ right   check if nums[i] + nums[left] + nums[right] == 0
//                                 nums[i] + nums[left] + nums[right] == -3 < 0 -> need increase -> left++
// -> [-4, -1, -1, 0, 1, 2]
//      ^ i        ^ left^ right   check if nums[i] + nums[left] + nums[right] == 0
//                                 nums[i] + nums[left] + nums[right] == -2 < 0 -> need increase -> left++
// -> [-4, -1, -1, 0, 1, 2]
//      ^ i      left ^  ^ right   check if nums[i] + nums[left] + nums[right] == 0
//                                 nums[i] + nums[left] + nums[right] == -1 < 0 -> need increase -> left++
// -> [-4, -1, -1, 0, 1, 2]
//      ^ i         left ^ right   left == right -> i++


// -> [-4, -1, -1, 0, 1, 2]        (if i==0 || nums[i]!=nums[i-1]) -> check if repeat number appear
//          ^ i ^ left   ^ right   check if nums[i] + nums[left] + nums[right] == 0
//                                 nums[i] + nums[left] + nums[right] ==  0 -> save 
//                                 -> check other possibility -> let left++ until nums[left] !=nums[left-1]

// -> [-4, -1, -1, 0, 1, 2]        (if i==0 || nums[i]!=nums[i-1]) -> check if repeat number appear
//          ^ i    ^ left^ right   check if nums[i] + nums[left] + nums[right] == 0
//                                 nums[i] + nums[left] + nums[right] ==  1 > 0 -> need reduce -> right--

// -> [-4, -1, -1, 0, 1, 2]        (if i==0 || nums[i]!=nums[i-1]) -> check if repeat number appear
//          ^i left^  ^ right   check if nums[i] + nums[left] + nums[right] == 0
//                                 nums[i] + nums[left] + nums[right] ==  0 -> save 

