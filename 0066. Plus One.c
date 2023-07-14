/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = digitsSize - 1;
    *returnSize = digitsSize;
    int *output;
    digits[i]++;
    while(digits[i] == 10 && i > 0){
      digits[i] = 0;
      digits[i-1]++;
      i--;
    }
    if(digits[0]==10){
      (*returnSize)++;
      output = (int *)calloc(sizeof(int) , (*returnSize));
      output[0] = 1;
      }
    else{
      output = (int *)malloc(sizeof(int) * (*returnSize));
      for(int i=0;i<(*returnSize);i++){
        output[i] = digits[i];
      }
    }
    return output;
    
}

// give 1 large integer represented as 1 integer array digits.
// where each digits[i] i the i th digit of the integer.
// return the integer + 1 (array of digits)

// ex: [1, 2, 3] 
//            ^ check if the digit == 9 -> the digits + 1 and next digit + 1 too.
// ex: [9, 9, 9] -> [1, 0, 0, 0] -> if the max digits == 9 we need check if it will impact the digitSize.

// ex: [9, 9, 9]
//            ^ i -> i = digitsSize - 1, digits[i]++, if digits[i] == 10 : digits[i] = 0 -> and i-- until digit[i] != 10;
//              and count the digit number. 
// ex: [9, 9, 10] -> [9, 10, 0] -> [10, 0, 0] -> if(digits[0] == 10){*returnSize++;} -> malloc *returnSize array -> array[0] = 1 other = 0
