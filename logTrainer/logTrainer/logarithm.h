#pragma once

//Dieses Programm dient dem Auswendiglernen der dekadischen Logarithmen (vierstellige Mantissen) der Zahlen von 2 bis 99.
//Hierzu wird eine zuf�llige Zahl n zwischen 1 und 100 ausgew�hlt und eine Eingabe abgewartet.
//Ist die Angabe das richtige Ergebnis der Rechnung log(n) dann wird die n�chste Zahl angezeigt.
//Wenn die Eingabe falsch ist wird das richtige Ergebnis angezeigt und forgefahren.

/*
Ver 0.1:
Features:
	- Einfache Konfiguration des Trainingsintervalls (Angabe der oberern Grenze)
	- Alle Zahlen des gefordeten Intervalls werden genau einmal in einer zuf�liligen Reihenfolge abgefragt. Anschlie�end werden die Indizes neu gemischt.
	- Bei falscher Eingabe wird das richtige Ergebnis ausgegeben und mit der n�chsten Zahl weitergemacht.

ToDo:
	- Features Punkt 3. Eventuell bei falscher Eingabe das richtige Ergebnis zwar Ausgeben aber die gleiche Zahl nochmal abfragen, damit man sie
		einmal richtig abtippen muss.
	- Bei Trainingsende eine kleine Auswertung einf�gen. % Korrekt bzw. Falsch etc.
	- Ergebnisse mit f�hrenden Nullen auf vier Stellen erweitern, also anstatt log(11) = 414 muss 0414 eingegeben werden.
	- Verschiedene Lernmodi. zB Lern- und Pr�fmodus. Lernmodus beliebig wie oben und Pr�fmodus einmal alle Zahlen bis zu
		einer bestimmten Grenze pr�fen.
	- Lernmodus mit unterschiedlichen Wahrscheinlichkeiten f�r die Wiederkehr von bestimmten Zahlen. zB eine korrekte
		Antwort f�hrt zu einer leicht niedrigeren Wahrscheinlichkeit, dass die entsprechende Zahl wieder auftaucht und
		umgekehrt. Hier alle Wahrscheinlichkeiten bei jedem Schritt anpassen.
			->	M�glichkeit die Wahrscheinlichkeiten zu speichern f�r das n�chste Training mit dem gleichen Intervall
*/

#include<iostream>
#include<array>
#include<cmath>
#include<vector>
#include<algorithm>

class logarithm {
private:
	//Das Array logarithms wird die dek. Logarithmen der Zahlen zwischen 2 und 99 enthalten.
	//Diese werden in Form einer ganzen Zahl < 10000 dargestellt. Wobei bei allen Zahlen ab
	//der 10 nach dem Logarithmieren von dem entsprechenden Ergebnis VOR der Multiplikation 
	//mit 10000 eine 1 abgezogen wird, damit nur die Mantissen �brig bleiben. Zudem wird
	//das Ergebnis des Logarithmierens noch gerundet um so eine ganze Zahl zu erhalten
	//die aus den ersten vier Mantissen des entsprechenden Logarithmus besteht.
	std::array<double, 1000> log_array;
	//obere Grenze der Zahlen bis zu der trainiert werden soll
	unsigned int upperBound;
	//Vector mit den Indizes (n viele) der zu lernenden Zahlen
	std::vector<int> indices;
	//bool zum �berpr�fen der Eingabe in der Funktion configure(). Wird in der Funktion learn() genutzt um das Training zu beenden.
	bool check_conf_Input;
public:
	logarithm();
	//Konfiguration des Trainings. Infos siehe Implementierung.
	void configure();
	//Trainingszyklus. siehe Implementierung.
	int learn();
};