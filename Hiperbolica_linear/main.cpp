/*
 * main.cpp
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */
#include "Hiperbolica_linear.h"

int main(){

	Hiperbolica_linear obj("XY.dat");
	void(Hiperbolica_linear::*EXEC)(void) = &Hiperbolica_linear::executa;

	cout<<endl<<"Tempo de Execução: "<<obj.Tempo_Execucao(EXEC)<<" us"<<endl;
	cout<<endl<<"Resultado: "
			<<endl<<"Coeficiente 'a': "<<obj.getFINAL()[0]
			<<endl<<"Coeficiente 'b': "<<obj.getFINAL()[1]<<endl;
}
