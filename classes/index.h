#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>

#pragma once
using namespace std;

class Vertex;

class Edge {
	public:
		Vertex *start;
		Vertex *end;
		Edge();
};

class Vertex {
	public:
		string name;
		vector <Edge*> previous;
		vector <Edge*> next;
		Vertex(string = "default");
		void addPrevious(Edge *);
		void addNext(Edge *);
};

class Graph {
	public:
		vector <Vertex*> vertices;
		vector <Edge*> edges;
		Graph();
		Graph(const Graph &graph);
		Vertex * addVertex(string);
		Edge * addEdge(Vertex *, Vertex *);
		void save(string = "graph.txt");
		void load(string = "graph.txt");
	private:
		vector<string> split(const string &, const string &);
};