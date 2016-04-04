//
//  Graph.cpp
//  Maximum Independent Set
//
//  Created by Emil Shirima on 4/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#include "Graph.hpp"

// O(n squared)
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
// TODO: Fix the adjacency bug
void Graph::removeVertex(Vertex unwantedVertex)
{
    tuple<bool, vector<Vertex>::iterator> vertexResponse = doesVertexExist(unwantedVertex);
    
    if (get<0>(vertexResponse))
    {
        Vertex* unwantedVertexPointer = &totalVertices.at(distance(totalVertices.begin(), get<1>(vertexResponse)));
        
        // METHOD I: Iterate through all the edges finding the unwanted one
        unwantedVertexPointer->edges.clear();
        
        for (vector<Edge>::iterator it = allEdges.begin(); it != allEdges.end(); ++it)
        {
            if (it->start->vertexId == unwantedVertexPointer->vertexId)
            {
                allEdges.erase(it);
            }
            else if (it->end->vertexId == unwantedVertexPointer->vertexId)
            {
                allEdges.erase(it);
            }
        }
        
        // METHOD II: Use the unwanted vertex's edges to delete it.
        // TODO: Doesn't fully work for the time being
        
//        int currentPosition = 0;
//        for (vector<Edge>::iterator it = unwantedVertexPointer->edges.begin(); it != unwantedVertexPointer->edges.end(); ++it)
//        {
//            cout << "Other Side of the edge " << it->otherSide(unwantedVertexPointer).vertexId << endl;
//            it->otherSide(unwantedVertexPointer).edges.erase(unwantedVertexPointer->edges.begin() + currentPosition);
//            allEdges.erase(it);
//            ++currentPosition;
//        }
        
        totalVertices.erase(totalVertices.begin() + distance(totalVertices.begin(), get<1>(vertexResponse)));
    }
    
    else
    {
        cerr << endl << endl << "Vertex " << unwantedVertex.vertexId << " does not exist in the graph" << endl << endl;
    }
}

// O(n squared) or O(|V||E|)
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
            cout << thisVertex.vertexId << endl;
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