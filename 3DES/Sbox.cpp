#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <deque>
#include <list>
#include <iterator>
#include <vector>
#include "SequenceD.cpp"

//Ibrahim & Cylia LAST v : 14 06 2020
//TOUTES LES METHODES DE CETTE CLASSE FONCTIONNENT CORRECTEMENT

class Sbox
{
private:
    //UN TAB DE INT VA ETRE PLUS SIMPLE A MANIPULER COMME INDIQUE DANS LE DESCRIPTIF
    int **box;

public:
    Sbox(int **);
    Sbox(Sbox &);
    ~Sbox();
    Sbox &operator=(Sbox &);
    int getValue(int, int);
    Sequence operator()(Sequence);
};
//cette methode nous permet de passer de bits vers decimals
int todecimal(Sequence a)
{
    int rem, temp, dec = 0, b = 1;
    int bin = 0;
    //Transformation en chiffre
    while (a.size() < 6)
        a.push();

    for (int i = 0; i < a.size(); i++)
        bin += a[i] * pow(10, a.size() - i - 1);
    temp = bin;
    while (temp > 0)
    {
        rem = temp % 10;
        dec = dec + rem * b;
        b *= 2;
        temp /= 10;
    }
    return dec;
}

Sbox::Sbox(int **tabInitial)
{
    //ALLOCATION DE MEMOIRE
    box = new int *[16 * 4];
    Sequence nul = 0;
    box[0] = new int[16 * 4];
    for (int i = 1; i < 4; i++)
        box[i] = box[i - 1] + 16;
    //affectation
    box = tabInitial;
}
//CONSTRUCTEUR DE RECOPIE
Sbox::Sbox(Sbox &newBox)
{
    box = newBox.box;
}

Sbox &Sbox::operator=(Sbox &s)
{
    return s;
}
int Sbox::getValue(int row, int col)
{
    return box[row][col];
}
Sequence Sbox::operator()(Sequence a)
{

    int row, col;
    list<int> rowl, coll;
    Sequence result = Sequence(4);
    // on recupere la ligne
    rowl.push_front(a[5]);
    rowl.push_front(a[0]);
    // on recupere la colonne
    coll.push_front(a[4]);
    coll.push_front(a[3]);
    coll.push_front(a[2]);
    coll.push_front(a[1]);
    //convertion en entier
    row = a(5) * 2 + a(5) * 4;
    row = todecimal(Sequence(rowl));
    col = todecimal(Sequence(coll));
    const auto val = getValue(row, col);
    result = val;
    return result;
}

Sbox::~Sbox()
{

    delete[] box[0];
    delete[] box;
}
/*
int main()
{
    
}*/