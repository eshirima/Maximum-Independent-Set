//
//  Graph.cpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#include "Graph.hpp"

// O(N)
Graph::Graph(string fileName)
{
    //if (doesFileExist(fileName))
    {
       // fstream fileStreamer(fileName);
        string fileLine; int count = 0;
        
        //if (cin.good())
        {
            getline(std::cin, fileLine);
            int totalGraphVertices = stoi(fileLine);
            totalVertices.resize(totalGraphVertices);
            
            createVertices(totalGraphVertices);
            
            while (getline(std::cin, fileLine))
            {
                string tempString;
                stringstream stringStream(fileLine);
                vector<string> stringTokens;
                
                while (stringStream >> tempString) stringTokens.push_back(tempString);
                
                Vertex* currentVertexPointer = &totalVertices.at(count);
                
                for (vector<string>::iterator it = stringTokens.begin() + 1; it != stringTokens.end(); ++it)
                {
                    int thisVertexId = stoi(*it);
                    Vertex* tempVertexPointer = &totalVertices.at(thisVertexId);
                    Edge tempEdge = Edge(currentVertexPointer, tempVertexPointer);
                    totalVertices.at(thisVertexId).edges.push_back(tempEdge);
                    allEdges.push_back(tempEdge);
                }
                
                ++count;
            }
        }
    }
}

// O(1)
bool Graph::doesFileExist(string fileName)
{
    fstream fileStreamer(fileName);
    
    if (fileStreamer.is_open())
    {
        fileStreamer.close();
        return true;
    }
    
    else
    {
        std::cerr << fileName << ": " << std::strerror(errno) << endl;
        fileStreamer.close();
        return  false;
    }
}

// O(|V|)
void Graph::createVertices(int numberOfVertices)
{
    for (int i = 0; i < numberOfVertices; ++i)
    {
        Vertex tempVertex = Vertex(i);
        totalVertices.at(i) = Vertex(i);
    }
}

// O(|V|)
void Graph::flagVertexAndNeighbours(Vertex* unwantedVertex)
{
    if(unwantedVertex->isDiscoverable)
    {
        unwantedVertex->isDiscoverable = false;
		numberFlagged += 1;
        
        for (vector<Edge>::iterator tempIterator = unwantedVertex->edges.begin(); tempIterator != unwantedVertex->edges.end(); ++tempIterator)
        {
            Vertex* vertexNeighbour = &totalVertices[tempIterator->start->vertexId];

            if (vertexNeighbour->isDiscoverable)
            {
                vertexNeighbour->isDiscoverable = false;
				numberFlagged += 1;;
            }
        }
    }
}

// O(N squared) or O(|V||E|)
void Graph::printGraph()
{
    for (auto vertex : totalVertices)
    {
        if (vertex.vertexId == JUNK) continue;
        
        cout << vertex.vertexId << ":";
        Vertex* pointerVertex = &vertex;
        
        for (auto neighbours : vertex.edges)
        {
            cout << "-->" << (neighbours.start != pointerVertex ? neighbours.start->vertexId : neighbours.end->vertexId);
        }
        
        cout << endl;
    }
    
    cout << endl;
}

// O(|V|)
void Graph::printVertices()
{
    for (auto thisVertex: totalVertices)
    {
        if (thisVertex.vertexId != JUNK)
        {
//            cout << thisVertex.vertexId << endl;
            cout << "Vertex ID: " << thisVertex.vertexId << " Status: " << thisVertex.isDiscoverable << endl;
        }
    }
    
    cout << endl;
}

// O(|E|)
void Graph::printEdges()
{
    for (auto thisEdge: allEdges)
    {
        cout << "Start: " << thisEdge.start->vertexId << " End: " << thisEdge.end->vertexId << endl;
    }
    
    cout << endl;
}