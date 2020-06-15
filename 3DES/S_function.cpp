
#include "Sbox.cpp";

class S_function
{
private:
    int*** Sboxes;
public:
    S_function(int ***);
    S_function();
    S_function(S_function&);
    S_function& operator=(S_function&);
    Sequence operator()(Sequence);
    ~S_function();
};

S_function::S_function(int *** tabInitial){
    Sboxes = tabInitial;
}
//CONSTRUCTEUR DE RECOPIE 
S_function::S_function(S_function & s)
{
    Sboxes = s.Sboxes;
}

S_function& S_function::operator=(S_function& s) {
    return s;
}


Sequence S_function::operator()(Sequence seq){
    Sequence res;
    return res;
}
//  http://sdz.tdct.org/sdz/ableaux-pointeurs-et-allocation-dynamique.html
S_function::~S_function()
{
    for (int i = 0; i < 8; i++)
    {
        for (j = 0; j < 64; j++)
        {
            free(Sboxes[i][j]);
        }
        free(Sboxes[i]);
    }
    free(Sboxes);
    //delete[] Sboxes[0];
    //delete Sboxes;
}