/*
 * Logaritmica.cpp
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */

#include "Logaritmica.h"

Logaritmica::Logaritmica(string nomeArquivo):a(0.1)
{
	this->nomeArquivo=nomeArquivo;
	if(!lerDados()) exit(1);
	ymax = *max_element(dadosY.begin(),dadosY.end());
	b=1/ymax;
}

Logaritmica::~Logaritmica()
{

}

bool Logaritmica::lerDados()
{
	ifstream arquivo(nomeArquivo.c_str());
	if(!arquivo.is_open()) return false;
	else
	{
		while(!arquivo.eof())
		{
			long double x,y;
			arquivo >> x >> y;
			dadosX.push_back(x);
			dadosY.push_back(y);
		}
		return true;
	}
}

void Logaritmica::gerDIFFA(VetorDados x,long double a,long double b)
{
	diffA.clear();
	for(unsigned int pos=0;pos<x.size()-1;pos++)
	{
		diffA.push_back(DIFFA(x[pos],a,b));
	}
}

void Logaritmica::gerDIFFB(VetorDados x,long double a,long double b)
{
	diffB.clear();
	for(unsigned int pos=0;pos<x.size()-1;pos++)
	{
		diffB.push_back(DIFFB(x[pos],a,b));
	}
}

void Logaritmica::gerF(VetorDados x,long double a,long double b)
{
	dadosF.clear();
	for(unsigned int pos=0;pos<x.size()-1;pos++)
	{
		dadosF.push_back(F(x[pos],a,b));
	}
}

Matriz *Logaritmica::montaZ() throw(int)
{
		if(diffA.size()!=diffB.size()) throw(5);
		static Matriz tempZ(diffA.size(),2);
		for(int l=0,pos=0; l<tempZ.tamanho_linha(); l++,pos++)
			{
			tempZ.atribuir(diffA[pos],l,0);
			tempZ.atribuir(diffB[pos],l,1);
			}
		return &tempZ;
}

VetorDados Logaritmica::setErro(VetorDados x,VetorDados y)
{
	VetorDados temp;
	for(unsigned int pos=0; pos<x.size();pos++) temp.push_back(x[pos]-y[pos]);
	return temp;
}

void Logaritmica::executa()
{
	VetorDados I(2,0);
	int cont=0;
	do{
		gerDIFFA(dadosX,a,b);
		gerDIFFB(dadosX,a,b);
		gerF(dadosX,a,b);
		erro = setErro(dadosY,dadosF);

		Matriz A((*(montaZ()->transposta())) * montaZ());
		Matriz B((*(montaZ()->transposta())) * erro);

		Gauss sistemaDeEquacoes(2);
		sistemaDeEquacoes.Seidel(A,B);

		I = sistemaDeEquacoes.getResultado();

		this->a=a+I[0];
		this->b=b+I[1];

		cont++;
		if(cont==10) break;
	}
	while(abs(I[0])>E || abs(I[1])>E);

	final.clear();
	final.push_back(a);
	final.push_back(b);
}

double Logaritmica::Tempo_Execucao(void(Logaritmica::*function)(void))
	{
		double ti,tf,deltaT; // ti==tempo inicial // tf==tempo final
		ti=tf=deltaT=0;
		struct timeval tempo_inicio,tempo_fim;
		gettimeofday(&tempo_inicio,NULL);

		(this->*function)(); //aqui o metodo ser executado

		gettimeofday(&tempo_fim,NULL);
		tf=(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
		ti=(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
		deltaT+=(tf-ti);
		return (deltaT);
	}
