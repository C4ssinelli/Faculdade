// Este trabalho visa realizar a sobrecarga de alguns operadores, como o << 

//Feito por Alex Luiz Domingues Cassinelli
//RA: 211021849

#include <iostream>
using namespace std;

class Vetor3D {
//public:
  float x, y, z;

public:
  friend void operator>>(istream &c, Vetor3D &v);
  friend ostream &operator<<(ostream &o, Vetor3D &v);

  Vetor3D(float x = 0, float y = 0, float z = 0) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  Vetor3D operator+(const Vetor3D &v) {
    Vetor3D aux;
    aux.x = x + v.x;
    aux.y = y + v.y;
    aux.z = z + v.z;
    return aux;
  }
  
  Vetor3D &operator+=(const float f) {
    x += f;
    y += f;
    z += f;
    return *this;
  }
  
  Vetor3D &operator+=(const Vetor3D &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }
  //Multiplicar por inteiro
  Vetor3D &operator*=(const int i)
  {
  	x *= i;
  	y *= i;
  	z *= i;
  	return *this;
  }
  //Dividir por inteiro
  Vetor3D &operator/=(const int i)
  {
  	x /= i;
  	y /= i;
  	z /= i;
  	return *this;
  }
  //Subtrair vetores
  Vetor3D &operator-=(const Vetor3D &v)
  {
  	x -= v.x;
  	y -= v.y;
  	z -= v.z;
  	return *this;
  }
};

void operator>>(istream &c, Vetor3D &v) {
  c >> v.x >> v.y >>  v.z;
}
//cout modificado
ostream &operator<<(ostream &o, Vetor3D &v)
{
	o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

int main() {

  Vetor3D vet1(1.2, 2.3, 3.4);
  Vetor3D vet2;

  cout << "Digite um valor tridimensional (tr�s valores): ";
  cin >> vet2;

  cout << "Valor1 = " << vet1 << endl;
  cout << "Valor2 = " << vet2 << endl;
  vet2 *= 2;
  cout << "Valor2 = " << vet2 << endl;
  vet2 /= 2;
  cout << "Valor2 = " << vet2 << endl;
  vet2 -= vet1;
  cout << "Valor2 = " << vet2 << endl;
  
}
