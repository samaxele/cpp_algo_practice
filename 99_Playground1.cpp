#include "myCustomHeader.h"


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

/** 
 * Code main body
 */

int main() {
    ListNode *myList = genListNode("happy");
    printList (myList);

    return 0;
}


