#include "myCustomHeader.h"

/** 
 * Function declaration
 */

ListNode *reverse_sub(ListNode*, int);

/** 
 * Code main body
 */

int main() {
    ListNode *myList = genListNode(std::vector<int> {2,2,3,4,5,6});
    std::cout << "my list generated = ";
    printList(myList);

    ListNode *new_head = new ListNode();
    new_head->next = myList;
    myList = new_head;

    std::cout << "my new head = ";
    printList(myList->next);

    return 0;
}

/** 
 * Function definition
 */
ListNode *reverse_sub (ListNode *start, int list_len) {
   ListNode* prev = nullptr;
   ListNode *ans;

    for (int i=0; i<list_len; i++) {
        ans = start;
        start = start->next;
        ans->next = prev;
        prev = ans;
    }
    return ans;
}
