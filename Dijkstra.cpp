#include "Graph.h"
#include "BetterPriorityQueue.h"
#include "Dijkstra.h"

// Time Complexity:
// n is the number of node and e the number of edges in the graph.
// Insertion and pop: O(log n)
// Contains and Update: O(n)
// BetterPriorityQueue::Update() loops through the entire vector to find the node that matches.
// For each node, we check its neighbors (e, total edges)
// Total: O(n*e) in the worst case due to linear update searches.

int dijkstra(nodekey_t start, nodekey_t end, const Graph *g){
    BetterPriorityQueue q;
    BPQNode startNode;
    startNode.gnode = start;
    startNode.pri = 0;
    set<nodekey_t> visited;
    q.push(startNode);
    while(!q.empty()){
        // get node with smallest priority, the way how BPQ is structured, smaller pri nodes come out first.
        BPQNode curr = q.top();
        q.pop();
        // iteration is at the destination, return the distance.
        if (curr.gnode == end){
            return curr.pri;
        }
        else if(visited.count(curr.gnode)){
            continue;
        }
        visited.insert(curr.gnode);
        set<const GraphEdge*> neighbors = g->GetOutwardEdgesFrom(curr.gnode);
        //https://www.geeksforgeeks.org/different-ways-to-iterate-over-a-set-in-c/
        // iterating over a set. 
        for(const GraphEdge* edge : neighbors){
            nodekey_t neighbor = edge->to;
            unsigned int w = edge->weight;
            // new distance is previous distance to this node and the current distance
            unsigned int newDist = curr.pri + w;
            BPQNode neighborNode;
            neighborNode.gnode = neighbor;
            neighborNode.pri = newDist;
            // push or update the queue with the new distance
            if (q.Contains(neighborNode)) {
                q.Update(neighborNode);
            } else {
                q.push(neighborNode);
            }
        }
    }
    return -1;
}