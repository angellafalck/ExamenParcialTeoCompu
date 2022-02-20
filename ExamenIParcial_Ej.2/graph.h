#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#define ARRAY 6
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
    void loadText();
    void printMatrix();
    void play(int, int);
    //void play(string,string);
    void winningComb(string,string);
    vector<string> vertexVector;
    vector<string> edgeVector;
    string process(string const& s);
    void initVertex();
    void initEdge();
    void createMatrix();
    void print();
    bool contains(string elem);

    //Variables
    char gameRules[ARRAY][ARRAY];
        //Variables
    int p1, p2;

    int vertexNum=5; // vertex num
    int edgesNum=10; // edge num
        string mVertex [MAX]; // vertex collection
    int mMatrix [MAX] [MAX]; // adjacency matrix
    // returns pos of str in matrix
    int getPosition(string str);
  
};


#endif