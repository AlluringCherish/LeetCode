/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */




struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head-> next = NULL;
    int flag = 0;
    struct ListNode* iter = head;
    
    while(l1!=NULL || l2!= NULL || flag==1){
        int n1=0, n2=0, sum=0;
        if (l1) {
            n1=l1->val;
            l1 = l1->next;
        }
        if (l2) {
            n2=l2->val;
            l2 = l2->next;
        }
        struct ListNode* Node=(struct ListNode*)malloc(sizeof(struct ListNode));
        
        sum = n1+n2;
        if (flag == 1){
            flag = 0;
            sum+=1;
        }
        if (sum>=10){
            flag=1;
            sum = sum%10;
        }
        
        Node->next = NULL;
        Node->val = sum;
        iter->next = Node;
        iter = iter->next;
        
    }
    struct ListNode* result = head->next;
    return result;
}