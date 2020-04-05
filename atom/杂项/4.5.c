list*fun(list* head)
{
  list* prev,cur,next;
  prev=head;
  prev->next=cur;
  cur->next=next;
  while (cur->val!=next->val) {
    next=next->next;
    cur=cur->next;
    prev=prev->next;
  }
  while (cur->val==next->val) {
    /* code */next=next->next;
  }
  cur=next;
  next=next->next;
  prev->next=cur;
  class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
       //若当前结点和下一结点相等，删除下个结点之后继续判断，直到下个结点不相等，然后删除当前结点。
        if(pHead == NULL || pHead->next == NULL) {
            return pHead;
        }
       ListNode* pre = NULL,*cur = pHead,*next = pHead->next;
        while (next) {
            if(next->val == cur->val) {
                while(next->val == cur->val) {
                    //删除next结点
                    cur->next = next->next;
                    free(next);
                    next = cur->next;
                    if (next == NULL) {
                        break;
                    }
                }
                //删除当前结点
                if(pre == NULL) {
                    pHead = next;
                } else {
                    pre->next = next;
                }
                free(cur);
                cur = next;
                if(cur != NULL) {
                    next = cur->next;
                }
            } else {
                pre = cur;
                cur = next;
                next = cur->next;
            }
        }
        return pHead;
    }
};

}
