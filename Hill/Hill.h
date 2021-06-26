/*
 * Hill.h
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */

#ifndef Hill_H_
#define Hill_H_

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

#define F(x,a,b) 	  ( pow(x,b)/(a+cte*pow(x,b)) )
#define DIFFA(x,a,b) ( - (pow(x,b)/(a+cte*pow(x,b))) )
#define DIFFB(x,a,b) ( ((pow(x,b)*log(x))/(a+cte*pow(x,b))) - ((cte*pow(x,2*b)*log(x))/pow((a+cte*pow(x,b)),2)) )


using namespace std;
typedef vector<long double> VetorDados;

class Hill {
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
	long double cte;
	static const long double E=0.00001;

public:
	Hill(string);
	bool lerDados();
	long double getYMAX(){ return ymax; };
	VetorDados getFINAL(){ return final; };
	void gerDIFFA(VetorDados x,long double a,long double b);
	void gerDIFFB(VetorDados x,long double a,long double b);
	void gerF(VetorDados x,long double a,long double b);
	VetorDados setErro(VetorDados x,VetorDados y);
	Matriz *montaZ() throw(int);
	void executa();
	double Tempo_Execucao(void(Hill::*function)(void));
	virtual ~Hill();
};

#endif /* Hill_H_ */
