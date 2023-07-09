#pragma once

//Dieses Programm dient dem Trainieren von Multiplikationsaufgaben

#include<iostream>
#include<random>
#include<chrono>
#include<numeric>

class multiplication {
private:
	//Definiert die Größe der Zahlen mit denen gerechnet werden sollen. zB. 4 entspricht Zahlen zwischen 1000-9999.
	unsigned int _length;
	//Definiert wie viele Zahlen miteinander multipliziert werden sollen
	unsigned int _block;
	//Prüfen der Konfigurationseingabe
	bool _check_conf_Input;

public:
	multiplication();
	void configure();
	int learn();
};