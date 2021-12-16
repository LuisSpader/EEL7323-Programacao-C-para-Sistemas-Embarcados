class parent // Classe Pai
{
protected:
  int j, k;

public:
  void setJ(int newj);
  void setK(int newk);
  int getJ();
  int getK();
};

// herdou a classe pai 'parent'
// Consegue acessar tudo inclusive o 'protected' pois herdou a classe usando 'public'
class parent // Classe Pai
{
protected:
  int j, k;

public:
  void setJ(int newj);
  void setK(int newk);
  int getJ();
  int getK();
};

class child : public parent
{
protected:
  int m, n;

public:
  void setM(int newm);
  void setN(int newn);
  int getM();
  int getN();
};
void parent::setJ(int newj)
{
  j = newj;
}
void parent::setK(int newk)
{
  k = newk;
}
int parent::getJ()
{
  return j;
}
int parent::getK()
{
  return k;
}
void child::setM(int newm)
{
  m = newm;
}
void child::setN(int newn)
{
  n = newn;
}
int child::getM()
{
  return m;
}
int child::getN()
{
  return n;
}

int main()
{
  parent prnt, prntl;
  child chld, chldl;

  prnt = chld; // can access chld.j and chld.k only

  // chld = prnt; // error: classe child contém elementos a mais do que a calsse parent

  parent *pp = &chld; // can access all 4 variables
  // ponteiro do tipo classe 'parent'
  // ????
  parent &rr = chld;
  // child* cc = &prnt; // error
  pp = &prntl;
  pp = &chldl;
  // Heterogeneuos list
  parent *list[4];
  list[0] = &prnt;  // prnt has 2 variables: j & k
  list[1] = &chld;  // chld has 4 variables: m, n, j & k
  list[2] = &prntl; // prntl has 2 variables: j & k
  list[3] = &chldl; // chldl has 4 variables: m, n, j & k
}
