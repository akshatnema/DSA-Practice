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
        if(head==NULL) return NULL;
        vector<int> freq(201, 0);
        ListNode* temp=head;
        ListNode* ans=NULL, *tmp=NULL;
        while(temp!=NULL){
            freq[temp->val+100]++;
            temp=temp->next;
        }
        for(int i=0;i<201;i++){
            if(freq[i]==0 || freq[i]>1) continue;
            else{
                ListNode* newNode=new ListNode;
                newNode->val=i-100;
                newNode->next=NULL;
                if(ans==NULL){
                    ans=newNode;
                }
                if(tmp==NULL){
                    tmp=newNode;
                }else{
                    tmp->next=newNode;
                    tmp=newNode;
                }
            }
        }
        return ans;
    }
};