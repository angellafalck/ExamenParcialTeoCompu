#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <iterator>
#include "rlutil.h"

using namespace std;

#define MAX 100
#include <fstream>

class Graph
{
public:
    Graph()
    {};
    //Variables
    vector<string> vertexVector;
    vector<string> edgeVector;
    vector<string> graphVector;
    vector<string> temp;
    
    
    //Functions
    void addVertex();
    void readFileVertex();
    void addEdge();
    void readFileEdge();
    string process(string const& s);
    void initVertex();
    void initEdge();
    void createMatrix();
    bool contains(string);
    bool containsEdge(string);
    bool validations(string);
    bool edgeValidation(string);
    bool startsWith(string, string);
    bool endsWith(string, string);
    void print();
    void createGraph();
    void addTag();
    void changeTagEdge(string tag);
    string spaceintegration(string s, vector<int>& sp);
    void print2();
    void print3();
    void print4();
    
    
    //Variables
    int p1, p2;

    int vertexNum; // vertex num
    int edgesNum; // edge num


private:

    string mVertex [MAX]; // vertex collection
    int mMatrix [MAX] [MAX]; // adjacency matrix
    // returns pos of str in matrix
    int getPosition(string str);

};


#endif