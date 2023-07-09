#include "multiplication.h"

multiplication::multiplication():_length(0),_block(0),_check_conf_Input(false)
{

}

void multiplication::configure()
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

	std::cout << "Wie viele Zahlen sollen miteinander multipliziert werden (2-10)? (0 R\x81 \bckkehr zum Hauptmen\x81)?" << std::endl;
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

int multiplication::learn()
{
	//Erzeugung  von (Pseudo-)Zufallszahlen in dem entsprechenden Zahlenbereich (vorgegeben durch die configure() Funktion)
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
			//Erzeugen der Faktoren
			std::vector<unsigned long long> factors(_block);
			for (size_t i = 0; i < factors.size(); ++i) {
				factors[i] = distribution(generator);
			}
			//Berechnung des Produkts
			unsigned long long product = std::accumulate(factors.begin(), factors.end(),static_cast<unsigned long long>(1), [](const unsigned long long &a, const unsigned long long &b) {return a*b; });
			//Ausgabe der Faktoren
			std::cout << std::endl << "\t" << factors[0] << std::endl;
			for (size_t i = 1; i < factors.size(); ++i) {
				std::cout << "*\t" << factors[i] << std::endl;
			}
			std::cout << "\t\t\t(0 R\x81 \bckkehr zum Hauptmen\x81)" << std::endl;
			//Einlesen des Ergebnisses
			std::cin >> input;
			if (input == product) {
				std::cout << std::endl << "Korrekt!" << std::endl;
			}
			else {
				std::cout << "\t" << product << std::endl;
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
