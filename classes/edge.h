#ifndef EDGE_H
#define EDGE_H

Edge::~Edge() {
	cout 
			<< "Edge with start in " 
			<< start->name 
			<< " and end in " 
			<< end->name 
			<< " has been removed" 
			<< endl;
};

#endif