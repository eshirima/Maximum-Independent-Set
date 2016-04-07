//
//  Graph.hpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include "Vertex.hpp"
#include "Edge.hpp"

#include <iostream>
#include <fstream>
#include <cerrno> // throws a description of the error thrown by fstream
#include <string>
#include <sstream>
#include <tuple>

using std::vector; using std::fstream;
using std::string; using std::getline;
using std::cout; using std::stoi;
using std::stringstream; using std::endl;
using std::find; using std::tuple;
using std::get; using std::distance;
using std::cerr;


static struct hasLessNeighbors{
	bool operator()(const Vertex v1, const Vertex v2)const{
		return v1.edges.size() > v2.edges.size();
	}
};


class Graph
{
public:
    
    Graph(string);
    bool doesFileExist(string);
    tuple<bool, vector<Vertex>::iterator> doesVertexExist(Vertex);
    void createVertices(int);
    void removeVertex(Vertex); // TODO: Fix the other side of the edge bug
    void printGraph();
    void printVertices();
    void printEdges();
    
	vector<Vertex> totalVertices;

private:
    vector<Edge> allEdges;
};

#endif /* Graph_hpp */
