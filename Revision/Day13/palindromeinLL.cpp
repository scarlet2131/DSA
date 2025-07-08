/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

//Bruteforce methodwith extra space of O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> stk;
        while(temp!=NULL){
            stk.push(temp->val);
            temp = temp->next;
        }
       
        temp = head;

        while(temp!=NULL){
            if(stk.top()!=temp->val){
                return false;
            }
            stk.pop();
            temp = temp->next;
        }
        return true;
        

        

    }
};