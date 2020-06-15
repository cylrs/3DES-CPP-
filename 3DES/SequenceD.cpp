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
//Ibrahim & Cylia LAST v : 01 06 2020
//TOUTES LES METHODES DE CETTE CLASSE FONCTIONNENT CORRECTEMENT
template <int maxsize = 4>
class SequenceD : public Sequence
{
public:
    SequenceD();
    SequenceD(Sequence, Sequence);
    SequenceD(Sequence);
    void set(Sequence);
    int size();
    void affiche();
    void decalageD(int);
    Sequence &left();
    Sequence &right();
    int operator()(int);      //  OK
    int &operator[](int);     //  OK
    void operator=(long int); //  OK

    SequenceD operator*(SequenceD);
    SequenceD get();
    void pop();

private:
    Sequence seqL;
    Sequence seqR;
};
template <int maxsize>
SequenceD<maxsize>::SequenceD()
{
    seqL = Sequence(maxsize / 2);
    seqR = Sequence(maxsize / 2);
}
template <int maxsize>
SequenceD<maxsize>::SequenceD(Sequence l, Sequence r)
{
    seqL = l;
    seqR = r;
}
template <int maxsize>
SequenceD<maxsize>::SequenceD(Sequence a)
{
    int n = a.size();
    seqL = a.sous_sequence(n / 2, n);
    seqR = a.sous_sequence(0, n / 2);
}
template <int maxsize>
void SequenceD<maxsize>::set(Sequence a)
{
    int n = a.size();
    seqL = a.sous_sequence(n / 2, n);
    seqR = a.sous_sequence(0, n / 2);
}

template <int maxsize>
int SequenceD<maxsize>::size()
{
    return seqL.size() + seqR.size();
}
template <int maxsize>
void SequenceD<maxsize>::affiche()
{

    seqR.affiche();
    seqL.affiche();
}
template <int maxsize>
void SequenceD<maxsize>::decalageD(int n)
{
    seqL.decalage(n);
    seqR.decalage(n);
}
template <int maxsize>
Sequence &SequenceD<maxsize>::left()
{
    return seqL;
}
template <int maxsize>
Sequence &SequenceD<maxsize>::right()
{
    return seqR;
}
template <int maxsize>
int SequenceD<maxsize>::operator()(int i)
{
    if (i < seqL.size())
        return seqL(i);
    return seqR(i - seqL.size());
}
template <int maxsize>
int &SequenceD<maxsize>::operator[](int i)
{
    if (i < seqL.size())
        return seqL[i];
    return seqR[i - seqL.size()];
}
template <int maxsize>
void SequenceD<maxsize>::operator=(long int i)
{
    Sequence seqq = i;
    int sousSeq = seqq.size() / 2;
    seqL = seqq.sous_sequence(0, sousSeq);
    seqR = seqq.sous_sequence(sousSeq, sousSeq * 2);
}
template <int maxsize>
SequenceD<maxsize>
    SequenceD<maxsize>::operator*(SequenceD<maxsize> s)
{
    SequenceD unionXor;
    unionXor.seqL = s.seqL * seqL;
    unionXor.seqR = s.seqR * seqR;
    return unionXor;
}

template <class T>
void afficheAll(T obj)
{
    obj.affiche();
    //for (int i =1; i <= obj.size(); i++) cout<<obj (i);
}

void write(SequenceD<64> s, std::ostream &outStr)
{

    string txt = s.left().afficheT() + s.right().afficheT();
    outStr.write((txt).c_str(), s.size());
}

void read(SequenceD<64> s, std::istream &inStr)
{
    cout << "inter the sequence of bits one by one";
    //Nous lisons un int mais on cosidere qu'il s'agit d'un char pour la foction qui suit
    char mysequence[64];
    inStr.read(mysequence, s.size());
    list<int> tabtolist;
    for (int i = 0; i < 64; i++)
        tabtolist.push_front(mysequence[i]);
    Sequence sousS = Sequence(tabtolist);
    s.set(sousS);
}

/*
int main()
{
    Sequence s  =Sequence(64);
    s =60;
    auto seqD =SequenceD<64> (s);
    seqD.affiche();
    //RESULTAT  {1  1  1  }  {1  0  0  }
    seqD.decalageD(1);
    seqD.affiche();
    //RESULTAT  {1  1  1  }  {0  0  1  }
    seqD.left().affiche();
    //RESULTAT {0  0  1  }
    seqD.right().affiche();
    //RESULTAT {1  1  1  }
    cout<<seqD.size(); 
    //RESULTAT : 6 
    afficheAll(seqD);
    //RESULTAT {1  1  1  }  {0  0  1  }
    cout<<seqD(1); //AFFICHE 0 DONC ok 
    seqD[1]=1;
    afficheAll(seqD);
    // RESULTAT {0  1  1  } {0  1  1  }
    seqD = seqD*seqD;
    seqD.affiche();
    // RESULTAT {0  0  0  } {0  0  0  }
    cout<<"afcchagggge test write";
    cout << "WRITE : " << endl;
    write(seqD,cout);
    
}*/
