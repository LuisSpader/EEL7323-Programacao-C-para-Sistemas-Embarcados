/*
 * file: CShape3d.cpp
 *
 * Descricao: Classe CShape3d - classe pai
 *
 * Autor: 
 * Data: 02/12/2021
 * 
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 02/12/2021
 *
 */

#include <iostream>
using namespace std;

const float PI = 3.1415927f;

class CShape3d {                  // Classe abstrata
          protected:
                     float a, b, c;
          public:
                     virtual float volume() = 0;
                     
};

class CBox : public CShape3d {
                     
          public:
                     CBox(float comprimento, float largura, float altura){   // construtor para CBox
                           a = comprimento;
                           b = largura;
                           c = altura;
                     }
                     
                     float volume(){
                     
                            return (a * b * c);
                     
                     }
                     
};

class CCone : public CShape3d {
                     
          public:
                     CCone(float raio, float altura){   // construtor para CCone
                           a = raio;
                           b = altura;
                     }
                     
                     float volume(){
                     
                            return (((PI * a * a) * b) / 3.0f);
                     
                     }
                     
};


class CCylinder : public CShape3d {
                     
          public:
                     CCylinder(float raio, float altura){   // construtor para CCylinder
                           a = raio;
                           b = altura;
                     }
                     
                     float volume(){
                     
                            return (((PI * a * a) * b));
                     
                     }
                     
};

int main(){
	CShape3d* shape;

	// Um ponteiro para CShape3d assume a forma de um CBox
	//
	shape = new CBox(10.5f, 12.2f, 5.7f);
	cout << "Volume do paralelogramo: " << shape->volume() << endl;
	delete shape;

	// Um ponteiro para CShape3d assume a forma de um CCone
	//
	shape = new CCone(1.2f, 3.4f);
	cout << "Volume do cone: " << shape->volume() << endl;
	delete shape;

	// Um ponteiro para CShape3d assume a forma de um CCylinder
	//
	shape = new CCylinder(1.2f, 4.5f);
	cout << "Volume do cilindro: " << shape->volume() << endl;
	delete shape;

	return 0;
}

