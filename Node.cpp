//
// Created by André on 23/09/2017.
//

#include "Node.h"

Node::Node(string r)
{
    this->rotulo = r;
}

int Node::frequency(Node* j)
{
    int freq = 0;

    for(int i = 0; i < adjacencias.size() ; i++ ){

        if ( adjacencias[i].first->rotulo == j->rotulo ){
            freq = adjacencias[i].second;
            break;
        }
    }

    return freq;
}

void Node::updateFrequency(Node* j, int f){
    for(int i = 0; i < adjacencias.size() ; i++ ){

        if (adjacencias[i].first->rotulo == j->rotulo){
            adjacencias[i].second = f + 1;
            break;
        }
    }
}