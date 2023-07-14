int removeDuplicates(int* nums, int numsSize){
    int fast= 1,slow= 1,count=1;
    if(numsSize == 1){return 1;}
    for(;fast<numsSize;fast++){
        if((nums[fast-1]==nums[fast] && count==1)){
            nums[slow] = nums[fast];
            slow++;
            count++;
        }
        else if((nums[fast-1]!=nums[fast])){
            nums[slow] = nums[fast];
            slow++;
            if(count==2){
            count = 1;}
        }   
    }
    return slow;
}

// give a integer array nums sorted in non-decreasing order
// we need remove some duplicates in-place
// element only appear at most twice
// relative order of the elements should be kept the same.
// return k(the remain elements number in nums)

// ex: nums = [1, 1, 1, 2, 2, 3]
//                ^                 we can use two pointer algo. solve the problem
//             slow,fast            and use a count to check the times of the element appearance, count = 1
//                                  if ((nums[fast-1] == nums[fast]) and count <= 1) → nums[slow] = nums[fast], slow++, count++(2)
// ex: nums = [1, 1, 1, 2, 2, 3]
//                   ^ 
//               slow,fast          if ((nums[fast-1] == nums[fast]) and count > 1) → fast++ to search until nums[fast-1] != nums[fast]
// ex: nums = [1, 1, 1, 2, 2, 3] → [1, 1, 2, 2, 2, 3]
//                   ^  ^                    ^                     
//                 slow fast             slow,fast
//                     ↑ if ((nums[fast-1] != nums[fast])) →  nums[slow] = nums[fast], slow++
//                     if(count == 2) → count = 1  represent the element is not repeat                                            
//  
// i.e.  if ((nums[fast-1] == nums[fast]) and count > 2) → pass (fast++)
