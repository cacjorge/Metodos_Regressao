/*
 * Matriz.cpp
 *
 *  Created on: 15/01/2010
 *      Author: Carlos Antonio
 */
#include <iostream>
#include "Matriz.h"

using namespace std;

Matriz::Matriz(Matriz *m):quantidadelinhas(m->tamanho_linha()),quantidadecolunas(m->tamanho_coluna())
	{
		matriz=new long double[m->tamanho_linha() * m->tamanho_coluna()];
		for(int l=0; l<quantidadelinhas; l++)
        	for(int c=0; c<quantidadecolunas; c++)
            	atribuir(m->obter(l,c),l,c);
     	delete m;
	}
Matriz::Matriz(vector<long double> vet):quantidadelinhas(vet.size()-1),quantidadecolunas(1)
	{
		matriz=new long double[vet.size()-1 * 1];
		for(int l=0; l<quantidadelinhas; l++)
        	for(int c=0; c<quantidadecolunas; c++)
            	atribuir(vet[l],l,c);
	}

Matriz::Matriz(int linhas,int colunas):quantidadelinhas(linhas),quantidadecolunas(colunas)
	{
		matriz=new long double[linhas*colunas];
	}

void Matriz::atribuir(long double el,int lin,int col) throw(int)
	{
		if(lin<0 || lin>quantidadelinhas) throw 1;
		if(col<0 || col>quantidadecolunas) throw 1;
		matriz[lin*quantidadecolunas+col]=el;
	}

void Matriz::operator= (Matriz  *m) throw(int)
{//inicio do metodo operator =
	 if(quantidadelinhas!=m->tamanho_linha() && quantidadecolunas!=m->tamanho_coluna())
	   throw 1;
	 for(int l=0; l<quantidadelinhas; l++)
        for(int c=0; c<quantidadecolunas; c++)
            atribuir(m->obter(l,c),l,c);
     delete m;
}//fim do metodo operator =

void Matriz::operator= (Matriz  &m) throw(int)
{//inicio do metodo operator =
	 if(quantidadelinhas!=m.tamanho_linha() && quantidadecolunas!=m.tamanho_coluna())
	   throw 1;
	 for(int l=0; l<quantidadelinhas; l++)
        for(int c=0; c<quantidadecolunas; c++)
            atribuir(m.obter(l,c),l,c);
}//fim do metodo operator =

Matriz *Matriz::operator+ (Matriz &m) throw(char)
{//inicio do metodo operator +
    if(tamanho_linha()!=m.tamanho_linha() || tamanho_coluna()!=m.tamanho_coluna())
      throw'a';
    Matriz *mat=new Matriz(tamanho_linha(),tamanho_coluna());
    for(int l=0;l<mat->tamanho_linha();l++)
        for(int c=0;c<mat->tamanho_coluna();c++)
            mat->atribuir(obter(l,c)+m.obter(l,c),l,c);
    return(mat);
}//fim do metodo operator +

Matriz *Matriz::operator- (Matriz &m) throw(char)
{//inicio do metodo operator -
    if(tamanho_linha()!=m.tamanho_linha() || tamanho_coluna()!=m.tamanho_coluna())
      throw'b';
    Matriz *mat=new Matriz(tamanho_linha(),tamanho_coluna());
    for(int l=0;l<mat->tamanho_linha();l++)
        for(int c=0;c<mat->tamanho_coluna();c++)
            mat->atribuir(obter(l,c)-m.obter(l,c),l,c);
        return(mat);
}//fim do metodo operator -

Matriz *Matriz::operator* (Matriz &m) throw(char)
{//inicio do metodo operator *
    if(tamanho_coluna()!=m.tamanho_linha()) throw'c';
    Matriz *mat=new Matriz(tamanho_linha(),m.tamanho_coluna());
    for(int l=0;l<tamanho_linha();l++)
    {//inicio do for_1
        for(int c=0;c<m.tamanho_coluna();c++)
        {//inicio for_2
        	long double mt=0;
            for(int el=0; el<tamanho_coluna();el++)
            {//inicio for_3
                mt+=obter(l,el)*m.obter(el,c);
                mat->atribuir(mt,l,c);
            }//fim for_3
        }//fim for_2
    }//fim do for_1
    return(mat);
}//fim do metodo operator */

Matriz *Matriz::operator* (Matriz *m) throw(char)
{//inicio do metodo operator *
	if(tamanho_coluna()!=m->tamanho_linha()) throw'c';
    Matriz *mat=new Matriz(tamanho_linha(),m->tamanho_coluna());
    for(int l=0;l<tamanho_linha();l++)
    {//inicio do for_1
        for(int c=0;c<m->tamanho_coluna();c++)
        {//inicio for_2
        	long double mt=0;
            for(int el=0; el<tamanho_coluna();el++)
            {//inicio for_3
                mt+=obter(l,el)*m->obter(el,c);
                mat->atribuir(mt,l,c);
            }//fim for_3
        }//fim for_2
    }//fim do for_1
    return(mat);
}//fim do metodo operator */

Matriz *Matriz::operator* (vector<long double> m) throw(char)
{//inicio do metodo operator *
    if(tamanho_coluna()!=(int)m.size()-1) throw'c';
    Matriz *mat=new Matriz(tamanho_linha(),1);
    for(int l=0;l<tamanho_linha();l++)
    {//inicio do for_1
        for(int c=0;c<1;c++)
        {//inicio for_2
        	long double mt=0;
            for(int el=0; el<tamanho_coluna();el++)
            {//inicio for_3
                mt+=obter(l,el)*m[el];
                mat->atribuir(mt,l,c);
            }//fim for_3
        }//fim for_2
    }//fim do for_1
    return(mat);
}//fim do metodo operator */


Matriz *Matriz::transposta()
{
	Matriz *mat=new Matriz(tamanho_coluna(),tamanho_linha());
		for(int l=0; l<quantidadelinhas; l++)
			for(int c=0; c<quantidadecolunas; c++)
				mat->atribuir(obter(l,c),c,l);
	return(mat);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
