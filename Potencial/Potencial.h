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

#define DIFFA(x,a,b) ( pow(x,b) )
#define DIFFB(x,a,b) ( a*pow(x,b)*log10(x) )
#define F(x,a,b) 	  ( a*pow(x,b) )

using namespace std;
typedef vector<long double> VetorDados;

class Potencial {
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
	Potencial(string);
	bool lerDados();
	long double getYMAX(){ return ymax; };
	VetorDados getFINAL(){ return final; };
	void gerDIFFA(VetorDados x,long double a,long double b);
	void gerDIFFB(VetorDados x,long double a,long double b);
	void gerF(VetorDados x,long double a,long double b);
	VetorDados setErro(VetorDados x,VetorDados y);
	Matriz *montaZ() throw(int);
	void executa();
	double Tempo_Execucao(void(Potencial::*function)(void));
	virtual ~Potencial();
};

#endif /* Potencial_H_ */
