/*
lidor mondel
207478256
lidormon20@gmail.com
*/


#pragma once

#include "Graph.hpp"
#include <unordered_set> 
#include <limits>
#include <queue>

using namespace std;
const int INF = numeric_limits<int>::max();

//2
namespace ariel {
    class Algorithms {
    public:
       
        static bool isConnected(Graph& graph);
        static string shortestPath(const Graph& graph, unsigned int start, unsigned int end);
        static bool isBipartite(const Graph& graph);
        static string negativeCycle(const Graph& graph);
        static string isContainsCycle(const Graph& graph);
        
    private:
        static bool dfs_for_cycle(unsigned int node, unsigned int parentNode, const Graph& graph, vector<bool>& visited, vector<unsigned int>& parent, string& cyclePath);
        static void DFS(const Graph& graph, unsigned int v, vector<bool>& visited);
        static bool help_bipartite(size_t start, const vector<vector<int>> &graph, vector<size_t> &colors, vector<vector<size_t>> &groups);
        
    };
}
