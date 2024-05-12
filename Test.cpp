/*
lidor mondel
207478256
lidormon20@gmail.com
*/




#include <iostream>
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <sstream>

using namespace ariel;
TEST_CASE("Test loading graph and NumVertex")
{
    // Test loading a graph and basic properties
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(g.size() == 3);
}

TEST_CASE("Test non-square graph")
{
    // Test loading a non-square graph
    Graph g;
    vector<vector<int>> g1 = {
        {0, 1, 0},
        {1, 0, 1}};
    CHECK_THROWS(g.loadGraph(g1));
}

TEST_CASE("Test isConnected ")
{
    // Test isConnected with connected and disconnected graphs
    Graph g;
    
        vector<vector<int>> g2 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(g2);
        CHECK(Algorithms::isConnected(g) == true);
    }
    
TEST_CASE("Test isNotConnected")
{
    ariel::Graph g;
    vector<vector<int>> g3 = {
        {0, 1},
        {0, 0}};
    g.loadGraph(g3);
    CHECK(ariel::Algorithms::isConnected(g)==false);

}
TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
    
    
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->2->1->0");
    
     vector<vector<int>> graph3 = {
           {0, 1, -1},
        {-1, 0, -2},
        {-3, -2, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->2->1->0");
}

TEST_CASE("Test isBipartite ")
{
    // Test isBipartite with bipartite and non-bipartite graphs
    Graph g;
    SUBCASE("Bipartite graph")
    {
        vector<vector<int>> bipartite_graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(bipartite_graph);
        CHECK(Algorithms::isBipartite(g) == true);
    }
    SUBCASE("Non-bipartite graph")
    {
        vector<vector<int>> non_bipartite_graph = {
           {0, 1, 1},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(non_bipartite_graph);
        CHECK(Algorithms::isBipartite(g) == false);
    }
}
    
    TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph5 = {
        {0, 1, -4},
        {-2, 0, 3},
        {4, -3, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Contains negative cycle");

    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Not contains negative cycle");
    
   }

TEST_CASE("Test isConnected, shortestPath, isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 3, 0, 0},
        {3, 0, 2, 0},
        {0, 2, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 3) == "2->3");
}

TEST_CASE("Test loading non-square graph")
{
    // Test loading a non-square graph
    Graph g;
    vector<vector<int>> g1 = {
        {0, 1, 0},
        {1, 0, 1}};
    CHECK_THROWS(g.loadGraph(g1));
}
TEST_CASE("More Test")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 5, 0, -10},
        {5, 0, 2, 0},
        {0, 2, 0, 9},
        {-0, 0, 9, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
   

 vector<vector<int>> g1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(g1);
    CHECK(ariel::Algorithms::isBipartite(g) == false);
}
