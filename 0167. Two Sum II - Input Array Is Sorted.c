/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *output = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int left = 0,right = numbersSize - 1;
    while(numbers[left] + numbers[right] != target){
        if((numbers[left] + numbers[right]) < target){left++;}
        else{right--;}
    }
    output[0] = left + 1;
    output[1] = right + 1;
    return output;
}

// give integer sorted in non-decreasing order array numbers and 1 integer target
// return the indices of the 2 numbers, index1 and index2, added by one as 1 integer array [index1,index2] of length 2.
// only has one solution and can't use same element twice.

// ex: numbers = [2, 7, 11, 15], target = 9 -> use 2 pointer "left" and "right"
//           left ^          ^ right      compare (left + right) with target 
//     if(numbers[left] + numbers[right] == target) -> return [left + 1, right + 1]
//     else if(numbers[left] + numbers[right] > target) -> too large -> need to become small ->right--
//     else -> too small -> need to become larger -> left++

// ex: numbers = [2, 7, 11, 15], target = 9 -> use 2 pointer "left" and "right"
//           left ^     ^ right   -> numbers[left] + numbers[right] > target -> right -- 
// ex: numbers = [2, 7, 11, 15], target = 9 -> use 2 pointer "left" and "right"
//           left ^  ^ right   -> numbers[left] + numbers[right] == target -> return output[0] = left + 1, output[1] = right + 1; 
