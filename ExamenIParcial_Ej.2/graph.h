#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;
#define MAX 100
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */

class Graph
{
public:
    Graph()
    {};

    //Functions
    void initVertex();
    void initEdge();
    void readFileVertex();
    void readFileEdge();
    void gameValidation(string, string);
    string lowerString(string);
    string process(string const& s);
    void createMatrix();
    void print();
    bool contains(string elem);
    void initAux();
    bool validateUserInput(string, string);

    //Variables
    int p1, p2;
    vector<string> vertexVector;
    vector<string> edgeVector;
    vector<char> aux;
    int vertexNum; // vertex num
    int edgesNum; // edge num
    string mVertex [MAX]; // vertex collection
    int mMatrix [MAX] [MAX]; // adjacency matrix
    // returns pos of str in matrix
    int getPosition(string str);
  
};


#endif