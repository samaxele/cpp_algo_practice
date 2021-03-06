// my custom header
#pragma once

/*
Basic IO
*/
#include <iostream>

/*
Containers library
*/
#include <vector>
#include <map>
#include <unordered_map>

/*
General utilities library
random() can call with time.h (init = srand(time(NULL))
*/
#include <string>
#include <time.h>
#include <ctime>
#include <chrono>

/*
Numerics library
*/
#include <algorithm>
#include <math.h>

/*
Threads support library
*/
#include <thread>
#include <mutex>


// using namespace std;     //not a good habit for using
/**
 * "using namespace" will import & simplify the calling of library fn
 * such as 'cout' instead of 'std::cout'
 * but if this extends to user library, this may impose problems when upgradiing
 * example:
 * foo.h has a function add() which call foo::add()
 * bar.h has a function sum() whcih call bar::sum()
 * 
 * "using namespace 'foo'" -> consist a function named sum()
 * "using namespace 'bar'" -> consist a function named add()
 * you may call sum() or add() without problem until an occasion where foo updated to foo 2.0 and 
 * new function add() added that happens to share the same name from bar.h 
 * now you have add() exist in foo.h and bar.h, this will take some time to fix especially if the
 * program is complex.
 * 
 * one good fix is to call the entire namespace so everyone knows where the fn coming from
 * 
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode (int x) : val(x), next(nullptr) {};
};

ListNode *genListNode(std::vector<int> x) {
    ListNode *head, *tail;
    tail = new ListNode(0);
    head = tail; 
    int size = x.size();
    if (0 == size) {return nullptr;}
    for (int i=0; i<size; i++) {
        tail->next = new ListNode(x[i]);
        tail = tail->next;
    }
    return head->next;
}

ListNode *genListNode(std::string str) {
    auto it = str.begin();
    ListNode *tail = new ListNode(0);
    ListNode *ans = tail;
    while (it != str.end()) {
        tail->next = new ListNode(*it);
        tail = tail->next;
        it++;
    }
    return ans->next;
}

void printList (ListNode *l1) {
    while(l1) {
        std::cout << l1->val << " > ";
        l1 = l1->next;
    }
    std::cout << "\b\b  \n";
}

void printList (int &l1) {
    std::cout << l1 << std::endl;
}

void printList (std::vector<int> &vec) {
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end()) {   //only listnode can use nullptr
        std::cout << *it << " > ";
        it++;
    }
    std::cout << "null\n";
} 

void printList (std::vector<unsigned int> &vec) {
    for (auto x : vec) {
        std::cout << x << " > ";
    }
    std::cout << "\b\b  \n";
}