#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include<locale>
#include<iostream>
#include <fstream>
#include"Hash.hpp"
#include <dirent.h>
#include <codecvt>
#include <vector>
#include <string>

#define MAXFILES 2;

using namespace std;

void PrintEnd(std::ofstream &output);
std::ofstream createOutput();
template <typename G>
void criaCSV(G g) {
	// Dados que você deseja escrever no arquivo CSV
	//std::vector<std::vector<std::string>> data = {
	//	{"Nome", "Idade", "Cidade"},
	//	{"João", "25", "São Paulo"},
	//	{"Maria", "30", "Rio de Janeiro"},
	//	{"Carlos", "22", "Belo Horizonte"}
	//};

	// Nome do arquivo CSV que você deseja gerar
	std::string filename = "dados.csv";

	// Abrir o arquivo CSV para escrita
	std::ofstream csvFile(filename);

	// Verificar se o arquivo foi aberto com sucesso
	if (csvFile.is_open()) {
        csvFile << "source,target" << "\n";
        for(auto &[key,value] : g)
        {
            for(auto v : value)
            {
                csvFile << key << "," << v << endl;
            } 
        }
	/*	for (const auto &row : data) {
			for (size_t i = 0; i < row.size(); ++i) {
				csvFile << row[i];
				// Adicionar uma vírgula após cada valor, exceto o último
				if (i < row.size() - 1) {
					csvFile << ",";
				}
			}
			// Adicionar uma quebra de linha após cada linha
			csvFile << "\n";
		}*/
    

		// Fechar o arquivo
		csvFile.close();
		std::cout << "Arquivo CSV gerado com sucesso.\n";
	} else {
		std::cerr << "Erro ao abrir o arquivo.\n";
	}
}

#endif
//end code
