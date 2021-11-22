// Question link - https://leetcode.com/problems/add-two-numbers/

#include <bits/stdc++.h>
using namespace std;

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

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* root=NULL;
        ListNode* pre=NULL;
        int x,bor;
        x=bor=0;
        while(temp1!=NULL && temp2!=NULL){
            x= temp1->val+temp2->val+bor;
            int dig= x%10;
            bor=x/10;
            ListNode *new_node= new ListNode(dig);
            if(root==NULL){
                root=new_node;
                pre=new_node;
            }
            else{
                pre->next=new_node;
                pre=new_node;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            x=temp1->val+bor;
            int dig= x%10;
            bor=x/10;
            ListNode *new_node= new ListNode(dig);
            if(root==NULL){
                root=new_node;
                pre=new_node;
            }
            else{
                pre->next=new_node;
                pre=new_node;
            }
            temp1=temp1->next;
        }
         while(temp2!=NULL){
            x=temp2->val+bor;
            int dig= x%10;
            bor=x/10;
            ListNode *new_node= new ListNode(dig);
            if(root==NULL){
                root=new_node;
                pre=new_node;
            }
            else{
                pre->next=new_node;
                pre=new_node;
            }
            temp2=temp2->next;
        }
        if(bor!=0 && temp1==NULL && temp2==NULL){
            ListNode *new_node= new ListNode(bor);
            if(root==NULL){
                root=new_node;
                pre=new_node;
            }
            else{
                pre->next=new_node;
                pre=new_node;
            }
        }
        return root;
    }
};