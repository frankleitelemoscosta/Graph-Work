#ifndef __HASH_HPP
#define __HASH_HPP

#include <map>
#include <string>
#include<unordered_map>
#include<vector>

using namespace std;

struct Data {
  unsigned short apparences;
  Data();
};

struct Hashh {
  std::map<std::string, Data> mp;
  void addWord(const std::string &word);
  unsigned short getApparences(string word); 
};

struct WordSave {
  unsigned short apparences;
  string Word_saved;
  void addWordSave(string word,unsigned short apparences);
  unsigned short getapparences();
}; 

//beguin the data of text

struct AuxData{

  string word;
  int X;
  int Y;

};

struct Text
{
  vector<AuxData> vet;
  void addWordVet(string word,int X,int Y);
  int counter;
  vector<int> positions;
  Text();
};

//end data of text

#endif
