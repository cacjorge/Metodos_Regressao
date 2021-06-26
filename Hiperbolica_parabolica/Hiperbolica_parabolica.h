/*
 * Hiperbolica_parabolica.h
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */

#ifndef Hiperbolica_parabolica_H_
#define Hiperbolica_parabolica_H_

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

#define F(x,a,b) 	  ( sqrt(x)/(a+b*sqrt(x)) )
#define DIFFA(x,a,b) (- (x/(pow((a+b*x),2)) ) )
#define DIFFB(x,a,b) (- (pow(x,2)/(pow((a+b*x),2)) ) )


using namespace std;
typedef vector<long double> VetorDados;

class Hiperbolica_parabolica {
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
	Hiperbolica_parabolica(string);
	bool lerDados();
	long double getYMAX(){ return ymax; };
	VetorDados getFINAL(){ return final; };
	void gerDIFFA(VetorDados x,long double a,long double b);
	void gerDIFFB(VetorDados x,long double a,long double b);
	void gerF(VetorDados x,long double a,long double b);
	VetorDados setErro(VetorDados x,VetorDados y);
	Matriz *montaZ() throw(int);
	void executa();
	double Tempo_Execucao(void(Hiperbolica_parabolica::*function)(void));
	virtual ~Hiperbolica_parabolica();
};

#endif /* Hiperbolica_parabolica_H_ */
