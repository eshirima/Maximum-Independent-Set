#ifndef SET_HPP
#define SET_HPP

#include <vector>
#include <algorithm>

#include "Graph.hpp"

struct hasLessNeighbors {
	bool operator()(const Vertex v1, const Vertex v2)const {
		return v1.edges.size() > v2.edges.size();
	}
};


class Set {
public:
	Set() {};
	
	void buildIndependantSet(Graph* graph);
	void heapifyGraphVertices(std::vector<Vertex>* graphVertices);

private:
	std::vector<Vertex> set;

};

#endif
