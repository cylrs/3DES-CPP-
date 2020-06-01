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
#include "KeyGen.cpp"

class F{
    
private:
    KeyGen cle;

public:
    F(SequenceD<Sequence,64>);
    ~F();
};

F::F(SequenceD<Sequence,64> k)
{
    cle = KeyGen(k);
}

F::~F()
{
}