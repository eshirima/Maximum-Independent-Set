//
//  Vertex.hpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#define JUNK -1

#include <vector>
#include "Edge.hpp"

using std::vector;
class Edge;

class Vertex
{
public:
    
    Vertex();
    Vertex(int, bool vertexStatus = true);
    
    int vertexId;
    bool isDiscoverable;
    vector<Edge> edges;
};

#endif /* Vertex_hpp */
