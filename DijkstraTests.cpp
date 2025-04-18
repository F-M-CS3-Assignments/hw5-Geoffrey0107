#include "Graph.h"
#include "BetterPriorityQueue.h"
#include "Dijkstra.h"

#include <iostream>
#include <cassert>

using namespace std;


int DijkstraTest(){
	cout << "Testing Dijkstra Algorithm..." << endl;
	
	// Test 1: graph from assignment
	Graph *g = new Graph();
	
	g->AddNode(1);
	g->AddNode(2);
	g->AddNode(3);
	g->AddNode(4);
	g->AddNode(5);
	g->AddNode(6);
	
	g->AddEdge(1, 2, 7);
	g->AddEdge(2, 1, 7);
	g->AddEdge(1, 3, 9);
	g->AddEdge(3, 1, 9);
	g->AddEdge(1, 6, 14);
	g->AddEdge(6, 1, 14);
	
	g->AddEdge(2, 3, 10);
	g->AddEdge(3, 2, 10);
	g->AddEdge(2, 4, 15);
	g->AddEdge(4, 2, 15);
	
	g->AddEdge(3, 6, 2);
	g->AddEdge(6, 3, 2);
	g->AddEdge(3, 4, 11);
	g->AddEdge(4, 3, 11);
	
	g->AddEdge(6, 5, 9);
	g->AddEdge(5, 6, 9);
	
	g->AddEdge(4, 5, 6);
	g->AddEdge(5, 4, 6);
	
	cout <<  "---Graph---" << endl;
	cout << "\tnodes: " << g->NodesToString() << endl;
	cout << "\tedges: " << g->EdgesToString() << endl;
	cout << "---Graph---" << endl << endl;

	nodekey_t start = 1;
	nodekey_t end = 5;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	int ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 20);

	delete g;
	
	cout << "DONE Testing Dijkstra Algorithm" << endl;
	
	return ans;
}


void MoreDijkstraTests(){
	cout << "Deep Testing Dijkstra Algorithm..." << endl;

	// Test 2: Graph with disconnected nodes
	Graph* g2 = new Graph();
	g2->AddNode(1);
	g2->AddNode(2);
	g2->AddNode(3); // No connection to or from node 3

	g2->AddEdge(1, 2, 5);
	g2->AddEdge(2, 1, 5);

	cout << "Test 2 (Disconnected Node): 1 to 3 should be unreachable" << endl;
	int dist = dijkstra(1, 3, g2);
	cout << "Distance: " << dist << endl;
	assert(dist == -1); // unreachable

	delete g2;

	// Test 3: All nodes connected in a straight line
	Graph* g3 = new Graph();
	for(int i = 1; i <= 5; i++) g3->AddNode(i);
	g3->AddEdge(1, 2, 1);
	g3->AddEdge(2, 3, 1);
	g3->AddEdge(3, 4, 1);
	g3->AddEdge(4, 5, 1);

	cout << "Test 3 (Linear Path): 1 to 5 should have total cost 4" << endl;
	int d2 = dijkstra(1, 5, g3);
	cout << "Distance: " << d2 << endl;
	assert(d2 == 4);

	delete g3;

	// Test 4 (Cycle):
	Graph* g4 = new Graph();
	g4->AddNode(1);
	g4->AddNode(2);
	g4->AddNode(3);
	g4->AddEdge(1, 2, 5);
	g4->AddEdge(2, 3, 5);
	g4->AddEdge(3, 1, 5); // closes the loop

	int dist4 = dijkstra(1, 3, g4);
	cout << "Test 4 (Cycle) distance=  " << dist4 << endl;
	assert(dist4 == 10); 

	delete g4;

	// Test 5 (Start == End): Distance from 42 to 42 =0
	Graph* g5 = new Graph();
	g5->AddNode(42);

	int dist5 = dijkstra(42, 42, g5);
	cout << "Test 5 (Start == End): Distance from 42 to 42 = " << dist5 << endl;
	assert(dist5 == 0);

	delete g5;

		
	cout << "DONE Deep Testing Dijkstra Algorithm" << endl;
}


int main(){
	
	DijkstraTest(); // this one by itself tests the graph on the assignment
	cout << endl;
	MoreDijkstraTests();
	cout << endl;
	cout << "ALL TESTS PASSED!" << endl;

	return 0;
}
