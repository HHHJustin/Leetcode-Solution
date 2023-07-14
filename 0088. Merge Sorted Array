void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
// 2 integer array nums1, nums2 non-decreasing order
// 2 integer m, n → num1, nums2 number of elements
// Problem → merge nums1 and nums2 into a single array sorted in non-decreasing order
// The length of nums1 is m + n. if last n element in nums1 is 0 → ignored
// i : nums1 index, j : nums2 index, m: the number of nums1 element, n: the number of num2 element.
// when m != 0 and n != 0
int i=0, j=0;
while((m!=0)&&(n!=0)){
  if(nums1[i]<=nums2[j]){
    i++;
    m--;
  }
  else{
    // nums1 [i+1] = nums1[i]
    // ex [1, 2, 3, 0] → [x, 1, 2, 3]
    for(int x = nums1Size - 1; x > i; x--){
      nums1[x] = nums1[x-1];
    }
    nums1[i] = nums2[j];
    i++; j++; n--;
  }
}
if(m==0){
  while(n!=0){
    nums1[i++] = nums2[j++];
    n--;
  }
}
return nums1;
// nums1 = [1, 2, 3, 0, 0, 0] nums2 = [2, 5, 6]  non-decreasing order
//          ^                          ^
// check the smaller in nums1 → i += 1, m -= 1

// nums1 = [1, 2, 3, 0, 0, 0] nums2 = [2, 5, 6]  
//             ^                       ^
// check the smaller nums1 = nums2 → choose nums1 i += 1, m -= 1

// nums1 = [1, 2, 3, 0, 0, 0] nums2 = [2, 5, 6]  
//                ^                    ^
// check the smaller nums2 → temp = nums[i], nums1[i] = nums2[j], nums[i+1] = temp, i += 1, j += 1, n -= 1

// nums1 = [1, 2, 2, 3, 0, 0] nums2 = [2, 5, 6]  
//                   ^                    ^ 
// check the smaller nums1[i] < nums2[j] → choose nums1 i += 1, m -= 1

// nums1 = [1, 2, 2, 3, 0, 0] nums2 = [2, 5, 6]  
//                      ^                 ^ 
// m = 0 → *nums1 = nums2 remain 
}
