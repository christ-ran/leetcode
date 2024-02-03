/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *list = new ListNode();
        ListNode *head = list;

        int r = 0;

        while (l1 && l2)
        {
            int v1 = l1->val;
            int v2 = l2->val;

            int c = v1 + v2 + r;
            r = c / 10;

            list->next = new ListNode(c % 10);
            list = list->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            int v1 = l1->val;
            int c = v1 + r;
            r = c / 10;

            list->next = new ListNode(c % 10);
            list = list->next;
            l1 = l1->next;
        }

        while (l2)
        {
            int v1 = l2->val;
            int c = v1 + r;
            r = c / 10;

            list->next = new ListNode(c % 10);
            list = list->next;
            l2 = l2->next;
        }

        if (r)
            list->next = new ListNode(r);

        return head->next;
    }
};