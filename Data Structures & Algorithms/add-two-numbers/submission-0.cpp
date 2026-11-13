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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;

        ListNode* ans=new ListNode();
        ListNode* temp=ans;

        while(t1 || t2){
            int carry=0;

            while(t1 && t2){
                int s=t1->val+t2->val+carry;
                int digit=s%10;
                carry=s/10;

                ListNode* n=new ListNode(digit);
                temp->next=n;
                temp=temp->next;
                t1=t1->next;
                t2=t2->next;
            }
            while(t1){
                 int s=t1->val+carry;
                int digit=s%10;
                carry=s/10;

                ListNode* n=new ListNode(digit);
                temp->next=n;
                temp=temp->next;
                t1=t1->next;
            }
            while(t2){
                int s=t2->val+carry;
                int digit=s%10;
                carry=s/10;

                ListNode* n=new ListNode(digit);
                temp->next=n;
                temp=temp->next;
                t2=t2->next;
            }
            if(carry!=0){
                ListNode* n=new ListNode(carry);
                temp->next=n;
                temp=temp->next;
            }
        }
        return ans->next;
    }
};
