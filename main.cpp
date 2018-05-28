#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

#include "classes/index.h"

int main() {
	Graph graph;

	graph.load();
	//Vertex v70 = graph.addVertex("70");
	//Vertex v80 = graph.addVertex("80");

	//graph.addEdge(v70, v80);

	graph.save();

	return 0;
}