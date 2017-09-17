/*Este header faz o gerenciamento dos arquivos em disco que armazenam os registros.
 *
 * Autores: Marcelo Rezin e Marcelo Bristot
 * Data de criação: 4 de set de 2017
 *
 * Última alteração: 17 de set de 2017
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "hash.h"

using namespace std;

const string classes[10] = {"dados_0.txt", "dados_1.txt", "dados_2.txt", "dados_3.txt", "dados_4.txt", "dados_5.txt", "dados_6.txt",
					  "dados_7.txt", "dados_8.txt", "dados_9.txt"};

class gerencia_arquivos{
	private:
		list<peca>::iterator it;

	public:
		string getclasse(int classe);
		void gravarestoque(list<peca> sublist, int classe);
		void carregaestoque(hash *hashestoque);
		void verificaaquivo();
};

string gerencia_arquivos::getclasse(int classe){
	return classes[classe];
}

void gerencia_arquivos::gravarestoque(list<peca> sublist, int classe){

	string endereco = getclasse(classe);

	fstream estoque;

	if(!sublist.empty()){

		estoque.open(endereco.c_str(), ios::trunc | ios::out);

		for(it=sublist.begin(); it!=sublist.end(); it++){
			estoque << it->getcodigo() << "\t" << it->getnome() << "\t" << it->getpreco() << "\n";

		}
	}else{
		remove(endereco.c_str());
		estoque.open(endereco.c_str());
	}

	estoque.close();
}

void gerencia_arquivos::carregaestoque(hash *hashestoque){
	for(int i=0; i<10; i++){

		fstream estoque(classes[i].c_str(), ios::in);

		while(!estoque.eof()){

			int codigo;
			string nome;
			float preco;

			peca p;

			estoque >> codigo >> nome >> preco;

			p.setcodigo(codigo);
			p.setnome(nome);
			p.setpreco(preco);

			if(nome !=""){//evita a leitura de lixo
				hashestoque->insere(p);
			}

		}

		estoque.close();
	}
}

void gerencia_arquivos::verificaaquivo(){
	ofstream estoque;

	for(int i=0; i<10; i++){
		estoque.open(getclasse(i).c_str(), ios_base::in);

		if(!estoque){
			estoque.open(getclasse(i).c_str());
		}
		estoque.close();
	}
}
