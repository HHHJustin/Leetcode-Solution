/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *output = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head = output;
    int sum, carry = 0;
    while(l1 || l2){
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        output->next = temp;
        output = temp;
        if(l1 && l2){
            sum = l1->val + l2->val + carry;
            output->val=(sum%10);
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
            }
        else if(l1){
            output->val=(l1->val + carry)%10;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        }
        else{
            output->val=(l2->val + carry)%10;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        }
    }
    if(carry == 1){
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        output->next = temp;
        output = temp;
        output->val = 1;
    }
    output->next = NULL;
    return head->next;

}

// give 2 non-empty linked lists retpresenting 2 non-negative integers.
// digits are storged in reverse order.
// each of their nodes contais 1 single digit.
// add 2 numbers and return the sum as 1 linked list.

// ex: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//           ^ i                         ^ i         
// construct 1 linked list output to record the result. let carry = 0 represent the sum carry
// while(l1 || l2){int sum = l1->val + l2->val + carry; if(sum > 10){carry = 1;}; output->val = sum % 10; l1 = l1 -> next; l2 = l2 -> next;}

// ex: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9] output = [8, ] carry = 1
//              ^ i                         ^ i     
// ex: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9] output = [8, 9, ] carry = 1
//                 ^ i                         ^ i     
// ex: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9] output = [8, 9, 9] carry = 1
//                    ^ i                         ^ i    
// ex: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9] output = [8, 9, 9, 9, 0] carry = 1
//                       ^ i                        ^ over      
// ex: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9] output = [8, 9, 9, 9, 0, 0] carry = 1
//                          ^ i                     ^ over 
// ex: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9] output = [8, 9, 9, 9, 0, 0, 0] carry = 1
//                             ^ i                  ^ over 
// ex: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9] output = [8, 9, 9, 9, 0, 0, 0, 0] carry = 1
//                               ^ over             ^ over 

// if carry == 1 -> need to construct ListNode : output->val = 1. output = [8, 9, 9, 9, 0, 0, 0, 0, 1] 
