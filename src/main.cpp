//libraries and files import

#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include "StopWords.hpp"
#include "Hash.hpp"
#include "Utils.hpp"
#include "grafo.hpp"
#include<queue>

//finish

using namespace std;

const int INF = 0x3f3f3f3f;

enum Cores {
	BRANCO,
	CINZA,
	PRETO
};

template <typename G> 

void BFS(G g, string best) {
  unordered_map<string, int> cor;
  unordered_map<string, int> d;
  unordered_map<string, string> pi;

  for(auto &[key,value] : g)
  {
    cor[key] = BRANCO;
    d[key] = INF;
    pi[key] = -1;
  }

  cor[best] = CINZA;
  d[best] = 0;
  pi[best] = -1;

  std::queue<pair<string, set<string>>> Q;
  auto it = g.find(best);
	Q.push(make_pair(it->first,it->second));

  while (!Q.empty()) {
		auto u = Q.front();
    Q.pop();
    for(auto v : u.second)
    {
      if (cor[v] == BRANCO) {
				cor[v] = CINZA;
				d[v] = d[u.first] + 1;
				pi[v] = u.first;
        it = g.find(v);
				Q.push(make_pair(it->first,it->second));
			}
    }
		cor[u.first] = PRETO;
	
  }

cout << endl;
 for(auto [key,value] : d)
  {
    cout << key << " --> " << value; 
    cout << endl;
  }
}

char *ReadFile(locale &loc)
{

  ifstream txt("./dataset/medicina.txt", ios::binary);

  if (!txt.is_open())
  {
    wcout << L"Não foi possível abrir o arquivo" << endl;
    exit(1);
  }

  // Set the locale to handle UTF-8 encoding
  txt.imbue(loc);

  // Determine the size of the file in bytes
  txt.seekg(0, ios::end);
  streampos fileSize = txt.tellg();
  txt.seekg(0, ios::beg);

  char *buffer = new char[fileSize];

  // Read the file contents into the buffer
  txt.read(buffer, fileSize);

  // Close the file
  txt.close();

  return buffer;
}

int main()
{

  //local variables

  setlocale(LC_ALL, "pt_BR.UTF-9");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  char *character = ReadFile(loc), *ch = character;
  string palavraaux;
  StopWords stop_words(loc);
  Hashh mp;
  Text ObjSaveAllText;
  WordSave ObjSaveWord;
  ofstream output = createOutput(); 
  int CounterFirstWord = 0;
  int X = 0;
  int Y = 1;

  //finish local variables

  ObjSaveAllText.positions.push_back(0);

  //main loop for read file

  while (*ch)
  {

    switch (*ch)
    {
    // in case the ch is in the end sentence or a speak or a question.
    case '.':
    case '!':
    case '?':
      if (!palavraaux.empty())
      {
        if (stop_words.isStopWord(palavraaux))
        {
          palavraaux.clear();
        }
        else
        {
          mp.addWord(palavraaux);
          if(CounterFirstWord == 0)
            ObjSaveWord.addWordSave(palavraaux,mp.getApparences(palavraaux));
          if(CounterFirstWord != 0 && (mp.getApparences(palavraaux) > ObjSaveWord.getapparences()))
            ObjSaveWord.addWordSave(palavraaux,mp.getApparences(palavraaux));
          CounterFirstWord++;
          ObjSaveAllText.addWordVet(palavraaux,X,Y);
	  Y++;
        }
      }
      palavraaux.clear();
      break;

    // in case the ch is in the skip of line.
    case '\n':
      if (!palavraaux.empty())
      {
        if (stop_words.isStopWord(palavraaux))
        {
          palavraaux.clear();
        }
        else
        {
          mp.addWord(palavraaux);
          if(CounterFirstWord == 0)
            ObjSaveWord.addWordSave(palavraaux,mp.getApparences(palavraaux));
          if(CounterFirstWord != 0 && (mp.getApparences(palavraaux) > ObjSaveWord.getapparences()))ObjSaveWord.addWordSave(palavraaux,mp.getApparences(palavraaux));
          CounterFirstWord++;
	  ObjSaveAllText.addWordVet(palavraaux,X,Y);
	}
      }
      X++;
      Y = 1;
      palavraaux.clear();
      break;

    // in case the ch is between space, comma, feature, quotation marks, bar, two points
    case ' ':
    case ',':
    case ':':
    case ';':
    case '(':
    case ')':
    case '"':
    case '-':
    case '/':
      if (!palavraaux.empty())
      {
        if (stop_words.isStopWord(palavraaux))
        {
          palavraaux.clear();
        }
        else
        {
          mp.addWord(palavraaux);
          if(CounterFirstWord == 0)
            ObjSaveWord.addWordSave(palavraaux,mp.getApparences(palavraaux));
	  if(CounterFirstWord != 0 && (mp.getApparences(palavraaux) > ObjSaveWord.getapparences()))
        ObjSaveWord.addWordSave(palavraaux,mp.getApparences(palavraaux));
	  
    CounterFirstWord++; 
          ObjSaveAllText.addWordVet(palavraaux,X,Y);
	  Y++;
        }

        palavraaux.clear();
      }
      break;

    // if there is no case, the letter will be concatenated with the word that had already been formed with the preceding letters.
    default:
      palavraaux += tolower(*ch);
      break;
    }
    ++ch;

    PrintEnd(output);
   }

   //finish main loop
 
   //find the positions where is the more frequence word

   Grafo Obj;
   Obj.addWordLimits(ObjSaveAllText.vet[0].word,ObjSaveAllText.vet[1].word);
   Obj.addWordLimits(ObjSaveAllText.vet[ObjSaveAllText.counter - 1].word,ObjSaveAllText.vet[ObjSaveAllText.counter - 2].word);

   for(int i = 1 ; i < ObjSaveAllText.counter - 1 ; i++)
   {
     Obj.addWord(ObjSaveAllText.vet[ i - 1 ].word,ObjSaveAllText.vet[ i ].word,ObjSaveAllText.vet[ i + 1 ].word );
   /*	    
        cout << ObjSaveAllText.vet[i].word << "["  << ObjSaveAllText.vet[i].X << "," << ObjSaveAllText.vet[i].Y << "]" << endl;
        if(ObjSaveWord.Word_saved == ObjSaveAllText.vet[i].word)ObjSaveAllText.positions.push_back(i);	
   */
  }

  for(auto &[key,value] : Obj.mp)
  {
    cout << key << " --> ";
    for(auto v : value)
    {
      cout << v << " --> ";
    } 
    cout << endl;
  }

  BFS(Obj.mp,ObjSaveWord.Word_saved);

   //ObjSaveAllText.positions.push_back(ObjSaveAllText.counter);

   //end
   
  /*for(int i = 0 ; i < ObjSaveAllText.positions.size() ; i++)
  {
  	cout << ObjSaveAllText.positions[i] << endl;
  }*/

   cout << ObjSaveWord.Word_saved <<endl ;

  criaCSV(Obj.mp);
    
  return 0;
}

//end code
