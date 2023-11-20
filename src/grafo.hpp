#ifndef _GRAFO__HPP
#define _GRAFO__HPP

#include<iostream>
#include<set>
#include"Hash.hpp"
#include<unordered_map>

using namespace std;

struct Grafo {
    unordered_map<string,set<string>> mp;
    void addWord(string w1, string w2, string w3);
    void addWordLimits(string w1,string w2);
    //unsigned short getApparences(string word);
    //void ConstructGraph(vector<int> positions, vector<AuxData> vet, string  Word,int frequence);
};

#endif
