/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
  char **output = (char *)malloc(20 * sizeof(char *));
  int count = 1, col_num = 0;
  int i = 0, s = 1;
  if(numsSize == 0){*returnSize = 0;return 0;}
  else{
    for(; s < numsSize; s++){
      if(nums[s] == nums[i + count - 1] + 1){count++;}
      else{
        output[col_num] = (char *)malloc(28);
        if(count == 1){
          // int snprintf ( char * str, size_t size, const char * format, ... );
          // 
          snprintf(output[col_num], 28, "%d", nums[i]);}
        else{
          snprintf(output[col_num], 28, "%d->%d", nums[i],nums[s-1]);
        }
        count = 1;
        col_num++;
        i = s;
      }
    }
    output[col_num] = (char *)malloc(28);
    if(count == 1){
        snprintf(output[col_num], 28, "%d", nums[i]);}
    else{
        snprintf(output[col_num], 28, "%d->%d", nums[i],nums[s-1]);
    }
    *returnSize = col_num + 1;
    return output;
  }
}

// give a sorted unique integer array nums
// range a -> b
// return the smallest sorted list cover all the numbers in the array exactly.
// if "a->b" : a != b
// if "a" : a==b

// we will use a matrix to save the output
// ex:[['0', '-', '>', '2', '\0'],
//      '4', '-', '>', '5', '\0'],
//      '7', '\0']]             so we need five char space at least
// use malloc to create the char matrix "output"
// let int colnum to record the column number.

// nums = [0, 1, 2, 4, 5, 7]
//         ^i,s             let a int count = 0 to record how many integer in the sub interval
//                          and record the first element in the sub interval.
//                          if count == 0 : count++ 
// nums = [0, 1, 2, 4, 5, 7] count = 1
//         ^i ^s            else if count != 0 : {check if nums[s] == nums[i + count -1] + 1} count++
// 
// nums = [0, 1, 2, 4, 5, 7] count = 2
//         ^i    ^s         else if count != 0 : {check if nums[s] == nums[i + count -1] + 1} count++
// 
// nums = [0, 1, 2, 4, 5, 7] count = 3
//         ^i       ^s      else if count != 0 : {check if nums[s] != nums[i + count -1] + 1} 
//                          if count > 1: set the "nums[i]->nums[s-1]" i.e."0->2" to the output matrix
//                          count reset to 1 & i = s 
// ....
// nums = [0, 1, 2, 4, 5, 7] count = 1
//                        ^  if count == 1: set "nums[i]" i.e. "7" to the output matrix

// final return output




