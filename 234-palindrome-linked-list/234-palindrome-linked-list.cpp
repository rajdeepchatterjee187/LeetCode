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
    bool isPalindrome(ListNode* head) {
        ListNode* middle = findMiddle(head);
        ListNode* endptr = reverseList(middle);
        
        while(head != nullptr and endptr != nullptr) {
            if(head->val!= endptr->val) return false;
            head = head->next;
            endptr = endptr->next;
        }
        
        return true;
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast!= nullptr and fast->next!= nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(curr!= nullptr) {
            ListNode* after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }
};