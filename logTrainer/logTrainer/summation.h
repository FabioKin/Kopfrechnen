#pragma once

//Dieses Programm dient dem Trainieren von Additionsaufgaben

#include<iostream>
#include<random>
#include<chrono>
#include<vector>
#include<numeric>

class summation {
private:
	//Definiert die Größe der Zahlen mit denen gerechnet werden sollen. zB. 4 entspricht Zahlen zwischen 1000-9999.
	unsigned int _length;
	//Definiert die Anzahl an Zahlen die addiert werden sollen
	unsigned int _block;
	//Prüfen der Konfigurationseingabe
	bool _check_conf_Input;

public:
	summation();
	void configure();
	int learn();
};