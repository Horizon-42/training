// all things about linked list
#include <iostream>
#include <vector>

using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
  private:
    void get(ListNode *head, vector<int> &res)
    {
        if (head->next == nullptr)
        {
            res.push_back(head->val);
            return;
        }
        get(head->next, res);
        res.push_back(head->val);
    }

  public:
    vector<int> printListFromTailToHeadConst(ListNode *head)
    {
        vector<int> res;
        if (head != nullptr)
        {
            get(head, res);
        }
        return res;
    }

    vector<int> printListFromTailToHeadReverse(ListNode *head)
    {
        vector<int> res;
        if (head != nullptr)
        {
            ListNode *pre = nullptr;
            ListNode *next = nullptr;

            while (head != nullptr)
            {
                next = head->next;
                head->next = pre;
                pre = head;
                head = next;
            }
            head = pre;
            while (head != nullptr)
            {
                res.push_back(head->val);
                head = head->next;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
