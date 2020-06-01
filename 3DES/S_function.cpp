
#include "Sbox.cpp";

class S_function
{
private:
    Sbox * Sboxes;
public:
    S_function(int ***);
    S_function(Sbox *);
    S_function operator=(S_function);
    Sequence operator()(Sequence);
    ~S_function();
};

S_function::S_function(int *** tabInitial){
    for(int x = 0; x < 8; ++x){
        Sbox a(tabInitial[x]);
        Sboxes[x] = a;
    }   
}

S_function::S_function(Sbox * s ){
    Sboxes = s;
}

S_function S_function::operator=(S_function s) {
    return S_function(s.Sboxes);
}

S_function::~S_function(){
    for(int x = 0; x < 8; ++x) Sboxes[x].~Sbox();
}

