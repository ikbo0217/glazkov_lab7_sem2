#ifndef GRAPH_H
#define GRAPH_H

Graph::Graph() {
	vertices.clear();
	edges.clear();
};

Graph::Graph(const Graph &graph) {
	vertices = graph.vertices;
	edges = graph.edges;
};

Graph::~Graph() {
	cout << "Graph has been removed" << endl;
};

Vertex Graph::addVertex(string name) {
	Vertex vertex(name);
	vertices.push_back(vertex);

	return vertex;
};

Edge Graph::addEdge(Vertex start, Vertex end) {
	Edge edge;

	start.addNext(edge);
	end.addPrevious(edge);

	edges.push_back(edge);

	return edge;
};

void Graph::save(string filename) {
	ofstream out(filename);

	for(int i = 0; i < edges.size(); i++) {
		out << edges[i].start->name << "-" << edges[i].end->name << endl;
	}

	for(int i = 0; i < vertices.size(); i++) {
		if(vertices[i].next.size() == 0) {
			out << vertices[i].name << endl;
		}
	}

	out.close();
};

void Graph::load(string filename) {
	ifstream in(filename);

	const string data((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());

	vertices.clear();
	edges.clear();

	vector<string> v = split(data, "\n");

	for(int i = 0; i < v.size(); i++) {
		vector<string> vv = split(v[i], "-");

		if(vv.size() == 2) {
			Vertex start = addVertex(vv[0]);
			Vertex end = addVertex(vv[1]);

			addEdge(start, end);
		}

		if(vv.size() == 1) {
			addVertex(vv[0]);
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

#endif