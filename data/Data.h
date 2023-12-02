#pragma once

#include <iostream>

class Data {
  private:
    int m_nDzien;
    int m_nMiesiac;
    int m_nRok;
    void Koryguj();

  public:
    void Ustaw(int d, int m, int r);
    void Wypisz() const;
    void Wpisz();

    int Porownaj(const Data& wzor) const;
    int Dzien() const;
    int Miesiac() const;
    int Rok() const;
};
