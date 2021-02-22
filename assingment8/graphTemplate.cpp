#include <bits/stdc++.h>
using namespace std;

class UndirectedGraph
{
private:
	int V;
	list<int> *adj;
public:
	UndirectedGraph(int V)
	{
		this->V = V;
		this->adj = new list<int>[this->V];
	}

	// add an edge
	void addEdge(int source, int destination)
	{
		if (source >= this->V || destination >= this->V)
			return;
		this->adj[source].push_back(destination);
		this->adj[destination].push_back(source);
	}

	// remove an edge
	void removeEdge(int source, int destination)
	{
		if (source >= this->V || destination >= this->V)
			return;
		auto itr1 = find(this->adj[source].begin(), this->adj[source].end(), destination);
		this->adj[source].erase(itr1);

		auto itr2 = find(this->adj[destination].begin(), this->adj[destination].end(), source);
		this->adj[destination].erase(itr2);
	}

	// traverse
	void printGraph()
	{
		for (int v = 0; v < this->V; v++)
		{
			cout << "0 -> ";
			for (auto itr = this->adj[v].begin(); itr != this->adj[v].end(); itr++)
			{
				cout << *itr << "-> ";
			}
			cout << endl;
		}
	}

};

int main()
{
	UndirectedGraph ug(7);
	ug.addEdge(0, 1);
	ug.addEdge(1, 2);
	ug.addEdge(2, 3);
	ug.addEdge(3, 4);
	ug.addEdge(3, 6);
	ug.addEdge(6, 2);
	ug.addEdge(6, 5);
	ug.printGraph();
	return 0;
}