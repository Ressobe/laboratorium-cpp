#include "ListaPracownikow.h"


void ListaPracownikow::Dodaj(const Pracownik& p) {
    if (this->Szukaj(p.Nazwisko(), p.Imie()) != nullptr) {
        return;
    }

    Pracownik* newPracownik = new Pracownik(p);
    Pracownik* current = m_pPoczatek;
    Pracownik* previous = nullptr;

    while (current != nullptr && current->Porownaj(*newPracownik) < 0) {
        previous = current;
        current = current->m_pNastepny;
    }

    if (previous == nullptr) {
        Pracownik* save = m_pPoczatek;
        m_pPoczatek = newPracownik;
        m_pPoczatek->m_pNastepny = save;
    }
    else {
		Pracownik* save = previous->m_pNastepny;
		previous->m_pNastepny = newPracownik;
		newPracownik->m_pNastepny = save;
    }

    m_nLiczbaPracownikow++;
}


void ListaPracownikow::Usun(const Pracownik& wzorzec) {
    if (this->Szukaj(wzorzec.Nazwisko(), wzorzec.Imie()) == nullptr) {
        return;
    }

    Pracownik* current = m_pPoczatek;
    Pracownik* previous = nullptr;

    
    while (current != nullptr && current->Porownaj(wzorzec) != 0) {
        previous = current;
        current = current->m_pNastepny;
    }

    if (previous != nullptr && current != nullptr) {
        previous->m_pNastepny = current->m_pNastepny;
        delete current;
        m_nLiczbaPracownikow--;
    }
}


ListaPracownikow::ListaPracownikow() {
  this->m_nLiczbaPracownikow = 0;
  this->m_pPoczatek = nullptr;
}


ListaPracownikow::~ListaPracownikow() {
  if (m_pPoczatek == nullptr) return;

  Pracownik* next = m_pPoczatek;
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

		if ((checkImie == 0) && (checkNazwisko == 0)) {
			return p;
		}
        p = p->m_pNastepny;
	}
	return nullptr;
}
