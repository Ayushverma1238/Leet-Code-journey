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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};
        int minVal = INT_MAX, maxVal = INT_MIN, prev = -1;
        ListNode * prevNode = head;
        ListNode * curr = head-> next;
        int i = 1;
        int first = -1;
        while(curr->next != nullptr){
            if((curr-> val > prevNode->val && curr-> val > curr->next->val) || (curr->val < prevNode->val && curr->val < curr->next->val)){
                if(prev != -1){
                    minVal = min(minVal, i-prev);
                }
                if(first != -1){
                    maxVal = max(maxVal, i-first);
                }
                if(prev == -1){
                    first = i;
                }
                prev = i;
            }
            prevNode = curr;
            curr = curr->next;
            i++;
        }
     
        return {minVal == INT_MAX ? -1 : minVal, maxVal == INT_MIN ? -1: maxVal};
    }
};