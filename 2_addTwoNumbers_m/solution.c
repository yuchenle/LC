/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->val = 0;
    ret->next = NULL;
    printf("addTwoNumbers:l1->val = %d, l2->val = %d\n", l1->val, l2->val);
    struct ListNode *initRet = ret;
    int extra = 0;

    while (l1 || l2) {
        if (l1) {
            ret->val += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            ret->val += l2->val;
            l2 = l2->next;
        }
        ret->val += extra;
        extra = ret->val >= 10 ? 1 : 0;
        ret->val = ret->val % 10;
        printf("ret->val = %d\n", ret->val);
        if (l1 || l2) {
            struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
            tmp->val = 0;
            tmp->next = NULL;
            ret->next = tmp;
            ret = tmp;
        }
    };
    
    if (extra == 1) {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->next = NULL;
        ret->next = tmp;
        ret = tmp;
        ret->val = 1;
    }

    return initRet;
}