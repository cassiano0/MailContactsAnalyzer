//
// Created by André on 23/09/2017.
//

#include "Graph.h"

Graph::Graph()
{
}
/*
void  Graph::insert_node(Node* i) {

    if(find(nodes.begin(), nodes.end(), i) != nodes.end())
    {
        //elem exists in the vector
    }else {

        nodes.push_back(i);
    }

}
*/
void  Graph::insert_node(string rotulo) {

    for (int i = 0; i < nodes.size(); i++){
        if (nodes[i]->rotulo == rotulo){
            return;
        }
    }

    Node *newNode = new Node(rotulo);
    nodes.push_back(newNode);
}

void Graph::cria_adjacencia(string from, string to){
   // cout << "init " << from << "," << to;
    //system("pause");
    insert_node(to);

    pair<bool,Node*> fromNode =  return_node(from);
    pair<bool,Node*> toNode =  return_node(to);

   // cout << "whit " << fromNode.second->rotulo << "," << toNode.second->rotulo;
   // system("pause");
    int frequency = fromNode.second->frequency(toNode.second);

    if(frequency == 0){
        fromNode.second->adjacencias.push_back(pair<Node*, int>(toNode.second, 1));
    }else{
        fromNode.second->updateFrequency(toNode.second, frequency);
    }
}

pair<bool,Node*> Graph::return_node(string rotulo){
    pair<bool,Node*> retorno;

    for(int i = 0; i < nodes.size() ; i++ ) {
        if ( nodes[i]->rotulo == rotulo ){
            retorno.first = true;
            retorno.second = (nodes[i]);
            return retorno;
        }
    }
    retorno.first = false;
    retorno.second = nullptr;
    return retorno;

}

/*

void Graph::imprime_adjacencias_grafo() {
   for (unsigned int i = 0; i < nodes.size();i++)
        nodes[i]->imprime_adjacencias();
    cout << endl;
}


Node* Graph::return_node(string rotulo){
    vector<string>::iterator it;

    for(it=nodes.begin() ; it < nodes.end(); it++,i++ ) {
        if ( it[i].rotulo == rotulo ){
            return it;
        }
    }

    return nullptr;

}

void  Graph::cria_adjacencia(No *i, No *j, int p) {
    i->adjacencias.push_back(pair<No*, int>(j, p));
}
void  Graph::remove_adjacencia(No *i, No *j) {
    for (unsigned int k = 0; k < i->adjacencias.size();k++) {
        if (i->adjacencias[k].first == j)
            i->adjacencias.erase(i->adjacencias.begin() + k);
    }
}
void  Graph::seta_informacao(No*j, string rot) {
    j->rotulo = rot;
}
int  Graph::adjacentes(No *j, vector<pair<No*, int> > &vetor_adjacentes) {
    for (unsigned int i = 0; i < j->adjacencias.size();i++)
        vetor_adjacentes.push_back(j->adjacencias[i]);

    return vetor_adjacentes.size();
}

 */