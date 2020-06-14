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

//Ibrahim & Cylia LAST v : 14 06 2020
//TOUTES LES METHODES DE CETTE CLASSE FONCTIONNENT CORRECTEMENT 

 //int static nbKey = 0; CETTE VARIABLE SERA INCLUSE DANS LA CLASSE
class KeyGen
{
private :
    SequenceD<56> Key; 
    int nbKey;
   
public:
    KeyGen(SequenceD<64>);
    KeyGen();
    void affiche();
    SequenceD<48> next();
    ~KeyGen();
};
KeyGen::KeyGen(){
    nbKey =0;
}
// LE PASSAGE DE 64 a 56 Bits se fait via l'operateur () de permutation et au vecteur de PC1
KeyGen::KeyGen(SequenceD<64> k)
{
    nbKey =0;
    vector<int> choicePC1 =  {57,49,41,33,25,17,9,
        1,58,50,42,34,26,18,
        10,2,59,51,43,35,27,
        19,11,3,60,52,44,36,
        63,55,47,39,31,23,15,
        7,62,54,46,38,30,22,
        14,6,61,53,45,37,29,
        21,13,5,28,20,12,4};

    Permutation<64,56> p;
    Key = p(k,choicePC1);
}
void KeyGen::affiche(){
   // Key.affiche();
}
SequenceD<48> KeyGen::next(){
    nbKey++;
    vector<int> vec;
    SequenceD<48> nvSeq;
    vector<int> choicePC2 = {14,17,11,24,1,5,3,28,
                 15,6,21,10,23,19,12,4,
                 26,8,16,7,27,20,13,2,
                 41,52,31,37,47,55,30,40,
                 51,45,33,48,44,49,39,56,
                 34,53,46,42,50,36,29,32};

    Permutation<56,48> p;
    nvSeq = p(Key,choicePC2);
    return nvSeq;



    /* ceci est un code qui effectue le travail correctement, 
    sauf que il n'utilise pas les autres classe de maniere complete 
    Nous n'avons pas compris qu'il fallait utiliser les vecteurs PC1 et PC2 du document DES3
    */
   /*
    for (int i = 0; i <64; i++) vec.push_back(i);
    random_shuffle (vec.begin(), vec.end());
    Permutation<64,64> permu;
    //Je place mon resultat de permutation DANS UNE SequenceD
    SequenceD<64> choice1(permu(Key,vec).get());
    //PASSAGE AU 56 BITS
    choice1.pop();
    Sequence left = choice1.left();
    Sequence right = choice1.right();
    left.popSeq();
    right.popSeq();
    left.decalage(1);
    right.decalage(1);
    SequenceD<48> res(left,right);
    nbKey++;
    return res; 
    */
}


KeyGen::~KeyGen(){}

//int main (){}


