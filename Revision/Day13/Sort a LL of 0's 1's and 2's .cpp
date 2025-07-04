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

class Solution {
public:
    ListNode *sortList(ListNode *head) {

       ListNode* zeroHead = new ListNode(-1);
       ListNode* oneHead = new ListNode(-1);
       ListNode* twoHead = new ListNode(-1);


       ListNode* zero = zeroHead;
       ListNode* one = oneHead;
       ListNode* two = twoHead;
       ListNode* temp = head;

       while(temp!=NULL){
            if(temp->val==0){
                zero->next = temp;
                zero = temp;
            }else if(temp->val==1){
                one->next = temp;
                one = temp;
            }else{
                two->next = temp;
                two = temp;
            }
            temp = temp->next;

       }
       zero->next = oneHead->next!=NULL ? oneHead->next : twoHead->next;
       one->next = twoHead->next;
       two->next = NULL; 

       return zeroHead->next;

        
    }
};