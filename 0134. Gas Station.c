int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int sum = 0, current = 0, start = 0, diff;
    for(int i=0;i<gasSize;i++){
        diff = gas[i] - cost[i];
        sum += diff;
        current += diff;
        if(current < 0){start = i + 1;current=0;}
    }
    return (sum < 0)? -1 :start;
}

// give 1 gas stations along 1 circular route, where the amount of gas at the i^th station is gas[i].
// 1 car with 1 unlimited gas tank and it costs cost[i] of gas to travel from the i^th station to its next (i + 1)^th station.
// begin the journey with 1 empty tank at one of the gas stations.
// given 2 integers arrays gas and cost, return the staring gas station's index if can travel around the circuit once in the clockwise direction.
// otherwise return -1.

// gas = [1, 2, 3, 4, 5], cost = [3, 4, 5, 3, 2] g = 0, count = 0, output = -1
//        ^ gas index             ^ gas index

// substract both -> [-2, -2, -2, 3, 3] -> if sum totally >= 0 -> we can have a circuit travel. otherwise -> can't finish the travel
//                     ^ start if the position < 0 -> represent the can't be the start.

// ex: sub array : [1, -2, 3, -1 , 4]
//                  ^ if the position > 0 -> might br the start. let current += sub[i]
//     sub array : [1, -2, 3, -1 , 4]
//                      ^ and in this position -> current += sub[i] < 0 -> represent this position and before are not the start.
//     sub array : [1, -2, 3, -1 , 4]
//                         ^ so we search the next posible start from next position......
