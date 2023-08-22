// https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/603/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL){return head;}
    struct ListNode zero;
    zero.next = head;
    struct ListNode *slow = &zero, *fast = head;
    while(n){
        fast = fast->next;
        n--;
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    if(slow->next){slow->next = slow->next->next;}
    else{slow->next = NULL;}
    return zero.next;
}

//  0->  1 -> 2 -> 3 -> 4 -> 5 -> 6 ex : n = 2
//  ^ slow ^fast

//  0->  1 -> 2 -> 3 -> 4 -> 5 -> 6 ex : n = 2
//                 ^ slow         ^ fast


//  0 -> 1
//  ^ s     ^ f -> will delete slow->next -> i.e. head will become NULL -> so we return zero->next
