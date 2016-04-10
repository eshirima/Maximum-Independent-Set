#include "Set.hpp"

//O(3n)
void Set::heapifyGraphVertices(std::vector<Vertex>* graphVertices) {
	make_heap(graphVertices->begin(), graphVertices->end(), hasLessNeighbors());
}


//O(n)
void Set::buildIndependantSet(Graph* graph) {
	while (!graph->totalVertices.empty()) {
		Vertex vertexHeapRoot = graph->totalVertices.front();
		//if(! vertexHeapRoot.isFlagged()){
		set.push_back(vertexHeapRoot);
		//vertexHeapRoot.flagNeighbors();
		//}
		heapifyGraphVertices(&(graph->totalVertices));
	}
}
