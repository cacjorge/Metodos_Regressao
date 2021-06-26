/*
 * main.cpp
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */
#include "Linear.h"

int main(){

	Linear obj("XY.dat");
	void(Linear::*EXEC)(void) = &Linear::executa;

	cout<<endl<<"Tempo de Execução: "<<obj.Tempo_Execucao(EXEC)<<" us"<<endl;
	cout<<endl<<"Resultado: "
			<<endl<<"Coeficiente 'a': "<<obj.getFINAL()[0]
			<<endl<<"Coeficiente 'b': "<<obj.getFINAL()[1]
	        <<endl<<"Coeficiente 'c': "<<obj.getFINAL()[2]<<endl;
}
