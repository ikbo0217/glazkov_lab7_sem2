#ifndef INDEX_H
#define INDEX_H

class Vertex;

class Edge {
	public:
		Vertex *start;
		Vertex *end;
		Edge();
		virtual ~Edge();
};

class Vertex {
	public:
		string name;
		vector <Edge> previous;
		vector <Edge> next;
		Vertex(string = "default");
		Edge addPrevious(Edge);
		Edge addNext(Edge);
		Edge createPrevious();
		Edge createNext();
		virtual ~Vertex();
};

class Graph {
	public:
		vector <Vertex> vertices;
		vector <Edge> edges;
		Graph();
		Graph(const Graph &graph);
		virtual ~Graph();
		Vertex addVertex(string name);
		Edge addEdge(Vertex start, Vertex end);
		void save(string = "graph.txt");
		void load(string = "graph.txt");
	private:
		vector<string> split(const string &, const string &);
};

#include "edge.h"
#include "vertex.h"
#include "graph.h"

#endif