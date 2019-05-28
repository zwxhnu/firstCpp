//
// Created by Apple on 2019-05-01.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution81 {
public:
    bool search(vector<int> &nums, int target) {
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (*it == target)
                return true;
        }
        return false;
    }
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        this->val = x;
        this->next = NULL;
    }
};

class Solution82 {
public:
    /**
     * 1->1->1->2->3
     * 2->3
     * 1->2->3->3->4->4->5
     * 1->2->5
     */
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *left = head, *ret = new ListNode(0), *p = ret;
        while (left != NULL) {
            int count = 1;
            while (left->next != NULL && left->val == left->next->val) {
                left = left->next;
                count++;
            }
            if (count == 1) {
                ListNode *tmp = new ListNode(left->val);
                tmp->next = NULL;
                p->next = tmp;
                p = p->next;
            }
            left = left->next;
        }
        return ret->next;
    }
};

class Solution86 {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *less = new ListNode(0), *greater = new ListNode(0), *rl = less, *rg = greater, *p = head;
        while (p != NULL) {
            ListNode *tmp = new ListNode(p->val);
            tmp->next = NULL;
            if (p->val < x) {
                less->next = tmp;
                less = less->next;
            } else {
                greater->next = tmp;
                greater = greater->next;
            }
            p = p->next;
        }
        less->next = rg->next;
        return rl->next;
    }
};

class Solution89 {
public:
    vector<int> grayCode(int n) {

    }
};

void print(ListNode *head) {
    ListNode *node = head;
    while (node->next != NULL) {
        cout << node->val << "->";
        node = node->next;
    }
    cout << node->val << endl;
}

int main() {
    Solution81 s81;
    vector<int> vector = {2, 5, 6, 0, 0, 1, 2};
    cout << s81.search(vector, 0) << endl;
    vector = {2, 5, 6, 0, 0, 1, 2};
    cout << s81.search(vector, 3) << endl;

    Solution82 s82;
    ListNode l1(1), l2(2), l3(3), l4(3), l5(3), l6(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = NULL;
    ListNode *r82 = s82.deleteDuplicates(&l1);
    print(r82);

//    Solution86 s86;
//    ListNode l1(1), l2(4), l3(3), l4(2), l5(5), l6(2);
//    l1.next = &l2;
//    l2.next = &l3;
//    l3.next = &l4;
//    l4.next = &l5;
//    l5.next = &l6;
//    l6.next = NULL;
//    ListNode *r = s86.partition(&l1, 3);
//    print(r);

    return 0;
}