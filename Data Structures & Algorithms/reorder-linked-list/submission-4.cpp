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
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next;
        slow->next = NULL;

        // reverse LL for temp

        ListNode* curr = temp;
        ListNode* prev = NULL;
        ListNode* agla = NULL;

        while (curr != NULL) {
            agla = curr->next;
            curr->next = prev;
            prev = curr;
            curr = agla;
        }

        ListNode* head2 = prev;

        // head and head2
        ListNode* temp1 = head;
        ListNode* temp2 = head2;

        while(temp2 != NULL)
        {
            ListNode* temp3=temp1->next;
            ListNode* temp4=temp2->next;
            temp1->next=temp2;
            temp2->next=temp3;
            temp1=temp3;
            temp2=temp4;
        }
        
    }
};
