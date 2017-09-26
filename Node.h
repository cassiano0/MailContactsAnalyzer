//
// Created by André on 23/09/2017.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    string rotulo;
    Node(string r);
    vector<pair<Node*, int> > adjacencias;
    int frequency(Node* j);
    void updateFrequency(Node* j, int);

};


#endif //UNTITLED_NODE_H
