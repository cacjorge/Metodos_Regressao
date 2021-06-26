#ifndef CLASSE_MATRIZ_H_
#define CLASSE_MATRIZ_H_

#include <iostream>
#include <vector>

using namespace std;

class Matriz
	{
		private:
				long double *matriz;
				const int quantidadelinhas;
				const int quantidadecolunas;
				
		public:
				Matriz(int linhas,int colunas);
				Matriz(Matriz *m);
				Matriz(vector<long double> vet);
				~Matriz(){ delete[] matriz; };
				int tamanho_linha()const {return(quantidadelinhas);};
				int tamanho_coluna()const {return(quantidadecolunas);};
				void atribuir (long double el,int lin,int col) throw(int);
				long double obter (int lin,int col)const throw(int)
            		{
            		 	if(lin<0 || lin>quantidadelinhas) throw 1;
            		 	if(col<0 || col>quantidadecolunas) throw 1;
            		 	return(matriz[lin*quantidadecolunas+col]);
            		};
 				void operator= (Matriz *m) throw (int);
				void operator= (Matriz &m) throw (int);
				Matriz *operator+ (Matriz &m) throw(char);
				Matriz *operator- (Matriz &m) throw(char);
				Matriz *operator* (Matriz &m) throw(char);
				Matriz *operator* (Matriz *m) throw(char);
				Matriz *operator* (vector<long double> m) throw(char);
				Matriz *transposta();
					
	};

#endif /*CLASSE_MATRIZ_H_*/
