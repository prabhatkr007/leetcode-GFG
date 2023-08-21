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
    ListNode* reverse( ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        ListNode* curr = head;
        
        while(curr){
            
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
     ListNode* getMiddle(ListNode *head){
       
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
         
        return slow;
    }
    
    bool compareList(ListNode* l1, ListNode* l2){
        
        while(l2 != NULL){
            if(l1 -> val != l2 -> val ) return false;
            l1 = l1-> next;
            l2 = l2 -> next;
        }
        return true;
    }
    
     
    bool isPalindrome(ListNode* head) {
        if(!head ){
            return NULL;
        }
        ListNode* h1 = head;
        ListNode* mid = getMiddle(h1);
        ListNode* h2 = reverse(mid);
        return compareList(h1,h2);
    }
};