#pragma once

#include <fstream>
#include "Pracownik.h"


class ListaPracownikow {
	private:
		Pracownik* m_pPoczatek;
		int m_nLiczbaPracownikow;
    void WyswietlMenu();

	public:
		ListaPracownikow();
		~ListaPracownikow();


		void Dodaj(const Pracownik& p);
		void Usun(const Pracownik& wzorzec);
		void WypiszPracownikow() const;
		const Pracownik* Szukaj(const char* nazwisko, const char* imie);

    void InterfejsDoListy();
    void ZapiszDoPliku(const char* filename);
    void OdczytajZPliku(const char* filename);
};
