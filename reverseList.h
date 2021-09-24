
#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

// 链表相关练习
// https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/

// https://ke.qq.com/course/package/35548

// 方法一：迭代
// 假设链表为 1 \rightarrow 2 \rightarrow 3 \rightarrow \varnothing1→2→3→∅，我们想要把它改成 \varnothing \leftarrow 1 \leftarrow 2 \leftarrow 3∅←1←2←3。

// 在遍历链表时，将当前节点的 \textit{next}next 指针改为指向前一个节点。由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。在更改引用之前，还需要存储后一个节点。最后返回新的头引用。

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode-solution-d1k2/

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) 
    {
        ListNode *prev=nullptr;
        ListNode *curr=pHead;
        while (curr)
        {
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }

    ListNode *ReverseList_M2(ListNode *pHead)
    {
        
        if(pHead==nullptr || pHead->next==nullptr)
        {
            return pHead;
        }
      
        ListNode *newHead=ReverseList_M2(pHead->next);

        pHead->next->next=pHead;            
        pHead->next=NULL;           
        return newHead;         

    }


    // 使用栈

    ListNode *ReverseList_M3(ListNode *pHead)
    {
        // 输入 {1} 期望输出 {1} 所以要返回 pHead 不能返回nullptr 
        if(pHead==NULL || pHead->next==NULL)
        {
            return pHead;
        }
      
        stack<ListNode*> stacks;
        while (pHead!=nullptr)
        {
            stacks.push(pHead);
            pHead=pHead->next;
        }
        ListNode *newHead=stacks.top();
        ListNode *nextNode=newHead;
        
        while (stacks.empty())
        {
            nextNode->next=stacks.top();     
            stacks.pop();
            nextNode=nextNode->next;
        }
        nextNode->next=nullptr;
        return newHead;    

    }
};





