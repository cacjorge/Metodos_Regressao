/*
 * main.cpp
 *
 *  Created on: 14/01/2010
 *      Author: Carlos Antonio
 */
#include "HillSuavizado.h"

int main(){

	HillSuavizado obj("XY.dat");
	void(HillSuavizado::*EXEC)(void) = &HillSuavizado::executa;
	cout<<endl<<"Tempo de Execução: "<<obj.Tempo_Execucao(EXEC)<<" us"<<endl;
	cout<<endl<<"Resultado: "
			<<endl<<"Coeficiente 'a': "<<obj.getFINAL()[0]
			<<endl<<"Coeficiente 'b': "<<obj.getFINAL()[1]
	        <<endl<<"Coeficiente 'c': "<<obj.getFINAL()[2]
	        <<endl<<"Y MED: "<<obj.getYMED()<<endl;
}
