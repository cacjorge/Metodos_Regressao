/*
 * Exponencial.h
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */

#ifndef Exponencial_H_
#define Exponencial_H_

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

#define DIFFA(x,a,b) ( exp(b*x) )
#define DIFFB(x,a,b) ( a*x*exp(b*x) )
#define F(x,a,b) 	  ( a*exp(b*x) )

using namespace std;
typedef vector<long double> VetorDados;

class Exponencial {
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
	static const long double E=0.00001;

public:
	Exponencial(string);
	bool lerDados();
	long double getYMAX(){ return ymax; };
	VetorDados getFINAL(){ return final; };
	void gerDIFFA(VetorDados x,long double a,long double b);
	void gerDIFFB(VetorDados x,long double a,long double b);
	void gerF(VetorDados x,long double a,long double b);
	VetorDados setErro(VetorDados x,VetorDados y);
	Matriz *montaZ() throw(int);
	void executa();
	double Tempo_Execucao(void(Exponencial::*function)(void));
	virtual ~Exponencial();
};

#endif /* Exponencial_H_ */
