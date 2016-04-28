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
//	String file;
	//std::cout << "Enter graph name: ";
		//std::cin >> file;

    Graph sampleGraph = *new Graph("");
    
	size_t currentTime = clock();
	Set testSet(&sampleGraph);
	testSet.buildIndependantSet(); // O(E + V log V)
	printf("Time taken: %.2fs\n", (double)(clock() - currentTime)/CLOCKS_PER_SEC);
	testSet.printSet();
    
    return 0;
}
