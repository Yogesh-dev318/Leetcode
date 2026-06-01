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
    ListNode* deleteDuplicates(ListNode* head) {
        // if(head==nullptr || head->next==nullptr){
        //     return head;
        // }
        // map<int,int> mp;
        // vector<int> arr;
        // ListNode* temp=head;
        // while(temp!=nullptr){
        //     mp[temp->val]++;
        //     temp=temp->next;
        // }
        // for(auto it:mp){
        //     if(it.second==1){
        //         arr.push_back(it.first);
        //     }
        // }
        // int n=arr.size();
        // if(n==0) return nullptr;
        // ListNode* head2=new ListNode(arr[0]);
        // ListNode* temp2=head2;
        // for(int i=1;i<n;i++){
        //     ListNode* newnode=new ListNode(arr[i]);
        //     temp2->next=newnode;
        //     temp2=temp2->next;
        // }
        // return head2;
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr != NULL) {
            if (curr->next != NULL && curr->val == curr->next->val) {
                while (curr->next != NULL && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};