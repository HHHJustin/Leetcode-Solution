typedef struct {
    int val;
    int min;
} Element;

typedef struct {
    int capacity;
    int top;
    Element *elements;
} MinStack;

//  construct 2 array in stack to save each value and minimum in ever appear number.
MinStack* minStackCreate() {
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->capacity = 30000;
    stack->top = 0;
    stack->elements = (Element *)malloc(sizeof(Element) * stack->capacity);
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    Element a;
    if(obj->top == 0){
        a.min = val;}
    else{
        if(val < obj->elements[(obj->top) - 1].min){
            a.min = val;}
        else{a.min = obj->elements[(obj->top) - 1].min;}
    }
    a.val = val;
    obj->elements[obj->top] = a;
    (obj->top)++;
}

void minStackPop(MinStack* obj) {
    (obj->top)--;
}

int minStackTop(MinStack* obj) {
    return obj->elements[obj->top - 1].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->elements[obj->top - 1].min;
}

void minStackFree(MinStack* obj) {
    free(obj->elements);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

// design 1 stack -> support 
// 1.push, 2.pop, 3.top, 4.retrieving the minimum element
// and in constant time.

// At most 3 * 10 ^ 4 will be made to do.
