int jump(int* nums, int numsSize){
    int jumps = 0;
    int currEnd = 0;
    int currFastLen = 0;
    for(int i = 0; i < numsSize - 1; i++){
        currFastLen = (currFastLen > nums[i] + i) ? currFastLen : nums[i] + i;
        if(currEnd == i){
            jumps++;
            currEnd = currFastLen;
        }
    }
    return jumps;
}

// give integer array "nums" and its length is "n"
// initially positioned at nums[0]

// each element nums[i] represents the maximum length of a forward from i.
// In other words, if you are at nums[i], you can jump to any nums[i + j]
// where: 
// 0 <= j <= nums[i] and i + j < n

// return the minimum number of jumps to reach num[n - 1].
// The test cases are generated such that you can reach nums[n - 1]

// ex: nums = [2, 3, 1, 1, 4]  -> because it must arrive the nums[numsSize - 1]
//             ^               -> so we don't need consider the condition it may not arrive.
//                                jumps : represent the jump numbers
//                                currEnds : represent current maximum of jump
//                                currFastLen : represent next jump maximum length
//                                init : jumps = 0, currEnds = 0, currFastLen = 0; (beginning never jump)
//  ex: nums = [2, 3, 1, 1, 4]
//              ^              -> jump++, and next jump maximum currFastLen, currEnds= num[i] + i == 2.
//  ex: nums = [2, 3, 1, 1, 4]
//                 ^           -> next nums[i] chech if currFastLen < nums[i] + i -> yes-> update currFastLen = nums[i] + i == 4
//  ....
//  ex: nums = [2, 3, 1, 1, 4]
//                    ^        -> while arrive i == currFastLen -> jumps++ (it means that must jump again)
//                                then find the next Farest jump distance.........


// i.e. nums = [2, 3, 1, 1, 4] nums[0] = 2 -> represent my first range must in nums[0] + i (1 ~ 2) 
//      nums = [2, 3, 1, 1, 4]
//                 ^  ^        and we use nums[1] & nums[2] to find the next farest length is in range nums[1] + 1 = 4 (2 ~ 4)
//                          

//      nums = [2, 3, 1, 1, 4]
//                          ^ and we don't need to calculate the last element.
