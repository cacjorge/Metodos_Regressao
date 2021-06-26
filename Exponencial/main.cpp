/*
 * main.cpp
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */
#include "Exponencial.h"

int main(){

	Exponencial obj("XY.dat");
	void(Exponencial::*EXEC)(void) = &Exponencial::executa;

	cout<<endl<<"Tempo de Execução: "<<obj.Tempo_Execucao(EXEC)<<" us"<<endl;
	cout<<endl<<"Resultado: "
			<<endl<<"Coeficiente 'a': "<<obj.getFINAL()[0]
			<<endl<<"Coeficiente 'b': "<<obj.getFINAL()[1]<<endl;
}
