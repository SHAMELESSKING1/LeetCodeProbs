/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * }
*/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
       struct ListNode *p=head;
    struct ListNode *q=NULL;
       int count=0;
       while(p!=NULL)
       {
           count++;
           p=p->next;
       }
    struct ListNode *prev=NULL;p=head;struct ListNode *next=NULL;
	while(p!=NULL)
	{
		next=p->next;
		p->next=prev;
		prev=p;
		p=next;
	}
	head=prev;
    p=head;
     for(int i=1;i!=n;i++)
     {
         q=p;
         p=p->next;
     }
    if(q==NULL)
    {
        head=p->next;
        free(p);
    }
    else{
        q->next=p->next;
        free(p);
    }
    struct ListNode *prev1=NULL;p=head;struct ListNode *next1=NULL;
    while(p!=NULL)
	{
		next1=p->next;
		p->next=prev1;
		prev1=p;
		p=next1;
	}
	head=prev1;
    return head;
}