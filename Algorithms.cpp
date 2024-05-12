/*
lidor mondel
207478256
lidormon20@gmail.com
*/


#include "Algorithms.hpp"
#include <vector>
#include <climits>
#include <queue> 


using namespace ariel;

//2

bool Algorithms::isConnected(Graph& graph) {

    vector<bool> vertex_vis(graph.size(), false);
    DFS(graph, 0, vertex_vis);

    for (bool vis : vertex_vis) {
        if (!vis){
            return false;//not connected
        }
    }

    graph.transposeGraph();
    fill(vertex_vis.begin(), vertex_vis.end(), false); 
    DFS(graph, 0, vertex_vis);
    graph.transposeGraph();

    for (bool vis : vertex_vis) {
        if (!vis){
            return false; //not connected
        }
    }

    return true;
}


string Algorithms::shortestPath(const Graph& graph, const unsigned int start, const unsigned int end) {

    const unsigned int num_vertes = graph.size();

    if(start >= num_vertes || end >= num_vertes) {
        throw invalid_argument("Invalid values:Not in the range of the matrix .");
    }

    vector<int> distance(num_vertes, INT_MAX); 
    distance[start] = 0; 
    vector<int> pred(num_vertes, -1); 

    for (unsigned int i = 0; i < num_vertes; i++) {
        for (unsigned int j = 0; j < num_vertes; j++) {
            for (unsigned int k = 0; k < num_vertes; k++) {

                if(graph.getEdge(j,k) != 0) {

                   
                    if (distance[j] != INT_MAX && distance[j] + graph.getEdge(j,k) < distance[k]) {
                        distance[k] = distance[j] + graph.getEdge(j,k);
                        pred[k] = static_cast<int>(j);
                    }
                }
            }
        }
    }


    for (unsigned int j = 0; j < num_vertes; j++) {
        for (unsigned int k = 0; k < num_vertes; k++) {
            if(graph.getEdge(j,k) != 0) {
                if (distance[j] != INT_MAX && distance[j] + graph.getEdge(j,k) < distance[k]) {
                    return "Negative Cycle.No shortest path.";
                }
            }
        }
    }

    if (distance[static_cast<unsigned int>(end)] == INT_MAX) {
        return "-1";
    }

    string path = to_string(end);

    for (unsigned int num_vertex = end; num_vertex != start; num_vertex = static_cast<unsigned int>(pred[num_vertex])) {
        path.insert(0, "->");
        path.insert(0, to_string(pred[num_vertex]));
    }

    return path;
}


string Algorithms::isContainsCycle(const Graph& graph) {

    const unsigned int num_vertex = graph.size(); 
    vector<bool> vis(num_vertex, false);
    vector<unsigned int> pred_vec(num_vertex, INT_MAX);
    string ans_path = "";
    for (unsigned int i = 0; i < num_vertex; i++) {
        if (!vis[i]) {
            if (dfs_for_cycle(i, INT_MAX, graph, vis, pred_vec, ans_path)) {

              unsigned int temp = 0;
                 for (const char ch : ans_path) {
                     if (ch == '>') {
                          temp++;
                    }
                }

                if (temp >= 2) {
                    return ans_path;
                }

                else {
                    ans_path = "";
                    fill(vis.begin(), vis.end(), false);
                }
            }
        }
    }

    // No cycle found
    return "0";
}






bool Algorithms::dfs_for_cycle(const unsigned int node, unsigned int parentNode, const Graph& graph, vector<bool>& vis, vector<unsigned int>& parent, string& ans_path) {
    vis[node] = true; 
    parent[node] = parentNode;

    for (const unsigned int nextNode : graph.get_voisin(node)) {

        if (!vis[nextNode]) {
            if (dfs_for_cycle(nextNode, node, graph, vis, parent, ans_path)) {
                return true ;
            }
        }

        else if (nextNode != parentNode) {

            unsigned int temp_no = node;
            ans_path = "The cycle is: " + to_string(nextNode); 

            while (temp_no != INT_MAX && temp_no != nextNode) {
                ans_path += "->" + std::to_string(temp_no); 
                temp_no = parent[temp_no];
            }

            ans_path += "->" + to_string(nextNode); 
            return true;
        }
    }

    return false;
}




bool Algorithms::help_bipartite(size_t start, const vector<vector<int>> &graph, vector<size_t> &colors, vector<vector<size_t>> &sets)
{
    queue<size_t> q;
    q.push(start);
    colors[start] = 0;

    while (!q.empty())
    {
        size_t node = q.front();
        q.pop();

        for (size_t neighbor = 0; neighbor < graph[node].size(); ++neighbor)
        {
            if (graph[node][neighbor] != 0)
            {
                if (colors[neighbor] == INF)
                {
                    colors[neighbor] = 1 - colors[node];
                    q.push(neighbor);
                }
                else if (colors[neighbor] == colors[node])
                {
                    return false;
                }
            }
        }
    }

    vector<size_t> set1;
    vector<size_t> set2;

    for (size_t i = 0; i < colors.size(); i++)
    {
        if (colors[i] == 0)
        {
            set1.push_back(i);
        }
        else
        {
            set2.push_back(i);
        }
    }
    sets.push_back(set1);
    sets.push_back(set2);

    return true;
}



bool Algorithms::isBipartite(const Graph& g) {
    const vector<vector<int>> &graph = g.getGraph();
    size_t num_vertex = g.size();
    vector<vector<size_t>> sets;
    vector<size_t> colors(num_vertex, INF); 

    for (size_t i = 0; i < num_vertex; ++i)
    {
        if (colors[i] == INF)
        {                                                       
            if (!help_bipartite(i, graph, colors, sets)) 
            {
                cout << "Graph is not Bipartite" << endl;
                return false;
            }
        }
    }

  cout << "Graph is Bipartite .The sets are::" << endl;
    for (size_t i = 0; i < sets.size(); i++)
    {
        cout << "Group " << (i % 2) + 1 << ": ";
        for (size_t vertex : sets[i])
        {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return true; 


}

string Algorithms::negativeCycle(const Graph& graph) {

    const unsigned int num_vertes = graph.size(); 
    for(unsigned int i = 0; i < num_vertes; i++) {
        if(shortestPath(graph, i, i) == "Negative Cycle.No shortest path.") {
            return "Contains negative cycle";
        }
    }

    
    return "Not contains negative cycle";
}

void Algorithms::DFS(const Graph& graph, unsigned int vis, vector<bool>& node_vis) {
    node_vis[vis] = true;

    vector<unsigned int> voisin=graph.get_voisin(vis);
    for (unsigned int i : voisin) {

    
        if (!node_vis[i]) {

            DFS(graph, i, node_vis);
        }
    }
}


