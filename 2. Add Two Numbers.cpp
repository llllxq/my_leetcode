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
        ListNode *p = new ListNode((l1->val + l2->val + 0) % 10);
        ListNode *pHead = p;
        int carry = (l1->val + l2->val + 0) / 10;

        while(true){
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;

            if(l1 && l2){
                p->next = new ListNode((l1->val + l2->val + carry) % 10);
                p = p->next;
                carry = (l1->val + l2->val + carry) / 10;
            }
            else if(l1 && !l2){
                p->next = new ListNode((l1->val + 0 + carry) % 10);
                p = p->next;
                carry = (l1->val + 0 + carry) / 10;
            }
            else if(!l1 && l2){
                p->next = new ListNode((0 + l2->val + carry) % 10);
                p = p->next;
                carry = (0 + l2->val + carry) / 10;
            }
            else{
                if(carry){
                    p->next = new ListNode(carry);
                    break;
                }
                else{
                    break;
                }
            }
        }
        return pHead;
    }
};
