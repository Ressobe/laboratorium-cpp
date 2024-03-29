#pragma once

#include "../napis/Napis.h"
#include "../data/Data.h"

class Pracownik {
  private:
    Napis m_Imie;
    Napis m_Nazwisko;
    Data m_DataUrodzenia;

    static int s_nLiczbaPracownikow; 
    const int m_nIDZatrudnienia;

  public:
    Pracownik* m_pNastepny = nullptr;

    Pracownik(const char* im = "", const char * naz = "", int dzien = 1, int miesiac = 1, int rok = 1); 
    Pracownik(const Pracownik& wzor);

    int Porownaj(const Pracownik& wzorzec) const;
    const char* Imie() const;
    const char* Nazwisko() const;

    void Imie(const char* nowe_imie);
    void Nazwisko(const char* nowe_nazwisko);
    void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);

    void Wypisz() const;
    void Wpisz();

    int SprawdzImie(const char* por_imie) const;
    int SprawdzNazwisko(const char* por_nazwisko) const;

    Pracownik& operator=(const Pracownik & wzor);
    bool operator==(const Pracownik & wzor) const;

    friend std::ostream& operator<<(std::ostream& wy, const Pracownik& p);
    friend std::istream& operator>>(std::istream& we, Pracownik& p);

    virtual void WypiszDane();
    virtual Pracownik* KopiaObiektu() const;
    virtual ~Pracownik() = default;
};
