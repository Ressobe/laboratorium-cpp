#pragma once

#include <iostream>

class Data {
  private:
    int m_nDzien = 0;
    int m_nMiesiac = 0;
    int m_nRok = 0;
    void Koryguj();

  public:
    Data() {}
    Data(int d, int m, int r); 

    void Ustaw(int d, int m, int r);
    void Wypisz() const;
    void Wpisz();

    int Porownaj(const Data& wzor) const;
    int Dzien() const;
    int Miesiac() const;
    int Rok() const;
    friend std::ostream & operator<<(std::ostream & wy, const Data & d);
    friend std::istream & operator>>(std::istream & we, Data & d);
};
