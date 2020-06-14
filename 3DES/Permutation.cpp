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


//Ibrahim & Cylia LAST v : 14 06 2020
//TOUTES LES METHODES DE CETTE CLASSE FONCTIONNENT CORRECTEMENT 

template<int tailleEntree,int tailleSortie>
class Permutation{

public: 
    Permutation();
    SequenceD<tailleSortie> operator()(SequenceD<tailleEntree>,vector<int>); 
}; 

template<int tailleEntree, int tailleSortie>
 Permutation<tailleEntree, tailleSortie>::Permutation(){
 }
//OPERATOR QUI PERMET DE CHANGER LA TAILLE ET LE POSITIONEMENT DES VALEUR
template<int tailleEntree, int tailleSortie>
 SequenceD<tailleSortie> Permutation<tailleEntree, tailleSortie>::operator()(SequenceD<tailleEntree> s, vector<int> v){
    int valV,valS; 
    list<int> li; 
    for (int i = 0; i < tailleSortie; i++){
        valV = v[i];
        // LES VALEURS DANS LE VECTEUR SONT DECALEES DE 1 
        valV= valV-1;
        valS =s[valV];        
        li.push_back(valS);
    }
    //INSERTION DES DONNEES DANS UNE LISTE POUR CRRER LA SEQUENCE
    Sequence trans = Sequence(li);
    auto res = SequenceD<tailleSortie> (trans);
    return res;
}
/*
int main(){
	SequenceD<6> seqEntree = SequenceD<6>();
	SequenceD<4> seqSortie = SequenceD<4>();
	vector<int> v{1,2,3,4};
	Permutation<6,4> p;
	cout << "Affichage SequenceD<6> :" << '\n';
	seqEntree.affiche();
	cout << "permutation vers SequenceD<4> :" << '\n';
    seqSortie = p(seqEntree, v);
	seqSortie.affiche();
   
}*/

    /*
    Affichage SequenceD<6> :
    {1  1  1  } {0  0  0  }
    permutation vers SequenceD<4> :
    {0  0  } {0  1  }

    */
    
    


