#include <stdio.h>
#include <stdlib.h> //Incluye las funciones rand y srand
#include "iostream" //Funciones estandar
#include <string.h>
#include <sstream>
#include <math.h>

using namespace std;
int     tamL     = 0;
int     tamC     = 0;
int 	aguloL	 = 0;
int 	aguloC	 = 0;
int cox,coy;
int lox,loy;
int cfx,cfy;
int lfx,lfy;

//-------------------------------------------------------------------------------------------------//
class Punto{
private:
	int x, y;
	
public:
	Punto (){}
	Punto(int x, int y){
		setX(x);
		setY(y);
	}

	void setX(int n){
		x=n;
	}
	void setY(int r){
		y=r;
	}
	int getX(){
	
		return x;
	}
	int getY(){
		return y;
	}


};
//-------------------------------------------------------------------------------------------------//
 void BresenhamLineX(int x1, int y1, int x2, int y2, Punto *p){
	 int x ;
	 int y ;
	 int dx  = 0;
	 int dy  = 0;
	 int dx1 = 0;
	 int dy1 = 0;
	 int px  = 0;
	 int py  = 0;
	 int xe	 = 0;
	 int ye	 = 0;
	 int i 	 = 0;
	 
	 dx  = x2-x1;
	 dy  = y2-y1;
	 dx1 = abs(dx);
	 dy1 = abs(dy);
	 px  = 2*dy1-dx1;
	 py  = 2*dx1-dy1;
	 
	 if(dy1<=dx1){
	  	if(dx>=0){
		   	x=x1;
		   	y=y1;
		   	xe=x2;
	  	}else{
		   x=x2;
		   y=y2;
		   xe=x1;
	  	}
	    p[0] = Punto(x,y); 
	  
		  for(i=0;x<xe;i++){
		   		x=x+1;
			   	if(px<0){
			    	px=px+2*dy1;
			    }else{
			    
					if((dx<0 && dy<0) || (dx>0 && dy>0)){
				     	y=y+1;
				    }else{
				     	y=y-1;
				    }
				    px=px+2*(dy1-dx1);
			   }
			   	p[i+1] = Punto(x,y);
		  }
	 }else{
		  if(dy>=0){
			   x=x1;
			   y=y1;
			   ye=y2;
		  }else{
			   x=x2;
			   y=y2;
			   ye=y1;
		  }
		  p[0] = Punto(x,y);
		  
		  for(i=0;y<ye;i++){
			   y=y+1;
			   if(py<=0){
			    	py=py+2*dx1;
			   }else{
			    	if((dx<0 && dy<0) || (dx>0 && dy>0)){
			     		x=x+1;
			    	}else{
			     		x=x-1;
			    	}
			   		py=py+2*(dx1-dy1);
			   }
			   p[i+1] = Punto(x,y);
		  }
	 }
 }
 //-------------------CIRCULO CON CENTRO FUERA DEL ORIGEN-----------------------------------------// 
 void Draw8Points(int xc,int yc, int a, int b, Punto *vec, int contador)
 {
                    vec[contador]   = Punto(xc+a, yc+b);    
					vec[contador+1] = Punto(xc-a, yc+b);   
                    vec[contador+2] = Punto(xc-a, yc-b);
                    vec[contador+3] = Punto(xc+a, yc-b);
                    vec[contador+4] = Punto(xc+b, yc+a);
                    vec[contador+5] = Punto(xc-b, yc+a);
                    vec[contador+6] = Punto(xc-b, yc-a);
                    vec[contador+7] = Punto(xc+b, yc-a);
 } 
          
 void CircleBresenham(int xc,int yc, int R, Punto *vec)
{
	int x=0,y=R;
	int d=1-R;
	int contador = 2;
	Draw8Points(xc,yc,x,y,vec,contador);
	while(x<y)
	{
		if(d < 0){
			d+=2*x+2;
		}else{
			d+=2*(x-y)+5;
			y--;
		}
		x++;
		Draw8Points(xc,yc,x,y,vec,contador);
		contador = contador + 8;
	}
} 

//---------------------------CIRCULO CON CENTRO EN EL ORIGEN--------------------------------------// 
 void circulo(int r,Punto *vec){
	int p = 0;
	int x = 0;
	int y = 0;
	int contador = 2;
	
	y = r;
	x = 0;
	vec[0] = Punto(x,y);
	vec[1] = Punto(x,-y);
	p = 1-r;
	
	do{
		if(p < 0){
			x = x+1;
			p = p + (2*x)+3;
		}else{
			x = x+1;
			y = y-1;
			p = p + 2*(x-y)+5;	
		}		
		vec[contador]   = Punto(x,y);    
		vec[contador+1] = Punto(y,x);  
		vec[contador+2] = Punto(y,-x);  
		vec[contador+3] = Punto(x,-y);  
		vec[contador+4] = Punto(-x,-y);  
		vec[contador+5] = Punto(-y,-x);  
		vec[contador+6] = Punto(-y,x);  
		vec[contador+7] = Punto(-x,y);  

		contador = contador + 8;
	}while( x <= y);
		
}
//-----------------------------------------------------------------------------------------------//
void traslacion (Punto *p, int t){
	int tx = 0;
	int ty = 0;
	string 	nombre;
	 if(p == NULL){
	 	cout<<"Vector de coordenadas vacio"<<endl;
	 }else{
		cout<<"Teclee el dezplazamiento en x: ";
		cin>>tx;
		cout<<"Teclee el dezplazamiento en y: ";
		cin>>ty;

		for(int i = 0; i < t; i++){
			p[i].setX(p[i].getX()+tx);
			p[i].setY(p[i].getY()+ty);
		}
	}
}
//----------------------------------------------------------------------------------------------//
void escaladoMulttiplicacion (Punto *p, int t){
	int ex = 0;
	int ey = 0;

	string 	nombre;
	 if(p == NULL){
	 	cout<<"Vector de coordenadas vacio"<<endl;
	 }else{
		cout<<"Ingrese el escalado en x: ";
		cin>>ex;
		cout<<"Ingrese el escalado en y: ";
		cin>>ey;

		for(int i = 1; i < t; i++){
			p[i].setX(p[i].getX()*ex);
		}

		for(int i = 1; i < t; i++){
			p[i].setY(p[i].getY()*ey);
		}
	}
}

//----------------------------------------------------------------------------------------------//
void escalado (Punto *p, int t){
	int ex = 0;
	int ey = 0;
	Punto *tmp=p;
	string 	nombre;
	 if(p == NULL){
	 	cout<<"Vector de coordenadas vacio"<<endl;
	 }else{
		cout<<"Ingrese el escalado en x: ";
		cin>>ex;
		cout<<"Ingrese el escalado en y: ";
		cin>>ey;

		for(int i = 0; i < ex; i++){
			for(int i = 0; i < t; i++){
				p[i].setX(p[i].getX()+tmp[i].getX());
			}
		}
	
		for(int i = 0; i < ey; i++){
			for(int i = 0; i < t; i++){
				p[i].setY(p[i].getY()+tmp[i].getY());
			}
		}
	}
}
//---------------------------------------------------------------------------------------------//
void rotacion(int x, int y, int xf, int yf, int angulo, Punto *p, int t){
	string 	nombre;
	if(p == NULL){
	 	cout<<"Vector de coordenadas vacio"<<endl;
	 }else{
		for(int i = 0; i < t; i++){
			p[i].setX(ceil(x + p[i].getX()*cos(angulo)- p[i].getY()*sin(angulo)));
		}
		
		for(int i = 0; i < t; i++){
			p[i].setY(ceil(y + p[i].getX()*sin(angulo)+ p[i].getY() *cos(angulo)));
		}
	}
}
//-------------------------------------------------------------------------------------------------//
int perimetroCircunferencia (int radio){
	return (int) ((2*radio)*3.1416);
}

//-------------------------------------------------------------------------------------------------//
int distanciaEntreDosPuntos(int x1, int y1, int x2, int y2){
  double distancia = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
  return (int) distancia + 1;
}

//-------------------------------------------------------------------------------------------------//
Punto * cir(){
	int radio = 0;
	int x = 0;
	int y = 0;
	cout<<"Teclee el tamaño del radio de la circunferencia: ";
			cin>>radio;
			cout<<"Teclee las coordenadas del origen (X,Y): ";
		   	cin>>x>>y;
		   	coy = y;
		   	cox = x;
		   	cfy = radio;
		   	cfx = x;
			tamC = perimetroCircunferencia (radio);
			Punto *vectorCirculo = new Punto[tamC];
		   	CircleBresenham(x,y, radio, vectorCirculo);
		   	//circulo(radio, vectorCirculo);
			//imprimir(vectorCirculo, tamC);	
			return vectorCirculo;
}
//-------------------------------------------------------------------------------------------------//
Punto * line(){
	int 	x 		= 0;
	int 	y 		= 0;
	int 	r 		= 0;
	int 	z 		= 0;
	cout<<"Teclee las coordenadas iniciales (X1,Y1): ";
		   	cin>>x>>y;
			loy = y;
		   	lox = x;
		   	cout<<"Teclee las coordenadas finales (X2,Y2): ";
		   	cin>>r>>z;
		   	lfy = z;
		   	lfx = r;
		   	tamL = distanciaEntreDosPuntos(x, y, r, z);
			Punto *vectorLinea  = new Punto[tamL];
		   	BresenhamLineX(x, y, r, z, vectorLinea);
		   	//imprimir(vectorLinea, tamL);
		   	return vectorLinea;
}

//-------------------------------------------------------------------------------------------------//
/*int main(){
	int 	angulo;
	Punto *vectorC =		NULL;
	Punto *vectorL =		NULL;
	//-----------Crear circunferencia-----------------Crear linea---------------//
  	vectorC = cir();
  	vectorL = line();

	//------------Trasladar Circulo-------------------Trasladar Linea-----------//
	traslacion (vectorC, tamC);
	traslacion (vectorL, tamL);

	//---------------Escalado Circulo------------------Escalado Linea------------//
   	cout<<"ingrese el angulo: ";
	cin>>angulo;
    rotacion(cox, coy, cfx, cfy, angulo, vectorC, tamC);

  	cout<<"ingrese el angulo: ";
	cin>>angulo;
    rotacion(lox, loy, lfx, lfy, angulo, vectorL, tamL);
	
	escalado (vectorC, tamC);
	escalado (vectorL, tamL);


return 0;
}*/
