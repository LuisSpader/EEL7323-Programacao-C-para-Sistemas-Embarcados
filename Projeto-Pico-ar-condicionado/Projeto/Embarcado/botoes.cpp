using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include <iomanip>   // para usar setfill() e setw()

class botoes
{
private:
    /* data */
    unsigned int temp;
    bool aumenta, diminui;
public:
    botoes(/* args */);
    ~botoes();

    void AumentaTemp();
    void DiminuiTemp();
};

botoes::botoes(/* args */)
{
}

botoes::~botoes()
{
}


void botoes::AumentaTemp(){
    aumenta <= true;
}

void botoes::DiminuiTemp(){
    diminui <= true;
}