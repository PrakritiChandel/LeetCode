/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;  
        // Initialize result to store decimal value        
        // Traverse the linked list from head to tail
        while (head != nullptr) {
            // Shift result left by 1 bit (multiply by 2) and add current bit
            result = result * 2 + head->val;            
            // Move to the next node
            head = head->next;
        }        
        return result;  // Return the final decimal value
    }
};