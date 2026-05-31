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
    ListNode* deleteMiddle(ListNode* head) {
        // ListNode* temp=head;
        // int count=0;
        // while(temp!=nullptr){
        //     count++;
        //     temp=temp->next;
        // }
        // if(count==0 || count==1){
        //     return nullptr;
        // }
        // temp=head;
        // int node=count/2;
        // while(temp!=nullptr){
        //     node--;
        //     if(node==0){
        //         break;
        //     }
        //     temp=temp->next;
        // }
        // ListNode* del=temp->next;
        // temp->next=del->next;
        // delete(del);
        // return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        if(count==0 || count==1){
            return nullptr;
        }
        fast=fast->next->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* del=slow->next;
        slow->next=del->next;
        delete(del);
        return head;
    }
};