/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULLptr) {}
 *     ListNode(int x) : val(x), next(NULLptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
            
public:

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* last = head;
        int n=1;
        while(last->next != NULL){
            n++;
            last = last->next;
        }
        int K = k%n;
        if(K ==0){
            return head;
        }
        int count =1;
        ListNode* temp = head;
       while(count < (n - K)){
            temp = temp->next;
            count++;
        }
        last->next =head;
        ListNode* result =temp->next;
        temp->next = NULL;
        return result;
    }
};