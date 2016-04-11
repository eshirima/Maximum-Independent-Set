#ifndef SET_HPP
#define SET_HPP

#include <vector>
#include <algorithm>

#include "Graph.hpp"

struct hasLessNeighbors {
	bool operator()(const Vertex* v1, const Vertex* v2)const {
		return v1->edges.size() > v2->edges.size();
	}
};


class Set {
public:
	Set(Graph*);
	
	void buildIndependantSet();
	void printSet();

private:
	Graph* _graph;
	std::vector<Vertex*> heap;
	std::vector<Vertex*> set;

};

#endif
