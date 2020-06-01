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
    /*
    SequenceD<Sequence, 48> sousP;
    SequenceD<Sequence,64> sousK;
    underK = 4;
    vector<int> vec;
    for (int i = 0; i <56; i++) vec.push_back(i);
    random_shuffle (vec.begin(), vec.end());
    Permutation<SequenceD<Sequence, 64>,64,64> permu;
    underP = Sequence(permu(Key,vec).get());
    if(nbKey<16){
        Sequence l = underP.left();
        Sequence r = underP.right();
        l.decalage(1);
        r.decalage(1);
        l.pop();
        r.pop();
        SequenceD<Sequence,64> u(r,l);
        underK.set(u.get());
        nbKey++;
    }
    else cout<<"16 Rounds dépassés";
    return underK;
    */
}


KeyGen::~KeyGen(){}



