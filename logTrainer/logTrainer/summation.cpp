#include "summation.h"

summation::summation() :_length(0), _block(0), _check_conf_Input(false)
{
}

void summation::configure()
{
	std::cout << "Konfiguration des Trainings: " << std::endl;
	std::cout << "Wie viele Stellen sollen die Zahlen besitzen (1-10)? (0 R\x81 \bckkehr zum Hauptmen\x81)?" << std::endl;
	while (!_check_conf_Input) {
		std::cin >> _length;
		if (_length == 0) {
			return;
		}
		else if (_length > 0 && _length < 11) {
			_check_conf_Input = true;
		}
		else {
			std::cout << "Ihre Eingabe liegt nicht im geforderten Intervall (1 bis 10)! Bitte erneut eingeben (0 R\x81 \bckkehr zum Hauptmen\x81): " << std::endl;
		}
	}
	std::cout << std::endl;

	//Reset der Input Check Variablen zur weiteren Konfiguration
	_check_conf_Input = false;

	std::cout << "Wie viele Zahlen sollen addiert werden (2-10)? (0 R\x81 \bckkehr zum Hauptmen\x81)?" << std::endl;
	while (!_check_conf_Input) {
		std::cin >> _block;
		if (_block == 0) {
			return;
		}
		else if (_block > 1 && _block < 11) {
			_check_conf_Input = true;
		}
		else {
			std::cout << "Ihre Eingabe liegt nicht im geforderten Intervall (2 bis 10)! Bitte erneut eingeben (0 R\x81 \bckkehr zum Hauptmen\x81): " << std::endl;
		}
	}
	std::cout << std::endl;
}

int summation::learn()
{
	//Erzeugung eines (Pseudo-)Zufallszahlengenerators der in dem entsprechenden Zahlenbereich (vorgegeben durch die configure() Funktion) erzeugen kann.
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::independent_bits_engine<std::mt19937, 64, std::uint_fast64_t> generator(seed);
	unsigned int upperBound = 1, lowerBound = 0;
	for (unsigned int i = 1; i < _length + 1; i++)
		upperBound *= 10;
	lowerBound = upperBound / 10;
	std::uniform_int_distribution<unsigned long long> distribution(lowerBound, upperBound);

	double input = -1.0;	//Initialisierung erfolgt so, da es in Ausnahmefällen passieren kann, dass der std::cin Befehl beim ersten Durchlauf nicht erreicht wird 
							//und es so nicht zu einem Abbruch der Schleife kommt.

	//Prüfe ob eine korrekte Eingabe gemacht wurde oder die 0 zum Beenden eingegeben wurde. Falls alles korrekt ist fahre fort.
	if (_check_conf_Input) {

		do {
			//Erzeugen der Summanden
			std::vector<unsigned long long> summands(_block);
			for (size_t i = 0; i < summands.size(); ++i) {
				summands[i] = distribution(generator);
			}
			//Berechnung der Summe
			auto sum = std::accumulate(summands.begin(), summands.end(), static_cast<unsigned long long>(0));
			//Ausgabe der Summanden
			std::cout << std::endl << "\t" << summands[0] << std::endl;
			for (size_t i = 1; i < summands.size(); ++i) {
				std::cout << "+\t" << summands[i] << std::endl;
			}
			std::cout << "\t\t\t(0 R\x81 \bckkehr zum Hauptmen\x81)" << std::endl;
			//Einlesen des Ergebnisses
			std::cin >> input;
			if (input == sum) {
				std::cout << std::endl << "Korrekt!" << std::endl;
			}
			else {
				std::cout << "\t" << sum << std::endl;
			}
		} while (input != 0);
		//Reset der Variablen für den Input Check, da bei einem weiteren Durchlauf sonst trotz der Eingabe von 0 das Programm nicht abgebrochen werden würde.
		_check_conf_Input = false;
		return 0;
	}
	else {
		//Reset. Siehe Ende if.
		_check_conf_Input = false;
		return 0;
	}

	return 0;
}
