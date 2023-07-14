/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

// give a head of a linked list. determine if the linked list has a cycle in it.
// if there is some node in the list that can be reached again by continuously following the next pointer.
// pos is used to denote the index of the node that tail's pointer is connected to.

// ex: [3, 2, 0, -4] we don't know "pos"
// we can use Floyd Cycle Detection Algorithm to check if have cycle
// [3, 2, 0, -4]
//  ^slow, fast  use 1 slow pointer and fast pointer.
// slow += 1 each time, fast += 2 each time 
// if have cycle -> fast == slow at a certain time -> return true
// if no fast will point a NULL -> return false
