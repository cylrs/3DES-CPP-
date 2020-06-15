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
#include "S_function.cpp"

class F{
    
private:
    KeyGen cle;
    S_function boxes;

public:
    F(SequenceD<64>);
    ~F();
};

F::F(SequenceD<64> k)
{
   cle = KeyGen(k); 
}

F::~F()
{
}
