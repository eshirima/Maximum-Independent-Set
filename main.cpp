//
//  main.cpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "Graph.hpp"
#include "Edge.hpp"
#include "Set.hpp"

int main(int argc, const char * argv[])
{
    Graph sampleGraph = *new Graph("Graph copy.txt");
	cout << "Done reading file" << endl;
    //sampleGraph.printGraph();
    
    //Vertex deleteVertex =  Vertex(41406);
    
    //sampleGraph.flagVertexAndNeighbours(deleteVertex);
	int currentTime = time(nullptr);
	Set testSet(&sampleGraph);
	testSet.buildIndependantSet();
	std::cout << time(nullptr) - currentTime << std::endl;
	testSet.printSet();
    //sampleGraph.printVertices();
    
    return 0;
}
