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
#define null NULL
#define Node ListNode

    void reverse(Node* head ,int size){
        Node* curr = head;
        Node* prev = null;

        while(size--){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == null) return null;

        Node* left = head;
        Node* prevleft = null;
        Node* res = null;
        Node* right = null;
        int size = k;

        while(true){
            right = left;

            for(int i = 0; i < size - 1; i++){
                if(right == null) break;
                right = right->next;
            }

            
            if(right){
                Node* nextleft = right->next;

                reverse(left, size);

                if(prevleft){
                    prevleft->next = right;
                } else {
                    res = right;   
                }

                left->next = nextleft;  

                prevleft = left;
                left = nextleft;
            }
            else{
                if(prevleft){
                    prevleft->next = left;
                }
                if(res == null){
                    res = head;
                }
                break;
            }
        }

        return res;
    }
};