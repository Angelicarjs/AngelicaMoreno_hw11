#include <iostream>
using namespace std;
//Declaracion variables de velocidad, posicion y tiempo
float x;
float v;
float t;
float h;

//Declaracion de la variables de gravitacion y masa M
float G;
float M;
	
//Declaracion de la funcion que calcula la velocidad
float derivada_x(float x, float v, float t);
	
//Declaracion de la funcion que calcula la posicion
float derivada_v(float x, float v, float t);
	
//Declaracion que la funcion que calcula las derivadas usando runge
void der(float x, float v, float t, float h);

//Defino lo que hace la funcion de la derivada de x
float derivada_x(float x, float v, float t){
	return v;
}

//Defino lo que hace la funcion de la derivada de v
float derivada_v(float x, float v, float t){
	return -(G*M)/(x*x)
}

//Defino lo que hace la funcion que calcula las derivadas usando runge 
void der(float x, float v, float t, float h){
	//Declaro condiciones iniciales
	float tO, xO, vO;
	//Declaro los pasos de x y v
  	float kx_1, kx_2, kx_3, kx_4;
  	float kv_1, kv_2, kv_3, kv_4;

  	tO = t;
  	xO = x;
  	vO = v;
	
	//Defino que el primer paso son las condiciones iniciales que se dan
	kx_1 = derivada_x(tO, xO, vO);
 	kv_1 = derivada_v(tO, xO, vO);
	
	//Defino el segundo paso usando la definicion de runge
	kx_2 = derivada_x(tO + h/2, xO + kx_1 * h/2, vO + kv_1 * h/2);
 	kv_2 = derivada_v(tO + h/2, xO + kx_1 * h/2, vO + kv_1 * h/2);
	
	//Defino el tercer paso usando la definicion de Runge 
	kx_3 = derivada_x(tO + h/2, xO + kx_2 * h/2, vO + kv_2 * h/2);
  	kv_3 = dericada_v(tO + h/2, xO + kx_2 * h/2, vO + kv_2 * h/2);
	
	//Defino el cuarto paso 
	ky_4 = derivada_x(tO + h, xO + kx_3 * h, vO + kv_3 * h);
  	kz_4 = derivada_v(tO + h, xO + kx_3 * h, vO + kv_3 * h);

	tO = tO + h;
  	xO = xO + h * (ky_1 + 2*ky_2 + 2*ky_3 + ky_4)/6.0;
  	vO = vO + h * (kz_1 + 2*kz_2 + 2*kz_3 + kz_4)/6.0;

	 t = tO;
  	 x = xO;
  	 v = vO;
	
}

//MAIN
int main() {
	//Le doy valores iniciales 
	t = 0.0
	xO = 0.1	
	v = 0.5
	h = 0.1
	G = 10.0;
	M = 1000.0;
	while(x>>0.1xO){
	cout<< t <<""<< x <<""<< v << endl;
	der(xO,v,t,h);	
	}		
	
return 0;
}
