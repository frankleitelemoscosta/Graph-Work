#include"Hash.hpp"

Data::Data() : apparences(0) {}
Text::Text() : counter(0) {}

void Hashh::addWord(const std::string &word)
{
 ++mp[word].apparences;
}

unsigned short Hashh::getApparences(string word)
{
 return mp[word].apparences;
}

void WordSave::addWordSave(std::string word,unsigned short int apparences)
{
 this->Word_saved = word;
 this->apparences = apparences;
}

unsigned short WordSave::getapparences()
{
 return this->apparences;
}

void Text::addWordVet(string word,int X,int Y)
{
 AuxData Obj;
 Obj.word = word;
 Obj.X = X;
 Obj.Y = Y;
 vet.push_back(Obj);
 this->counter++;
}
