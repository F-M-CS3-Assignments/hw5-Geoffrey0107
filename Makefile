graph-tests: Graph.cpp GraphTests.cpp
	g++ -Wall -g Graph.cpp GraphTests.cpp -o graph-tests

bpq-tests: Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp
	g++ -Wall -g Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests

dijkstra: Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp DijkstraTests.cpp
	g++ -Wall -g Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp DijkstraTests.cpp -o dijkstra

try: graph-tests bpq-tests dijkstra
	./graph-tests
	./bpq-tests
	./dijkstra
