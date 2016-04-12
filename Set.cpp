#include "Set.hpp"

Set::Set(Graph* graph) {
	_graph = graph;
	for (auto itr = graph->totalVertices.begin(); itr != graph->totalVertices.end(); itr++) {
		heap.push_back(&(*itr));
	}
	make_heap(heap.begin(), heap.end(), hasLessNeighbors());
}

//O(n)
void Set::buildIndependantSet() {
	while (_graph->numberFlagged < _graph->totalVertices.size()) {
		
		if (heap.front()->isDiscoverable) {
			set.push_back(heap.front());

			_graph->flagVertexAndNeighbours(heap.front());
		}
		pop_heap(heap.begin(), heap.end(), hasLessNeighbors());
                heap.pop_back();

	}
}

void Set::printSet() {

	for (vector<Vertex*>::iterator it = set.begin(); it != set.end(); ++it)
	{
		cout << "Vertex-" << (*it)->vertexId << " ";
	}

	//for (auto itr = set.begin(); itr != set.end(); itr++) {
	//	cout << itr->vertexId << " ";
	//}
}
