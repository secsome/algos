/*
* UPDATE ON 11/18/2020
* Commitments updated.
*/

/*
* A* path-finding algorithm
* 
* 0. About the data structure
*   Consider to use a set as open_set, and another unordered_set as the close_set
* 
* 1. Add the start point into open_set
*   open_set.insert(start_point);
* 
* 2. Main Process
*   Loop while:
*       open_set is not empty AND cur_point is not the dest_point
*   Do:
*       1) Get the node owns least 'F' value from open_set
*           cur_point = open_set.first();
* 
*       2) Put this node into close_set
*           close_set.insert(cur_point);
*           open_set.erase(cur_point);
* 
*       3) For each node adjacent to this cur_point:
*           if(adj_point is not reachable OR adj_point exists in close_set)
*               continue;
*           else
*               if (adj_point exists in open_set)
*                   Compare the existed value with this new value, and update it if current one is better
*               else
*                   Add adj_point into open_set and update it's values
* 
* 3. Save the path, iterate from the dest_point to start_point, that's the path we are finding.
* 
* What is 'F' ?
* F = G + H
* G = the cost of movement from start_point
* H = the estimate cost from cur_point to dest_point 
* It's really important to select a good function for H,
* for a bad function would lead  to a bad result.
* For example, we can use Manhattan distance as H.
*
* In fact, A* just works as Dijkstra with heap and also BFS search,
* the only difference between them is the "value", called 'F' in A*.
* That's what we exactly improved:
*   In a large map we need higher effeciency and an estimate
*   value can help make our algorithm runs fast in averange.
*
* A* works well in a static map field, for it searchs from the
* starting point to the destination point, and a little change
* occured on the map may cause "replan", which will take a lot
* of time. So when the map is dynamic, consider to use D* algo
* which is also known as Dynamic A Star Algorithm to find the
* path.
*
* -- SEC_SOME 11/18/2020
*/

// Just for example, this might be an example for how we store the data.
#include <set>
#include <unordered_set>

union CoordStruct
{
    struct {
        int X, Y;
    };
    int Data[2];
};

std::set<CoordStruct> OpenSet;
std::unordered_set<CoordStruct> CloseSet;