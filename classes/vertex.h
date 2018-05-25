#ifndef VERTEX_H
#define VERTEX_H

Vertex::Vertex(string NAME) {
	name = NAME;
};

Edge Vertex::addPrevious(Edge edge) {
	previous.push_back(edge);
	edge.end = this;

	return edge;
};

Edge Vertex::addNext(Edge edge) {
	next.push_back(edge);
	edge.start = this;

	return edge;
};

Edge Vertex::createPrevious() {
	Edge edge;

	addPrevious(edge);

	return edge;
};

Edge Vertex::createNext() {
	Edge edge;

	addPrevious(edge);

	return edge;
};

Vertex::~Vertex() {
	cout << "Vertex " << name << " has been removed" << endl;
};

#endif