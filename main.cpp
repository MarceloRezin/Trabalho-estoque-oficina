/*Este arquivo contém o main, sendo responsável pela interação do usuário com o software e pelo gerenciamento das funções a serem executadas.
 *
 * Autores: Marcelo Rezin e Marcelo Bristot
 * Data de criação: 16 de set de 2017
 *
 * Última alteração: 17 de set de 2017
 */

#include <cstdlib>
#include <iostream>
#include "gerencia_arquivos.h"


using namespace std;

void listamenu(){
    cout << "Gerenciador de Estoque para Oficina" << endl;
    cout<<"1 - Inserir item"<<endl;
    cout<<"2 - Remover item"<<endl;
    cout<<"3 - Consultar Especifico - pelo codigo"<<endl;
    cout<<"4 - Consultar Especifico - pelo nome"<<endl;
    cout<<"5 - Listar"<<endl;
    cout<<"6 - Gerar 10 000 Registros" << endl;
    cout<<"0 - Sair"<<endl<<endl;
}


void iniciar(){
    hash *hashestoque = new hash();
    
    gerencia_arquivos ge = gerencia_arquivos();
    
    ge.verificaaquivo();
    ge.carregaestoque(hashestoque);

    int opcao;
    
    peca p;
    int codigo;
    string nome;
    float preco;
    
    do{
        listamenu();

        cout << "Informe a opcao: ";
        cin >> opcao;
        
        switch(opcao){
           case 0:
              exit(0);
              break;
           case 1:
              cout << "Informe o codigo: ";
              cin >> codigo;
              cout << "Informe o nome: ";
              cin >> nome;
              cout << "Informe o preco: ";
              cin >> preco;
                              
              p.setcodigo(codigo);
              p.setnome(nome);
              p.setpreco(preco);

              
              hashestoque->insere(p);

              ge.gravarestoque(hashestoque->getsublist(codigo), hashestoque->gerahash(codigo));
              break;
              
           case 2:
              cout << "Informe o codigo: ";
              cin >> codigo;
              
              hashestoque-> remove(codigo);
              ge.gravarestoque(hashestoque->getsublist(codigo), hashestoque->gerahash(codigo));

              break;
              
           case 3:
              cout << "Informe o codigo: ";
              cin >> codigo;
              
              hashestoque-> consulta(codigo);
              break;
              
           case 4:
              cout << "Informe o nome: ";
              cin >> nome;
              
              hashestoque-> consultanome(nome);

              break;
              
           case 5:
              hashestoque->imprimirhash();
              break;

           case 6:
        	   nome = "pecaAutomotiva";

        	   cout << "Gerando ..." << endl;
        	   for(int i=1; i<10001; i++){
        			p.setcodigo(i);
        		    p.setnome(nome);
        		    p.setpreco(i*5);

        		    hashestoque->insere(p);

        		    ge.gravarestoque(hashestoque->getsublist(p.getcodigo()), hashestoque->gerahash(p.getcodigo()));
        	   }

        	   cout << "Gerado!" << endl;
        	   break;

           default:
              cout << "Opcao invalida" << endl;
        }

        cout << "\n\n";
        
    }while(opcao != 0);
}



int main()
{
    iniciar();

    return EXIT_SUCCESS;
}
