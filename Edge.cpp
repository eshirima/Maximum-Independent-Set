//
//  Edge.cpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#include "Edge.hpp"

Edge::Edge()
{
    start = nullptr;
    end = nullptr;
}

Edge::Edge(Vertex* first, Vertex* second)
{
    start = first;
    end = second;
}

Vertex Edge::otherSide(Vertex* currentVertex)
{
    if (currentVertex->vertexId == start->vertexId) return *end;
    
    return *start;
}