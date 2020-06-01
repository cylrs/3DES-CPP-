#include <iostream>
#include <math.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <deque>
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
#include "SequenceD.cpp"
#include "Permutation.cpp"
using namespace std;

//ibrahim & Cylia LAST v : 01 06 2020
//TOUTES LES METHODES DE CETTE CLASSE FONCTIONNENT CORRECTEMENT 

 int static nbKey = 0;
class KeyGen
{
private :
    SequenceD<Sequence,64> Key; 
   
public:
    KeyGen();
    KeyGen(SequenceD<Sequence,64>);
    void affiche();
    SequenceD<Sequence,48> next();
    ~KeyGen();
};
KeyGen::KeyGen(){
    SequenceD<Sequence,64> c;
    c=34;
    Key=c;
}
KeyGen::KeyGen(SequenceD<Sequence,64> k)
{
    Key = Sequence(k.get());
   
}
void KeyGen::affiche(){
    Key.affiche();
}



SequenceD<Sequence, 48> KeyGen::next(){
    
    vector<int> vec;
    for (int i = 0; i <64; i++) vec.push_back(i);
    random_shuffle (vec.begin(), vec.end());
    Permutation<SequenceD<Sequence, 64>,64,64> permu;
    //Je place mon resultat de permutation DANS UNE SequenceD
    SequenceD<Sequence, 64> choice1(permu(Key,vec).get());
    //PASSAGE AU 56 BITS
    choice1.pop();
    Sequence left = choice1.left();
    Sequence right = choice1.right();
    left.popSeq();
    right.popSeq();
    left.decalage(1);
    right.decalage(1);
    SequenceD<Sequence,48> res(left,right);
    nbKey++;
    return res;  
}


KeyGen::~KeyGen(){}

int main (){
 cout<<"hhh";
 SequenceD<Sequence, 64> c;
 c=40;
 KeyGen k(c);
 

}


