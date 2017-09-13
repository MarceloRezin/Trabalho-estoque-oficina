/* Este header representa uma peça de veículo através dos atributos código, nome do produto e preço.
 * 
 * Autores: Marcelo Rezin e Marcelo Bristot
 * Data: 4 de set de 2017
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class peca{
	private:
		int codigo;
		string nome;
		float preco;

	public:
		peca();
		peca(int codigo, string nome, float preco);
		int getcodigo();
		void setcodigo(int codigo);
		string getnome();
		void setnome(string nome);
		float getpreco();
		void setpreco(float preco);
		void imprimir();


};

peca::peca(){
	this->codigo = 0;
	this->nome = "semNome";
	this->preco = 0;
}

peca::peca(int codigo, string nome, float preco){

	this->codigo = codigo;
	this->nome = nome;
	this->preco = preco;
}

int peca::getcodigo(){
	return codigo;
}

void peca::setcodigo(int codigo){
	this->codigo = codigo;
}

string peca::getnome(){
	return nome;
}

void peca::setnome(string nome){
	this->nome = nome;
}

float peca::getpreco(){
	return preco;
}

void peca::setpreco(float preco){
	this->preco = preco;
}

void peca::imprimir(){
	cout << "Codigo: " << codigo << endl;
	cout << "Nome:   " << nome << endl;
	cout << "Preco:  " << preco << endl;
}


