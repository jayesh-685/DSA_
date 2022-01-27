#include "bits/stdc++.h"
using namespace std;

/* Problem: You are given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Example 1: Consider the following 3 activities sorted by
finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The 
maximum set of activities that can be executed 
is {0, 2} [ These are indexes in start[] and 
finish[] ]

Example 2: Consider the following 6 activities 
sorted by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and 
finish[] ]

The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.

To do this:
Sort the activities according to their finishing time.
Select the first activity from the sorted array and print it.
Do following for remaining activities in the sorted array.
If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.

Proof that first activity is always selected in the optimal solution:
Consider a set s1, having n elements, which includes first activity and set s2, having m elements, which doesn't include first activity
if s2 is the better solution, then m > n
if we exclude the first element of s2 then no of elements in s2 = m-1 and since first element of s1 will always be less than first element of s2, it can be replaced with first element of s1 which means that m-1 + 1 = n i.e m = n which contradicts our assumption */