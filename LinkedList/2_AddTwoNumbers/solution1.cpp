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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *add = new ListNode;
        add->next = nullptr;
        int sum = l1->val + l2->val;
        add->val = (sum < 10) ? sum : (sum % 10);
        int xx = sum / 10;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr && l2 != nullptr)
        {
            ListNode *tmp = new ListNode;
            sum = l1->val + l2->val + xx;
            tmp->val = (sum < 10) ? sum : (sum % 10);
            tmp->next = add;
            xx = sum / 10;
            add = tmp;

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != nullptr)
        {
            while (l1 != nullptr)
            {
                ListNode *tmp = new ListNode;
                sum = l1->val + xx;
                tmp->val = (sum < 10) ? sum : (sum % 10);
                tmp->next = add;
                xx = sum / 10;
                add = tmp;

                l1 = l1->next;
            }
        }

        if (l2 != nullptr)
        {
            while (l2 != nullptr)
            {
                ListNode *tmp = new ListNode;
                sum = l2->val + xx;
                tmp->val = (sum < 10) ? sum : (sum % 10);
                tmp->next = add;
                xx = sum / 10;
                add = tmp;

                l2 = l2->next;
            }
        }

        if (xx != 0)
        {
            ListNode *tmp = new ListNode;
            tmp->val = xx;
            tmp->next = add;
            add = tmp;
        }

        ListNode *result = new ListNode;
        result->val = add->val;
        result->next = nullptr;
        add = add->next;
        while (add != nullptr)
        {
            ListNode *tmp = new ListNode;
            tmp->val = add->val;
            tmp->next = result;
            result = tmp;

            add = add->next;
        }

        return result;
    }
};