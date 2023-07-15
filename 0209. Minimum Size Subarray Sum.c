#define MIN(i, j)(((i) < (j)) ? (i) : (j))

int minSubArrayLen(int target, int* nums, int numsSize){
    int left = 0, right = 0, res = numsSize + 1, sum = 0;
    while(right < numsSize){
        while(sum < target && right<numsSize){
            sum += nums[right++];
        }
        while(sum >= target){
            res = MIN(right-left,res);
            sum -= nums[left++];
        }
    }
    return (res == numsSize + 1)? 0 : res;
}

// give 1 array of positive integers nums
// and 1 positive integer target.
// return minimal length of a subarray whose sum is greater than or equal to target.
// if there is no such subarray, return 0.

// ex : nums = [2, 3, 1, 2, 4, 3], target = 7 -> we will retrun 2 because the sum of subarray -> [4, 3] == 7.

// nums = [2, 3, 1, 2, 4, 3], target = 7 -> sum = 0, res = len + 1 (7)
//    left ^ right                      -> use 2 pointer left and right.
// 
// nums = [2, 3, 1, 2, 4, 3], target = 7 
//    left ^ right                      -> let right++ -> sum+= nums[right++] until sum > target
//                            
// nums = [2, 3, 1, 2, 4, 3], target = 7 -> sum = 7
//    left ^        ^ right              -> and left++ -> sum-=nums[left++] until sum < target. res = min(right - left, res);
//                                         
// nums = [2, 3, 1, 2, 4, 3], target = 7 -> res = min(right - left, res) = 3
//       left ^     ^ right              
// .......
// return (res == len + 1) ? 0 : res + 1

// ex : nums = [1, 1, 1 , 1, 1, 1, 1] target = 11 -> we will return 0 because there is no subarray can == 11.
//         left ^                  ^ right -> until right > size break and res == len + 1 -> retrun 0;
