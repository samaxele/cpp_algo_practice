#include <iostream>
#include <vector>

struct ListNode {
    int val;    
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

ListNode *generateList (std::vector<int> a) {
    ListNode *head, *tail;
    tail = new ListNode(0);
    head = tail;
    auto it = a.begin();
    while (it < a.end()) {
        tail->next = new ListNode (*it);
        tail = tail->next;
        it++;
    }
    tail->next = nullptr;
    return head->next;
}

ListNode *generateList (int *arr) {
    ListNode *head, *tail;
    tail = new ListNode(0);
    head = tail;
    int arr_size = sizeof(arr) / sizeof(int);
    for (int i=0; i<arr_size; i++) {
        tail->next = new ListNode(arr[i]); 
        tail = tail->next;
    }
    tail->next = nullptr;
    return head->next;
}

void printList (ListNode *head) {
    while (head) {

        std::cout << head->val << " > ";
        head = head->next;
    }
    std::cout << "\b\b  \n";
}

/*
Given 2 lists
l1 = 1 > 2 > > 4
l2 = 0 > 3 > 4 > 5
*/
class Solution {
public:
    ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
        while (l1 && l2) {
            //while l1 and l2 are not null
            if (l1->val <= l2->val) {
                l1->next = merge2Lists(l1->next,l2);
                return l1;
            }
            else if (l1->val > l2->val) {
                l2->next = merge2Lists(l1,l2->next);
                return l2;
            }
        }
        return l1?l1:l2;
    }
};

int main() {
 
    Solution Sol;
    std::vector<int> sample1 = {1,2,3,4};
    ListNode *tcase1 = generateList(sample1);

    std::vector<int> sample2 = {0,1,2,3,6};
    ListNode *tcase2 = generateList(sample2);

    std::cout << "Hello World! We will try to merge:\n";
    printList(tcase1);
    printList(tcase2);
    std::cout << "The ans = ";
    ListNode *ans = Sol.merge2Lists(tcase1, tcase2);

    printList(ans);

    return 0;
}