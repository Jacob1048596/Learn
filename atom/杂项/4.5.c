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
       //����ǰ������һ�����ȣ�ɾ���¸����֮������жϣ�ֱ���¸���㲻��ȣ�Ȼ��ɾ����ǰ��㡣
        if(pHead == NULL || pHead->next == NULL) {
            return pHead;
        }
       ListNode* pre = NULL,*cur = pHead,*next = pHead->next;
        while (next) {
            if(next->val == cur->val) {
                while(next->val == cur->val) {
                    //ɾ��next���
                    cur->next = next->next;
                    free(next);
                    next = cur->next;
                    if (next == NULL) {
                        break;
                    }
                }
                //ɾ����ǰ���
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
