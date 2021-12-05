/* Question Link - https://leetcode.com/contest/weekly-contest-270/problems/delete-the-middle-node-of-a-linked-list/ */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
/*
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
        ListNode* temp = head;
        int ct=0;
        while(temp!=NULL){
            ct++;
            temp=temp->next;
        }
        if(ct==1){
            head=NULL;
            return head;
        }
        int mid=ct/2;
        int ct1=0;
        temp=head;
        ListNode *pre=head;
        ListNode *curr=head;
        ListNode *next1=head->next;
        while(temp!=NULL){
            if(ct1==mid-1){
               pre=temp;
               curr=temp->next;
               if(curr!=NULL){
                   next1=curr->next;
                   pre->next=next1;
               }
               else{
                   pre->next=NULL;
               }
               break; 
            }
            else{
                ct1++;
            }
          temp=temp->next;  
        }
        return head;
    }
};