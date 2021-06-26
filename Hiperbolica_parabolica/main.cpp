/*
 * main.cpp
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */
#include "Hiperbolica_parabolica.h"

int main(){

	Hiperbolica_parabolica obj("XY.dat");
	void(Hiperbolica_parabolica::*EXEC)(void) = &Hiperbolica_parabolica::executa;

	cout<<endl<<"Tempo de Execução: "<<obj.Tempo_Execucao(EXEC)<<" us"<<endl;
	cout<<endl<<"Resultado: "
			<<endl<<"Coeficiente 'a': "<<obj.getFINAL()[0]
			<<endl<<"Coeficiente 'b': "<<obj.getFINAL()[1]<<endl;
}
