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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* mid=NULL;
      
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        ListNode* head2=slow->next;
       
      slow->next=NULL;
       ListNode* current=head2;
       ListNode* pre=NULL;
       while(current!=NULL){
        ListNode* nextu=current->next;
        current->next=pre;
        pre=current;
        current=nextu;
       }
       ListNode* hehe=head;
     ListNode* head2final=pre;
    
      while(head2final != NULL){
            ListNode* temp1 = head->next;
            ListNode* temp2 = head2final->next;

            head->next = head2final;
            head2final->next = temp1;

            head = temp1;
            head2final = temp2;
        }
    

        

    }
};
