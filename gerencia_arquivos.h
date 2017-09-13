/*Este header faz o gerenciamento dos arquivos em disco que armazenam os registros.
 *
 * Autores: Marcelo Rezin e Marcelo Bristot
 * Data: 4 de set de 2017
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#define CLASSE_0 "dados_0.txt"
#define CLASSE_1 "dados_1.txt"
#define CLASSE_2 "dados_2.txt"
#define CLASSE_3 "dados_3.txt"
#define CLASSE_4 "dados_4.txt"
#define CLASSE_5 "dados_5.txt"
#define CLASSE_6 "dados_6.txt"
#define CLASSE_7 "dados_7.txt"
#define CLASSE_8 "dados_8.txt"
#define CLASSE_9 "dados_9.txt"

class gerencia_arquivos{
	private:
		string classe();

	public:
		void gravarestoque(int classe);
		void carregaestoque();
		void verificaaquivo();
};


void gerencia_arquivos::gravarestoque(int classe){

}
