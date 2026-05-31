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
    ListNode* oddEvenList(ListNode* head) {
        // vector<int> arr;
        // ListNode* temp=head;
        // int i=0;
        // while(temp!=nullptr){
        //     if(i%2==0){
        //         arr.push_back(temp->val);
        //     }
        //     i++;
        //     temp=temp->next;
        // }
        // temp=head;
        // i=0;
        // while(temp!=nullptr){
        //     if(i%2!=0){
        //      arr.push_back(temp->val);
        //     }
        //     i++;
        //     temp=temp->next;
        // }
        // temp=head;
        // int count=0;
        // while(temp!=nullptr){
        //     temp->val=arr[count];
        //     count++;
        //     temp=temp->next;
        // }
        // return head;
        if(head == nullptr || head->next == nullptr)return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenhead=even;
        while(even!=nullptr && even->next!=nullptr){
            odd->next=odd->next->next;
            odd=odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};