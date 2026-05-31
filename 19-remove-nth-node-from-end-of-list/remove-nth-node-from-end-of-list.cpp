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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int node=count-n;
        if(node==0){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        temp = head;
        while(temp!=nullptr){
            node--;
            if(node==0){
                break;
            }
            temp=temp->next;
        }
        ListNode* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
        return head;
    }
};