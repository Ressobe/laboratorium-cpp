#include "Pracownik.h"

const char* Pracownik::Imie() const
{
	return this->m_Imie.Zwroc();
}

const char* Pracownik::Nazwisko() const
{
	return this->m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char* nowe_imie)
{
	this->m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	this->m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	this->m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	std::cout << this->m_Imie.Zwroc() << "		" << this->m_Nazwisko.Zwroc() << "		";
	this->m_DataUrodzenia.Wypisz();
}

void Pracownik::Wpisz()
{
	std::cout.flush();
	std::cout << "Podaj imie: ";
	this->m_Imie.Wpisz();

	std::cout << "Podaj nazwisko: ";
	this->m_Nazwisko.Wpisz();

	std::cout << "Podaj date urodzenia:	" << std::endl;
	this->m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char* por_imie) const
{
	return this->m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	return this->m_Nazwisko.SprawdzNapis(por_nazwisko);
}
