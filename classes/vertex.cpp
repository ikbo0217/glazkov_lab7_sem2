#include "index.h"

Vertex::Vertex(string NAME) {
	name = NAME;
};

void Vertex::addPrevious(Edge *edge) {
	previous.push_back(edge);
};

void Vertex::addNext(Edge *edge) {
	next.push_back(edge);
};