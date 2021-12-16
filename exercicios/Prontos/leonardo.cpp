/* Linux - Escrever um programa em C++ para manipulacao de vetores 
(criar a classe "Vetor") onde o operador << e' sobrecarregado de 
forma a listar todos os elementos do vetor. O operador >> deve ser 
sobrecarregado de forma a incluir um elemento na primeira posicao 
livre do vetor (da esquerda para a direita). O operador + deve ser 
sobrecarregado de forma a permitir a soma de dois vetores (cada 
elemento dos dois vetores), retornando o resultado em um terceiro vetor. 
O programa pode ser desenvolvido para execucao na plataforma Linux. 
Utilizar como base o exemplo: teste_cin.cpp
*/

#include <iostream>
#include <string>
using namespace std;

namespace {
  constexpr auto kSize {10};
}
class Vetor{
    bool temDadoValido[kSize] = {true, false, true, true, true, true, true, true, true, true};
    int stuff[kSize] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int tmp;
  public:
    friend void operator>> (istream& c, Vetor& v);
    friend std::ostream& operator<< (std::ostream& os, const Vetor& v);
    friend Vetor operator+ (const Vetor& x, const Vetor& y);
};

Vetor operator+ (const Vetor& x, const Vetor& y){
  Vetor w;
  for(auto i = 0; i < kSize; i++){
    w.stuff[i] = x.stuff[i] + y.stuff[i];
  }
  return w;
}

std::ostream& operator<< (std::ostream& os, const Vetor& v) {
  
  for(auto i = 0; i < kSize; i++){
    os << v.stuff[i];
    if (i < (kSize-1))
        os << ", "; 
    else 
        os << " ";
  }
  return os;
}
                   
void operator>> (istream& c, Vetor& v) {
  for(auto i = 0; i < kSize; i++){
    if(!v.temDadoValido[i])
    c >> v.stuff[i];
  }
}

int main() {

  Vetor var1, var2;
   
  cout << "Conteudo de var1: " << endl;
  cout << var1 << endl;

  cout << "Digite um valor inteiro a ser incluido na primeira posicao livre: ";
  cin >> var1;
  
  cout << "Conteudo de var1: " << endl;
  cout << var1 << endl;
  cout << "Conteudo de var2: " << endl;
  cout << var2 << endl;
  
  var1 = var1 + var2;
  
  cout << "Conteudo de var1: " << endl;
  cout << var1 << endl;

}

