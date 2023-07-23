int cmp(const void *a, const void *b){
   return (*(int *)a - *(int *)b);
}

int hIndex(int* citations, int citationsSize){
  int output = 0;
  qsort(citations, citationsSize, sizeof(int), cmp);
  for(int i=0; i < citationsSize; i++){
    if(citations[i] >= citationsSize - i){output = citationsSize - i;break;}
  }
return output;
}

// give 1 integer array "citations" where citations[i] is the number of citations a researcher received for their ith paper
// return the researcher's h-index.
// h-index is defined as the maximum value of h such that the given researcher has published at least h paper that have each been cited at least h times.

// citations = [3, 0, 6, 1, 5] 
//              ^     ^     ^ because have 3 paper that have at least 3 citation -> therefore. the h-index of the researcher is 3
// -> we can sorted the array from low to high 
// citations = [0, 1, 3, 5, 6] for loop from citationsSize to 0 
//              ^ i -> check if have 5-index -> citations[0] must >= 5, so check if the citations[0] == 0 >= 5 -> not -> next

// citations = [0, 1, 3, 5, 6] 
//                 ^ i -> check if have 4-index -> citations[1] must >= 4, so check if the citations[1] == 1 >= 4 -> not -> next

// citations = [0, 1, 3, 5, 6] 
//                    ^ i -> check if have 3-index -> citations[2] must >= 3, so check if the citations[2] == 3 >= 3 -> yes -> return i + 1;
