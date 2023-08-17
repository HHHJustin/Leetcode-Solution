int singleNumber(int* nums, int numsSize){
    int n = nums[0];
    for(int i = 1; i< numsSize;i++){
        n ^= nums[i];
    }
    return n;
}

//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
//You must implement a solution with a linear runtime complexity and use only constant extra space.
// nums = [4, 1, 2, 1, 2]
// use xor bitwise operation to solve
// 4 ^ 1 ^ 2 ^ 1 ^ 2 -> 4 ^ 1 ^ 1 ^ 2 ^ 2 -> 4 ^ 0 -> 4  
