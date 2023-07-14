#define MIN(i, j) ((i < j) ? (i) : (j))
#define MAX(i, j) ((i > j) ? (i) : (j))

int maxProfit(int* prices, int pricesSize){
    int mini = prices[0],max_out = 0;
    for(int i=0;i<pricesSize;i++){
        int cost = prices[i] - mini;
        mini = MIN(prices[i],mini);
        max_out = MAX(cost,max_out);
    }
    return max_out;
}

// give 1 integer array prices
// prices[i] is the price of a given stock on i th day
// want to maximize profit by choosing a single dat to buy stock
// choosing a different day in the duture to sell that stock.
// if can't achieve any profit return 0.

// [7, 1, 5, 3, 6, 4] → brute force 
//  ^  ^              → calculate each combination → return maximum, if the maximum < 0 return 0
//                    → result: Time Limit Exceeded. Time Complexity:O(n^2)

// mini: record the minimum seen element.
// max_out: record the maximum profit. 
// init: max_out = 0, mini = prices[0]
// for loop all prices 
// use mini record minimum element
// if(prices[i] < mini){mini = prices[i];}
// if(prices[i] - mini > max_out){max_out = prices[i] - mini;}
// return max_out;

// [7, 1, 5, 3, 6, 4]
//  ^              
//  mini = 7, max_out = 0;
// [7, 1, 5, 3, 6, 4]
//     ^              
//  mini = 1, max_out = 0;
// [7, 1, 5, 3, 6, 4]
//        ^              
//  mini = 1, max_out = 4;
// [7, 1, 5, 3, 6, 4]
//           ^              
//  mini = 1, max_out = 4;
// [7, 1, 5, 3, 6, 4]
//              ^              
//  mini = 1, max_out = 5;
// [7, 1, 5, 3, 6, 4]
//                 ^              
//  mini = 1, max_out = 5;
