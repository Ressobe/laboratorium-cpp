#include "ListaPracownikow.h"


void ListaPracownikow::Dodaj(const Pracownik& p) {
    if (this->Szukaj(p.Nazwisko(), p.Imie()) != nullptr) {
        return;
    }

    Pracownik* nowyPracownik = new Pracownik(p);


    Pracownik* obecny = m_pPoczatek;
    Pracownik* poprzedni = nullptr;

    while (obecny != nullptr && obecny->Porownaj(*nowyPracownik) < 0) {
        poprzedni = obecny;
        obecny = obecny->m_pNastepny;
    }

    if (poprzedni == nullptr) {
        nowyPracownik->m_pNastepny = m_pPoczatek;
        m_pPoczatek = nowyPracownik;
    } else {
        poprzedni->m_pNastepny = nowyPracownik;
        nowyPracownik->m_pNastepny = obecny;
    }

    m_nLiczbaPracownikow++;
}

void ListaPracownikow::Usun(const Pracownik& wzorzec) {
    if (this->Szukaj(wzorzec.Nazwisko(), wzorzec.Imie()) == nullptr) {
        return;
    }

    Pracownik* obecny = m_pPoczatek;
    Pracownik* poprzedni = nullptr;
    
    while (obecny != nullptr && obecny->Porownaj(wzorzec) != 0) {
        poprzedni = obecny;
        obecny = obecny->m_pNastepny;
    }

    poprzedni->m_pNastepny = obecny->m_pNastepny;

    delete obecny;
}


ListaPracownikow::ListaPracownikow() {
  this->m_nLiczbaPracownikow = 0;
  this->m_pPoczatek = nullptr;
}


ListaPracownikow::~ListaPracownikow() {
  Pracownik* next = m_pPoczatek->m_pNastepny;
  Pracownik* temp = nullptr;

  while (next != nullptr) {
    temp = next;
    next = next->m_pNastepny;

    delete temp;
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
