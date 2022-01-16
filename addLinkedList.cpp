/*
Create a function which returns a linked list with folowing inputs

Input: sorted ListNode and int
Return: a listNode with added target int into a sorted listnode

*/

#include "myCustomHeader.h"

ListNode *addin(ListNode*, int);

int main() {
    ListNode *testcase = genListNode({2,4,5,6,7});
    int target = 123;

    std::cout << "hello world\n";
    printList(testcase);
    return 0;
}

ListNode *addin(ListNode *l1, int target) {
    return 
}