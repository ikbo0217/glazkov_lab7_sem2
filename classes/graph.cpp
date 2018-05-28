#include "index.h"

Graph::Graph() {
	vertices.clear();
	edges.clear();
};

Graph::Graph(const Graph &graph) {
	vertices = graph.vertices;
	edges = graph.edges;
};

Vertex * Graph::addVertex(string name) {
	for(int i = 0; i < vertices.size(); i++) {
		if(vertices[i]->name == name) {
			cout << "Returning existing Vertex " << vertices[i]->name << endl;
			return vertices[i];
		}
	}

	vertices.push_back(new Vertex(name));
	return vertices[vertices.size() - 1];
};

Edge * Graph::addEdge(Vertex *start, Vertex *end) {
	edges.push_back(new Edge());

	int size = edges.size() - 1;

	edges[size]->start = start;
	edges[size]->end = end;

	edges[size]->start->addNext(edges[size]);
	edges[size]->end->addPrevious(edges[size]);

	cout << edges[size]->start->name << "-" << edges[size]->end->name << endl;

	return edges[size];
};

void Graph::save(string filename) {
	ofstream out(filename);

	string data = "";

	for(int i = 0; i < edges.size(); i++) {
		cout << "start" << (void*)edges[i]->start << endl;
		cout << edges[i]->start->name << "-" << edges[i]->end->name  << endl;
		data += edges[i]->start->name + "-" + edges[i]->end->name + "\n";
	}

	for(int i = 0; i < vertices.size(); i++) {
		if(vertices[i]->next.size() == 0 && vertices[i]->previous.size() == 0) {
			data += vertices[i]->name + "\n";
		}
	}

	cout << data;

	out << data;

	out.close();
};

void Graph::load(string filename) {
	ifstream in(filename);

	string line;
	int i = 0; 

	vertices.clear();
	edges.clear();

	while(getline(in, line)) {
		cout << "line " << line << endl;
		i++;

		vector<string> v = split(line, "-");

		if(v.size() == 2) {
			cout << "v1 " << v[0] << " v2 " << v[1] << endl;
			Vertex *start = addVertex(v[0]);
			Vertex *end = addVertex(v[1]);

			cout << (void*)start << endl;


			addEdge(start, end);
		}

		if(v.size() == 1) {
			addVertex(v[0]);
		}
	}

	cout << "total vertices: " << vertices.size() << endl;
	cout << "total edges: " << edges.size() << endl;
};

vector<string> Graph::split(const string &s, const string &c) {
	vector<string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = s.find(c, prev);
    if (pos == string::npos) pos = s.length();
    string token = s.substr(prev, pos-prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + c.length();
  }
  while (pos < s.length() && prev < s.length());
  return tokens;
};
