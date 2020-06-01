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
    int operator[](int);                //OK
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
Sequence::Sequence(int t){
    seq.assign(t, experimental::randint(0, 1));
}
Sequence::Sequence(list<int> li){
    seq.insert(seq.begin(),li.begin(),li.end());

}
int Sequence::operator()(int i) {
    deque<int>::iterator it = seq.begin()+i-1;
    return *it;
}
int Sequence::operator[](int i){
    deque<int>::iterator it = seq.begin()+i;
    return *it;
    //NON COMPREHENSON DE LA QUESTION !
    //L’opérateur [] quipermettra d’accéder 
    //(et potentiellement modifier) un bit de la séquence.
}
void Sequence::operator=(long int decimal){
    //VOIR COMMENT REDUIRE LE CODE ET ENLEVER DE TABLEAU QUI EST INUTILE 
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
int Sequence::size(){
    int conteur = 0;
    for (auto &i : seq) conteur++;
    return conteur;
}
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
void Sequence::decalage(int i){
    int val;
    for (int pos = 0; pos <i; pos++){
        val = seq.front();
        cout<<val;
        seq.pop_front();
        seq.push_back(val);
    }
}
Sequence Sequence::permutation(vector<int> v){
    list<int> li;
    li.insert (li.begin (), v.begin (), v.end());
    return Sequence(li);
}
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


