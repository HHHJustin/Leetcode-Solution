int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 1){return 1;}
    int slow = 1;
    for(int fast=1;fast<numsSize;fast++){
        if(nums[slow-1] != nums[fast]){
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}
    
// 1 integer array nums sorted in non-decreasing order, remove the duplicates in-place. ex: [1, 1, 2]
// relative order of the elements should be kept same.
// return the number of unique elements in nums.   


// i:pointer to the currently check, means the count too.(the number at least = 1)
// nums = [1, 1, 2]
//         ^        because here is index 0, we don't need to check it. → i = 1

// nums = [1, 1, 2]
//            ^     check if nums[i] == nums[i-1] 
// yes: nums[i] = nums[i+1] each element move to i-1 index
// nums = [1, 2, _]
//            ^     check if nums[i] == nums[i-1] 
// no: i++
// nums = [1, 2, _]
//               ^  break

