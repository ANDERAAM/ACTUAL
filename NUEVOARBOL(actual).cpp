#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <vector>
using namespace std;

typedef struct Empleados{
    long long Cedula ;
    long long Salario;
    long long Bonificaciones;
    long long Descuentos;
    string Nombre ;
    string NombreEmpresa ;
    string FechaNacimiento;
    string Departamento;
    string Cod1;
    string Cod2; 
    struct Empleados *izq , *der ;

}*ABB1,*ABB2,*ABB3;

ABB1 Abb1 = NULL;
ABB2 Abb2 = NULL;
ABB3 Abb3 = NULL;

vector<string>B;vector<string>Auxiliar;vector<string>Fichero;


Empleados *CrearEmpleados(Empleados *&Arbol ,long long Cedula, long long Salario,long long  Bonificaciones , long long Descuentos ,string Nombre ,string NombreEmpresa , string FechaNacimiento , string Departamento , string Cod1,string Cod2 ){
    Empleados *Empleado              =   new Empleados();
    Empleado->Nombre                 =   Nombre;
    Empleado->Cedula                 =   Cedula;
    Empleado->NombreEmpresa          =   NombreEmpresa;
    Empleado->FechaNacimiento        =   FechaNacimiento;
    Empleado->Departamento           =   Departamento;
    Empleado->Salario                =   Salario;
    Empleado->Bonificaciones         =   Bonificaciones;
    Empleado->Descuentos             =   Descuentos;
    Empleado->Cod1                   =   Cod1;
    Empleado->Cod2                   =   Cod2;
    Empleado->der                    =   NULL;
    Empleado->izq                    =   NULL;
    return Empleado;
}
void InsertarEmpleados(Empleados *&Arbol,long long Cedula,long long Salario,long long Bonificaciones , long long Descuentos ,string Nombre ,string NombreEmpresa , string FechaNacimiento , string Departamento ,string Cod1 , string Cod2){
 if   (Arbol == NULL){
      Arbol = CrearEmpleados(*&Arbol,Cedula,Salario,Bonificaciones,Descuentos ,Nombre ,NombreEmpresa ,FechaNacimiento ,Departamento ,Cod1,Cod2);
      }else if (Cedula < Arbol->Cedula) {
      InsertarEmpleados(*&Arbol->izq,Cedula,Salario,Bonificaciones,Descuentos ,Nombre ,NombreEmpresa ,FechaNacimiento ,Departamento ,Cod1,Cod2);
      }else if (Cedula > Arbol->Cedula) {
      InsertarEmpleados(*&Arbol->der,Cedula,Salario,Bonificaciones,Descuentos ,Nombre ,NombreEmpresa ,FechaNacimiento ,Departamento ,Cod1,Cod2);
      }
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
long long Convertir(string x){
   int tam = x.size();string num;string total;
   for(int i=0;i<tam;i++){
   num = x.substr(i,1);
   if( num=="0"| num=="1" || num=="2" || num=="3" || num=="4" || num=="5" || num=="6"  || num=="7" || num=="8" || num=="9"){
   total=total+num;	
   } 
   }
   if(x==total){
   long long N = atoll(total.c_str());
   return N;
   }else{
       system ("cls");
       gotoxy(40,9);printf("I N G R E S E  U N  N U M E R O  V A L I D O ");
       gotoxy(42,15);exit(1);
   }
}
string Espacio(string x){
    string y;
    for(int i=1;i<x.size();i++){
        y=y+x[i];
    }
    return y;
}



void CrearEmpleado();
void Empresa1();
void Departamento1();

ABB1 unirABB1(ABB1 izq , ABB1 der){
    if(izq==NULL) return der;
    if(der==NULL) return izq;
    ABB1 centro = unirABB1(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}
ABB2 unirABB2(ABB2 izq , ABB2 der){
    if(izq==NULL) return der;
    if(der==NULL) return izq;
    ABB2 centro = unirABB2(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}
ABB3 unirABB3(ABB3 izq , ABB3 der){
    if(izq==NULL) return der;
    if(der==NULL) return izq;
    ABB3 centro = unirABB3(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void EliminarABB1(ABB1 &arbol, long long x){
     if(arbol==NULL) return;

     if(x<arbol->Cedula)
         EliminarABB1(arbol->izq, x);
     else if(x>arbol->Cedula)
         EliminarABB1(arbol->der, x);

     else
     {
         ABB1 p = arbol;
         arbol = unirABB1(arbol->izq, arbol->der);
         delete p;
     }
}
void EliminarABB2(ABB2 &arbol, long long x){
     if(arbol==NULL) return;
     if(x<arbol->Cedula)
         EliminarABB2(arbol->izq, x);
     else if(x>arbol->Cedula)
         EliminarABB2(arbol->der, x);

     else
     {
         ABB2 p = arbol;
         arbol = unirABB2(arbol->izq, arbol->der);
         delete p;
     }
}
void EliminarABB3(ABB3 &arbol, long long x){
     if(arbol==NULL) return;
     if(x<arbol->Cedula)
         EliminarABB3(arbol->izq, x);
     else if(x>arbol->Cedula)
         EliminarABB3(arbol->der, x);

     else
     {
         ABB3 p = arbol;
         arbol = unirABB3(arbol->izq, arbol->der);
         delete p;
     }
}


void BaseFichero(){
ifstream Archivo;fflush( stdin );
Archivo.open("Parametros.txt",ios::app | ios::in);int c=0;string letra;string guardar;string x;
Archivo>>letra;
if(letra!=""){
while(!Archivo.eof()){
if(letra!="*"){
guardar=guardar+" "+letra;
}else{
guardar = Espacio(guardar);    
Fichero.push_back(guardar);
guardar.clear();
letra.clear();
}
Archivo >> letra;
}
}
Archivo.close();
}
void BaseArbol(){
ifstream Archivo;string letra;string total;fflush( stdin );vector<string>v;
Archivo.open("Empleados.txt",ios::in);
while(!Archivo.eof()){
    Archivo>>letra;
      if(letra!="*" && letra!="|"){
      total=total+" "+letra;
      }if(letra=="*" && letra!="|" ){
      total = Espacio(total);
      v.push_back(total);
      total.clear();
    }
    if(letra=="|"){
    B.push_back(v[0]);B.push_back(v[1]);
    for(int i=0;i<v.size();i++)cout<<v[i]<<endl;
    
    
    
    
    
    
    
    
    v.clear();Fichero.errase(Fichero.begin()+0,Fichero.begin()+)
    }
    
}
Archivo.close();
}
 
void PreOrden(Empleados *&Arbol){
     if(Arbol!=NULL)
     {
           cout <<"{"<<Arbol->Cedula<<"}"<<" -> "<<"{"<<Arbol->Nombre<<"}"<<" -> "<<"{"<<Arbol->NombreEmpresa<<"}"<<" -> "<<"{"<<Arbol->FechaNacimiento<<"}"<<" -> "<<"{"<<Arbol->Departamento<<"}"<<" -> "<<"{"<<Arbol->Salario<<"}"<<endl;
           PreOrden(Arbol->izq);
           PreOrden(Arbol->der);
     }
}

bool busquedaRec(Empleados *&Arbol, long long dato){
     int r=0;   // 0 indica que lo encontre

     if(Arbol==NULL)
        return r;

     if(dato<Arbol->Cedula)
         r = busquedaRec(Arbol->izq, dato);

     else if(dato>Arbol->Cedula)
         r = busquedaRec(Arbol->der, dato);

     else
        r = 1;   // son iguales, lo encontre

     return r;
}
void MOD(Empleados *&Arbol,long long x){
    if(Arbol!=NULL)
    {     
          if( Arbol->Cedula == x ){            
          cout<<"ESTE ES EL VALOR DE X : "<<x<<endl;getch();
          }
          MOD(Arbol->izq,x);
          MOD(Arbol->der,x);
    }
}
void Encontro(Empleados *&Arbol,long long x){
    int P = busquedaRec(Arbol,x);
    if(P==0){
        system ("cls");
        gotoxy(40,9);printf("I N G R E S O  N U M E R O  V A L I D O");
        gotoxy(42,15);exit(1);    
    }else{
        MOD(Arbol, x);
    }
}


bool busquedaRec(Empleados *&Arbol, long long dato){
     int r=0;   // 0 indica que lo encontre

     if(Arbol==NULL)
        return r;

     if(dato<Arbol->Cedula)
         r = busquedaRec(Arbol->izq, dato);

     else if(dato>Arbol->Cedula)
         r = busquedaRec(Arbol->der, dato);

     else
        r = 1;   // son iguales, lo encontre

     return r;
}
void MOD(Empleados *&Arbol,long long x){
    if(Arbol!=NULL)
    {     
          if( Arbol->Cedula == x ){            
          cout<<"ESTE ES EL VALOR DE X : "<<x<<endl;getch();
          }
          MOD(Arbol->izq,x);
          MOD(Arbol->der,x);
    }
}
void Encontro(Empleados *&Arbol,long long x){
    int P = busquedaRec(Arbol,x);
    if(P==0){
        system ("cls");
        gotoxy(40,9);printf("I N G R E S O  N U M E R O  V A L I D O");
        gotoxy(42,15);exit(1);    
    }else{
        MOD(Arbol, x);
    }
}


int main(){
    fflush( stdin );fflush( stdin );fflush( stdin );
    //BaseFichero();
    BaseArbol();//for(int i=0;i<v.size();i++)cout<<v[i]<<endl;
    //PreOrden(Abb1);
	getch();
}







int arbol;string Departamento;string NombreEmpresa;string Opcion; int a=0 ;
void Empresa1(){
system("cls");cin.clear();fflush( stdin );
gotoxy(65,8);cout<<"SELECCIONE LA EMPRESA QUE VA A AFILIAR AL EMPLEADO";
gotoxy(75,11); cout<<"1. EMPRESA A (ECOPETROL)";
gotoxy(75,13); cout<<"2. EMPRESA B (BAVARIA)";
gotoxy(75,15); cout<<"3. EMPRESA C  (CEMENTOS ARGOS)";
gotoxy(68,17);cout<<"Seleccione La Empresa Deacuerdo Al Numero -> ";fflush( stdin );cin>>Opcion;
if(Opcion=="1"){
fflush( stdin );NombreEmpresa="ECOPETROL EMPRESA A";
}else if(Opcion=="2"){
fflush( stdin );NombreEmpresa="BAVARIA EMPRESA B";
}else if(Opcion=="3"){
fflush( stdin );NombreEmpresa="CEMENTOS ARGOS EMPRESA C";
}else{
    system ("cls");
    gotoxy(72,20);printf("::: I N G R E S O  N U M E R O  V A L I D O :::");getch();
    gotoxy(42,15);exit(-1);
}
Auxiliar[1]=NombreEmpresa;
arbol=atoi(Opcion.c_str());
getch();
}
void Departamento1(){
system("cls");cin.clear();fflush( stdin );
gotoxy(62,8);  cout<<" SELECCIONE EL DEPARTAMENTO QUE VA A TRABAJAR EL EMPLEADO ";
gotoxy(83,11); cout<<"1. SISTEMA";
gotoxy(83,13); cout<<"2. NOMINA";
gotoxy(83,15); cout<<"3. GESTION HUMANA";
gotoxy(83,17); cout<<"4. PRODUCCION";
gotoxy(83,19); cout<<"5. CONTABILIDAD";
gotoxy(65,22); cout<<"Seleccione EL Departamento Deacuerdo Al Numero -> ";fflush( stdin );cin>>Opcion;
if(Opcion=="1"){
fflush( stdin );Departamento="SISTEMA";
}else if(Opcion=="2"){
fflush( stdin );Departamento="NOMINA";
}else if(Opcion=="3"){
fflush( stdin );Departamento="GESTION HUMANA";
}else if(Opcion=="4"){
fflush( stdin );Departamento="PRODUCCION";
}else if(Opcion=="5"){
fflush( stdin );Departamento="CONTABILIDAD";
}else{
    system ("cls");
    gotoxy(72,20);printf("::: I N G R E S O  N U M E R O  V A L I D O :::");getch();
    gotoxy(42,15);exit(-1);    
}
Auxiliar[4]=Departamento;
getch();
}
/*void CrearEm(){
Empresa1();
Departamento1();
system("cls");fflush( stdin );fflush( stdin );
fflush( stdin );string Numero;long long Cedula;string Nombre ;string FechaNacimiento;string y;long long Salario;
gotoxy(53,8); cout<<" I N G R E S E  L O S  D A T O S  D E L  N U E V O  E M P L E A D O";
gotoxy(59,12); cout<<"INGRESE LA CEDULA DEL NUEVO EMPLEADO : ";fflush( stdin );cin>>Numero;Cedula=Convertir(Numero);
if(VerificarCedula(y)==-1){
    system ("cls");
    gotoxy(65,20);printf("::: I N G R E S O  U N A  C E D U L A  N O  R E P E T I D A  :::");getch();
    gotoxy(42,15);exit(1);  
}
gotoxy(59,14); cout<<"INGRESE EL NOMBRE DEL NUEVO EMPLEADO : ";fflush( stdin );cin.clear();getline(cin,Nombre);Vacio(Nombre);
gotoxy(59,16);cout<<"INGRESE LA FECHA DE NACIMEINTO DEL NUEVO EMPLEADO : ";fflush( stdin );cin.clear();getline(cin,FechaNacimiento);Vacio(FechaNacimiento);Fecha(FechaNacimiento);
gotoxy(59,18);cout<<"INGRESE EL SALARIO DEL NUEVO EMPLEADO : ";fflush( stdin );cin>>Numero;y=validar(Numero);Salario=atoll(y.c_str());
getch();
fstream Archivo;
Archivo.open("Empleado.txt",ios::app);
Archivo<<Cedula<<" * "<<NombreEmpresa<<" * "<<Nombre<<" * "<<FechaNacimiento<<" * "<<Departamento<<" * "<<Salario<<" * "<<endl;
Archivo.close();
system ("cls");
gotoxy(72,20);printf("::: D A T O S  G U A R D A D O S  C O N  E X I T O :::");getch();
gotoxy(42,15);exit(-1);
	getch();
BaseExtra();
BaseArbol();
}*/



