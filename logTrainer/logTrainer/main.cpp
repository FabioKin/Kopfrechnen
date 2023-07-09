//Kleines Programm zum Kopfrechentraining mit verschiedenen Funktionen

/*
	Features:
		- einfaches textbasiertes Menü
		- Logarithmus Training
*/

/*	Vision: Kopfrechentraining Programm mit verschiednen Features:
			- Auswendig lernen von Logarithmen (zum Wurzelziehen)
			- Wurzelziehen mit ganzen Zahlen als Ergebnis (so.)
			- Muliplikation
			- Addition
			- Kalenderrechnung
			- Quadratwurzelziehen (hohe Genauigkeit)
			- Pi oder e auswendig lernen
			- etc.
*/

//Inlcudes
#include<iostream>
#include"logarithm.h"
#include"multiplication.h"
#include"summation.h"
#include"date.h"

int main() {

	//Ausgabe einiger Informationen
	std::cout << "Kleines Programm zum Kopfrechentraining" << std::endl;
	std::cout << "Version 0.2" << std::endl << std::endl;
	
	//Initialisierung der einzelnen Trainingsprogramme
	logarithm myLogTraining;
	multiplication myMultTraining;
	summation mySumTraining;
	date myDateTraining;

	//Menü
	int Input = 1;
	while (Input!=0) {
		std::cout << std::endl << "1 Logarithmen auswendiglernen (vierstellige Mantissen)" << std::endl;
		std::cout << "2 Multiplikation" << std::endl;
		std::cout << "3 Addition" << std::endl;
		std::cout << "4 Kalenderrechnung" << std::endl;
		std::cout << "0 Beenden" << std::endl << std::endl;
		std::cin >> Input;
		switch (Input){
		case 1:
			std::cout << std::endl << "Starte Logarithmentraining." << std::endl;
			myLogTraining.configure();
			myLogTraining.learn();
			break;
		case 2:
			std::cout << std::endl << "Starte Multiplikationstraining." << std::endl;
			myMultTraining.configure();
			myMultTraining.learn();
			break;
		case 3:
			std::cout << std::endl << "Starte Additionstraining." << std::endl;
			mySumTraining.configure();
			mySumTraining.learn();
			break;
		case 4:
			std::cout << std::endl << "Starte Kalenderrechnungstraing." << std::endl;
			myDateTraining.learn();
			break;
		case 0:
			std::cout << "Beende Programm." << std::endl;
			break;
		default:
			std::cout << "Falsche Eingabe. Bitte erneut eingeben." << std::endl;
			break;
		}
	}

	return 0;
}