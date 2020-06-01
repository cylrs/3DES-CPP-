#include <iostream>
#include <math.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <deque>
#include <list>
#include <iterator>
#include <vector>
#include "SequenceD.cpp"
using namespace std;


//ibrahim & Cylia LAST v : 01 06 2020
//TOUTES LES METHODES DE CETTE CLASSE FONCTIONNENT CORRECTEMENT 

template<class T,int tailleE,int tailleS>
class Permutation{
    int i;
    SequenceD<Sequence,64> p;
public: 
    Permutation();
    T operator()(SequenceD<Sequence,tailleE>,vector<int>); 
}; 
template<class T, int tailleE, int tailleS>
 Permutation<T, tailleE, tailleS>::Permutation(){
     i=0;
 }

template<class T, int tailleE, int tailleS>
 T Permutation<T, tailleE, tailleS>::operator()(SequenceD<Sequence,tailleE> s, vector<int> v){
    int tailleV = v.size();
    int valV,valS; 
    list<int> li; 
    for (int i = 0; i < tailleV; i++){
        valV = v[i];
        valV= valV-1;
        valS =s[valV];
        if (valS>1)valS=0;        
        li.push_back(valS);
    }
    Sequence trans = Sequence(li);
    SequenceD<Sequence,tailleS> res(trans);
    res.affiche();
    p=res;
    return res;
}
/*
int main(){
    
    SequenceD<Sequence,100> res;
    res = 9;
    res.affiche();
    vector<int> v = {3,2,1,4};
    Permutation<SequenceD<Sequence,100>,100,100> tes;
    tes(res,v);
    return 0;
}*/

    /* EN SUIVANT CETTE AFFICHAGE NOUS AURONS LE RESULAT SUIVANT :
    source : 
    {1  0  0  1  }
    Resultat : dont le vecteur de la permutaiton est : v = {3,2,1,4}
    {0  0  1  1  }
    */
    
    


