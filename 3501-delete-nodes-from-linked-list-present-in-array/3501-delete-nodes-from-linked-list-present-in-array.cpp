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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> vec;
        ListNode* curr = head;

        while (curr) {
            if (s.count(curr->val) == 0) vec.push_back(curr->val);
            curr = curr->next;
        }

        if (vec.empty()) return nullptr;

        curr = head;
        ListNode* prev = nullptr;
        for (int v : vec) {
            curr->val = v;
            prev = curr;
            curr = curr->next;
        }

        if (prev) prev->next = nullptr;
        return head;
    }
};