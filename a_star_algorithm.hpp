/*
* A* path-finding algorithm
* 
* 0. About the data structure
*   Consider to use a set as open_list, and another set as the close_list
* 
* 1. Add the start point into open_list
*   open_list.insert(start_point);
* 
* 2. Main Process
*   Loop while:
*       open_list is not empty AND cur_point is not the dest_point
*   Do:
*       1) Get the node owns least 'F' value from open_list
*           cur_point = open_list.first();
* 
*       2) Put this node into close_list
*           close_list.insert(cur_point);
*           open_list.erase(cur_point);
* 
*       3) For each node adjacent to this cur_point:
*           if(adj_point is not reachable OR adj_point exists in close_list)
*               continue;
*           else
*               if (adj_point exists in open_list)
*                   Compare the existed value with this new value, and update it if current one is better
*               else
*                   Add adj_point into open_list and update it's values
* 
* 3. Save the path, from the dest_point to start_point, that's the path we are finding.
* 
* What is 'F' ?
* F = G + H
* G = the cost of movement from start_point
* H = the estimate cost from cur_point to dest_point
* 
* It's really important to select a good function for H,
* for a bad function would lead  to a bad result.
* For example, we can use Manhattan distance as H.
* 
* -- SEC_SOME 11/18/2020
*/



// Just for example, this might be an example for how we store the data.
#include <set>

union CoordStruct
{
    struct {
        int X, Y;
    };
    int Data[2];
};

std::set<CoordStruct> OpenList, CloseList;