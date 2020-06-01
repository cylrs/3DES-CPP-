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

template<class T,int tailleE,int tailleS>
class Permutation{
public: 
    T operator()(SequenceD<Sequence,tailleE>,vector<int>); 
};
template<class T, int tailleE, int tailleS>
 T Permutation<T, tailleE, tailleS>::operator()(SequenceD<Sequence,tailleE> s, std::vector<int> v){
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
    return res;
}

int main(){
    SequenceD<Sequence,100> res;
    res = 9;
    res.affiche();
    vector<int> v = {3,2,1};
    Permutation<SequenceD<Sequence,100>,100,100> tes;
    tes(res,v);

    SequenceD<Sequence, 64> underP;
    underP=3;
    int nbkey =0;
    /*
    SequenceD<Sequence, 64> underP;
    SequenceD<Sequence,64> underK;
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


    cout<<"hiihelo";

}