/*
lidor mondel
207478256
lidormon20@gmail.com
*/



#pragma once

#include <iostream>
#include <vector>

using namespace std;
//2
namespace ariel{
    class Graph{
    //adjacent matrix
        vector<vector<int>> adj_mat; 

    public:
        /**
         * loads a new graph from an adjacency matrix.
         */
        void loadGraph(const vector<vector<int>>& graph);
        string printGraph() const;
        void transposeGraph();
        unsigned int size() const;
        const int getEdge(unsigned int x, unsigned int y) const;
        vector<unsigned int> get_voisin(unsigned int vertex) const;
        const vector<vector<int>> &getGraph() const;
        
    
    };
}
