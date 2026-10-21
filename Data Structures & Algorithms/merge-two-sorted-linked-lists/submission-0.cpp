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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode();
        ListNode* temp=ans;
        ListNode* l1=list1;
        ListNode* l2=list2;
        while(l1 || l2){
            while(l1 && l2){
                if(l1->val >= l2->val){
                    ListNode* n=new ListNode(l2->val);
                    temp->next=n;
                    l2=l2->next;
                    temp=temp->next;
                }
                else if(l1->val < l2->val){
                    ListNode* n=new ListNode(l1->val);
                    temp->next=n;
                    l1=l1->next;
                    temp=temp->next;
                }
            }
            while(l1){
                ListNode* n=new ListNode(l1->val);
                    temp->next=n;
                    l1=l1->next;
                    temp=temp->next;
            }
            while(l2){
                ListNode* n=new ListNode(l2->val);
                    temp->next=n;
                    l2=l2->next;
                    temp=temp->next;
            }
        }
        return ans->next;
    }
};
