/*
 * Linear.h
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */

#ifndef Linear_H_
#define Linear_H_

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

#define DIFFA(x,a,b) ( x )
#define DIFFB(x,a,b) ( 1 )
#define F(x,a,b) 	  ( (a*x)+b )

using namespace std;
typedef vector<long double> VetorDados;

class Linear {
private:
	string nomeArquivo;

	VetorDados dadosX;
	VetorDados dadosY;
	VetorDados diffA;
	VetorDados diffB;
	VetorDados dadosF;
	VetorDados erro;
	VetorDados final;

	long double ymax;
	long double a;
	long double b;
	long double c;
	static const long double E=0.00001;

public:
	Linear(string);
	bool lerDados();
	long double getYMAX(){ return ymax; };
	void setABC(long double a,long double b,long double c){ this->a=a;this->b=b;this->c=c; };
	VetorDados getFINAL(){ return final; };
	void gerDIFFA(VetorDados x,long double a,long double b);
	void gerDIFFB(VetorDados x,long double a,long double b);
	void gerF(VetorDados x,long double a,long double b);
	VetorDados setErro(VetorDados x,VetorDados y);
	Matriz *montaZ() throw(int);
	void executa();
	double Tempo_Execucao(void(Linear::*function)(void));
	virtual ~Linear();
};

#endif /* Linear_H_ */
