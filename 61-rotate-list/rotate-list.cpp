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
        // vector<int> arr;
        // ListNode* temp=head;
        // while(temp!=nullptr){
        //     arr.push_back(temp->val);
        //     temp=temp->next;
        // }
        // int n=arr.size();
        // vector<int> arr2(n);
        // for(int i=0;i<n;i++){
        //     arr2[(i+k)%n]=arr[i];
        // }
        // temp=head;
        // int i=0;
        // while(temp!=nullptr){
        //     temp->val=arr2[i];
        //     i++;
        //     temp=temp->next;
        // }
        // return head;
        if(head==nullptr){
            return head;
        }
        int n=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k%n==0){
            return head;
        }
        temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=head;
        int i=n-k;
        temp=head;
        while(i!=1){
            i--;
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
        
    }
};