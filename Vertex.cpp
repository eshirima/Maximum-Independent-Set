//
//  Vertex.cpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#include "Vertex.hpp"

Vertex::Vertex()
{
    vertexId = JUNK;
    isDiscoverable = true;
}

Vertex::Vertex(int info, bool vertexStatus)
{
    vertexId = info;
    isDiscoverable = vertexStatus;
}