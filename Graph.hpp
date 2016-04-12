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
#include <map>

using std::vector; using std::fstream;
using std::string; using std::getline;
using std::cout; using std::stoi;
using std::stringstream; using std::endl;
using std::find; using std::tuple;
using std::get; using std::distance;
using std::cerr; using std::map;

class Graph
{
public:
    
    Graph(string);
    bool doesFileExist(string);
    void createVertices(int);
    void flagVertexAndNeighbours(Vertex*);
    
    // MARK: Print Functions
    void printGraph();
    void printVertices();
    void printEdges();
    
	vector<Vertex> totalVertices;
	int numberFlagged = 0;

private:
    vector<Edge> allEdges;
};

#endif /* Graph_hpp */
