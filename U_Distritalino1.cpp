#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
using namespace std;
//Para el GAME OVER
void inicializar_tablero(char [][21], int);
void cargargameover(char [][21], int);
void imprimir_gameover(char l[][21], int t);
void inicializar_tablero(char l[] [21], int){
	for ( int i=0; i<21; i++){
		for ( int j=0; j<21; j++){
			l[i][j]=' ';
		}
	}
}
void cargargameover(char l[][21], int t){
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			if((j==5&&((i>1&&i<6)||(i>6&&i<10)||(i>15&&i<21)))||(j==12&&((i>1&&i<5)||(i>10&&i<16)||(i>15&&i<20)))||(j==10&&(i>15&&i<21))){
				l[j][i]=(char)4;
			}
			if((i==1&&((j>5&&j<10)||(j>12&&j<17)))||(i==5&&((j>6&&j<10)||(j>12&&j<17)))||(i==6&&((j>5&&j<11)||(j>11&&j<16)))){
				l[j][i]=(char)4;
			}
			if((i==11&&((j>4&&j<11)||(j>11&&j<18)))||(i==15&&j>4&&j<11)||(i==10&&((j>5&&j<11)||(j>11&&j<16)))||(i==16&&((j>4&&j<11)||(j>11&&j<18)))){
				l[j][i]=(char)4;
			}
			if((j==10&&i>1&&i<5)||(j==7&&(i==3||i==4))||(j==8&&(i>5&&i<11))||((j==6&&i==12)||(j==7&&i==13)||(j==6&&i==14))){
				l[j][i]=(char)4;
			}
			if((j==7&&i>15&&i<20)||(j==17&&((i>1&&i<5)||(i>10&&i<16)))||((j==16&&i==7)||(j==17&&i==8)||(j==16&&i==9))||(j==14&&((i>11&&i<15)||(i>15&&i<20)))){
				l[j][i]=(char)4;
			}
			if((j==13&&i==20)||(i==20&&j<18&&j>14)){
				l[j][i]=(char)4;
			}
			
			
		}
	}
}
void imprimir_gameover(char gameover[][21], int t){
	inicializar_tablero(gameover,21);
	cargargameover(gameover,21);
	for(int i=0;i<t;i++){
		cout<<"   ";
		for(int j=0;j<t;j++){
			cout<< gameover[i][j]<<" ";
		}
		cout<<endl;
	}
}





//Juego
void imp_tablero(char[][50],int);
void inicializar_tablero(char[][50],int);
void marco(char[][50],int);
void muros_aleatorios(char[][50], int);
void pbestiast(char [][50],int );
void pbestiasl(char [][50],int );
void mov_bestias(char[][50],int,char,char);
void movimientobestias(char [][50], int , char);
void poder(char [][50], int , char );
int radiodealcanceauxl(char [][50], int, char, char);
int radiodealcanceauxt(char [][50], int, char, char);
int radiodealcanceletales(char [][50], int, char, int);
int radiodealcancetormentosas (char [][50], int, char, int);
void ayuda(int, int, char [][50],char);
int posicionX(char);
int posicionY(char);
void objetivos(char[][50]);
int muros_seguidos(char [][50],int,char);
void objetivostable(int, int, char );
int posicionmoc(char[][50], char);
void inicio();
//para rango de bestias
void inicializar_rango(char [][5], int);
void imprimir_rango(char l[][5], int t);
void inicializar_rango(char l[] [5], int){
	for ( int i=0; i<5; i++){
		for ( int j=0; j<5; j++){
			l[i][j]=' ';
		}
	}
}

void imprimir_rango(char rango[][5], int t){
	for(int i=0;i<t;i++){
		cout<<"\t\t\t";
		for(int j=0;j<t;j++){
			cout<<rango[i][j]<<" ";
		}
		cout<<endl;
	}
}





void inicio(){
	//sndPlaySound("C:\\Users\\Familia Bautista\\Documents\\Viviana\\Kalimba.wav");
	system("color 0B");
	cout<<"\n\n\n\n\n\t\t    °°°°° *** <<< ||| >>> *** °°°°°    \n";
	cout<<"\t\t °°°                              °°°  \n";
	cout<<"\t\t°°°    Bienvenido a UDistritalino   °°°  \n";
	cout<<"\t\t  °°°                             °°°   \n";
	cout<<"\t\t    °°°°° *** <<< ||| >>> *** °°°°° \n\n\n\n   ";
	cout<<"\n\n Es tu Primer Semestre en la Universidad Distrial FJDC, Estás un poco nervioso  ";
	cout<<" y perdido (como todo primiparo); Los estudiantes vagos y maliciosos de  ";
	cout<<"\n semestres adelantados deciden hacerte una mala broma...  ";
	cout<<"\n Te quitan la maleta y con ella las cosas necesarias para pasar el Semestre.";
	cout<<"\n\n Los chicos deciden devolver tus cosas pero ¡Ohh, Que Mala Onda! dejan tus" ;
	cout<<"\n pertenencias en cualquier lugar de la U y tu tienes que ir a buscarlas.";
	cout<<"\n\n Ahora, si quieres pasar el semestre tienes que ser ordenado e ir en busca ";
	cout<<"\n de tus objetivos, pero ¡Espera! no olvides que puedes encontarte con malos";
	cout<<"\n compañeros que ta haran retrasar o lo que es aún peor, con malos profesores";
	cout<<"\n que te haran perder el semestre y te expulsaran...";
	cout<<"\n\n Pero no tengas miedo, todo depende de ti y como afrontes la situación.";
	cout<<"\n\n\t\t\t ¡¡EXITO EN TU SEMESTRE!!\n\n\n";
	system ("Pause");
	system ("cls");
	cout<<"\n\n\t\t             - * * * - \n";
	cout<<"\n\n\t\tEXISTEN DOS MODALIDADES DE JUEGO...\n\n\n"<<endl;
	cout<<"Digita "<<(char)34<<"m"<<(char)34<<" para Juego Manual: El Jugador Realiza Los Movimientos. "<<endl;
	cout<<"Digita "<<(char)34<<"a"<<(char)34<<" para Juego Automatico: El Computador Realiza el Rol de Jugador"<<endl;
	cout<<"\n\n\t\t    ¿Que modo de juego quieres? ";
	
}
void inicializar_tablero(char z[][50], int t){
	for(int i=0; i<t; i++){
		for(int j=0; j<t; j++){
			z[i][j]=' ';
		}
	}
}
void marco(char z[][50], int t){
	for(int i=0; i<t; i++){
		for(int j=0; j<t; j++){
			if(i==0){
				z[i][j]=(char)223;
			}
			if(i==49){
				z[i][j]=(char)220;
			}
			if(j==0 || j==49){
				z[i][j]=(char)219;
			}
			
		}
		
	}
	
}
void muros_aleatorios(char z[][50],int t){
	int j=0, i=0;
	for(int k=0;k<t;k++){
		i=rand()%49+1;
		j=rand()%49+1;
		if(j!=49 && i!=49)z[i][j]=(char)176;
	}
}
void imp_tablero(char z[][50], int t){
	cout<<endl<<endl;
	for(int i=0; i<t; i++){
		cout<<"\t\t";
		for(int j=0; j<t; j++){
			cout<<z[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

void objetivos(char z[][50]){
	int j=0, i=0;
	for(int k=1; k<=6; k++){
		i=rand()%48+1;
		j=rand()%48+1;
		z[i][j]=k;
	}
}

int posicionX(char tablero[][50],int a,char z){
	for(int i=0;i<a;i++){
		for(int j=0; j<a; j++){
			if(tablero[i][j]==z){
				return i;
			}
		}
	}
}
int posicionY(char tablero[][50],int a,char z){
	for(int i= 0;i<a;i++){
		for(int j=0; j<a; j++){
			if(tablero[i][j]==z){
				return j;
			}
		}
	}
}


void pbestiast(char z[][50],int t){
	
	z[rand()%48+1][rand()%48+1]='a';
	z[rand()%48+1][rand()%49+1]='b';
	if(t==3) {
		z[rand()%48+1][rand()%48+1]='c';
	}
	if(t==4){
		z[rand()%48+1][rand()%48+1]='c';
		z[rand()%48+1][rand()%48+1]='d';
	}
	if(t==5){
		z[rand()%48+1][rand()%48+1]='c';
		z[rand()%48+1][rand()%48+1]='d';
		z[rand()%48+1][rand()%48+1]='e';
	}
	if(t==6){
		z[rand()%48+1][rand()%48+1]='c';
		z[rand()%48+1][rand()%48+1]='d';
		z[rand()%48+1][rand()%48+1]='e';
		z[rand()%48+1][rand()%48+1]='f';
	}
	if(t==7){
		z[rand()%48+1][rand()%48+1]='c';
		z[rand()%48+1][rand()%48+1]='d';
		z[rand()%48+1][rand()%48+1]='e';
		z[rand()%48+1][rand()%48+1]='f';
		z[rand()%48+1][rand()%48+1]='g';
	}
	if(t==8){
		z[rand()%48+1][rand()%48+1]='c';
		z[rand()%48+1][rand()%48+1]='d';
		z[rand()%48+1][rand()%48+1]='e';
		z[rand()%48+1][rand()%48+1]='f';
		z[rand()%48+1][rand()%48+1]='g';
		z[rand()%48+1][rand()%48+1]='h';
	}

}
void pbestiasl(char z[][50],int t){
	
	z[rand()%48+1][rand()%48+1]='A';
	z[rand()%48+1][rand()%48+1]='B';
	if(t==3) {
		z[rand()%48+1][rand()%48+1]='C';
	}
	if(t==4){
		z[rand()%48+1][rand()%48+1]='C';
		z[rand()%48+1][rand()%48+1]='D';
	}
	if(t==5){		
		z[rand()%48+1][rand()%48+1]='C';
		z[rand()%48+1][rand()%48+1]='D';
		z[rand()%48+1][rand()%48+1]='E';
	}
	if(t==6){
		z[rand()%48+1][rand()%48+1]='C';
		z[rand()%48+1][rand()%48+1]='D';
		z[rand()%48+1][rand()%48+1]='E';
		z[rand()%48+1][rand()%48+1]='F';
	}
	if(t==7){
		z[rand()%48+1][rand()%48+1]='C';
		z[rand()%48+1][rand()%48+1]='D';
		z[rand()%48+1][rand()%48+1]='E';
		z[rand()%48+1][rand()%48+1]='F';
		z[rand()%48+1][rand()%48+1]='G';
	}
	if(t==8){
		z[rand()%48+1][rand()%48+1]='C';
		z[rand()%48+1][rand()%48+1]='D';
		z[rand()%48+1][rand()%48+1]='E';
		z[rand()%48+1][rand()%48+1]='F';
		z[rand()%48+1][rand()%48+1]='G';
		z[rand()%48+1][rand()%48+1]='H';
	}

}


void movimientobestias(char tablero[][50], int a, char jugador){
	
	mov_bestias(tablero,50,jugador,'a');
	mov_bestias(tablero,50,jugador,'b');
	mov_bestias(tablero,50,jugador,'c');
	mov_bestias(tablero,50,jugador,'d');
	mov_bestias(tablero,50,jugador,'e');
	mov_bestias(tablero,50,jugador,'f');
	mov_bestias(tablero,50,jugador,'g');
	mov_bestias(tablero,50,jugador,'h');
	mov_bestias(tablero,50,jugador,'A');
	mov_bestias(tablero,50,jugador,'B');
	mov_bestias(tablero,50,jugador,'C');
	mov_bestias(tablero,50,jugador,'D');
	mov_bestias(tablero,50,jugador,'E');
	mov_bestias(tablero,50,jugador,'F');
	mov_bestias(tablero,50,jugador,'G');
	mov_bestias(tablero,50,jugador,'H');
	
}
int radiodealcancetormentosas(char tablero[][50], int t, char jugador, int besttor){
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,penalizacion=0;
	a=radiodealcanceauxt(tablero,t,jugador,'a');
	b=radiodealcanceauxt(tablero,t,jugador,'b');
	if(besttor==3){
		c=radiodealcanceauxt(tablero,t,jugador,'c');
	}
	if(besttor==4){
		c=radiodealcanceauxt(tablero,t,jugador,'c');
		d=radiodealcanceauxt(tablero,t,jugador,'d');
	}
	if(besttor==5){
		c=radiodealcanceauxt(tablero,t,jugador,'c');
		d=radiodealcanceauxt(tablero,t,jugador,'d');
		e=radiodealcanceauxt(tablero,t,jugador,'e');
	}
	if(besttor==6){
		c=radiodealcanceauxt(tablero,t,jugador,'c');
		d=radiodealcanceauxt(tablero,t,jugador,'d');
		e=radiodealcanceauxt(tablero,t,jugador,'e');
		f=radiodealcanceauxt(tablero,t,jugador,'f');
	}
	if(besttor==7){
		c=radiodealcanceauxt(tablero,t,jugador,'c');
		d=radiodealcanceauxt(tablero,t,jugador,'d');
		e=radiodealcanceauxt(tablero,t,jugador,'e');
		f=radiodealcanceauxt(tablero,t,jugador,'f');
		g=radiodealcanceauxt(tablero,t,jugador,'g');
	}
	if(besttor==8){
		c=radiodealcanceauxt(tablero,t,jugador,'c');
		d=radiodealcanceauxt(tablero,t,jugador,'d');
		e=radiodealcanceauxt(tablero,t,jugador,'e');
		f=radiodealcanceauxt(tablero,t,jugador,'f');
		g=radiodealcanceauxt(tablero,t,jugador,'g');
		h=radiodealcanceauxt(tablero,t,jugador,'h');
	}
	penalizacion=a+b+c+d+e+f+g+h;
	return penalizacion;
}
int radiodealcanceletales(char tablero[][50], int t, char jugador, int bestlet){
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,gameover=0;
	a=radiodealcanceauxl(tablero,t,jugador,'A');
	b=radiodealcanceauxl(tablero,t,jugador,'B');
	if(bestlet==3) {
		c=radiodealcanceauxl(tablero,t,jugador,'C');
	}
	if(bestlet==4){
		c=radiodealcanceauxl(tablero,t,jugador,'C');
		d=radiodealcanceauxl(tablero,t,jugador,'D');
	}
	if(bestlet==5){
		c=radiodealcanceauxl(tablero,t,jugador,'C');
		d=radiodealcanceauxl(tablero,t,jugador,'D');
		e=radiodealcanceauxl(tablero,t,jugador,'E');
	}
	if(bestlet==6){
		c=radiodealcanceauxl(tablero,t,jugador,'C');
		d=radiodealcanceauxl(tablero,t,jugador,'D');
		e=radiodealcanceauxl(tablero,t,jugador,'E');
		f=radiodealcanceauxl(tablero,t,jugador,'F');
	}
	if(bestlet==7){
		c=radiodealcanceauxl(tablero,t,jugador,'C');
		d=radiodealcanceauxl(tablero,t,jugador,'D');
		e=radiodealcanceauxl(tablero,t,jugador,'E');
		f=radiodealcanceauxl(tablero,t,jugador,'F');
		g=radiodealcanceauxl(tablero,t,jugador,'G');
	}
	if(bestlet==8){
		c=radiodealcanceauxl(tablero,t,jugador,'C');
		d=radiodealcanceauxl(tablero,t,jugador,'D');
		e=radiodealcanceauxl(tablero,t,jugador,'E');
		f=radiodealcanceauxl(tablero,t,jugador,'F');
		g=radiodealcanceauxl(tablero,t,jugador,'G');
		h=radiodealcanceauxl(tablero,t,jugador,'H');
	}
	gameover=a+b+c+d+e+f+g+h;
	return gameover;
	
}
int radiodealcanceauxt(char tablero[][50], int t, char jugador, char bestia){
	int x=0, y=0;
	int c=0; //penalizacion del n porcieto de yo no se que hijupuchas
	x=posicionX(tablero,t,bestia);
	y=posicionY(tablero,t,bestia);
	if(tablero[x-1][y]==jugador || tablero[x-1][y+1]==jugador || tablero[x-1][y-1]==jugador ){
		cout<<endl<<" \t\t       * * *";
		cout<<endl<<" \t\t  ¡¡BESTIA TORMENTOSA!!\n";
		c=x+y; 
		cout<<endl<<"\t\tBestia "<<(char)34<<bestia<<(char)34<<" Ubicada en ["<<x<<"]["<<y<<"] ";
		cout<<endl<<"\t\t\tTe absorbe "<<c<<" movimientos."<<endl;
		system("Pause");
	}
	
	if(tablero[x][y-1]==jugador || tablero[x][y+1]==jugador){
		cout<<endl<<" \t\t       * * *";
		cout<<endl<<" \t\t  ¡¡BESTIA TORMENTOSA!!\n";
		c=x+y; 
		cout<<endl<<"\t\tBestia "<<(char)34<<bestia<<(char)34<<" Ubicada en ["<<x<<"]["<<y<<"] ";
		cout<<endl<<"\t\t\tTe absorbe "<<c<<" movimientos."<<endl;
		system("Pause");
	}
	
	if(tablero[x+1][y]==jugador || tablero[x+1][y-1]==jugador || tablero[x+1][y+1]==jugador){
		cout<<endl<<" \t\t       * * *";
		cout<<endl<<" \t\t  ¡¡BESTIA TORMENTOSA!!\n";
		c=x+y; 
		cout<<endl<<"\t\tBestia "<<(char)34<<bestia<<(char)34<<" Ubicada en ["<<x<<"]["<<y<<"] ";
		cout<<endl<<"\t\tTe absorbe "<<c<<" movimientos.\n\n\n"<<endl;
		system("Pause");
	}

	return c;
}

int radiodealcanceauxl(char tablero[][50], int t, char jugador, char bestia){
	int x=0, y=0, c=0;
	x=posicionX(tablero,t,bestia);
	y=posicionY(tablero,t,bestia);
	if(tablero[x-1][y]==jugador || tablero[x-1][y+1]==jugador || tablero[x-1][y-1]==jugador ){
		cout<<endl<<" \t\t  *  *  *  * " <<endl;
		cout<<endl<<" \t\t¡¡NOOO, BESTIA LETAL!!\n\n\n " <<endl;
		system("Pause");
		system ("cls");
		system ("color 0A");
		char gameover[21][21];
		imprimir_gameover(gameover,21);
		c++;
	}

	if(tablero[x][y-1]==jugador || tablero[x][y+1]==jugador){
		cout<<endl<<" \t\t  *  *  *  * " <<endl;
		cout<<endl<<" \t\t¡¡NOOO, BESTIA LETAL!!\n\n\n " <<endl;
		system("Pause");
		system ("cls");
		system ("color 0E");
		char gameover[21][21];
		imprimir_gameover(gameover,21);
		c++;
	}

	if(tablero[x+1][y]==jugador || tablero[x+1][y-1]==jugador || tablero[x+1][y+1]==jugador){
		cout<<endl<<" \t\t  *  *  *  * " <<endl;
		cout<<endl<<" \t\t¡¡NOOOO, BESTIA LETAL!! \n\n\n" <<endl;
		system("Pause");
		system ("cls");
		system ("color 0D");
		char gameover[21][21];
		imprimir_gameover(gameover,21);
		c++;
	}

	return c;
	
}



void mov_bestias(char tablero[][50],int a,char jugador,char bestia){
	int x=0, y=0, p=0;
	x=posicionX(tablero,a,bestia);
	y=posicionY(tablero,a,bestia);
	do{
		p=2+(rand()%7);
		if(p==8){
			if(x-1!=0){
				if(tablero[x-1][y]==' '){
					tablero[x][y]=' ';
					x=x-1;
					y=y;
					tablero[x][y]=bestia;
					
					}
				}
			}
		
		
		if(p==4){
			if(y-1!=0){
				if(tablero[x][y-1]==' '){
					tablero[x][y]=' ';
					x=x;
					y=y-1;
					tablero[x][y]=bestia;
					
					}
				}
			}
		
		if(p==6){
			if(y+1!=49){
				if(tablero[x][y+1]==' '){
					tablero[x][y]=' ';
					x=x;
					y=y+1;
					tablero[x][y]=bestia;
					
					}
				}
			}
		
		
		if(p==2){
			if(x+1!=49){
				if(tablero[x+1][y]==' '){
					tablero[x][y]=' ';
					x=x+1;
					y=y;
					tablero[x][y]=bestia;
				}
			}
		}
		}while( p==3 || p==5 || p==7);
}

void ayuda(int p, int movimientos, char tablero[][50], char jugador){
	if(p==1){
		system("cls");
		cout<<"\n\n\t\t\t * * * \n";
		cout<<"\n\n\t\t  ¡¡SUGERIR CAMINO!!\n\n ";
		cout<<"\n\n\t Emm bueno, esto es algo incomodo...Yo te sugiero \n ";
		cout<<"\t que sigas a tu corazon, solo así encontraras\n ";
		cout<<"\t el verdadero camino. \n\n ";
		cout<<"\n\t Un buen consejo vale por 1000 pero por esta vez ";
		cout<<"\n\t solo seran 10 movimientos. :)\n\n\n\n ";
		
		
	}
	if(p==3){
		system("cls");
		cout<<"\n\n\t\t\t * * * \n";
		cout<<"\n\n\t\t  ¡¡INSTRUCCIONES!!\n\n ";
		cout<<"\n\n\t Las teclas de movimiento basicas son 2,4,6,8 que son abajo, ";
		cout<<"\n\t izquierda, derecha y arriba respectivamente.";
		cout<<"\n\n\t Ok, antes de ir por los objetivos tienes que tener tu mochila "<<(char)230;
		cout<<"\n\t porque sin ella, no podras hacer algo.  \n ";
		cout<<"\n\t Una vez tengas la Mochila Activada, tendras que llevarla a";
		cout<<"\n\t a todo lugar, sin embargo, para facilitar tus movimientos,";
		cout<<"\n\t se te activaran las teclas 7,9,1,3 para que puedas moverte";
		cout<<"\n\t de una forma mas facil. ";
		cout<<"\n\n\t Los objetivos se podran adquirir de forma ascendente o descendete ";
		cout<<"\n\t según como lo hayas indicado al inicio del juego. ";
		cout<<"\n\n\t En la parte inferior del tablero de juego, aparecera el orden  ";
		cout<<"\n\t obligatorio con cual pudras guiarte, por ejemplo, si elegiste ";
		cout<<"\n\t Ascendente, los objetivos por obtener apareceran de la ";
		cout<<"\n\t siguente manera:  "<<(char)6<<" "<<(char)5<<" "<<(char)4<<" "<<(char)3<<" "<<(char)2<<" "<<(char)1;
		cout<<"\n\n\t Donde el primer objetivo a conseguir es "<<(char)1<<", luego "<<(char)2<<" y asi ";
		cout<<"\n\t sucesivamente hasta llegar al ultimo objetivo que, en este caso,";
		cout<<"\n\t corresponde al "<<(char)6;
		cout<<"\n\n\t Por otro lado, existen dos tipos de Bestias: Tormentosas y Letales.";
		cout<<"\n\n\t -Las Bestias Tormentosas estan en letras Minusculas y el encuentro ";
		cout<<"\n\t con alguna de ellas (casilla vecina) generara una perdida de ";
		cout<<"\n\t movimientos segun en la posicion en la que se encuentre.";
		cout<<"\n\n\t -Las Bestias Letales estan en letras Mayusculas y el encuentro";
		cout<<"\n\t con alguna de ellas (casilla vecina) generara una perdida instantanea";
		cout<<"\n\t del juego.";
		cout<<"\n\n\t Tienes una gran cantidad de movimientos al inicio del juego, pero ";
		cout<<"\n\t cada vez que pidas ayuda, se penalizara con movimientos.";
		cout<<"\n\n\t La ayuda se pide marcando el 911 y segun la opcion que escogas";	
		cout<<"\n\t se te quitaran cierta cantidad de movimientos.";
		cout<<"\n\t Existen cuatro tipos de ayuda, Sugerir caminio que te quitara 10";
		cout<<"\n\t movimientos al igual que Vecinos Peligroso, pudes recordar las";
		cout<<"\n\t instrucciones que solo te quitara un movimiento y por ultimo el ";
		cout<<"\n\t famoso 'poder'. ";
		cout<<"\n\n\t El Poder fue creado con la necesidad de romper un muro, cuando ";
		cout<<"\n\t la situacion lo requiera, sin embargo, pedir el poder o Recargar ";
		cout<<"\n\t el arma que es lo mismo, te quita una cantidad de 400 movimientos. ";
		cout<<"\n\t Es decir que solo puedes hacer uso de este 'poder' mientras tus ";
		cout<<"\n\t movimientos sean sufucientes de lo contrario perderas el juego. ";
		
		
		
	}
	if(p==2){
		system("cls");
		cout<<"\n\n\t\t\t * * * \n";
		cout<<"\n\n\t\t  ¡¡VECINOS PELIGROSOS!!\n\n ";
		cout<<"\n\n\t A continuacion te mostraremos un tipo de radar, donde podras \n ";
		cout<<"\t observar las bestias que te acechan...¡CUIDADO! este radar es solo\n ";
		cout<<"\t un indicador, puede estar cerca cualquier bestia o incluso puede que\n ";
		cout<<"\t sea un objetivo, ¿quien sabe? solo tu puedes averiguarlo... \n ";
			
		char rango[5][5];
		inicializar_rango(rango, 5);

		int x=posicionX(tablero,50,jugador);
		int y=posicionY(tablero,50,jugador);
		
		rango[2][2]=jugador;
		if(tablero[x-2][y-2]==(' '|| (char)176)) rango[0][0]=(char)207;
		if(tablero[x-2][y-1]==(' '|| (char)176)) rango[0][1]=(char)207;
		if(tablero[x-2][y]==(' '|| (char)176)) rango[0][2]=(char)207;
		if(tablero[x-2][y+1]==(' '|| (char)176)) rango[0][3]=(char)207;
		if(tablero[x-2][y+2]==(' '|| (char)176)) rango[0][4]=(char)207;
		if(tablero[x-1][y-2]==(' '|| (char)176)) rango[1][0]=(char)207;
		if(tablero[x-1][y+2]==(' '|| (char)176)) rango[1][4]=(char)207;
		if(tablero[x-1][y-1]==(' '|| (char)176)) rango[1][1]=(char)207;
		if(tablero[x-1][y+1]==(' '|| (char)176)) rango[1][3]=(char)207;
		if(tablero[x-1][y]==(' '|| (char)176)) rango[1][2]=(char)207;
		if(tablero[x][y-2]==(' '|| (char)176)) rango[2][0]=(char)207;
		if(tablero[x][y-1]==(' '|| (char)176)) rango[2][1]=(char)207;
		if(tablero[x][y+2]==(' '|| (char)176)) rango[2][4]=(char)207;
		if(tablero[x][y+1]==(' '|| (char)176)) rango[2][3]=(char)207;
		if(tablero[x+2][y-2]==(' '|| (char)176)) rango[4][0]=(char)207;
		if(tablero[x+2][y-1]==(' '|| (char)176)) rango[4][1]=(char)207;
		if(tablero[x+2][y]==(' '|| (char)176)) rango[4][2]=(char)207;
		if(tablero[x+2][y+1]==(' '|| (char)176)) rango[4][3]=(char)207;
		if(tablero[x+2][y+2]==(' '|| (char)176)) rango[4][4]=(char)207;
		if(tablero[x+1][y-2]==(' '|| (char)176)) rango[3][0]=(char)207;
		if(tablero[x+1][y+1]==(' '|| (char)176)) rango[3][3]=(char)207;
		if(tablero[x+1][y-1]==(' '|| (char)176)) rango[3][1]=(char)207;
		if(tablero[x+1][y+2]==(' '|| (char)176)) rango[3][4]=(char)207;
		if(tablero[x+1][y]==(' '|| (char)176)) rango[3][2]=(char)207;
		cout<<endl<<endl;
		imprimir_rango(rango,5);
		cout<<endl<<endl;
		cout<<"\t Cuando el radar detecta a alguna bestia se muestra así: "<<(char)207;
		cout<<"\n\n\tPenalizacion: 10 Movimientos. \n\n\n";
	
	}

	if(p==4){
		cout<<endl<<"\t\t* * *\n\t\t¡ARMA RECARGADA! \n\t Cuando desees activarla solo basta \n\t oprimir la BARRA ESPACIADORA\n";
		cout<<endl<<"\t\tPenalización: 400 movimientos\n\n\n"<<endl;
	}
			
}






void poder(char tablero[][50],int a, char jugador){
	int x=0, y=0;
	x=posicionX(tablero,50,jugador);
	y=posicionY(tablero,50,jugador);
	if(a==8){
		if(tablero[x-1][y]==(char)176){
			tablero[x-1][y]=' ';
		}else{
			cout<<" \n\n \t\t¡¡BALA PERDIDA!!  "<<endl<<endl;
			system("pause");
			}
		}
	
	if(a==2){
		if(tablero[x+1][y]==(char)176){
			tablero[x+1][y]=' ';
		}else{
			cout<<" \n\n \t\t¡¡BALA PERDIDA!!  "<<endl<<endl;
			system("pause");
		}
	}
	
	if(a==4){
		if(tablero[x][y-1]==(char)176){
			tablero[x][y-1]=' ';
		}else{
			cout<<" \n\n \t\t¡¡BALA PERDIDA!!  "<<endl<<endl;
			system("pause");
		}
	}

	if(a==6){
		if(tablero[x][y+1]==(char)176){
			tablero[x][y+1]=' ';
		}else{
			cout<<" \n\n \t\t¡¡BALA PERDIDA!!  "<<endl<<endl;
			system("pause");
		}
	}
}

int murosseguidos(char tablero[][50]){     
	int penalizaciontotal=0, penalizacion=0;
	for(int i=1;i<49;i++){
		for(int j=1; j<49; j++){
			penalizacion=0;
			if(tablero[i][j]==(char)176){
				if(tablero[i+1][j]==(char)176){
				penalizacion++;
				}
				if(tablero[i-1][j]==(char)176){
					penalizacion++;
				}
				if(tablero[i][j+1]==(char)176){
					penalizacion++;
				}
				if(tablero[i][j-1]==(char)176){
					penalizacion++;
				}
				if(penalizacion>1){
					penalizacion=penalizacion++;
				}
				penalizaciontotal=penalizaciontotal+penalizacion;
		}
	}
	}
	return penalizaciontotal;
}
int posicionmoc(char tablero[][50], char jugador){
	int h=0, x=0, y=0;
	x=posicionX(tablero,50,jugador);
	y=posicionY(tablero,50,jugador);
	if(tablero[x][y+1]==(char)230){
		h=6;
		return h;
		
	}
	if(tablero[x][y-1]==(char)230){
		h=4;
		return h;
		
	}
	if(tablero[x-1][y]==(char)230){
		h=8;
		return h;
		
	}
	
	if(tablero[x+1][y]==(char)230){
		h=2;
		return h;
		
	}
}



void objetivostable(int objetivosobt, int objetivospor, char orden ){
	char t=' ';
	if(orden=='d'){
		cout<<endl<<"\tObjetivos Obtenidos("<<objetivosobt<<"): ";
		for(int m=6; m>objetivospor; m--){
			t=m;
			cout<<t<<" ";}
		
		cout<<endl<<"\tObjetivos Por Obtener("<<objetivospor<<"): ";
		for(int m=1; m<=objetivospor; m++){
			t=m;
			cout<<t<<" ";
		}
	}
	if(orden=='a'){
		cout<<endl<<"\tObjetivos Obtenidos("<<objetivosobt<<"): ";
		for(int m=1; m<=objetivosobt; m++){
			t=m;
			cout<<t<<" ";}
		
		cout<<endl<<"\tObjetivos Por Obtener("<<objetivospor<<"): ";
		for(int m=6; m>objetivosobt; m--){
			t=m;
			cout<<t<<" ";
		}
	}

	
}
	



	
int mochila(int, char [][50], char);
int mochila(int z, char tablero[][50], char jugador){
	int h=0, x=0, y=0;
	x=posicionX(tablero,50,jugador);
	y=posicionY(tablero,50,jugador);
	if(z==char('8')){
		for(int k=1; k<7; k++){ 
			if(tablero[x-1][y]==(char)230){
				h=1;
				return h;
				break;
			}}
	}
	if(z==char('4')){
		for(int k=1; k<7; k++){ 
			if(tablero[x][y-1]==(char)230){
				h=1;
				return h;
				break;
				
			}
		}}
	if(z==char('6')){
		for(int k=1; k<7; k++){
			if(tablero[x][y+1]==(char)230){
				h=1;
				return h;
				break;
				
			}
		}
	}
	if(z==char('2')){
		for(int k=1; k<7; k++){ 
			if(tablero[x+1][y]==(char)230){
				h=1;
				return h;
				break;
			}}
	}
	
	return h;
}

int irporobj(char [][50], int, char, char);
int irporobj(char tablero[][50], int z, char jugador, char objetivo){
	int xj=0, yj=0, yo=0, xo=0, h=0;
	xj=posicionX(tablero,50,jugador);
	yj=posicionY(tablero,50,jugador);
	xo=posicionX(tablero,50,objetivo);
	yo=posicionY(tablero,50,objetivo);
	if(xj==xo && yj<yo){
		cout<<"2";
		if(tablero[xj][yj+1]==' '){
			tablero[xj][yj+1]=jugador;
			tablero[xj][yj]=' ';
		}
		if(tablero[xj][yj+1]==objetivo){
			tablero[xj][yj+1]=jugador;
			tablero[xj][yj]=' ';
			h=1;
		}
	}
	if(xj==xo && yj>yo){
		cout<<"3";
		if(tablero[xj][yj-1]==' '){
			tablero[xj][yj-1]=jugador;
			tablero[xj][yj]=' ';
		}
		if(tablero[xj][yj-1]==objetivo){
			tablero[xj][yj-1]=jugador;
			tablero[xj][yj]=' ';
			h=1;
		}
	}
	if(yj==yo && xj>xo){
		cout<<"4";
		if(tablero[xj-1][yj]==' '){
			tablero[xj-1][yj]=jugador;
			tablero[xj][yj]=' ';
		}
		else if(tablero[xj-1][yj]==objetivo){
			tablero[xj-1][yj]=jugador;
			tablero[xj][yj]=' ';
			h=1;
		}
	}
	if(yj==yo && xj<xo){
		cout<<"5";
		if(tablero[xj+1][yj]==' '){
			tablero[xj+1][yj]=jugador;
			tablero[xj][yj]=' ';
		}
		else if(tablero[xj+1][yj]==objetivo){
			tablero[xj+1][yj]=jugador;
			tablero[xj][yj]=' ';
			h=1;
		}
	}
	if(yj>yo && (xj>xo||xj<xo)){
		cout<<"6";
		if(tablero[xj][yj-1]==' '){
			tablero[xj][yj-1]=jugador;
			tablero[xj][yj]=' ';
		}
		else if(tablero[xj+1][yj]==' '){
			tablero[xj][yj+1]=jugador;
			tablero[xj][yj]=' ';
		}
		else if(tablero[xj-1][yj]==' '){
			tablero[xj-1][yj]=jugador;
			tablero[xj][yj]=' ';
		}
		
	}
	if(yj<yo && (xj>xo||xj<xo)){
		cout<<"7";
		if(tablero[xj][yj+1]==' '){
			tablero[xj][yj+1]=jugador;
			tablero[xj][yj]=' ';
		}
		else if(tablero[xj-1][yj]==' '){
			tablero[xj-1][yj]=jugador;
			tablero[xj][yj]=' ';
		}
		else if(tablero[xj+1][yj]==' '){
			tablero[xj+1][yj]=jugador;
			tablero[xj][yj]=' ';
		}
		
	}
	
		
	
	return h;

}



int main() {
	
	inicio();
	char nivel=' ', jugador=' ', orden=' ',modo=' ';
	int muros=0, bestiastorm=0,bestiaslet=0,jugadoraux=0;
	cin>>modo;
	while(modo!='a' && modo!='m'){
		cout<<"\n\n\t\t\t    - * * * - ";
		cout<<endl<<"\t\t\t¡Opcion Invalida! \n\t\tVuelve a Ingresar el Modo De Juego (m/a):  ";
		cin>>modo;
	}
	if(modo=='a'){
		cout<<endl<<"\t\t\t\t- * * * -";
		cout<<endl<<"\t\t\t  ¡¡ MODO AUTOMATICO !!";
		cout<<endl<<"\t\t¿En que orden quieres que la computadora \n\t\tobtenga los objetivos? (a/d):  ";
		cin>>orden;
		while(orden!='a' && orden!='d'){
			cout<<"\n\n\t\t ¡Espera!";
			cout<<endl<<"\t¡¿Que te Pasa?¿Que clase de orden es ese?!"<<endl;
			cout<<"\tVuelve a Digitar el Orden(a/d): ";
			cin>>orden;
		}
		system("cls");

		char tablero[50][50];
		inicializar_tablero(tablero,50);
		marco(tablero,50);
		muros=650;
		muros_aleatorios(tablero,muros);
		bestiaslet=5;
		bestiastorm=5;
		pbestiasl(tablero,bestiaslet);
		pbestiast(tablero,bestiastorm);
		objetivos(tablero);
		int x=0, y=0; 
		x=rand()%48+1;
		y=rand()%48+1;
		tablero[x][y]=(char)230;
		jugador=(char)64;
		x=rand()%48+1;
		y=rand()%48+1;
		while(tablero[x+1][y]!=(' '|| (char)176) && tablero[x][y+1]!=(' '|| (char)176 )&& tablero[x-1][y]!=(' '|| (char)176 ) && tablero[x][y-1]!=(' '|| (char)176 )
		&& tablero[x-1][y+1]!=(' '|| (char)176) && tablero[x+1][y-1]!=(' '|| (char)176 )&& tablero[x+1][y+1]!=(' '|| (char)176 )&& tablero[x-1][y-1]!=(' '|| (char)176 )){
			x=rand()%48+1;
			y=rand()%48+1;
		}
		tablero[x][y]=jugador;
		imp_tablero(tablero,50);
		int p=0, movimientos=0,disparos=0,vgameover=0, objetivospor=6, objetivosobt=0,penmuros=0;
		int mochilaa=0,posicionmoch=0, vari=0;
		int penalizacion=0, obtobj=0;
		char objetivo=' ';
		movimientos=49*49;
		penmuros=murosseguidos(tablero);
		movimientos=movimientos-penmuros;

		do{
		cout<<endl<<"\t\t\t\t- * * * -";
		cout<<endl<<"\t\t\t  ¡¡ MODO AUTOMATICO !!\n";
		cout<<endl<<"\t\t JUGADOR: "<<jugador;
		cout<<"\t\t"<<(char)230<<" MOCHILA: ";
		if(mochilaa==0) cout<<"DESACTIVADA";
		if(mochilaa==1) cout<<"ACTIVADA";
		if(orden=='d') vari=objetivospor;
		if(orden=='a') vari=objetivosobt+1;
		cout<<endl<<endl;
		objetivostable(objetivosobt,objetivospor,orden);
		cout<<endl<<endl<<endl;
		penalizacion=radiodealcancetormentosas(tablero,50,jugador,bestiastorm);
		movimientos=movimientos-penalizacion;
		vgameover=radiodealcanceletales(tablero,50,jugador,bestiaslet);
		if(vgameover>0) {
			return 0;
		}
		if(mochilaa==0){
			objetivo=(char)230;
			mochilaa==irporobj(tablero,50,jugador,objetivo);
			system("pause");
		}
		system("cls");
		movimientobestias(tablero,50,jugador);
		imp_tablero(tablero,50);
		}while(objetivosobt==1);
		system("cls");
		cout<<"\n\n\n\t\t\t:(\n\n\n"<<endl;
		system("pause");
		return 0;
	}
	system ("cls");
	cout<<"\n\t\t¡¡ MODO MANUAL XD !!"<<endl;
	cout<<endl<<"\tAHORA, ELIGE EL NIVEL O CONFIGURA TU JUEGO...  "<<endl;
	cout<<endl<<"\tFácil(f), Dificil(d), Personalizado(j): ";
	cin>>nivel;
	while(nivel!='f' && nivel!='d' && nivel!='j'){
		cout<<endl<<"\t¡NIVEL INEXISTENTE! \n\tVuelva a Ingresar el Nivel(f,d,j): ";
		cin>>nivel;
	}
	if(nivel=='f' || nivel=='d'){
	if(nivel=='f'){
		muros=727;
		bestiastorm=6;
		bestiaslet=4;
	}
	if(nivel=='d'){
		muros=947;
		bestiastorm=4;
		bestiaslet=6;
		}
	cout<<endl<<"\n\t¡NO TAN RAPIDO!\n\t ¿En que orden quieres ir por los objetivos?"<<endl;
	cout<<"\tAscendente o Descendente (a/d): ";
	cin>>orden;
	while(orden!='a' && orden!='d'){
		cout<<"\n\n\t\t ¡Espera!";
		cout<<endl<<"\t¡¿Que te Pasa?¿Que clase de orden es ese?!"<<endl;
		cout<<"\tVuelve a Digitar el Orden(a/d): ";
		cin>>orden;
	}
	}
	if(nivel=='j'){
		system("cls");
		cout<<endl<<"\n\t\t           ***    "<<endl;
		cout<<"\t\t ¡¡CONFIGURA TU JUEGO!"<<endl;
		cout<<endl<<"\n\tPrimero lo Primero... ";
		
		cout<<"\n\t ¿En que orden quieres ir por los objetivos?"<<endl;
		cout<<"\tAscendente o Descendente (a/d): ";
		cin>>orden;
		while(orden!='a' && orden!='d'){
			cout<<"\n\n\t\t ¡Espera!";
			cout<<endl<<"\t¡¿Que te Pasa?¿Que clase de orden es ese?!"<<endl;
			cout<<"\tVuelve a Digitar el Orden(a/d): ";
			cin>>orden;

		}
		cout<<endl<<"\t- * * * - ";
		cout<<endl<<"\t¿Cuantos muros deseas? (Min650, max950): ";
		cin>>muros;
		while(muros<650 || muros>950){
			cout<<endl<<"\tAl parecer deseas cosas imposibles..."<<endl;
			cout<<endl<<"\tRecuerda! Minimo 650 muros y Maximo 950 muros.";
			cout<<endl<<"\tDigita una cantidad diferente de muros: ";
			cin>>muros;
		}
		cout<<endl<<"\t- * * * - ";
		cout<<endl<<"\tAhora, tienes que elegir a las BESTIAS... "<<endl<<"\tJAJAJA ¡NO TE ASUSTES!\n";
		cout<<endl<<"\tEstas bestias son muy diferentes a como te las imaginas,";
		cout<<endl<<"\tlejos de tener cuernos, aspecto tenebroso o demás...";
		cout<<endl<<"\tEstas bestias estan camufladas e incluso parecen amigables";
		cout<<endl<<"\tpero no te dejes engañar."<<endl;
		cout<<endl<<"\tEstoy hablando de Bestias TORMENTOSAS, en letras minusculas y";
		cout<<endl<<"\tte llaman amigo pero lo unico que hacen es hacerte perder ";
		cout<<endl<<"\tmovimientos dentro de la U. La otra clase de Bestia es LETAL ";
		cout<<endl<<"\testan en Mayusculas y se titulan Maestros, pero no cualquier ";
		cout<<endl<<"\ttipo de maestro, si te llegas a encontrar con alguno de ellos ";
		cout<<endl<<"\tte sacaran de la Universidad antes que puedas pedir piedad.  ";
		cout<<endl<<"\n\tTienes que enfrentarte a 10 Bestias en total...";
		cout<<endl<<"\tCantidad de Bestias Tormentosas(Min2, Max8):";
		cin>>bestiastorm;
		while(bestiastorm<2 || bestiastorm>8){
			cout<<endl<<"\t- - - ";
			cout<<endl<<"\tEsa cantidad de bestias es TORMENTOSAAAA..."<<endl;
			cout<<"\t¡Recuerda! Minimo 2 y Maximo 8 bestias Tormentosas.";
			cout<<endl<<"\tDigite una cantidad diferente de bestias Tormentosas: ";
			cin>>bestiastorm;
		}
		bestiaslet=10-bestiastorm;
		cout<<endl<<"\t- * * * - ";
		cout<<endl<<"\tElegiste enfrentarte a "<<bestiastorm<<" bestias TORMENTOSAS, \n \t y además tienes que enfrentarte a "<<bestiaslet<<" Bestias LETALES. \n"<<endl;
		system("Pause");
		
	}
	system("cls");
	cout<<endl<<" \t\t\t - * * * -  "<<endl;
	cout<<endl<<"\t¡Antes de Empezar!, ¿Que Personaje Quieres?:  ";
	cout<<"\n\n\t\t1. "<<(char)20<<" Individualista ";
	cout<<"\n\t\t2. "<<(char)21<<" Desafiante   ";
	cout<<"\n\t\t3. "<<(char)146<<" Reformador";
	cout<<"\n\t\t4. "<<(char)190<<" Investigador ";
	cout<<"\n\t\t5. "<<(char)208<<" Entusiasta  "<<endl;
	cout<<endl<<"\tPara Elegir, Digite el Numero del Personaje: ";
	cin>>jugadoraux;
	while(jugadoraux>5 || jugadoraux<1){ 
		cout<<endl<<"¡El personaje que deseas NO esta disponible! ";
		cout<<endl<<"Por favor, elige nuevamente el personaje: ";
		cin>>jugadoraux;
	}   
	cout<<endl<<" \t\t\t   - * * * -  "<<endl;
	if(jugadoraux==1) {
		cout<<endl<<"\t\t     ¡¡INDIVIDUALISTA!!  "<<(char)20<<endl;
		cout<<"\t¡Buena Eleccion! Seguro no tendras problemas para\n\t evadir a las bestias Tormentosas..."<<endl<<endl;
		jugador=(char)20;
	}
	if(jugadoraux==2){
		cout<<endl<<"\t\t     ¡¡DESAFIANTE!!  "<<(char)21<<endl;
		cout<<"\t¡Entendido! Las Bestias Letales te deben odiar, ten cuidado..."<<endl<<endl;
		jugador=(char)21;
	}
	if(jugadoraux==3) {
		cout<<endl<<"\t\t     ¡¡REFORMADOR!!  "<<(char)146<<endl;
		cout<<"\t¡Ehh! ¿Que te puedo decir? Si no te gusta, cambialo..."<<endl<<endl;
		jugador=(char)146;
	}
	if(jugadoraux==4) {
		cout<<endl<<"\t\t     ¡¡INVESTIGADOR!!  "<<(char)190<<endl;
		cout<<"\t¡Tu mania de saberlo todo quizás te ayude, suerte!"<<endl<<endl;
		jugador=(char)190;
	}
	if(jugadoraux==5) {
		cout<<endl<<"\t\t     ¡¡ENTUSIASTA!!  "<<(char)208<<endl;
		cout<<"\tLo bueno de ti es que aunque vayas perdiendo \n\t el semestre, siempre mantienes la buena actitud"<<endl<<endl;
		jugador=(char)208;
	
	}
	system ("pause");
	system("cls");
	char tablero[50][50];
	inicializar_tablero(tablero,50);
	marco(tablero,50);
	muros_aleatorios(tablero,muros);
	pbestiasl(tablero,bestiaslet);
	pbestiast(tablero,bestiastorm);
	objetivos(tablero);
	int x=0, y=0; 
	x=rand()%48+1;
	y=rand()%48+1;
	tablero[x][y]=(char)230;
	x=rand()%48+1;
	y=rand()%48+1;
	while(tablero[x+1][y]!=(' '|| (char)176) && tablero[x][y+1]!=(' '|| (char)176 )&& tablero[x-1][y]!=(' '|| (char)176 ) && tablero[x][y-1]!=(' '|| (char)176 )
	   && tablero[x-1][y+1]!=(' '|| (char)176) && tablero[x+1][y-1]!=(' '|| (char)176 )&& tablero[x+1][y+1]!=(' '|| (char)176 )&& tablero[x-1][y-1]!=(' '|| (char)176 )){
		x=rand()%48+1;
		y=rand()%48+1;
	}
	tablero[x][y]=jugador;
	
	imp_tablero(tablero,50);
	int p=0, movimientos=0,disparos=0,vgameover=0, objetivospor=6, objetivosobt=0,penmuros=0;
	int mochilaa=0,posicionmoch=0, vari=0;
	movimientos=49*49;
	penmuros=murosseguidos(tablero);
	movimientos=movimientos-penmuros;

	do{
		cout<<endl<<endl<<"\tMovimientos Disponibles: "<<movimientos;
		cout<<"\t\t"<<(char)230<<" Mochila: ";
		if(mochilaa==0) cout<<"Desactivada";
		if(mochilaa==1) cout<<"Activada";
		if(orden=='d') vari=objetivospor;
		if(orden=='a') vari=objetivosobt+1;
		cout<<endl<<"\t\t\t\t\t      Disparos Disponibles: "<<disparos<<endl;
		objetivostable(objetivosobt,objetivospor,orden);
		cout<<endl<<"\n\n\t\t¡RECUERDA! SI NECESITAS AYUDA LLAMA AL 911 "<<endl;
		int penalizacion=0, obtobj=0;
		penalizacion=radiodealcancetormentosas(tablero,50,jugador,bestiastorm);
		movimientos=movimientos-penalizacion;
		vgameover=radiodealcanceletales(tablero,50,jugador,bestiaslet);
		if(vgameover>0) {
			return 0;
		}
	
		p=getch();
		
		if(p==char('8')){
			if(mochilaa==0){
				if(tablero[x-1][y]==' '){
					tablero[x][y]=' ';
					x=x-1;
					y=y;
					tablero[x][y]=jugador;
					movimientos--;}
				mochilaa=mochila(p,tablero,jugador);
				if(mochilaa==1)movimientos--;
			}
			if(mochilaa==1){
				posicionmoch=posicionmoc(tablero,jugador);
				if(posicionmoch==8){
					if(tablero[x-2][y]==' '){
						tablero[x-2][y]=(char)230;
						tablero[x][y]=' ';
						x=x-1;
						y=y;
						tablero[x][y]=jugador;
						movimientos--;
					}
					if(tablero[x-2][y]==vari){
						tablero[x-2][y]=(char)230;
						tablero[x][y]=' ';
						x=x-1;
						y=y;
						tablero[x][y]=jugador;
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
					
				}
				if(posicionmoch==6){
					if(tablero[x-1][y]==' '){
						tablero[x-1][y]=(char)230;
						tablero[x][y+1]=' ';
						movimientos--;
					}
					if(tablero[x-1][y]==vari){
						tablero[x-1][y]=(char)230;
						tablero[x][y+1]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
					
				}
				if(posicionmoch==2){
					if(tablero[x-1][y]==' '){
						tablero[x-1][y]=(char)230;
						tablero[x+1][y]=' ';
						movimientos--;
					}
					if(tablero[x-1][y]==vari){
						tablero[x-1][y]=(char)230;
						tablero[x+1][y]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==4){
					if(tablero[x-1][y]==' '){
						tablero[x-1][y]=(char)230;
						tablero[x][y-1]=' ';
						movimientos--;
					}
					if(tablero[x-1][y]==vari){
						tablero[x-1][y]=(char)230;
						tablero[x][y-1]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
			}
		}
		if(p==char('4')){
			if(mochilaa==0){
					if(tablero[x][y-1]==' '){
						tablero[x][y]=' ';
						x=x;
						y=y-1;
						tablero[x][y]=jugador;
						movimientos--;}
				mochilaa=mochila(p,tablero,jugador);
				if(mochilaa==1) movimientos--;
			}
			
			if(mochilaa==1){
				posicionmoch=posicionmoc(tablero,jugador);
				if(posicionmoch==4){
					if(tablero[x][y-2]==' '){
						tablero[x][y-2]=(char)230;
						tablero[x][y]=' ';
						x=x;
						y=y-1;
						tablero[x][y]=jugador;
						movimientos--;
					}
					if(tablero[x][y-2]==vari){
						tablero[x][y-2]=(char)230;
						tablero[x][y]=' ';
						x=x;
						y=y-1;
						tablero[x][y]=jugador;
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==2){
					if(tablero[x][y-1]==' '){
						tablero[x][y-1]=(char)230;
						tablero[x+1][y]=' ';
						movimientos--;
					}
					if(tablero[x][y-1]==vari){
						tablero[x][y-1]=(char)230;
						tablero[x+1][y]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==6){
					if(tablero[x][y-1]==' '){
						tablero[x][y-1]=(char)230;
						tablero[x][y+1]=' ';
						movimientos--;
					}
					vari=objetivosobt+1;
					if(tablero[x][y-1]==vari){
						tablero[x][y-1]=(char)230;
						tablero[x][y+1]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==8){
					if(tablero[x][y-1]==' '){
						tablero[x][y-1]=(char)230;
						tablero[x-1][y]=' ';
						movimientos--;
					}
					if(tablero[x][y-1]==vari){
						tablero[x][y-1]=(char)230;
						tablero[x-1][y]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
			}
		}
		
		if(p==char('6')){
			if(mochilaa==0){
				if(tablero[x][y+1]==' '){
					tablero[x][y]=' ';
					x=x;
					y=y+1;
					tablero[x][y]=jugador;
					movimientos--;
				}
				mochilaa=mochila(p,tablero,jugador);
				if(mochilaa==1) movimientos--;
				
			}
			
				
			if (mochilaa==1){
				posicionmoch=posicionmoc(tablero,jugador);
				if(posicionmoch==6){
					if(tablero[x][y+2]==' '){
						tablero[x][y+2]=(char)230;
						tablero[x][y]=' ';
						x=x;
						y=y+1;
						tablero[x][y]=jugador;
						movimientos--;
					}
					if(tablero[x][y+2]==vari){
						tablero[x][y+2]=(char)230;
						tablero[x][y]=' ';
						x=x;
						y=y+1;
						tablero[x][y]=jugador;
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==2){
					if(tablero[x][y+1]==' '){
						tablero[x][y+1]=(char)230;
						tablero[x+1][y]=' ';
						movimientos--;
					}
					if(tablero[x][y+1]==vari){
						tablero[x][y+1]=(char)230;
						tablero[x+1][y]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==4){
					if(tablero[x][y+1]==' '){
						tablero[x][y+1]=(char)230;
						tablero[x][y-1]=' ';
						movimientos--;
					}
					if(tablero[x][y+1]==vari){
						tablero[x][y+1]=(char)230;
						tablero[x][y-1]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==8){
					if(tablero[x][y+1]==' '){
						tablero[x][y+1]=(char)230;
						tablero[x-1][y]=' ';
						movimientos--;
					}
					if(tablero[x][y+1]==vari){
						tablero[x][y+1]=(char)230;
						tablero[x-1][y]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
			}
		}
		if(p==char('2')){
			if(mochilaa==0){
				if(tablero[x+1][y]==' '){
					tablero[x][y]=' ';
					x=x+1;
					y=y;
					tablero[x][y]=jugador;
					movimientos--;
					
				}
				mochilaa=mochila(p,tablero,jugador);
				if(mochilaa==1) movimientos--;
				
			}
			
			
			
			if(mochilaa==1){
				posicionmoch=posicionmoc(tablero,jugador);
				if(posicionmoch==2){
					if(tablero[x+2][y]==' '){
						tablero[x+2][y]=(char)230;
						tablero[x][y]=' ';
						x=x+1;
						y=y;
						tablero[x][y]=jugador;
						movimientos--;
					}
					if(tablero[x+2][y]==vari){
						tablero[x+2][y]=(char)230;
						tablero[x][y]=' ';
						x=x+1;
						y=y;
						tablero[x][y]=jugador;
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==8){
					if(tablero[x+1][y]==' '){
						tablero[x+1][y]=(char)230;
						tablero[x-1][y]=' ';
						movimientos--;
					}
					if(tablero[x+1][y]==vari){
						tablero[x+1][y]=(char)230;
						tablero[x-1][y]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==6){
					if(tablero[x+1][y]==' '){
						tablero[x+1][y]=(char)230;
						tablero[x][y+1]=' ';
						movimientos--;
					}
					if(tablero[x+1][y]==vari){
						tablero[x+1][y]=(char)230;
						tablero[x][y+1]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==4){
					if(tablero[x+1][y]==' '){
						tablero[x+1][y]=(char)230;
						tablero[x][y-1]=' ';
						movimientos--;
					}
					if(tablero[x+1][y]==vari){
						tablero[x+1][y]=(char)230;
						tablero[x][y-1]=' ';
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
			}
		}
		
		
		if(mochilaa==1){
		if(p==char('9')){ 
					posicionmoch=posicionmoc(tablero,jugador);
					if(posicionmoch==8){
						if(tablero[x-1][y+1]==' '){
							tablero[x-1][y+1]=(char)230;
							tablero[x][y]=' ';
							x=x-1;
							y=y;
							tablero[x][y]=jugador;
							movimientos--;
						}
						if(tablero[x-1][y+1]==vari){
							tablero[x-1][y+1]=(char)230;
							tablero[x][y]=' ';
							x=x-1;
							y=y;
							tablero[x][y]=jugador;
							movimientos--;
							objetivosobt++;
							objetivospor--;
						}
					}
					if(posicionmoch==6){
						if(tablero[x-1][y+1]==' '){
							tablero[x-1][y+1]=(char)230;
							tablero[x][y]=' ';
							x=x;
							y=y+1;
							tablero[x][y]=jugador;
							movimientos--;
						}
						if(tablero[x-1][y+1]==vari){
							tablero[x-1][y+1]=(char)230;
							tablero[x][y]=' ';
							x=x;
							y=y+1;
							tablero[x][y]=jugador;
							movimientos--;
							objetivosobt++;
							objetivospor--;
						}
					}

			}
			
		if(p==char('1')){
			
				posicionmoch=posicionmoc(tablero,jugador);
				if(posicionmoch==4){
					if(tablero[x+1][y-1]==' '){
						tablero[x+1][y-1]=(char)230;
						tablero[x][y]=' ';
						x=x;
						y=y-1;
						tablero[x][y]=jugador;
						movimientos--;
					}

					if(tablero[x+1][y-1]==vari){
						tablero[x+1][y-1]=(char)230;
						tablero[x][y]=' ';
						x=x;
						y=y-1;
						tablero[x][y]=jugador;
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
					
				}
				if(posicionmoch==2){
					if(tablero[x+1][y-1]==' '){
						tablero[x+1][y-1]=(char)230;
						tablero[x][y]=' ';
						x=x+1;
						y=y;
						tablero[x][y]=jugador;
						movimientos--;
					}
					if(tablero[x+1][y-1]==vari){
						tablero[x+1][y-1]=(char)230;
						tablero[x][y]=' ';
						x=x+1;
						y=y;
						tablero[x][y]=jugador;
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}

			}
		
		if(p==char('3')){
				posicionmoch=posicionmoc(tablero,jugador);
				if(posicionmoch==6){
					if(tablero[x+1][y+1]==' '){
						tablero[x+1][y+1]=(char)230;
						tablero[x][y]=' ';
						x=x;
						y=y+1;
						tablero[x][y]=jugador;
						movimientos--;
					}
					if(tablero[x+1][y+1]==vari){
						tablero[x+1][y+1]=(char)230;
						tablero[x][y]=' ';
						x=x;
						y=y+1;
						tablero[x][y]=jugador;
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				if(posicionmoch==2){
					if(tablero[x+1][y+1]==' '){
						tablero[x+1][y+1]=(char)230;
						tablero[x][y]=' ';
						x=x+1;
						y=y;
						tablero[x][y]=jugador;
						movimientos--;
					}
					if(tablero[x+1][y+1]==vari){
						tablero[x+1][y+1]=(char)230;
						tablero[x][y]=' ';
						x=x+1;
						y=y;
						tablero[x][y]=jugador;
						movimientos--;
						objetivosobt++;
						objetivospor--;
					}
				}
				
			
		}
		if(p==char('7')){
			
			posicionmoch=posicionmoc(tablero,jugador);
			if(posicionmoch==8){
				if(tablero[x-1][y-1]==' '){
					tablero[x-1][y-1]=(char)230;
					tablero[x][y]=' ';
					x=x-1;
					y=y;
					tablero[x][y]=jugador;
					movimientos--;
				}
				if(tablero[x-1][y-1]==vari){
					tablero[x-1][y-1]=(char)230;
					tablero[x][y]=' ';
					x=x-1;
					y=y;
					tablero[x][y]=jugador;
					movimientos--;
					objetivospor--;
					objetivosobt++;
				}
				
			}
			if(posicionmoch==4){
				if(tablero[x-1][y-1]==' '){
					tablero[x-1][y-1]=(char)230;
					tablero[x][y]=' ';
					x=x;
					y=y-1;
					tablero[x][y]=jugador;
					movimientos--;
				}
				if(tablero[x-1][y-1]==vari){
					tablero[x-1][y-1]=(char)230;
					tablero[x][y]=' ';
					x=x;
					y=y-1;
					tablero[x][y]=jugador;
					movimientos--;
					objetivospor--;
					objetivosobt++;
				}
				
			}
		}
		
	}
		if(p==(char)57){
			p=getch();
			if(p==(char)49){
				p=getch();
				if(p==(char)49){
					int m=0;
					cout<<endl<<"\t\t ¡¡911 ¿CUAL ES SU EMERGENCIA!!  " <<endl;
					cout<<"\t1.Sugerir camino.\n\t2.Vecinos peligrosos.\n\t3.Recordar instrucciones.\n\t4.Recargar Arma."<<endl;
					cout<<endl<<"\tDigite el numero de la opcion que necesita: ";
					cin>>m;
					while(m!=4 && m!=2 && m!=1 && m!=3){
						cout<<endl<<"\t\t ¡¡OPCION INVALIDA!!  " <<endl;
						cout<<endl<<"\tVuelva a digitar la opcion: ";
						cin>>m;
					}
					ayuda(m,movimientos,tablero,jugador);
					if(m==4) {
						movimientos=movimientos-400;
						disparos++;
					}
					if(m==2 || m==1) {
						movimientos=movimientos-10;
					}
					if(m==3) {
						movimientos--;
					}
					system("pause");
				}
			}
		}
			
		
		if(p==(char)32){
			if(disparos>0){
			int direccion=0;
			cout<<"\n\n\t\t¡ARMA ACTIVADA! \n\t DIGITE LA DIRECCION(8,4,6,2): ";
			cin>>direccion;
			while(direccion!=8 && direccion!=4 && direccion!=6 && direccion!=2){
				cout<<endl<<"\n\n\t\t¿QUE? LAS DIRECCIONES SON:"<<endl;
				cout<<"\tArriba: 8 / Abajo: 2 / Izquierda: 4 / Derecha: 6";
				cout<<endl<<"\tVuelve a digitar la direccion: ";
				cin>>direccion;
			}
			poder(tablero,direccion,jugador);
			disparos--;
			}else{
				cout<<"\n\n\t\tNO TIENES DISPAROS, LLAMA AL 911.\n\n"<<endl;
				system("pause");
			}
		}

		system("cls");
		if(objetivosobt==6){
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			char gameover[21][21];
			imprimir_gameover(gameover,21);
			system("cls");
			system("color 0E");
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			imprimir_gameover(gameover,21);
			system("cls");
			system("color 0A");
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			imprimir_gameover(gameover,21);
			system("cls");
			system("color 0F");
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			imprimir_gameover(gameover,21);
			system("cls");
			system("color 0D");
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			imprimir_gameover(gameover,21);
			system("cls");
			system("color 0B");
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			imprimir_gameover(gameover,21);
			system("cls");
			system("color 0E");
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			imprimir_gameover(gameover,21);
			system("cls");
			system("color 0A");
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			imprimir_gameover(gameover,21);
			system("cls");
			system("color 0F");
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			imprimir_gameover(gameover,21);
			system("cls");
			system("color 0B");
			cout<<endl<<"\n\t\t ¡¡FELICIDADES!! ¡¡GANASTE EL JUEGO!!";
			imprimir_gameover(gameover,21);

			return 0;
		}
		movimientobestias(tablero,50,jugador);
		imp_tablero(tablero,50);
		
		
	}while(movimientos>0);
	cout<<"\n\n\t\t ¡¡SIN MOVIMIENTOS!! ";
	system("pause");
	system ("cls");
	char gameover[21][21];
	imprimir_gameover(gameover,21);
	return 0;
}
