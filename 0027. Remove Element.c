int removeElement(int* nums, int numsSize, int val){
  // 1 integer array nums ex: [3, 2, 2, 3]
  // require: in-place → can't use other memory space solve the problem
  // the integer val : remove value ex: 3

  // idea & example
  // i = 0 nums index, k = 0 count
  // [3, 2, 2, 3] from index 0 check, if element = val, nums[i+1] = nums[i]
  //  ^           if element = val, nums[i+1] = nums[i]
  // [2, 2, 3, x] x : don't care. k++.
  //  ^           if element != val, i++
  // [2, 2, 3, x] x : don't care. 
  //     ^           
  // ...
  // [2, 2, x, x] 

  int k = 0;
  for(int a = 0; a < numsSize; a++){
    if(nums[k] == val){
      for(int x = k; x < numsSize-1;x++){
        nums[x] = nums[x+1];
      }
    }
    else{
      k++;
    }
  }
  return k;
}
