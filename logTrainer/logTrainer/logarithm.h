#pragma once

//Dieses Programm dient dem Auswendiglernen der dekadischen Logarithmen (vierstellige Mantissen) der Zahlen von 2 bis 99.
//Hierzu wird eine zufällige Zahl n zwischen 1 und 100 ausgewählt und eine Eingabe abgewartet.
//Ist die Angabe das richtige Ergebnis der Rechnung log(n) dann wird die nächste Zahl angezeigt.
//Wenn die Eingabe falsch ist wird das richtige Ergebnis angezeigt und forgefahren.

/*
Ver 0.1:
Features:
	- Einfache Konfiguration des Trainingsintervalls (Angabe der oberern Grenze)
	- Alle Zahlen des gefordeten Intervalls werden genau einmal in einer zufäliligen Reihenfolge abgefragt. Anschließend werden die Indizes neu gemischt.
	- Bei falscher Eingabe wird das richtige Ergebnis ausgegeben und mit der nächsten Zahl weitergemacht.

ToDo:
	- Features Punkt 3. Eventuell bei falscher Eingabe das richtige Ergebnis zwar Ausgeben aber die gleiche Zahl nochmal abfragen, damit man sie
		einmal richtig abtippen muss.
	- Bei Trainingsende eine kleine Auswertung einfügen. % Korrekt bzw. Falsch etc.
	- Ergebnisse mit führenden Nullen auf vier Stellen erweitern, also anstatt log(11) = 414 muss 0414 eingegeben werden.
	- Verschiedene Lernmodi. zB Lern- und Prüfmodus. Lernmodus beliebig wie oben und Prüfmodus einmal alle Zahlen bis zu
		einer bestimmten Grenze prüfen.
	- Lernmodus mit unterschiedlichen Wahrscheinlichkeiten für die Wiederkehr von bestimmten Zahlen. zB eine korrekte
		Antwort führt zu einer leicht niedrigeren Wahrscheinlichkeit, dass die entsprechende Zahl wieder auftaucht und
		umgekehrt. Hier alle Wahrscheinlichkeiten bei jedem Schritt anpassen.
			->	Möglichkeit die Wahrscheinlichkeiten zu speichern für das nächste Training mit dem gleichen Intervall
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
	//mit 10000 eine 1 abgezogen wird, damit nur die Mantissen übrig bleiben. Zudem wird
	//das Ergebnis des Logarithmierens noch gerundet um so eine ganze Zahl zu erhalten
	//die aus den ersten vier Mantissen des entsprechenden Logarithmus besteht.
	std::array<double, 1000> log_array;
	//obere Grenze der Zahlen bis zu der trainiert werden soll
	unsigned int upperBound;
	//Vector mit den Indizes (n viele) der zu lernenden Zahlen
	std::vector<int> indices;
	//bool zum Überprüfen der Eingabe in der Funktion configure(). Wird in der Funktion learn() genutzt um das Training zu beenden.
	bool check_conf_Input;
public:
	logarithm();
	//Konfiguration des Trainings. Infos siehe Implementierung.
	void configure();
	//Trainingszyklus. siehe Implementierung.
	int learn();
};