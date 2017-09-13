/*Este header realiza o hashing das peças da oficina através do método da divisão inteira para separar as classes.
 * 
 *
 * Autores: Marcelo Rezin e Marcelo Bristot
 * Data: 4 de set de 2017
 */

#include <cstdlib>
#include <list>
#include "peca.h"

using namespace std;

#define TAM 10

class hash{
	private:
		list<peca> listapecas[TAM];
		list<peca>::iterator it;

	public:
		hash();
		~hash();
		int gerahash(int codigo);
		void insere(peca p);
		void remove(int cod);
		void consulta(int cod);
		void consultanome(string nome);
		void imprimirhash();
};

hash::hash(){}

hash::~hash(){
	for(int i=0; i<TAM; i++){
		listapecas[i].clear();
	}
}

int hash::gerahash(int codigo){
	return codigo%TAM;
}

void hash::insere(peca p){
	listapecas[gerahash(p.getcodigo())].push_back(p);
}

void hash::remove(int cod){
	bool encontrado = false;
	int hashgerado = gerahash(cod);

	if(!listapecas[hashgerado].empty()){
		for(it=listapecas[hashgerado].begin(); it!=listapecas[hashgerado].end(); it++){
			if(it->getcodigo() == cod){
				listapecas[hashgerado].erase(it);
					encontrado = true;
					break;
			}
		}
	}

	if(encontrado == false){
		cout << "Nao foi encontrado!" << endl;
	}
}

void hash::consulta(int cod){
	bool encontrado = false;
	list<peca> sublist = listapecas[gerahash(cod)];

	if(!sublist.empty()){
		for(it=sublist.begin(); it!=sublist.end(); it++){
			if(it->getcodigo() == cod){
				it->imprimir();
					encontrado = true;
					break;
			}
		}
	}

	if(encontrado == false){
		cout << "Nao foi encontrado!" << endl;
	}
}

void hash::consultanome(string nome){
	bool encontrado = false;

	for(int i=0; i<TAM; i++){
		list<peca> sublist = listapecas[i];

		for(it=sublist.begin(); it!=sublist.end(); it++){
			if(it->getnome() == nome){
				it->imprimir();
				encontrado = true;
				break;
			}
		}
	}

	if(encontrado == false){
		cout << "Nao foi encontrado!" << endl;
	}
}

void hash::imprimirhash(){
	bool encontrado = false;

	cout << "\n";
	for(int i=0; i<5; i++){
		list<peca> sublist = listapecas[i];

		for(it=sublist.begin(); it!=sublist.end(); it++){
				it->imprimir();
				encontrado = true;
				cout << "\n";
		}
	}

	if(encontrado == false){
		cout << "A lista esta vazia!" << endl;
	}
}

