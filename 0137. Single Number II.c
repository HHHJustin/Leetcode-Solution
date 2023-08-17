int singleNumber(int* nums, int numsSize){
  int sum = 0;
  for(int i = 0; i < 32; i++){
      int temp = 0;
      for(int j = 0; j < numsSize;j++){
          temp += (nums[j] >> i) & 1;
      }
      temp %= 3;
      sum += (temp << i);
  }
  return sum;
}

// nums = [2, 2, 3, 2] -> return 3
//        0010
//        0010
//        0011
// +      0010
// -----------
//        0041 -> % 3 -> 0011 -> 3

