int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid;
    if(target <= nums[left]){return 0;}
    if(target > nums[right]){return numsSize;}
    while(left < right){
        mid = (left + right) / 2;
        
        if((mid == left)||(mid == right)){break;}
        if(target > nums[mid]){left = mid;}
        else if(target < nums[mid]){right = mid;}
        else{return mid;}
        
    } 
    if(target > nums[left]){mid++;}
    return mid;
}

// give a integer array and a integer target
// search the index. if the targer were not in array, return the inserted index. 

// [1, 3, 5, 6]  use binery search 
//  ^ left   ^ right    if target < nums[0] return 0. if target > nums[numsSize -1] return numsSize;
// step 1 check (left(0) + right(3)) / 2 -> mid (1)
// [1, 3, 5, 6]
//     ^ mid     
// if target = 5 > nums[1] left = mid 
// [1, 3, 5, 6]
//     ^left ^right
// mid = (1 + 3) / 2 = 2
// target == nums[2] == 5 return mid 

// if target = 2 < nums[1] right = mid 
// [1, 3, 5, 6]
//  ^l ^ right
// mid = (0 + 1) / 2 = 0
// target = 2 > nums[0] right = mid
// [1, 3, 5, 6]
//  ^ right

// if target = 7 > nums[1] left = mid 
// [1, 3, 5, 6]
//     ^l    ^ right
// mid = (1 + 3) / 2 = 2
// target = 7 > nums[2] left = mid
// [1, 3, 5, 6]
//        ^l ^ right

// if (left == mid) break;
// and if nums[mid] > nums[right] -> return mid + 1;
