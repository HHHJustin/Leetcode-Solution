/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head){
    struct ListNode *n = head;
    int count = 0;
    while(n){count++; n = n->next;}
    if(count == 1){return;}
    struct ListNode **array = (struct ListNode **)malloc(sizeof(struct ListNode *) * count);
    n = head;
    int i = 0;
    while(n){
        array[i] = n;
        i++; n = n->next;
    }
    n = head;
    int start = 1, end = count - 1;
    while(start <= end){
        n->next = array[end];
        n = n->next;
        end--;
        if(start > end){break;}
        n->next = array[start];
        n = n->next;
        start++;
    }
    n->next = NULL;
}

// use a array to save the listNode
// ex : 1, 2, 3, 4, 5
// -> [1, 2, 3, 4, 5]
//        ^ left   ^ right
// -> while(left < right) {
//    head->next = array[right];
//    head = head->next;
//    if(left > right){break;}
//    head->next = array[left];
//    head = head->next;
// }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Method 2 

void reorderList(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    // because the fast is after slow so we just need to check if fast and it next exist
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // then cut the linked list from middle
    // one : 1 -> 2 -> 3 -> NULL  two : 4 -> 5 -> NULL
    struct ListNode* first = head;
    struct ListNode* second = slow->next;
    slow->next = NULL;

    // reverse the second linked list
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL 
    // ^ cur      1. set the prev = NULL. 2. set temp = cur->next, 3. cur->next = prev. 4. prev = cur 5. cur = temp  -> until cur == NULL.
    // return prev
    struct ListNode* prev = NULL;
    struct ListNode* cur = second;
    struct ListNode* temp;
    while(cur){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    // prev is the reverse start
    second = prev;
    struct ListNode* temp1;
    struct ListNode* temp2;
    while(second){
        temp1 = first->next;
        temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

// ex : head = [1, 2, 3, 4, 5]
// first search the middle of the linked list
// 1 -> 2 -> 3 -> 4 -> 5
//           ^ middle 

// use slow and fast pointer to do
// 1 -> 2 -> 3 -> 4 -> 5
// ^s   ^f

// 1 -> 2 -> 3 -> 4 -> 5
//      ^s        ^f

// 1 -> 2 -> 3 -> 4 -> 5
//           ^s             ^f == NULL -> break

// s is the middle in the linked list

// then cut the linked list from middle
// one : 1 -> 2 -> 3  two : 4 -> 5

// reverse the no.2 linked list
// one : 1 -> 2 -> 3  two(reversed) : 5 -> 4

// combine both -> one -> two -> one -> two -> one .....




