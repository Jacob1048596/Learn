/*
解题思路：将数组中要删除的元素用后面的元素覆盖掉
1.原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)
*/
int removeElement(int* nums, int numsSize, int val){
  int src = 0;
  int dst = 0;
  while(src < numsSize)
 {
    // 将数组中不等于val的值依次挪动到数组的开始位置
    if(nums[src] != val)
   {
      nums[dst] = nums[src];
      src++;
      dst++;
   }
    else
   {
      //如果是被删除的元素，直接++src位置，找到第一个不是val的位置
      src++;
   }
 }
  return dst;
}

/*
解题思路：大致思路同上题，用非重复的元素去覆盖重复元素
2.删除排序数组中的重复项
*/
int removeDuplicates(int* nums, int numsSize)
{
    int src1 = 0, src2 = 1;
    int dst = 0;
    // 跟上题的思路一致，相同的数只保留一个，依次往前放
    while(src2 < numsSize)
    {
        nums[dst] = nums[src1];
        ++dst;
		//如果两个指针指向的元素不重复，则指针同时向后移动
        if(nums[src1] != nums[src2])
        {
            ++src1;
            ++src2;
        }
        else
        {
            //如果重复，找到第一个不重复的元素
            while(src2 < numsSize && nums[src1] == nums[src2])
            {
                ++src2;
            }
            //更新指针
            src1 = src2;
            ++src2;
        }
    }

    if(src1 < numsSize)
    {
            nums[dst] = nums[src1];
            ++dst;
    }


    return dst;
}

/*
解题思路：此题是用一个数的数组形式 + 一个整数， 返回和的数组形式。
模拟加法进行逐位相加， 从低位向高位相加，最后整体逆置，得到最终结果
1. 每一位的值 = 对应位值的和 + 前一位的进位
2. 每一位的值计算出来之后，需要检查是否需要进位
3. 最高位计算之后，需要考虑是否还需要向上进位
5.数组形式的整数加法
*/
void reverse(int* nums, int begin, int end)
{
  while(begin < end)
  {
    int tmp = nums[begin];
    nums[begin] = nums[end];
    nums[end] = tmp;

    ++begin;
    --end;
  }
}

// 本题需要特别注意对[9,9,9,7] + 5的等特殊情况的处理
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
  int* addRet = (int*)malloc(10001*sizeof(int));
  //reti: 第i位的结果
  int reti = 0;
  //从低位开始相加
  int ai = ASize-1;
  int next = 0; // 进位值
  while(ai >= 0 || K > 0)
  {
     
    int x1 = 0;
    //如果ai没有越界，还有未相加的位，取出一位存入x1
    if(ai >= 0)
    {
      x1 = A[ai];
      --ai;
    }

    int x2 = 0;
    //如果k大于0，获取k的第i位
    if(K > 0)
    {
      x2 = K%10;
      K /= 10;
    }
    //第i位的结果：每一位的值 + 进位
    int ret = x1+x2+next;
    //如果结果大于9，需要进位
    if(ret > 9)
    {
      ret %= 10;
      next = 1;
    }
    else
    {
      next = 0;
    }
    //存入第i位的结果到数组中
    addRet[reti++] = ret;
  }
  //如果最高位有进位，需要在存入1
  if(next == 1)
  {
    addRet[reti++] = 1;
  }	
  //逆置结果
  reverse(addRet, 0, reti-1);
  *returnSize = reti;

  return addRet;
}

/*
解题思路：使用三次逆转法，让数组旋转k次
1. 先整体逆转
2. 逆转子数组[0, k - 1]
3. 逆转子数组[k, size - 1]
*/
void reverse(int* nums, int begin, int end)
{
    while(begin < end)
    {
        int tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;

        ++begin;
        --end;
    }
}

// 三趟逆置倒的思路
void rotate(int* nums, int numsSize, int k){
    if(k > numsSize)
    {
        k %= numsSize;
    }
    
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}

/*
解题思路：从最大值开始合并，所以合并从两个数组的末尾元素开始合并，依次把最大的元素放到末尾即可。
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //end1:nums1的末尾
    //end2:nums2的末尾
    //end:合并之后整个数组的末尾
     int end1 = m-1;
     int end2 = n-1;
     int end = m+n-1;
    
    while(end1 >= 0 && end2 >= 0)
    {   //选出尾最大的元素，存放到整个数组的末尾
        //每存放一个元素，尾向前移动一个位置
        if(nums1[end1] > nums2[end2])
        {
            nums1[end--] = nums1[end1--]; 
        }
        else
        {
            nums1[end--] = nums2[end2--];
        }
    }
    //剩余元素依次向末尾存放
    while(end1 >= 0)
    {
        nums1[end--] = nums1[end1--];
    }
    
    while(end2 >= 0)
    {
        nums1[end--] = nums2[end2--];
    }
}


/*
解题思路：从头节点开始进行元素删除，每删除一个元素，需要重新链接节点
*/
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL)
        return NULL;
    
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    
    while(cur)
    {
        //如果当前节点是需要删除的节点
        if(cur->val == val)
        {
            //首先保存下一个节点
            struct ListNode* next = cur->next;
            //如果删除的为头节点，更新头节点
            //否则让当前节点的前趋节点链接next节点
            if(prev == NULL)
            {
                head = cur->next;
            }
            else
            {
                prev->next = cur->next;  
            }
            //释放当前节点，让cur指向next
            free(cur);
            cur = next;
        }
        else
        {
            //如果cur不是需要删除的节点，则更新prev,cur
            prev = cur;
            cur = cur->next;
        }
    }
    
    return head;
}

// 1.删除链表中等于给定值 val 的所有节点
// 题目内容：
// 1.删除链表中等于给定值 val 的所有节点。 https://leetcode-cn.com/problems/remove-linked-list-elements/description/

// 第2题（编程题）
// 题目名称：
// 2.反转一个单链表
// 题目内容：
// 2.反转一个单链表。 OJ链接
/*
解题思路： 此题一般常用的方法有两种，三指针翻转法和头插法
1. 三指针翻转法
   记录连续的三个节点，原地修改节点指向
2. 头插法
   每一个节点都进行头插
*/
// 三个指针翻转的思想完成逆置
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode* n1, *n2, *n3;
    n1 = head;
    n2 = n1->next;
    n3 = n2->next;
    n1->next = NULL;
    //中间节点不为空，继续修改指向
    while(n2)
    {
        //中间节点指向反转
        n2->next = n1;
        //更新三个连续的节点
        n1 = n2;
        n2 = n3;
        if(n3)
            n3 = n3->next;
    }
    //返回新的头
    return n1;
}

// 取节点头插的思想完成逆置
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    while(cur)
    {
        struct ListNode* next = cur->next;
        //头插新节点，更新头
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    
    return newhead;
}

// 第3题（编程题）
// 题目名称：
// 3.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
// 题目内容：
// 3.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。OJ链接
/*
解题思路：
通过快慢指针找到中间节点，快指针每次走两步，慢指针每次走一步，当快指针走到结尾的时候，慢指针正好走到中间位置
*/
typedef struct ListNode Node;
struct ListNode* middleNode(struct ListNode* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next != NULL)
    {
       slow = slow->next;
       fast = fast->next->next;
    }

    return slow;
}

// 第4题（编程题）
// 题目名称：
// 4.输入一个链表，输出该链表中倒数第k个结点
// 题目内容：
// 4.输入一个链表，输出该链表中倒数第k个结点。 OJ链接
/*
解题思路：
快慢指针法 fast, slow, 首先让fast先走k步，然后fast,slow同时走，fast走到末尾时，slow走到倒数第k个节点。
*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        struct ListNode* slow = pListHead;
        struct ListNode* fast = slow;
        while(k--)
        {
            if(fast)
                fast = fast->next;
            else
                return NULL;
        }
         
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
         
        return slow;
    }
};

// 5.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
// 题目内容：
// 5.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。OJ链接
/*
解题思路：
此题可以先创建一个空链表，然后依次从两个有序链表中选取最小的进行尾插操作进行合并。
*/
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
           return l1;
             
        Node* head = NULL, *tail = NULL;
        //创建空链表
    	head = tail = (Node*)malloc(sizeof(Node));
        tail->next = NULL;
        while(l1 && l2)
        {
            // 取小的进行尾插
            if(l1->val < l2->val)
            {
                tail->next = l1;
                tail = tail->next;

                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                tail = tail->next;

                l2 = l2->next;
            }
        }
        //剩余元素直接拼接
        if(l1)
            tail->next = l1;
        else
            tail->next = l2;

        Node* list = head->next;
        free(head);
        return list;
}


// 第2题（编程题）
// 题目名称：
// 6.编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
// 题目内容：
// 6.编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 。OJ链接
/*
解题思路
创建两个链表，分别存放小于x的节点和大于等于x的节点，分别进行尾插
*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead == NULL)
            return NULL;
        
        struct ListNode* lessHead, *lessTail,*greaterHead, *greaterTail;
        //创建链表表头
        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* cur = pHead;
        while(cur)
        {
            //小于x的尾插到lessTail
            if(cur->val < x)
            {
                lessTail->next = cur;
                lessTail = lessTail->next;
            }
            //大于等于x的尾插到greaterTail
            else
            {
                greaterTail->next = cur;
                greaterTail = greaterTail->next;
            }
            cur = cur->next;
        }
        //链接两个链表
        lessTail->next = greaterHead->next;
        greaterTail->next = NULL;
        //获取表头
        pHead = lessHead->next;
        free(lessHead);
        free(greaterHead);
        
        return pHead;
    }
};

// 第3题（编程题）
// 题目名称：
// 7.链表的回文结构
// 题目内容：
// 7.链表的回文结构。OJ链接
/*
解题思路：
此题可以先找到中间节点，然后把后半部分逆置，最近前后两部分一一比对，如果节点的值全部相同，则即为回文。
*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		if (A == NULL || A->next == NULL)
			return true;
		ListNode* slow, *fast, *prev, *cur, *nxt;
		slow = fast = A;
		//找到中间节点
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		prev = NULL;
		//后半部分逆置
		cur = slow;
		while (cur)
		{
			nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}
		//逐点比对
		while (A && prev)
		{
			if (A->val != prev->val)
				return false;
			A = A->next;
			prev = prev->next;
		}
		return true;
	}
};
/*
此题也可以先把链表中的元素值全部保存到数组中，然后再判断数组是否为回文。不建议使用这种解法，因为如果没有告诉链表最大长度，则不能同此解法
*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        int a[900] = {0};
        ListNode* cur = A;
        int n = 0;
        //保存链表元素
        while(cur)
        {
            a[n++] = cur->val;
            cur = cur->next;
        }
        //判断数组是否为回文结构
        int begin = 0, end = n-1;
        while(begin < end)
        {
            if(a[begin] != a[end])
                return false;
            ++begin;
            --end;
        }
         
        return true;
    }
};


// 第4题（编程题）
// 题目名称：
// 8.输入两个链表，找出它们的第一个公共结点
// 题目内容：
// 8.输入两个链表，找出它们的第一个公共结点。OJ链接
/*
解题思路：
此题可以先计算出两个链表的长度，让长的链表先走相差的长度，然后两个链表同时走，直到遇到相同的节点，即为第一个公共节点
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0, lenB = 0;
    struct ListNode* curA = headA, *curB = headB;
    //计算链表长度
    while(curA) {
        ++lenA;
        curA = curA->next;
    }
    
    while(curB) {
        ++lenB;
        curB = curB->next;
    }
    
    int gap = abs(lenA-lenB);
    struct ListNode* longList = headA, *shortList = headB;
    if(lenA < lenB) {
        longList = headB;
        shortList = headA;
    }
    //让长链表先走几步
    while(gap--){
        longList = longList->next;
    }
    //两个链表同时走，直到遇到相同的节点
    while(longList && shortList)
    {
        if(longList->val == shortList->val) {
            return longList;
        }
        else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    
    return NULL;
}


// 第5题（编程题）
// 题目名称：
// 9.给定一个链表，判断链表中是否有环
// 题目内容：
// 9.给定一个链表，判断链表中是否有环。 OJ链接
/*
解题思路：
定义快慢指针fast,slow, 如果链表确实有环，fast指针一定会在环内追上slow指针。
*/
typedef struct ListNode Node;
bool hasCycle(struct ListNode *head) {
   Node* slow = head;
   Node* fast = head;

  while(fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast)
      return true;
  }

  return false;
}

// 第6题（编程题）
// 题目名称：
// 10.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
// 题目内容：
// 10.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL OJ链接
/*
解题思路：
如果链表存在环，则fast和slow会在环内相遇，定义相遇点到入口点的距离为X,定义环的长度为C,定义头到入口的距离为L,fast在slow进入环之后一圈内追上slow,则会得知：
slow所走的步数为:L + X
fast所走的步数为：L + X + N * C
并且fast所走的步数为slow的两倍，故：
2*(L + X) = L + X + N * C
即： L = N * C - X
所以从相遇点开始slow继续走，让一个指针从头开始走，相遇点即为入口节点
*/
typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
    	Node* slow = head;
        Node* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            //走到相遇点
            if(slow == fast)
            {
                // 求环的入口点
                Node* meet = slow;
                Node* start = head;

                while(meet != start)
                {
                    meet = meet->next;
                    start = start->next;
                }

                return meet;
            }
        }

        return NULL;
}


// 第7题（编程题）
// 题目名称：
// 11.给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深度拷贝
// 题目内容：
// 11.给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

// 要求返回这个链表的深度拷贝。OJ链接
/*
解题思路：
此题可以分三步进行：
1.拷贝链表的每一个节点，拷贝的节点先链接到被拷贝节点的后面
2.复制随机指针的链接：拷贝节点的随机指针指向被拷贝节点随机指针的下一个位置
3.拆解链表，把拷贝的链表从原链表中拆解出来
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1.拷贝链表，并插入到原节点的后面
        Node* cur = head;
        while(cur)
        {
            Node* next = cur->next;

            Node* copy = (Node*)malloc(sizeof(Node));
            copy->val = cur->val;

            // 插入
            cur->next = copy;
            copy->next = next;

            // 迭代往下走
            cur = next;
        }

        // 2.置拷贝节点的random
        cur = head;
        while(cur)
        {
            Node* copy = cur->next;
            if(cur->random != NULL)
                copy->random = cur->random->next;
            else
                copy->random = NULL;

            cur = copy->next;
        }

        // 3.解拷贝节点，链接拷贝节点
        Node* copyHead = NULL, *copyTail = NULL;
        cur = head;
        while(cur)
        {
            Node* copy = cur->next;
            Node* next = copy->next;

            // copy解下来尾插
            if(copyTail == NULL)
            {
                copyHead = copyTail = copy;
            }
            else
            {   
                copyTail->next = copy;
                copyTail = copy;
            }

            cur->next = next;

            cur = next;
        }

        return copyHead;
    }
};
