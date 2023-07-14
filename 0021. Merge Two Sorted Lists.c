/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *new = head, *r = head; 
    while(list1 && list2){
        if(list1->val <= list2->val){new->next = list1;list1=list1->next;new=new->next;}
        else{new->next = list2;list2=list2->next;new=new->next;}
    }
    if(list1){new->next=list1;}
    else{new->next=list2;}
    return r->next;
}

// give 2 heads of 2 sorted linked lists "list1" and "list2".
// we need merge the 2 linked lists to 1 sorted linked list.
// return the head of the merged linked list.

// ex: list1 = [1, 2, 4], list2 = [1, 3, 4]
//              ^ i                ^ j      use i, j represent the checking position
//                                          we can use a pointer of struct ListNode to link the sorted result. 
//     list1 : 1-> 2-> 4 , list2 : 1-> 3-> 4   while(list1 != NULL && list2 != NULL){to check if list1->val <= list2->val{output->next = list1; list1 = list1->next}}
//                                                                                              else{output->next = list1; list1 = list1->next;output = output->next;}
// ex: list1 = [1, 2, 4], list2 = [1, 3, 4]
//                       ^ i             ^ j   while 1 linked list check over -> push another to output.
