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
#include <tnt/tnt.h>
#include "Gauss.h"

#define DIFFA(x,a,b,c) (- (pow(x,c)/pow(a+b*pow(x,c),2)) )
#define DIFFB(x,a,b,c) (- (pow(x,2*c)/pow(a+b*pow(x,c),2)) )
#define DIFFC(x,a,b,c) ( a*pow(x,c)*log(x)/pow(a+b*pow(x,c),2) )
#define F(x,a,b,c) 	  ( pow(x,c)/(a+b*pow(x,c)) )

using namespace std;
typedef vector<long double> VetorDados;
typedef TNT::Matrix<long double> Matrix;

class HillSuavizado {
private:
	string nomeArquivo;

	VetorDados dadosX;
	VetorDados dadosY;
	VetorDados diffA;
	VetorDados diffB;
	VetorDados diffC;
	VetorDados dadosF;
	VetorDados final;
	Matrix erro;

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
	Matrix setErro(VetorDados x,VetorDados y);
	Matrix montaZ() throw(int);
	Matrix transposta(Matrix A);
	void executa();
	double Tempo_Execucao(void(HillSuavizado::*function)(void));
	virtual ~HillSuavizado();
};

#endif /* HillSuavizado_H_ */
