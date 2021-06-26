/*
 * HillSuavizado.cpp
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */

#include "HillSuavizado.h"

HillSuavizado::HillSuavizado(string nomeArquivo):a(0.1),c(1.0)
{
	this->nomeArquivo=nomeArquivo;
	if(!lerDados()) exit(1);
	ymax = *max_element(dadosY.begin(),dadosY.end());
	b=1/ymax;
	ymed=0;
	for(unsigned int pos=0;pos<dadosY.size()-1;pos++) ymed+=dadosY[pos];

	ymed=ymed/(dadosY.size()-1);
}

HillSuavizado::~HillSuavizado()
{

}

bool HillSuavizado::lerDados()
{
	dadosX.clear();
	dadosY.clear();
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

void HillSuavizado::gerDIFFA(VetorDados x,long double a,long double b, long double c)
{
	diffA.clear();
	for(unsigned int pos=0;pos<x.size()-1;pos++)
	{
		diffA.push_back(DIFFA(x[pos],a,b,c));
	}
}

void HillSuavizado::gerDIFFB(VetorDados x,long double a,long double b, long double c)
{
	diffB.clear();
	for(unsigned int pos=0;pos<x.size()-1;pos++)
	{
		diffB.push_back(DIFFB(x[pos],a,b,c));
	}
}

void HillSuavizado::gerDIFFC(VetorDados x,long double a,long double b, long double c)
{
	diffC.clear();
	for(unsigned int pos=0;pos<x.size()-1;pos++)
	{
		diffC.push_back(DIFFC(x[pos],a,b,c));
	}
}

void HillSuavizado::gerF(VetorDados x,long double a,long double b, long double c)
{
	dadosF.clear();
	for(unsigned int pos=0;pos<x.size()-1;pos++)
	{
		dadosF.push_back(F(x[pos],a,b,c));
	}
}

Matrix HillSuavizado::montaZ() throw(int)
{
		if(diffA.size()!=diffB.size() || diffB.size()!=diffC.size()) throw(5);
		Matrix tempZ(diffA.size(),3);
		for(int l=0,pos=0; l<tempZ.num_rows(); l++,pos++)
			{
			tempZ[l][0]=diffA[pos];
			tempZ[l][1]=diffB[pos];
			tempZ[l][2]=diffC[pos];
			}
		return tempZ;
}
Matrix HillSuavizado::transposta(Matrix A)
{
	Matrix temp(A.num_cols(),A.num_rows());
		for(int l=0; l<A.num_rows(); l++)
			for(int c=0; c<A.num_cols(); c++)
				temp[c][l]=A[l][c];
	return(temp);
}

Matrix HillSuavizado::setErro(VetorDados x,VetorDados y)
{
	Matrix temp(x.size(),1);
	for(unsigned int pos=0; pos<x.size();pos++) temp[pos][0]=x[pos]-y[pos];
	return temp;
}

void HillSuavizado::executa()
{
	VetorDados I;
	do{
		gerDIFFA(dadosX,a,b,c);
		gerDIFFB(dadosX,a,b,c);
		gerDIFFC(dadosX,a,b,c);
		gerF(dadosX,a,b,c);
		erro = setErro(dadosY,dadosF);

		Matrix A(transposta(montaZ()) * montaZ());
		Matrix B(transposta(montaZ()) * erro);

		Gauss sistemaDeEquacoes(3);
		sistemaDeEquacoes.Seidel(A,B);

		I = sistemaDeEquacoes.getResultado();

		this->a+=I[0];
		this->b+=I[1];
		this->c+=I[2];
	}
	while(abs(I[0])>E || abs(I[1])>E || abs(I[2])>E);

	final.clear();
	final.push_back(a);
	final.push_back(b);
	final.push_back(c);
}

double HillSuavizado::Tempo_Execucao(void(HillSuavizado::*function)(void))
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
