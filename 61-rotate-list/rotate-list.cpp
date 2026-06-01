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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        vector<int> arr2(n);
        for(int i=0;i<n;i++){
            arr2[(i+k)%n]=arr[i];
        }
        temp=head;
        int i=0;
        while(temp!=nullptr){
            temp->val=arr2[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};