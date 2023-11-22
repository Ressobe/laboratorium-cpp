#include "Napis.h"
#include "Data.h"
#include "Pracownik.h"
#include <iostream>
#include <vector>


void testKoryguj() {
	Data data1;
	
	data1.Ustaw(32, 1, 2022);
	data1.Wypisz();

	data1.Ustaw(30, 2, 2024);
	data1.Wypisz();

	data1.Ustaw(29, 2, 2023);
	data1.Wypisz();


	data1.Ustaw(0, 4, 2022);
	data1.Wypisz();

	data1.Ustaw(31, 4, 2022);
	data1.Wypisz();

	data1.Ustaw(31, 6, 2022);
	data1.Wypisz();

	data1.Ustaw(32, 12, 2022);
	data1.Wypisz();
}


void testDataPorownaj() {
	Data data1;
	Data data2;

	data1.Ustaw(29, 2, 2024);
	data2.Ustaw(28, 2, 2025);

	std::cout << "Porownanie - 1 " << std::endl;
	std::cout << data2.Porownaj(data1) << std::endl;

	data1.Ustaw(31, 1, 2022);
	data2.Ustaw(1, 2, 2022);

	std::cout << "Porownanie - 2 " << std::endl;
	std::cout << data1.Porownaj(data2) << std::endl;

	data1.Ustaw(30, 4, 2022);
	data2.Ustaw(1, 5, 2022);

	std::cout << "Porownanie - 3 " << std::endl;
	std::cout << data2.Porownaj(data1) << std::endl;

	data1.Ustaw(31, 12, 2022);
	data2.Ustaw(1, 1, 2023);

	std::cout << "Porownanie - 4 " << std::endl;
	std::cout << data1.Porownaj(data2) << std::endl;
	
	data1.Ustaw(29, 2, 2000);
	data2.Ustaw(28, 2, 2100);


	std::cout << "Porownanie - 5 " << std::endl;
	std::cout << data2.Porownaj(data1) << std::endl;
	
	data1.Ustaw(1, 1, 1);
	data2.Ustaw(1, 1, 3000);

	std::cout << "Porownanie - 6 " << std::endl;
	std::cout << data1.Porownaj(data2) << std::endl;
}

void testNapis() {
	Napis napis1;
    Napis napis2;

    // Ustawienie tekstu w obiektach
    napis1.Ustaw("Hello, world!");
    napis2.Ustaw("Testowy napis");

    // Wyœwietlenie zawartoœci obiektów
    std::cout << "Napis 1: ";
    napis1.Wypisz();
    std::cout << std::endl;

    std::cout << "Napis 2: ";
    napis2.Wypisz();
    std::cout << std::endl;

    // Porównanie napisów
    int wynikPorownania = napis1.SprawdzNapis("Hello, world!");
    if (wynikPorownania == 0) {
        std::cout << "Napis 1 jest identyczny z podanym wzorcem." << std::endl;
    } else {
        std::cout << "Napis 1 nie jest identyczny z podanym wzorcem." << std::endl;
    }

    wynikPorownania = napis2.SprawdzNapis("Inny napis");
    if (wynikPorownania == 0) {
        std::cout << "Napis 2 jest identyczny z podanym wzorcem." << std::endl;
    } else {
        std::cout << "Napis 2 nie jest identyczny z podanym wzorcem." << std::endl;
    }

    // Wprowadzenie nowego napisu ze standardowego wejœcia
    std::cout << "Podaj nowy napis: ";
    napis1.Wpisz();

    // Wyœwietlenie zaktualizowanej zawartoœci napisu
    std::cout << "Napis 1 po aktualizacji: ";
    napis1.Wypisz();
    std::cout << std::endl;
}


void testPracownik() {
	Pracownik programista1;
	programista1.Wpisz();

	std::cout << programista1.Imie() << std::endl ;
	std::cout << programista1.Nazwisko() << std::endl ;


	std::cout << programista1.SprawdzImie("adf");

}

int main() {
	testPracownik();
}