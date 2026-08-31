class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int firstCritical = -1;
        int prevCritical = -1;
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minDistance = min(minDistance, index - prevCritical);
                }
                prevCritical = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        if (prevCritical == -1 || firstCritical == prevCritical) {
            return {-1, -1};
        }

        return {minDistance, prevCritical - firstCritical};
    }
};