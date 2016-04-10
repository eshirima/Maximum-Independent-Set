//
//  main.cpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"
#include "Edge.hpp"

int main(int argc, const char * argv[])
{
    Graph sampleGraph = *new Graph("Graph.txt");
    sampleGraph.printGraph();
    
    Vertex deleteVertex =  Vertex(41406);
    
    sampleGraph.flagVertexAndNeighbours(deleteVertex);
    
    sampleGraph.printVertices();
    
    return 0;
}
