bool canJump(int* nums, int numsSize){
    int max_len = 0;
    if(numsSize == 1){return true;}
    for(int i=0;i<numsSize;i++,max_len--){
        if(max_len < nums[i]){max_len = nums[i];}
        if(i < numsSize - 1 && max_len == 0){return false;}
    }
    return true;
}

// give 1 integer array "nums"
// initially positioned at the array's first index.
// and each element in the array represents maximum jump length at that postion
// if can reach the last index -> true. else return false.
// 
// ex: nums = [2, 3, 1, 1, 4]
//             ^i             let int max_len to record the max legnth currently.
//                            if check the can arrive position(i.e index + nums[i]) > max_len -> max_len =  i + nums[i]
//                            while i == numsSize - 1 -> return true. if(i != numsSize && max_len == 0) -> return false.
