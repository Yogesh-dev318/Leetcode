/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // map<ListNode*,int>mp;
        // ListNode* temp1=headA;
        // ListNode* temp2=headB;
        // while(temp1!=nullptr){
        //     mp[temp1]++;
        //     temp1=temp1->next;
        // }
        // while(temp2!=nullptr){
        //     if(mp.find(temp2)!=mp.end()){
        //         return temp2;
        //     }
        //     mp[temp2]++;
        //     temp2=temp2->next;
        // }
        // return nullptr;
        if(headA==nullptr || headB==nullptr) return nullptr;
        ListNode* t1=headA;
        ListNode* t2=headB;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2) return t1;
            if(t1==nullptr) t1=headB;
            if(t2==nullptr) t2=headA;
        }
        return t1;
    }
};