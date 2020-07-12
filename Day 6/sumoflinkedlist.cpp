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
        int carry = 0, sum;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(l1 != NULL || l2 != NULL){
            ListNode* temp = new ListNode();
            temp->next = NULL;
            if(l1 == NULL)
                sum = l2->val + carry;
            else if(l2 == NULL)
                sum = l1->val + carry;
            else
                sum = l1->val + l2->val + carry;
            carry /= 10;
            if(sum < 10){
                temp->val = sum;
            }
            else{
                temp->val = sum%10;
                carry = sum/10;
            }
            if(l1 == NULL)
                l2 = l2->next;
            else if(l2 == NULL)
                l1 = l1->next;
            else{
                l1 = l1->next;
                l2 = l2->next;
            }
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }
       // while(carry){
        if(carry > 0){
            ListNode* temp = new ListNode();
            temp->next = NULL; 
            temp->val = carry;
            tail->next = temp;
        }
        //}
       // if(l1 == NULL){
         //   while(l2 != NULL){
           //     sum = l2->val + carry;
            //}
        //}
        return head;
    }
};