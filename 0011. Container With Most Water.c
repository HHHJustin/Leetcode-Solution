#define MIN(i,j)((i) < (j) ? (i) : (j))

int maxArea(int* height, int heightSize){
    int i=0,j=heightSize-1,max;
    max=(j-i)*MIN(height[i],height[j]);
    while(i<j){
    if(max < (j-i)*MIN(height[i],height[j])){max=(j-i)*MIN(height[i],height[j]);}
    if(height[i]<height[j]){i++;}
    else{j--;}}
    return max;
}

// give 1 integer array "height" of length "n"
// There are n vertical lines drawn such that the 2 endpoints of ith are(i, 0) and (i, height[i]).
// Find 2 lines that together with the x-axis form a container, such that the container contains the most water.
// return the maximum amount of water a container can store.

// ex : height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
//                   ^                    ^ -> choose the 2 lines -> we can get max area of water that contain 49

// we calculate the water area is choose shorter line between 2 lines and multiple the x distance.
// ex : height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
//                ^  ^                      -> min(height[0], height[1]) * x distance(== 1 - 0) = 1 * 1 = 1

// let two pointer i, j to point the index 0, index hi first and use max to storage the water area.
// ex : height = [1, 8, 6, 2, 5, 4, 8, 3, 7] max = (j - i) * min(height[i], height[j]) = 8
//                ^ i                     ^ j                     
// while(i < j) -> to find the result bigger than now
// ex : height = [1, 8, 6, 2, 5, 4, 8, 3, 7] 
//                   ^ i                  ^ j   -> we will move the short line -> i++
//                                              -> and update the new maximum -> if((j - i) * min(height[i], height[j]) > max) : max = (j - i) * min(height[i], height[j]) = 7 * 7 = 49
// ...... max = 49 over -> return max
