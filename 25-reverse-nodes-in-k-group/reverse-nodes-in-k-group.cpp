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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        while(curr != nullptr){
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        // head = pre;
        return pre;
    }
    ListNode* kfind(ListNode* head, int k) {
        k--;
        while(head != nullptr && k > 0){
            k--;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
        return head;

        ListNode* temp = head;
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        while(temp != nullptr){
            ListNode* knode = kfind(temp , k);
            if(knode == nullptr){
                if(pre != nullptr){
                    pre->next = temp;
                }
                break;
            }
            nxt = knode->next;
            knode->next = nullptr;
            knode = reverse(temp);
            if(temp == head){
                head = knode;
            }
            else{
                pre->next = knode;
            }
            pre = temp;
            temp = nxt;
        }
        return head;


    }
};