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
    if (doesFileExist(fileName))
    {
        fstream fileStreamer(fileName);
        string fileLine; int count = 0;
        
        if (fileStreamer.good())
        {
            getline(fileStreamer, fileLine);
            int totalGraphVertices = stoi(fileLine);
            totalVertices.resize(totalGraphVertices);
            
            createVertices(totalGraphVertices);
            
            while (getline(fileStreamer, fileLine))
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
tuple<bool, vector<Vertex>::iterator> Graph::doesVertexExist(Vertex currentVertex)
{
    
    for (vector<Vertex>::iterator it = totalVertices.begin(); it != totalVertices.end(); ++it)
    {
        if (it->vertexId == currentVertex.vertexId) return std::make_tuple(true, it);
    }
    
    return std::make_tuple(false, totalVertices.end());
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
void Graph::flagVertexAndNeighbours(Vertex unwantedVertex)
{
    tuple<bool, vector<Vertex>::iterator> vertexResponse = doesVertexExist(unwantedVertex);
    
    if(get<0>(vertexResponse))
    {
        Vertex* unwantedVertexPointer = &totalVertices.at(distance(totalVertices.begin(), get<1>(vertexResponse)));
        unwantedVertexPointer->isDiscoverable = false;
		numberFlagged+=1;
        
        map<int, Vertex*>vertexNeighboursMap;
        
        // put vertex neigbours in a map
        for (vector<Edge>::iterator tempIterator = unwantedVertexPointer->edges.begin(); tempIterator != unwantedVertexPointer->edges.end(); ++tempIterator)
        {
            vertexNeighboursMap[tempIterator->start->vertexId] = tempIterator->start;
        }
        
        // flag the map vertices as not discoverable in the totalVertices
        for (vector<Vertex>::iterator tempIterator = totalVertices.begin(); tempIterator != totalVertices.end(); ++tempIterator)
        {
            if (vertexNeighboursMap.find(tempIterator->vertexId) != vertexNeighboursMap.end())
            {
                tempIterator->isDiscoverable = false;
				numberFlagged += 1;;
            }
        }
        
        vertexNeighboursMap.clear();
    }
    else
    {
        cerr << "Vertex " << unwantedVertex.vertexId << " does not exist" << endl << endl;
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