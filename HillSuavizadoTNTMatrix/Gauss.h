/*
 * Gauss.h
 *
 *  Created on: Jan 19, 2010
 *      Author: carlos
 */

#ifndef GAUSS_H_
#define GAUSS_H_
#include <iostream>
#include <vector>
#include <tnt/tnt.h>

using namespace std;

typedef TNT::Matrix<long double> Matrix;

class Gauss {
private:
	static const long double erro=0.00000001;
	int len;
	vector<long double> result;
public:
	Gauss(int tam):len(tam){};
	virtual ~Gauss(){};
	long double Subtratorio(vector<long double> X1,Matrix &A,int lin);
	long double max(vector<long double> X1);
	vector<long double> diferenca(vector<long double> X1,vector<long double> Y);
	void escreve(vector<long double> X1,int iteracao);
	void copy(long double *X1, long double *X2);
	long double abs(long double v);
	void Seidel(Matrix &A, Matrix &B);
	vector<long double> getResultado(){ return result; };
};

#endif /* GAUSS_H_ */
