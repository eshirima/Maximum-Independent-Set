//
//  main.cpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "Graph.hpp"
#include "Edge.hpp"

using std::make_heap;
using std::pop_heap;
using std::push_heap;
using std::sort_heap;

int main(int argc, const char * argv[])
{
    Graph sampleGraph = *new Graph("Graph.txt");
    //sampleGraph.printGraph();
    
	//O(3n)
	make_heap(sampleGraph.totalVertices.begin(),sampleGraph.totalVertices.end(),hasLessNeighbors());

	sampleGraph.printGraph();

//    Vertex deleteVertex =  Vertex(2);
//    
//    cout << "*** DELETING VERTEX " << deleteVertex.vertexId << " ***"<< endl;
//    
//    sampleGraph.removeVertex(deleteVertex);
//    
//    sampleGraph.printVertices();
//    
//    sampleGraph.printEdges();
//    
//    sampleGraph.printGraph();
    
    return 0;
}
