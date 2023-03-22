#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "Edge.h"
#include "Node.h"

using namespace std;

Node::Node(char node) {
	label = node;
	visited = false;
}

void Node::addNeighbor(Edge* e) {
	neighbors.push_back(e);
}

Edge::Edge(Node* node1, Node* node2, int w) {
	n1 = n1;
	n2 = n2;
	weight = w;
}

vector<Edge*> bucket;
map<char, Node*> nodes;

//void mstPrim(Node* start) {
//	start->visited = true;
//	vector<Edge*> mstEdges;
//	int totalWeight = 0;
//	for (Edge* e : start->neighbor) {
//		bucket.push_back(e);
//	}
//	Edge* e = getBestEdge();
//	while (e != nullptr)
//	{
//		Node* node1 = e->n1;
//		Node* node2 = e->n2;
//		node1->visited = true;
//		node2->visited = true;
//		totalWeight += e->weight;
//		for (Edge* e : node1->neighbor) {
//			bucket.push_back(e);
//		}
//		for (Edge* e : node2->neighbor) {
//			bucket.push_back(e);
//		}
//		e = getBestEdge();
//	}
//	cout << "MST has a weight of " << totalWeight << "and consists of these edges: " << endl;
//	
//
//}
//
//Edge* getBestEdge() {
//	Edge* best = nullptr;
//	while (best == nullptr && bucket.size() != 0)
//	{
//		best = bucket[0];
//		int bestIndex = 0;
//		for (int i = 1; i < bucket.size(); i++)
//		{
//			Edge* e = bucket[i];
//			if (e->weight < best->weight)
//			{
//				best = e;
//				bestIndex = i;
//				e->n2->visited = true;
//			}
//		}
//		if (best->n1->visited && best->n2->visited)
//		{
//			bucket.erase(bucket.begin() + bestIndex);
//		}
//	}
//	return best;
//}

int main(int argc, char** argv) {
	// handles missing command - line parameters and "file-not-found" errors.
	if (argc == 1) {
		cout << "You forgot the command line parameter" << endl;
		exit(0);
	}
	ifstream ifs;
	ifs.open(argv[1], ios::in);
	if (!ifs) {
		cout << "could not find file " << argv[1] << endl;
		exit(0);
	}
	// checks the first line of the file to determine the node names.
	// getline gets the first line from the ifstream and stores it into a string variable.
	string nodeNames;
	getline(ifs, nodeNames);
	string secondLine;
	getline(ifs, secondLine);
	int numLines = stoi(secondLine);

	string nodeName1;
	string nodeName2;
	string tmp;
	int weight;
	for (int i = 0; i < numLines; i++)
	{
		getline(ifs, nodeName1, ' ');
		getline(ifs, nodeName2, ' ');
		getline(ifs, tmp);
		weight = stoi(tmp);
		cout << nodeName1 << " - " << weight << " - " << nodeName2 << endl;
		Node* n1 = nodes[nodeName1[0]];
		Node* n2 = nodes[nodeName2[0]];
		Edge* edge = new Edge(n1, n2, weight);
		bucket.push_back(edge);
		n1->addNeighbor(edge);
		n2->addNeighbor(edge);
	}
}