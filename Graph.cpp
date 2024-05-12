/*
lidor mondel
207478256
lidormon20@gmail.com
*/




#include "Graph.hpp"

using namespace ariel;

//2
// Load the graph
void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {

    for(unsigned int i = 0; i < graph.size(); i++){
        if (graph.size() != graph[i].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

		if (graph[i][i] != 0){
			throw invalid_argument("Invalid graph.");
		}
    }
    adj_mat = graph;
}

string Graph::printGraph() const {
    int num_edges = 0;

    for (const auto& edge : adj_mat) {
        for (int num : edge) {
            if (num != 0) {
                num_edges++;
            }
        }
    }

    string result = "Graph with " + std::to_string(adj_mat.size()) + " vertices and " + to_string(num_edges) + " edges.";
    return result;
}

unsigned int Graph::size() const{
    return adj_mat.size();
}


const int Graph::getEdge(unsigned int x, unsigned int y) const{

    if (x >= adj_mat.size() || y >= adj_mat[0].size()) {
        throw out_of_range("Invalid :Index out of range ");
    }

    return adj_mat[x][y];
}

void Graph::transposeGraph() {
    for (size_t i = 0; i < adj_mat.size(); i++) {
        for (size_t j = i + 1; j < adj_mat.size(); j++) {

            // Swap elements at position (i, j) and (j, i)
            int temp = adj_mat[i][j];
            adj_mat[i][j] = adj_mat[j][i];
            adj_mat[j][i] = temp;
        }
    }
}
const vector<vector<int>> &Graph::getGraph() const
{
    return this->adj_mat;
}

vector<unsigned int> Graph::get_voisin(unsigned int vertex) const {

    vector<unsigned int> voisins;
   
    if (vertex >= adj_mat.size()) {
        throw out_of_range("Inavlid: Index out of range");
    }

    const vector<int>& num_edges = adj_mat[vertex];
    for (unsigned int i = 0; i < num_edges.size(); ++i) {
        if (num_edges[i] != 0) {
            voisins.push_back(i);
        }
    }

    return voisins;
}


