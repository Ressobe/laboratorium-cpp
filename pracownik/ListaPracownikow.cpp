#include "ListaPracownikow.h"


void ListaPracownikow::Dodaj(const Pracownik& p) {
    // Sprawdzamy, czy pracownik o takich danych już istnieje na liście
    if (this->Szukaj(p.Nazwisko(), p.Imie()) != nullptr) {
        return;  // Pracownik już istnieje, więc nie dodajemy go ponownie
    }

    // Tworzymy nowy pracownik
    Pracownik* nowyPracownik = new Pracownik(p);


    // W przeciwnym razie dodajemy pracownika w odpowiednie miejsce (rosnąco)
    Pracownik* obecny = m_pPoczatek;
    Pracownik* poprzedni = nullptr;

    while (obecny != nullptr && obecny->Porownaj(*nowyPracownik) < 0) {
        poprzedni = obecny;
        obecny = obecny->m_pNastepny;
    }

    if (poprzedni == nullptr) {
        // Nowy pracownik będzie pierwszym na liście
        nowyPracownik->m_pNastepny = m_pPoczatek;
        m_pPoczatek = nowyPracownik;
    } else {
        // Wstawiamy nowego pracownika między obecnym a poprzednim
        poprzedni->m_pNastepny = nowyPracownik;
        nowyPracownik->m_pNastepny = obecny;
    }

    m_nLiczbaPracownikow++;  // Zwiększamy liczbę pracowników
}


ListaPracownikow::ListaPracownikow() {
  this->m_nLiczbaPracownikow = 0;
  this->m_pPoczatek = nullptr;
}


ListaPracownikow::~ListaPracownikow() {
  Pracownik* next = m_pPoczatek->m_pNastepny;
  while (next != nullptr) {
    Pracownik* temp = next;
    next = next->m_pNastepny;
    delete next;
  }
}


void ListaPracownikow::WypiszPracownikow() const {
	Pracownik* p = this->m_pPoczatek;
	while (p != nullptr) {
		p->Wypisz();
		p = p->m_pNastepny;
	}
}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) {
	Pracownik* p = this->m_pPoczatek;
	while (p != nullptr) {
		int checkImie = p->SprawdzImie(imie);
		int checkNazwisko = p->SprawdzNazwisko(nazwisko);
		if (checkImie == 0 && checkNazwisko == 0) {
			return p;
		}
	}
	return nullptr;
}
