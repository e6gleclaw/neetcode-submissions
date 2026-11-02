
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        // Insert the head of every non-empty linked list
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            ListNode* node = top.second;

            // Attach the smallest node
            temp->next = node;
            temp = temp->next;

            // Insert the next node of the extracted node
            if (node->next != NULL) {
                pq.push({node->next->val, node->next});
            }
        }

        return ans->next;
    }
};
