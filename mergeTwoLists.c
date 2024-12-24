/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list2==NULL){return list1;}
    if(list1==NULL){return list2;}
    struct ListNode * l1, *l2, *current, *prev=NULL;
    if(list1->val<=list2->val){
        l1=list1;
        l2=list2;
    }
    else{
        l1=list2;
        l2=list1;
    }
    current=l1->next;
    prev=l1;
    while(l2!=NULL){
        if(current!=NULL&&l2->val<current->val){
            prev->next = l2;
            prev = l2;
            l2 = l2->next;
            prev->next = current;
        }
        else if(current==NULL){
            prev->next = l2;
            prev = l2;
            l2 = l2->next;
        }
        else{
            prev = current;
            current = current->next;
        }
    }
    return l1;
}
