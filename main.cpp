#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"
#include <dirent.h>
#include <sys/stat.h>
#include <regex>
#include <string>

using namespace std;

void imprimeVector(vector<string> a){
    cout << endl;
    for (int i = 0 ; i < a.size();i++)
        cout << a[i] << endl;
}
vector<string> split(const char *str, char c = ' '){
    vector<string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}

void readEmail(string pathFile, bool firstEmail, Graph *G, string *from){

    ifstream emailFile;
    emailFile.open(pathFile);

    //vector<string> to;

    if (emailFile.fail()){
        cout << "Fail" << endl;
        return ;
    }

    //MARK: - Line by line
    string line = "";
    unsigned int foundLine = 0;
    bool verify = false;

    vector<string> tokensLine;
    vector<string> emailOfFile;
    const char * charToToken;

    do{
        getline(emailFile, line);

        if (firstEmail){
            foundLine = line.find_first_not_of("From:",0,5);
            if (foundLine) {
                charToToken = line.c_str();
                tokensLine = split(charToToken, ' ');
                *from = tokensLine[1];
                G->insert_node(*from);
                firstEmail = false;
            }
        }

        foundLine = line.find_first_not_of("Subject:",0,8);
        if (foundLine) {
            if (emailOfFile.size() > 0)
                emailOfFile.erase(emailOfFile.begin()); // the first element is always "To:"
            break;
        }

        foundLine = line.find_first_not_of("To:",0,3);
        if (foundLine || verify) {
            //Tokenizar a Line
              charToToken = line.c_str();
              tokensLine = split(charToToken, ' ');

            for (int i = 0; i < tokensLine.size(); i++) {

                if (!tokensLine[i].find_first_not_of(" :",0)){
                    string regexString = regex_replace(tokensLine[i],regex("\\s+"), "");
                    regexString = regex_replace(regexString,regex(","), "");
                    emailOfFile.push_back(string(regexString));
                }

            }
            verify = true;
        }

    }while(!emailFile.eof());



    emailFile.close();
    string to;

    if (emailOfFile.size()) {
        for (int c = 0; c < emailOfFile.size(); c++) {
            to = string(emailOfFile[c]);
            G->cria_adjacencia(*from, to);
        }
    }

}

void exploreEachEmail(char *dir_name, Graph *G){
    DIR *dir; //pointer to an open director
    struct dirent *entry; //stuff in the directory
    struct stat info;   //information about each entry
    bool firstMailOfThePerson = true;

    //1 open
    dir = opendir(dir_name);

    if(!dir){
        cout << "Directory " << string(dir_name) << " was not found\n" << endl;
        return;
    }
    string from;
    //2 read
    while ( (entry = readdir(dir))  != NULL){

        if( entry->d_name[0] != '.'){
            string path = string(dir_name) + "\\" + string(entry->d_name);

            if (!S_ISDIR(info.st_mode)){

                readEmail(path, firstMailOfThePerson, G, &from);
                firstMailOfThePerson = false;
            }
        }
    }

    //3 close
    closedir(dir);
}

vector<string> searchPeople(char *dir_name){
    vector<string> people;
    DIR *dir; //pointer to an open director
    struct dirent *entry; //stuff in the directory

    //1 open
    dir = opendir(dir_name);
    if(!dir){
        cout << "Directory "<< string(dir_name) <<" was not found\n" << endl;
        return people;
    }

    //2 read
    while ( (entry = readdir(dir))  != NULL)
        if( entry->d_name[0] != '.')
            people.push_back(string(entry->d_name));

    //3 close
    closedir(dir);
    return people;
}

void exploreOriginal(char *dir_name){
    DIR *dir; //pointer to an open director
    struct dirent *entry; //stuff in the directory
    struct stat info;   //information about each entry

    //1 open
    dir = opendir(dir_name);
    if(!dir){
        cout << "Directory "<< string(dir_name)<<" was not found\n" << endl;
        return;
    }

    //2 read
    while ( (entry = readdir(dir))  != NULL){

        if( entry->d_name[0] != '.'){
            string path = string(dir_name) + "/" + string(entry->d_name);
            cout << "Entry =  "<< path << endl;

            stat(path.c_str(), &info);
            if (S_ISDIR(info.st_mode)){
                exploreOriginal((char*)path.c_str());
               // readEachEmail(path);
            }


        }
    }

    //3 close
    closedir(dir);
}

void musa(string *a){
    *a = "terra";
    cout << *a;
}
int main() {

    Graph *G = new Graph();

    string path = "D:\\untitled\\Enron\\";
    vector<string> pessoas = searchPeople((char*)path.c_str());

    //path = string("D:\\untitled\\Enron\\" + pessoas[1] + "\\sent" );
    //explore((char*)path.c_str());
    for (int i = 0 ; i < pessoas.size();i++){
        path = string("D:\\untitled\\Enron\\" + pessoas[i] + "\\sent");
        exploreEachEmail((char*)path.c_str(), G);
    }
    //exploreEachPerson(PATH_ENRON, pessoas);

    cout << G->nodes.size();

    return 0;
}

