#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <deque>
#include <list>
#include <iterator>
#include <vector>
#include "Sequence.cpp"

class Sbox
{
private:
    Sequence **box;
public:
    Sbox(int **);
    Sbox(Sequence **);
    ~Sbox();
    Sbox operator=(Sbox);
    Sequence operator()(Sequence);
};
int todecimal(Sequence a){
    int  rem, temp, dec = 0, b = 1;
    int bin = 0;
    //Transformation en chiffre
    while (a.size()<6) a.push();
    
    for (int i = 0; i <a.size(); i++)bin+=a[i] *pow(10,a.size()-i-1);
    temp = bin;
    while (temp > 0){
        rem = temp % 10;
        dec = dec + rem * b;
        b *= 2;
        temp /= 10;
    }
    return dec;
}

Sbox::Sbox(int ** tabInitial)
{
    //ALLOCATION DE MEMOIRE 
    box = new Sequence*[16*4];
    Sequence nul =0;
    box[0] = new Sequence[16*4];
    for(int i=1;i<4;i++)box[i]=box[i-1]+16;
    //TRANSFORMATION DE CHAQUE CASE DU TAB 2D
     for(int i=0;i<4;i++)
    {
        for(int j=0;j<16;j++){
            Sequence a=tabInitial[i][j];
            int row,col;
            list<int> rowl,coll,val;
            rowl.push_front(a[5]);
            rowl.push_front(a[0]);
            coll.push_front(a[4]);
            coll.push_front(a[3]);
            coll.push_front(a[2]);
            coll.push_front(a[1]);
            val.push_front(a[5]);
            val.push_front(a[4]);
            val.push_front(a[3]);
            val.push_front(a[2]);
            row = todecimal(Sequence(rowl));
            col = todecimal(Sequence(coll));
            box[row][col]= Sequence(val);
        }
    }

        
}
//CONSTRUCTEUR DE RECOPIE
Sbox::Sbox(Sequence ** tabInitial){
    //ALLOCATION DE MEMOIRE 
    box = new Sequence*[16*4];
    Sequence nul =0;
    box[0] = new Sequence[16*4];
    for(int i=1;i<4;i++)box[i]=box[i-1]+16;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<16;j++){
           box[i][j]=tabInitial[i][j]; 
        }
    }
}

Sbox Sbox::operator=(Sbox s){
    return Sbox(s.box);
}

Sequence Sbox::operator()(Sequence a){
    int row,col;
    list<int> rowl,coll,val;
    rowl.push_front(a[5]);
    rowl.push_front(a[0]);
    coll.push_front(a[4]);
    coll.push_front(a[3]);
    coll.push_front(a[2]);
    coll.push_front(a[1]);
    val.push_front(a[5]);
    val.push_front(a[4]);
    val.push_front(a[3]);
    val.push_front(a[2]);
    row = todecimal(Sequence(rowl));
    col = todecimal(Sequence(coll));
    return Sequence(val);
}

Sbox::~Sbox()
{
    delete [] box[0];
    delete [] box;
}
