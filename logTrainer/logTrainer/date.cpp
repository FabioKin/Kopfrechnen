#include "date.h"

void date::create_date()
{
	//Überschreiben des eventuell vorhandenen vorherigen Datums
	_day = 0;
	_month = 0;
	_year = 0;
	_leapyear_test = false;

	//Erzeugung eines (Pseudo-)Zufallszahlengenerators der in dem entsprechenden Zahlenbereich (vorgegeben durch die configure() Funktion) erzeugen kann.
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::independent_bits_engine<std::mt19937, 64, std::uint_fast64_t> generator(seed);
	unsigned int upperBound_days = 31, lowerBound_days = 1;
	unsigned int upperBound_months = 12, lowerBound_months = 1;
	unsigned int upperBound_years = 2100, lowerBound_years = 1600;
	std::uniform_int_distribution<unsigned int> distribution_d(lowerBound_days, upperBound_days);
	std::uniform_int_distribution<unsigned int> distribution_m(lowerBound_months, upperBound_months);
	std::uniform_int_distribution<unsigned int> distribution_y(lowerBound_years, upperBound_years);

	//Erzeugen eines korrekten zufälligen Datums
	_year = distribution_y(generator);
	_month = distribution_m(generator);
	//Handelt es sich um den 1., 3., 5., 7., 8., 10. oder 12. Monat des Jahres, so kann der Monat bis zu 31 Tage haben.
	if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) {
		_day = distribution_d(generator);
	}
	//Handelt es sich dagegen um den 4., 6., 9., oder 11. Monat des Jahres so können diese nur bis zu 30 Tage haben.
	//Damit alle Tage gleich Wahrscheinlich vorkommen wird wenn der 31. als Tag ausgegeben wird. Solange ein neuer Tag ausgesucht bis es 
	//nicht mehr der 31. ist.
	else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
		_day = distribution_d(generator);
		while (_day == 31) {
			_day = distribution_d(generator);
		}
	}
	//Fall _month == 2 := Februar. Hier hat der Monat entweder bis zu 28 oder 29 Tage je nachdem ob es sich um ein Schaltjahr handelt oder nicht.
	else {
		//Prüfe, ob es sich um ein Schaltjahr handelt.
		if (_year % 4 == 0) {
			if (_year % 100 == 0) {
				if (_year % 400 == 0) {
					_leapyear_test = true;
				}
				else {
					_leapyear_test = false;
				}
			}
			else {
				_leapyear_test = true;
			}
		}
		else {
			_leapyear_test = false;
		}
		//Fall es handelt sich um ein Schaltjahr. Somit kann der Februar bis zu 29 Tage haben. while -> siehe Monate mit 30 Tagen.
		if (_leapyear_test) {
			_day = distribution_d(generator);
			while (_day > 29) {
				_day = distribution_d(generator);
			}
		}
		//Kein Schaltjahr. 28 Tage.
		else {
			_day = distribution_d(generator);
			while (_day > 28) {
				_day = distribution_d(generator);
			}
		}
	}
}

date::date():_day(0), _month(0), _year(0), _leapyear_test(false)
{
}

int date::learn()
{
	std::cout << std::endl << "1 Montag, 2 Dienstag, 3 Mittwoch, 4 Donnerstag, 5 Freitag, 6 Samstag, 7 Sonntag" << std::endl << std::endl;
	int input = -1;
	do {
		//Erzeugen eines Datums (wird in die Variablen _day, _month, _year geschrieben)
		create_date();
		//Ausgabe des Datums
		std::cout << std::endl << "\t" << _day << "." << _month << "." << _year << "\t(0 R\x81 \bckkehr zum Hauptmen\x81)" << std::endl;
		//Einlesen des Ergebnisses
		std::cin >> input;
		//Prüfen des Ergebnisses mithilfe der Kopfrechenmethode (Wikipedia: https://de.wikipedia.org/wiki/Wochentagsberechnung).
		//Berechnung des richtigen Wochentages
		int _act_day;
		int _d, _m, _y, _c, _ly;
		_d = _day % 7;
		std::vector<int> _m_numbers = { 0,3,3,6,1,4,6,2,5,0,3,5 };
		_m = _m_numbers[_month-1];
		_y = static_cast<int>((_year % 100) + std::floor((_year % 100) / 4.0)) % 7;
		_c = (3 - (static_cast<int>(std::floor(_year / 100.0)) % 4)) * 2;
		if (_month < 3 && _leapyear_test == true) {
			_ly = -1;
		}
		else {
			_ly = 0;
		}
		_act_day = (_d + _m + _y + _c + _ly) % 7;
		//In dieser Rechnung ist der Sonntag := 0. Da dies das Lernen abbrechen würde wird dieser auf 7 gesetzt.
		if (_act_day == 0) {
			_act_day = 7;
		}
		else {
			//do nothing. Alles ist korrekt.
		}
		//Prüfen des Ergebnisses
		if (input == _act_day) {
			std::cout << std::endl << "Korrekt!" << std::endl;
		}
		else {
			std::cout << "\t" << _act_day << std::endl;
		}
	} while (input != 0);

	return 0;
}
