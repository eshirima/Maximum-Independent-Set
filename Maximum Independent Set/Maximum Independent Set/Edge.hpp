//
//  Edge.hpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include "Vertex.hpp"

class Vertex;

class Edge
{
public:
    
    Edge();
    Edge(Vertex*, Vertex*);
    Vertex otherSide(Vertex*);
    Vertex *start, *end;
    
};

#endif /* Edge_hpp */
