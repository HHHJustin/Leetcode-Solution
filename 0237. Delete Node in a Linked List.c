// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

// ex : 1 -> 2 -> 3 -> 4  given node is not tail node -> node = 2
//           ^ node   -> let node pretend the node->next

//      1 -> 3 -> 3 -> 4 
//           ^ node   -> and we have 2 node->next and delete the node->next

//      1 -> 3 -> 4   -> done
