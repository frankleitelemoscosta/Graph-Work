#include"grafo.hpp"

void Grafo::addWord(string w1,string w2,string w3)
{
 mp[w2].insert(w1);
 mp[w2].insert(w3);
}

void Grafo::addWordLimits(string w1,string w2)
{
 mp[w1].insert(w2);
}
