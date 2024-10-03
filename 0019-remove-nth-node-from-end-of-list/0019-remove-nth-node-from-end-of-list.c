/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int NumNode=0;
    struct ListNode* temp = head;
    struct ListNode* temp1 = head;
    while(temp1!=NULL){
        if (temp1) NumNode++;
        temp1 = temp1->next;
    }
    printf("%d",NumNode);
    if (NumNode == 1) {
        head = NULL;

    }
    else if (NumNode == n){
        head = head->next;
        
    }
    else{
        for (int i=0;i<(NumNode-n-1);i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    
    return head;
}