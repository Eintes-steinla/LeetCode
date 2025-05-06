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
class Solution
{
public:
    void push_front(ListNode *&head, int sum, int &xx)
    {
        if (head == nullptr)
        {
            head = new ListNode;
            head->val = (sum < 10) ? sum : (sum % 10);
            head->next = nullptr;
        }
        else
        {
            ListNode *tmp = new ListNode;
            tmp->val = (sum < 10) ? sum : (sum % 10);
            tmp->next = head;
            head = tmp;
        }
        xx = sum / 10;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *add;
        int sum = l1->val + l2->val;
        int xx = 0;
        push_front(add, sum, xx);
        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr && l2 != nullptr)
        {
            sum = l1->val + l2->val + xx;
            push_front(add, sum, xx);

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != nullptr)
        {
            while (l1 != nullptr)
            {
                sum = l1->val + xx;
                push_front(add, sum, xx);
                l1 = l1->next;
            }
        }

        if (l2 != nullptr)
        {
            while (l2 != nullptr)
            {
                sum = l2->val + xx;
                push_front(add, sum, xx);
                l2 = l2->next;
            }
        }

        if (xx != 0)
        {
            push_front(add, xx, xx);
        }

        ListNode *result;
        push_front(result, add->val, xx);
        add = add->next;
        while (add != nullptr)
        {
            push_front(result, add->val, xx);
            add = add->next;
        }

        return result;
    }
};