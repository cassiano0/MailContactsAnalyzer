//
// Created by André on 23/09/2017.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#include <iostream>
#include <vector>
#include "Node.h"
#include <iterator>
#include <string>
using namespace std;

class Graph {
public:
    vector<Node*> nodes;
    Graph();
//    void insert_node(Node* i);
    void insert_node(string rotulo);
    void cria_adjacencia(string from, string to);
    pair< bool,Node*> return_node(string rotulo);

    /*
    void imprime_adjacencias_grafo();

    void cria_adjacencia(Node *i, Node *j, int p);
    void remove_adjacencia(Node *i, Node *j);
    void seta_informacao(Node *j, string rot);
    int adjacentes(Node *j, vector<pair<Node *, int> > &vetor_adjacentes);

    Node* return_node(string rotulo);
     */

};


#endif //UNTITLED_GRAPH_H
