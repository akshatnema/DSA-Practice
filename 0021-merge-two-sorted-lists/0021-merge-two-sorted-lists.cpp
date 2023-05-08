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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1=list1, *head2=list2;
        ListNode* mainhead=NULL, *temp=NULL;
        while(head1!=NULL && head2!=NULL){
            ListNode* newNode = new ListNode(0);
            if(head1->val<head2->val){
                newNode->val=head1->val;
                head1=head1->next;
            }else{
                newNode->val=head2->val;
                head2=head2->next;
            }
            if(mainhead==NULL){
                temp=newNode;
                mainhead=newNode;
            }else{
                temp->next=newNode;
                temp=newNode;
            }
        }
        while(head1!=NULL){
            ListNode* newNode = new ListNode(0);
            newNode->val=head1->val;
            head1=head1->next;
            if(mainhead==NULL){
                temp=newNode;
                mainhead=newNode;
            }else{
                temp->next=newNode;
                temp=newNode;
            }
        }
        while(head2!=NULL){
            ListNode* newNode = new ListNode(0);
            newNode->val=head2->val;
            head2=head2->next;
            if(mainhead==NULL){
                temp=newNode;
                mainhead=newNode;
            }else{
                temp->next=newNode;
                temp=newNode;
            }
        }
        return mainhead;
    }
};