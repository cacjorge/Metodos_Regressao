/*
 * Gauss.cpp
 *
 *  Created on: Jan 19, 2010
 *      Author: carlos
 */

#include "Gauss.h"

long double Gauss::Subtratorio(vector<long double> X1,Matrix &A,int lin)
{
	long double total=0;
	for(int i=0;i<len;i++)
	if(i!=lin) total-= X1[i] * A[lin][i];
	return total;
}

long double Gauss::max(vector<long double> X1)
{
	long double max=X1[0];
	for(int i=0;i<len;i++) if(X1[i]>max) max=X1[i];
	return max;
}

vector<long double> Gauss::diferenca(vector<long double> X1,vector<long double> Y)
{
	vector<long double> dif(len,0);
	for(int i=0;i<len;i++) dif[i]=X1[i]-Y[i];
	return dif;
}


long double Gauss::abs(long double v)
{
	if(v<0)return v*-1;
	return v;
}

void Gauss::Seidel(Matrix &A,Matrix &B)
{
	vector<long double> X(len,0);
	vector<long double> X1(len,0);
	X1=X;
	while(true)
	{
		for(int i=0;i<len;i++) X1[i] = (B[i][0] + Subtratorio(X1,A,i))/A[i][i];
		if(abs(max(diferenca(X,X1))) < erro) break;
		X=X1;
		this->result=X;
	}

}
