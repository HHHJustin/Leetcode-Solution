/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HASHSIZE 20011
int hash_function(int key){
    int index = key % HASHSIZE;
    return index < 0 ? index + HASHSIZE : index;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *output = (int *)malloc(sizeof(int) * 2);
    int *hashmap = (int *)malloc(sizeof(int) * HASHSIZE);
    *returnSize = 2;
    int hashkey;
    // for(int i=0; i < HASHSIZE; i++){
    //     hashmap[i] = -1;
    // }
    // initialization same as below memset function
    memset(hashmap, -1, HASHSIZE * sizeof(int));
    for(int i=0; i < numsSize ; i++){
        hashkey = target - nums[i];
        hashkey = hash_function(hashkey);
        if(hashmap[hashkey] != -1){
            output[0] = hashmap[hashkey];
            output[1] = i;
            break;
        }
        hashmap[hash_function(nums[i])] = i;
    }
    
    return output;
}

// give 1 integer array nums and 1 integer target.
// return indices of 2 numbers such that they add up to target.
// assume that each input would have exactly  solution, and may not use the same element twice.
// can return the answer in any order.

// ex: nums = [2, 7, 11, 15], target = 9 -> we can construct an hash map to save the number ever appear 
//                                       -> hash_function == key % HASHSIZE -> if hashmap[hashkey] != -1 -> return hashmap[hashkey], i.
//                                       -> else -> save index to hashmap[hash_function(nums[i])].

