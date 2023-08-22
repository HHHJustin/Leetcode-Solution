// https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/772/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head){
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->next = head;
    struct ListNode *slow = new, *fast = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct ListNode *prev = NULL, *cur = slow->next, *next;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }    
    slow->next = NULL;
    
    while(head && prev){
        if(head->val != prev->val){return false;}
        head = head->next;
        prev = prev->next;
    }
    return true;
}

// 1 -> 2 -> 3 -> 2 -> 1
// ^ slow, fast

// 1 -> 2 -> 3 -> 2 -> 1
//      ^ slow    ^ fast

// 1 -> 2 -> 3 -> 2 -> 1 -> reverse
//      ^ slow           ^ fast

// 1 -> 2  1 -> 2 -> 3
// ^ n     ^ slow        if(n->val != slow->val) -> return false;

// 1 -> 2  1 -> 2 -> 3
//        ^ n        ^ slow   

//  -> return true;
