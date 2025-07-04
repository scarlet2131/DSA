class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if(left!=NULL){
            temp->next = left;
        }else{
            temp->next = right;
        }
        return head->next;
    }
    ListNode* sortList(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* mid = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = NULL;
        
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

       return merge(leftHead, rightHead);

    }
};

