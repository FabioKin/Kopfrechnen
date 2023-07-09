#include "logarithm.h"

logarithm::logarithm():upperBound(0),check_conf_Input(false)
{
	//Befüllen des Arrays nach den in der Header Datei angegebenen Beschreibungen
	//Mantissen von log(n) als ganze Zahl < 10000.
	for (size_t i = 0; i < log_array.size(); ++i) {
		if (i < 9) {
			log_array[i] = std::round(std::log10(i + 1.0)*10000.0);
		}
		else if (i == 9) {
			log_array[i] = 0;
		}
		else if (i >= 10 && i < 99) {
			log_array[i] = std::round((std::log10(i + 1.0) - 1.0)*10000.0);
		}
		else if (i == 99) {
			log_array[i] = 0;
		}
		else if (i >= 100 && i < 999) {
			log_array[i] = std::round((std::log10(i + 1.0) - 2.0)*10000.0);
		}
		else if (i == 999) {
			log_array[i] = 0;
		}
	}

	indices.clear();
}

//Diese Funktion enthält den Lernzyklus. In einer einfachen do-while-Schleife wird solange abgefragt und geprüft bis die Eingabe 0 gegeben wird.
int logarithm::learn()
{
	double input = -1.0;	//Initialisierung erfolgt so, da es in Ausnahmefällen passieren kann, dass der std::cin Befehl beim ersten Durchlauf nicht erreicht wird 
							//und es so nicht zu einem Abbruch der Schleife kommt.
	unsigned int n = 0;		//Laufindex

	//Prüfe ob eine korrekte Eingabe gemacht wurde oder die 0 zum Beenden eingegeben wurde. Falls alles korrekt ist fahre fort.
	if (check_conf_Input) {

		do {
			//Falls der Laufindex zu groß wird (die Größe des Arrays/Vectors überschreitet, wird dieser auf 0 gesetzt und
			//die Indices erneut durchgemischt. So ist nach jedem vollem Durchgang eine neue Reihenfolge vorhanden.
			if (n >= indices.size()) {
				std::random_shuffle(indices.begin(), indices.end());
				n = 0;
			}
			else if (indices[n] + 1 == 1 || indices[n] + 1 == 10 || indices[n] + 1 == 100) {
				//Übergang zum nächsten Durchlauf, dh. fahre mit den nächsten Index fort. 
				//Da log(10) := 0 (in der obgien Darstellung) würde bei korrekter Eingabe der Zyklus abgebrochen.
				++n;
			}
			else {
				std::cout << "log(" << indices[n] + 1 << ") = ? (0 zum beenden)" << std::endl; //+ 1, da indices bei 0 beginnen die zu übenden Zahlen aber bei 1 
				std::cin >> input;
				if (input == log_array[indices[n]]) {
					std::cout << "Korrekt!" << std::endl;
				}
				else {
					std::cout << log_array[indices[n]] << std::endl;
				}
				++n;
			}
		} while (input != 0);
		//Reset der Variablen für den Input Check, da bei einem weiteren Durchlauf sonst trotz der Eingabe von 0 das Programm nicht abgebrochen werden würde.
		check_conf_Input = false;
		return 0;
	}
	else {
		//Reset. Siehe Ende if.
		check_conf_Input = false;
		return 0;
	}
}

//Konfiguration des Trainings
//	- bis zu welcher ganzen Zahl soll trainiert werden
//	- anschließend erstellen eines vectors mit der entsprechenden Anzahl an Indizes und schließlich das durchmischen dieser
void logarithm::configure()
{
	std::cout << "Konfiguration des Trainings: " << std::endl;
	std::cout << "Bis zu welcher Zahl soll trainiert werden (Hinweis: Bisher nur Zahlen von 2 bis 100. 0 R\x81 \bckkehr zum Hauptmen\x81)?" << std::endl;
	while (!check_conf_Input) {
		std::cin >> upperBound;
		if (upperBound == 0) {
			return;
		}
		else if (upperBound > 1 && upperBound < 101) {
			check_conf_Input = true;
		}
		else {
			std::cout << "Ihre Eingabe liegt nicht im gefordertem Intervall (2 bis 100)! Bitte erneut eingeben (0 R\x81 \bckkehr zum Hauptmen\x81): " << std::endl;
		}
	}
	std::cout << std::endl;

	//Befüllen eines Arrays mit den Indizes (n viele) der zu lernenden Zahlen
	indices.reserve(upperBound);
	for (size_t i = 0; i < upperBound; ++i) {
		indices.push_back(i);
	}

	/*
	//Ausgabe der Indizes
	for (size_t i = 0; i < indices.size(); ++i) {
	std::cout << indices[i] << std::endl;
	}
	*/

	//Zufälliges vertauschen der Indices
	std::random_shuffle(indices.begin(), indices.end());
}
