#include <iostream>
#include <math.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <deque>
#include <list>
#include <iterator>
#include <vector>
#include "Sequence.cpp"
using namespace std;
template<class T,int maxsize>
class SequenceD
{
    public:
        SequenceD();
        SequenceD(T,T);
        SequenceD(T);
        void set(T);
        int size();
        void affiche();
        void decalageD(int);
        T left();
        T right();
        int operator()(int);                //  OK
        int operator[](int);                //  OK
        void operator=(long int);           //  OK
        
        SequenceD operator*(SequenceD);
        T get();
        void pop();

    private:
        T seqq;

};
template<class T,int maxsize>
 SequenceD<T,maxsize>::SequenceD()
{
    seqq = Sequence(maxsize);
}
template<class T,int maxsize>
 SequenceD<T,maxsize>::SequenceD(T a, T b)  
{
    list<int> l1= a.toList();
    list<int> l2= b.toList();
    l1.merge(l2);
    seqq=Sequence(l1);
    cout<<seqq.size()<<'\n';
}
template<class T,int maxsize>
 SequenceD<T,maxsize>::SequenceD(T a)  
{
    seqq=a;
}
template<class T, int maxsize>
 void SequenceD<T, maxsize>::set(T a ){
     seqq=a;
 }

template<class T,int maxsize>
 int SequenceD<T,maxsize>::size()
{
    seqq.affiche();
    return seqq.size();
}
template<class T,int maxsize>
 void SequenceD<T,maxsize>::affiche(){
    seqq.affiche();
}
template<class T,int maxsize>
 void SequenceD<T,maxsize>::decalageD(int n){
    Sequence lright= (right());
    Sequence lleft= left();
    lright.decalage(n);
    lleft.decalage(n);
    list<int> ll = lleft.toList();
    list<int> lr = lright.toList();
    ll.merge(lr);
    seqq = Sequence(ll);
}
template<class T,int maxsize>
 T SequenceD<T,maxsize>::left()
{
    int n =seqq.size();
    Sequence l = seqq.sous_sequence(n/2,n);
    return l;
}
template<class T,int maxsize>
 T SequenceD<T,maxsize>::right()
{
int n =seqq.size();
    Sequence l = seqq.sous_sequence(0,n/2);
    return l;
}
template<class T, int maxsize>
 int SequenceD<T, maxsize>::operator()(int i){
    return seqq.operator()(i);
}
template<class T, int maxsize>
 int SequenceD<T, maxsize>::operator[](int i){
    return seqq.operator[](i);
}
template<class T, int maxsize>
 void SequenceD<T, maxsize>::operator=(long int i){
     seqq.operator=(i);
}
template<class T, int maxsize> SequenceD<T, maxsize>
 SequenceD<T, maxsize>::operator*(SequenceD<T, maxsize> s){
     SequenceD newS = SequenceD();
     newS.seqq = seqq.operator*(s.get());
     return newS;
}
template<class T,int maxsize>
 T SequenceD<T,maxsize>::get()
{
    return seqq;
}

template<class T>
 void afficheAll(T obj)
{
   for (int i =1; i <= obj.size(); i++) cout<<obj (i);
}
template<class T, int maxsize>
 void SequenceD<T, maxsize>::pop(){
     seqq.pop();
 }

template<class T>
int permut(T, vector<int> v){

    
    return 0;
}


/*
int main()
{
    SequenceD<Sequence,100> cyl;
    cyl=11;
    cyl.affiche();
    vector<int> v = {3,4,1,2,5};

    int tailleV = v.size();
    int valV= 0;
    int valS;



    list<int> li; 
    for (int i = 0; i < tailleV; i++)
    {
        valV = v[i];
        valV= valV-1;
        valS =cyl[valV];
        if (valS>1)valS=0;        
        li.push_back(valS);
        cout<<valV<< "  se trouve la valeur suivante  "<<valS<<"  insert  a "<<i<<'\n';
    }
    Sequence trans = Sequence(li);
    trans.affiche();

    
}*/