void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int n){
    // nums: array begin, n:array size
    int begin = 0, end = n - 1;
    while(begin < end){
        swap(nums + begin, nums + end);
        begin++;
        end--;
    } 
}

void rotate(int* nums, int numsSize, int k){
    k = k%numsSize;
    reverse(nums,numsSize);
    reverse(nums,k);
    reverse(nums+k,numsSize-k);  
}
// a integer array nums
// rotate the array to right by k steps
// k is a non-negative integer

// three different ways
// idea 1 :[1, 2, 3, 4, 5, 6, 7]  from index numsSize - 1
//                    ^   use a temp save the first element, temp = nums[numsSize -1] = 7
// nums[(i)%numsSize] = nums[(i-1)%numsSize] 
// step 1 = [1, 2, 3, 4, 5, 6, 6]  
//                          ^   
// ... step 6 = [1, 1, 2, 3, 4, 5, 6]
//               nums[0] = temp  
// results → limit exceed

// idea 2: use a extra array
// 
//              ^       index:(i+(numsSize-k))%numsSize
// [x, x, x, x, x, x, x]
//  ^                   index: i
// return output array

// idea 3: combine idea 1 & idea 2
// just need storage k element
// [1, 2, 3, 4, 5, 6, 7] k%numsSize = 3 → save[5, 6, 7]
// [x, x, x, 1, 2, 3, 4] nums[numsSize-k+i] = nums[i] do numsSize-k times 
// [5, 6, 7, 1, 2, 3, 4] nums[i] = save[i] do k times


