#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <list>
#include <iterator>
#include <vector>
#include <experimental/random>

//ibrahim & Cylia LAST v : 01 06 2020
//TOUTES LES METHODES DE CETTE CLASSE FONCTIONNENT CORRECTEMENT 

using namespace std;
class Sequence
{
private:
    deque<int> seq;
public:
    Sequence();                         //OK
    Sequence(int);                      //OK
    Sequence(list<int> li);             //OK
    ~Sequence();
    int operator()(int);                //OK
    int& operator[](int);                //OK
    void operator=(long int);           //OK
    Sequence operator*(Sequence);       //OK
    int size();                         //OK
    void decalage(int);                 //OK
    Sequence permutation(vector<int>);  //OK
    Sequence sous_sequence(int, int);   //OK  
    void affiche(); 
    string afficheT();                    //OK
    list<int> toList();                 //OK
    void pop();
    void popSeq();
    void push();
};
Sequence::Sequence(){
    seq.assign(5, experimental::randint(0, 1));
}
//CONTSTRUCTEUR AVEC TAILLE DE LA DEQUE
Sequence::Sequence(int t){
    seq.assign(t, experimental::randint(0, 1));
}
//CONSTRUCTEUR PRENNANT UNE LISTE DE DONNEE
Sequence::Sequence(list<int> li){
    seq.insert(seq.begin(),li.begin(),li.end());

}
//OPERATOR D ACCES
int Sequence::operator()(int i) {
    deque<int>::iterator it = seq.begin()+i-1;
    return *it;
}
//OPERATOR D ACCES AVEC POSSIBLITE DE MODIFICATION
int& Sequence::operator[](int i){
    deque<int>::iterator it = seq.begin()+i;
    return *it;
}
//OPPERATOR QUI PERMET DE TRADUIT UN INT EN UNE SEQUENCE DE BIT PAR AFFECTATION 
void Sequence::operator=(long int decimal){
    int bits, facteur;
    bits = int(log(decimal)/log(2));
    int binary[bits+1];
    float binaire =0;
    deque<int> newdeque;
    for(int i = 0; i < bits+1; ++i){
        facteur=int(pow(2,bits-i));
		binary[i]=(decimal / facteur > 0? 1 : 0);
		decimal=(decimal / facteur > 0? decimal - facteur : decimal);
    }
    for (int bit : binary) newdeque.insert(newdeque.end(),bit);
    seq.swap(newdeque);
}
//METHODE QUI RENVOI LA TAILLE DE DEQUE DE NOTRE SEQUENCE 
int Sequence::size(){
    int conteur = 0;
    for (auto &i : seq) conteur++;
    return conteur;
}
//OPERATOR XOR
Sequence Sequence::operator*(Sequence s){
    int n = s.size();
    Sequence xorr= s;
    if( seq.size()!= n ) return xorr;
    for (int i = 0; i < seq.size(); i++){
        if(seq[i]!=s.seq[i]) xorr.seq[i]=1; 
        else xorr.seq[i]=0;
        
        cout<<xorr.seq[i];
    }
    return xorr;
}
//METHODE POUR DECALER LES BITS D UNE SEQUENCE DE i POSITION(s) VERS LA GAUCHE 
void Sequence::decalage(int i){
    int val;
    for (int pos = 0; pos <i; pos++){
        val = seq.front();
        cout<<val;
        seq.pop_front();
        seq.push_back(val);
    }
}
//METHODE DE PERMUTATION POUR REMPLACER PAR LES DONNEES DU VECTOR
Sequence Sequence::permutation(vector<int> v){
    list<int> li;
    li.insert (li.begin (), v.begin (), v.end());
    return Sequence(li);
}
//RETURN UNE SOUS SEQUENCE 
Sequence Sequence::sous_sequence(int debut, int fin){
    list<int> donnee;
    for (int i = debut; i < fin; i++) donnee.push_back(seq[i]);
    return Sequence(donnee);
}
void Sequence::affiche(){
    cout<<"\n"<<"{";
    for (auto &i : seq) cout<<i <<"  ";
    cout<<"}"<<"\n";    
}
list<int> Sequence::toList(){
    list<int> liste;
    liste.insert(liste.begin (), seq.begin (), seq.end());
    return liste;
}
void Sequence::pop(){
    for (int i = 0; i < 8; i++)seq.pop_back();
 
}
void Sequence::popSeq(){
    for (int i = 0; i < 3; i++)seq.pop_back();
 
}
void Sequence::push(){
    seq.push_front(0);
}
string Sequence::afficheT(){

    string txt ;
    deque<int> s = seq;
    while (!s.empty())
    {
        txt.insert(0,1,(s.front()));
        s.pop_front();
    }
    return txt;
}
Sequence::~Sequence(){}

/* **** ICI LES TESTS DES METHODES DEMANDEES AVEC LEURS RESULTATS *******************
int main(){
Sequence seqtest = Sequence();
seqtest.affiche();
     // RESULTAT : {0  0  0  0  0  }
seqtest = Sequence(2);
seqtest.affiche();
     // RESULTAT : {1  1  }
seqtest[1]= 0;
seqtest.affiche();
     // RESULTAT : {1  0 }
seqtest= 11;
seqtest.affiche();
     // RESULTAT : {1  0  1  1  }
seqtest.sous_sequence(0,2).affiche();
     // RESULTAT : {1  0 }
seqtest.decalage(1);
seqtest.affiche();
    //RESULTAT :  {0  1  1  1  }

seqtest.permutation(vector<int> {1,0,0,1}).affiche();
    //RESULTAT :  {1 0 0 1  }
Sequence seq1 = Sequence(2);
seq1 =2; // {1 0}
seqtest = 3;  // {1 1}
seq1= seq1*seqtest;
seq1.affiche();
    //RESULTAT :  {0 1 }  

} 
*/
