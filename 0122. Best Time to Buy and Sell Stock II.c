#define MAX(i, j) ((i) > (j) ? (i) : (j))

int maxProfit(int* prices, int pricesSize){
    int prevNotHold = 0;
    int prevHold = INT_MIN;
    int curHold, curNotHold;
    for(int i = 0;i < pricesSize;i++){
        curHold = prevHold;
        curNotHold = prevNotHold;
        prevHold = MAX(curHold, curNotHold - prices[i]);
        prevNotHold = MAX(curNotHold, curHold + prices[i]);
    }
    return prevNotHold;
}

// give a integer array "prices"
// prices[i] is the price of a given stock on the i_th day
// 

// [7, 1, 5, 3, 6, 4] init -> curHold = INT_MIN, curNotHold = 0;
//  ^                 prevHold = INT_MIN, prevNotHold = 0;
// curHold = MAX(prevHold(INT_MIN), prevNotHold(0) - stockPrice(7))) = -7
// curNotHold = MAX(prevNotHold(0), prevHold(INT_MIN) + stockPrice(7)) = 0

// [7, 1, 5, 3, 6, 4] 
//     ^                 prevHold = -7, prevNotHold = 0;
// curHold = MAX(prevHold(-7), prevNotHold(0) - stockPrice(1))) = -1
// curNotHold = MAX(prevNotHold(0), prevHold(-7) + stockPrice(1)) = 0

// [7, 1, 5, 3, 6, 4] 
//        ^              prevHold = -1, prevNotHold = 0;
// curHold = MAX(prevHold(-1), prevNotHold(0) - stockPrice(5))) = -1
// curNotHold = MAX(prevNotHold(0), prevHold(-1) + stockPrice(5)) = 4

// [7, 1, 5, 3, 6, 4] 
//           ^           prevHold = -1, prevNotHold = 4;
// curHold = MAX(prevHold(-1), prevNotHold(4) - stockPrice(3))) = 1
// curNotHold = MAX(prevNotHold(4), prevHold(-1) + stockPrice(3)) = 4 

// [7, 1, 5, 3, 6, 4] 
//              ^        prevHold = 1, prevNotHold = 4;
// curHold = MAX(prevHold(1), prevNotHold(4) - stockPrice(6))) = 1
// curNotHold = MAX(prevNotHold(4), prevHold(1) + stockPrice(6)) = 7 

// [7, 1, 5, 3, 6, 4] 
//                 ^     prevHold = 1, prevNotHold = 7;
// curHold = MAX(prevHold(1), prevNotHold(7) - stockPrice(4))) = 3
// curNotHold = MAX(prevNotHold(7), prevHold(1) + stockPrice(4)) = 7 
