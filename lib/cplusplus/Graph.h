#ifndef ___GRAPH_H___
#define ___GRAPH_H___

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include "Parser.h"

class Graph
{
private:
    
    void readFiles();
    
public:
    Graph() {}
    std::unordered_set<std::string> routeAtStation(std::unordered_set<std::string> stoptimes,std::string tripsLoc);
    ~Graph(){}
};







#endif