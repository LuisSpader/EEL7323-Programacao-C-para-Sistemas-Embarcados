

#include "ABP.cpp"

main()
{

  ABP r;

  r.imprimirABP();
  r.inserirNodo(10);
  r.inserirNodo(20);
  r.inserirNodo(5);
  r.inserirNodo(15);
  cout << "Escreve ABP..." << endl;
  r.imprimirABP();

  ABP *rptr = new ABP();

  rptr->inserirNodo(10);
  rptr->inserirNodo(5);
  rptr->inserirNodo(20);
  rptr->inserirNodo(15);
  cout << "Novamente..." << endl;
  rptr->imprimirABP();
}
