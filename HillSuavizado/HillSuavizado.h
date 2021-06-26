/*
 * HillSuavizado.h
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */

#ifndef HillSuavizado_H_
#define HillSuavizado_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <sys/time.h>
#include "Gauss.h"
#include "Matriz.h"

#define DIFFA(x,a,b,c) (- (pow(x,c)/pow(a+b*pow(x,c),2)) )
#define DIFFB(x,a,b,c) (- (pow(x,2*c)/pow(a+b*pow(x,c),2)) )
#define DIFFC(x,a,b,c) ( a*pow(x,c)*log(x)/pow(a+b*pow(x,c),2) )
#define F(x,a,b,c) 	  ( pow(x,c)/(a+b*pow(x,c)) )

using namespace std;
typedef vector<long double> VetorDados;

class HillSuavizado {
private:
	string nomeArquivo;

	VetorDados dadosX;
	VetorDados dadosY;
	VetorDados diffA;
	VetorDados diffB;
	VetorDados diffC;
	VetorDados dadosF;
	VetorDados erro;
	VetorDados final;

	long double ymax;
	long double ymed;
	long double a;
	long double b;
	long double c;
	static const long double E=0.00001;

public:
	HillSuavizado(string);
	bool lerDados();
	long double getYMAX(){ return ymax; };
	long double getYMED(){ return ymed; };
	long double getSIZE(){ return dadosY.size(); };
	void setABC(long double a,long double b,long double c){ this->a=a;this->b=b;this->c=c; };
	VetorDados getFINAL(){ return final; };
	void gerDIFFA(VetorDados x,long double a,long double b, long double c);
	void gerDIFFB(VetorDados x,long double a,long double b, long double c);
	void gerDIFFC(VetorDados x,long double a,long double b, long double c);
	void gerF(VetorDados x,long double a,long double b, long double c);
	VetorDados setErro(VetorDados x,VetorDados y);
	Matriz *montaZ() throw(int);
	void executa();
	double Tempo_Execucao(void(HillSuavizado::*function)(void));

	void printMatriz(Matriz *mat){
     	for(int l=0;l<mat->tamanho_linha();l++)
     		{//inicio do for
	            cout<<"|";
           		int c=0;
		    	for(;c<mat->tamanho_coluna()-1;c++)
		    	    cout<<left<<setw(3)<<mat->obter(l,c)<<" ";
        	    cout<<left<<setw(3)<<mat->obter(l,c)<<"|"<<endl;
    		}//fim do for
	}
	void printAll(){
		for(unsigned int pos=0;pos<dadosF.size();pos++) cout<<endl<<dadosY[pos]<<"\t - \t"<<dadosF[pos]<<"\t = \t"<<erro[pos];
	}
	void printDIFF(){
			for(unsigned int pos=0;pos<diffA.size();pos++) cout<<endl<<diffA[pos]<<" "<<diffB[pos]<<" "<<diffC[pos];
		}
	virtual ~HillSuavizado();
};

#endif /* HillSuavizado_H_ */
