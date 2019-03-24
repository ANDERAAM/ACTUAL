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

vector<string>B1;vector<string>B2;vector<string>Auxiliar;vector<string>Fichero;

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

string itoa(long long num){
  stringstream s;
  s<<num;
  return s.str();
 } 
string validar(char num[]){
for (int i = 0; i < strlen(num); i++){
if(!isdigit(num[i]) ) {
system ("cls");
gotoxy(40,9);printf("I N G R E S E  U N  N U M E R O  V A L I D O ");
gotoxy(42,15);exit(1);
}
}
string y = num;
return y;
}
void MesD(string mes , int dia,int anio){ 
if((mes=="ENERO" || mes=="FEBRERO" || mes=="MARZO" || mes=="ABRIL" || mes=="MAYO" || mes=="NOVIEMBRE"
||  mes=="JUNIO" || mes=="JULIO" ||  mes=="AGOSTO" || mes=="SEPTIEMBRE" || mes=="OCTUBRE" || mes=="DICIEMBRE") && anio>=1959 && anio<=2001){
if( (mes=="FEBRERO" && (dia!=0 || dia<=28))  || mes=="FEBRERO" && (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) && (dia!=0 || dia<=29) ){
}
if( (mes=="ENERO" || mes=="MARZO" || mes=="MAYO" || mes=="AGOSTO" || mes=="JULIO" || mes=="OCTUBRE" || mes=="DICIEMBRE") && (dia!=0 || dia<=31) ){
}
if( (mes=="ABRIL" || mes=="JUNIO" || mes=="SEPTIEMBRE" || mes=="NOVIEMBRE") && (dia!=0 || dia<=30)){
}
}else{
	 system ("cls");
            gotoxy(40,9);printf("INGRESE FECHA DE NACIMIENTO VALIDA");
            gotoxy(40,13);printf("ESCRIBA LA FECHA EN MAYUSCULA Y ESPACIOS COMO SE MUESTRA A CONTINUACION  : 21 DICIEMBRE 1996");
            cout<<endl;
            gotoxy(42,15);exit(1);

}
}
void Fecha(string fecha){ 
string dato[3];int dia,anio,contador=0;
string a;
for(int i=0;i<fecha.size();i++){
	if(fecha[i]!=' '){
    a=a+fecha[i];
	}else{
	dato[contador]=a;
	contador++;
	a.clear();
	}
}
dato[2]=a;
char* cadena1;char *cadena2;
cadena1 = (char *)a.c_str();
cadena2 = (char *)dato[0].c_str();
validar(cadena1);
validar(cadena2);
anio = atoi(a.c_str());
dia =  atoi(dato[0].c_str());
MesD(dato[1],dia,anio);
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
int Posicion(string x,vector<string>b){
   fflush( stdin );fflush( stdin );int a=0;
  for(int i=0;i<b.size()/2;i++){
     a = i*2;
     if(b[a]==x){
       return a;
       exit(1);
    } 
   }
   return -1;
     
}
string Parbol(string x,vector<string>b){
    int P = Posicion(x,b);
    if(b[P+1]=="ECOPETROL EMPRESA A"){return "Abb1";exit(1);}
    if(b[P+1]=="BAVARIA EMPRESA B"){return "Abb2";exit(1);}
    if(b[P+1]=="CEMENTOS ARGOS EMPRESA C"){return "Abb3";exit(1);}
    return "-1";
}
void Vacio(string letra){
if (letra==""){
      system ("cls");
      gotoxy(40,9);printf("C A M P O  V A C I O  E R R O R ");
      gotoxy(42,15);exit(1);
    }

}

void BaseFichero(){
ifstream Archivo;fflush( stdin );
Archivo.open("Parametros.txt",ios::app | ios::in);int c=0;string letra;string guardar;string x;
while(!Archivo.eof()){
    Archivo>>letra;
    if(letra!="*" && letra!="|"){
    guardar=guardar+" "+letra;
    }if(letra=="*" && letra!="|" ){
    guardar = Espacio(guardar);
    Fichero.push_back(guardar);
    guardar.clear();
    }
    }
   Archivo.close();
   for(int i=0;i<Fichero.size()/8;i++){
       c = i*8;
       B1.push_back(Fichero[c]);
       c=c+1;
       B1.push_back(Fichero[c]);
       c=0;
   }
}
void BaseArbol(){
fflush( stdin );vector<string>v;
ifstream Archivo;string letra;string total;
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
     fflush( stdin );cin.clear();
     if(v.size()!=0){B2.push_back(v[0]);B2.push_back(v[1]);}
     int P = Posicion(v[0],B1);
       if(P==-1 && v.size()!=0){ fflush( stdin );cin.clear();
       if(v[1]=="ECOPETROL EMPRESA A"){
       InsertarEmpleados(Abb1 ,atoll(v[0].c_str()),atoll(v[5].c_str()),0,0,v[1],v[2],v[3],v[4],".",".");
      // cout<<"ARBOL 1* "<<" - "<<atoll(v[0].c_str())<<" - "<<atoll(v[5].c_str())<<" - "<<0<<" - "<<0<<" - "<<v[1]<<" - "<<v[2]<<" - "<<v[3]<<" - "<<v[4]<<" - "<<"."<<" - "<<"."<<endl;    
       }if(v[1]=="BAVARIA EMPRESA B"){
       InsertarEmpleados(Abb2 ,atoll(v[0].c_str()),atoll(v[5].c_str()),0,0,v[1],v[2],v[3],v[4],".","." );    
      // cout<<"ARBOL 2* "<<" - "<<atoll(v[0].c_str())<<" - "<<atoll(v[5].c_str())<<" - "<<0<<" - "<<0<<" - "<<v[1]<<" - "<<v[2]<<" - "<<v[3]<<" - "<<v[4]<<" - "<<"."<<" - "<<"."<<endl;
       }if(v[1]=="CEMENTOS ARGOS EMPRESA C"){
     InsertarEmpleados(Abb3 ,atoll(v[0].c_str()),atoll(v[5].c_str()),0,0,v[1],v[2],v[3],v[4],".",".");   
      /// cout<<"ARBOL 3* "<<" - "<<atoll(v[0].c_str())<<" - "<<atoll(v[5].c_str())<<" - "<<0<<" - "<<0<<" - "<<v[1]<<" - "<<v[2]<<" - "<<v[3]<<" - "<<v[4]<<" - "<<"."<<" - "<<"."<<endl;
       }   
     }if(P!=-1){ fflush( stdin );cin.clear();
     if(v[1]=="ECOPETROL EMPRESA A"){
     InsertarEmpleados(Abb1 ,atoll(v[0].c_str()),atoll(v[5].c_str()),atoll(Fichero[P+7].c_str()),atoll(Fichero[P+6].c_str()),v[1],v[2],v[3],v[4],Fichero[P+4],Fichero[P+5]);    
    // cout<<"ARBOL 1 "<<" - "<<atoll(v[0].c_str())<<" - "<<atoll(v[5].c_str())<<" - "<<atoll(Fichero[7].c_str())<<" - "<<atoll(Fichero[6].c_str())<<" - "<<v[1]<<" - "<<v[2]<<" - "<<v[3]<<" - "<<v[4]<<" - "<<Fichero[4]<<" - "<<Fichero[5]<<endl;     
     Fichero.erase(Fichero.begin()+P,Fichero.begin()+(P+8));
     }if(v[1]=="BAVARIA EMPRESA B"){
     InsertarEmpleados(Abb2 ,atoll(v[0].c_str()),atoll(v[5].c_str()),atoll(Fichero[7].c_str()),atoll(Fichero[6].c_str()),v[1],v[2],v[3],v[4],Fichero[4],Fichero[5] );    
  //   cout<<"ARBOL 2 "<<" - "<<atoll(v[0].c_str())<<" - "<<atoll(v[5].c_str())<<" - "<<atoll(Fichero[7].c_str())<<" - "<<atoll(Fichero[6].c_str())<<" - "<<v[1]<<" - "<<v[2]<<" - "<<v[3]<<" - "<<v[4]<<" - "<<Fichero[4]<<" - "<<Fichero[5]<<endl;     
     Fichero.erase(Fichero.begin()+P,Fichero.begin()+(P+8));
     }if(v[1]=="CEMENTOS ARGOS EMPRESA C"){
     InsertarEmpleados(Abb3 ,atoll(v[0].c_str()),atoll(v[5].c_str()),atoll(Fichero[7].c_str()),atoll(Fichero[6].c_str()),v[1],v[2],v[3],v[4],Fichero[4],Fichero[5]);   
    // cout<<"ARBOL 3 "<<" - "<<atoll(v[0].c_str())<<" - "<<atoll(v[5].c_str())<<" - "<<atoll(Fichero[7].c_str())<<" - "<<atoll(Fichero[6].c_str())<<" - "<<v[1]<<" - "<<v[2]<<" - "<<v[3]<<" - "<<v[4]<<" - "<<Fichero[4]<<" - "<<Fichero[5]<<endl;     
     Fichero.erase(Fichero.begin()+P,Fichero.begin()+(P+8));
     }   
     }
    v.clear();
    }
    }
  Archivo.close();  
}


 
void PreOrden(Empleados *&Arbol){
     fflush( stdin );fflush( stdin );fflush( stdin );
     if(Arbol!=NULL)
     {
    cout <<"{"<<Arbol->Cedula<<"}"<<" -> "<<"{"<<Arbol->Nombre<<"}"<<" -> "<<"{"<<Arbol->NombreEmpresa<<"}"<<" -> "<<"{"<<Arbol->FechaNacimiento<<"}"<<" -> "<<"{"<<Arbol->Departamento<<"}"<<" -> "<<"{"<<Arbol->Salario<<"}"<<" -> "
     <<"{"<<Arbol->Cod1<<"}"<<" -> "<<"{"<<Arbol->Cod2<<"}"<<" -> "<<"{"<<Arbol->Descuentos<<"}"<<" -> "<<"{"<<Arbol->Bonificaciones<<"}"<<endl;
           PreOrden(Arbol->izq);
           PreOrden(Arbol->der);
     }
}

void Empresa1();
void Departamento1();

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
        Auxiliar.push_back(itoa(Arbol->Cedula));Auxiliar.push_back(Arbol->Nombre);Auxiliar.push_back(Arbol->NombreEmpresa);Auxiliar.push_back(Arbol->FechaNacimiento);
        Auxiliar.push_back(Arbol->Departamento);Auxiliar.push_back(itoa(Arbol->Salario));Auxiliar.push_back(Arbol->Cod1);Auxiliar.push_back(Arbol->Cod2);
        Auxiliar.push_back(itoa(Arbol->Descuentos));Auxiliar.push_back(itoa(Arbol->Bonificaciones));
     return r;
}
void MOD(Empleados *&Arbol,long long x){
    if(Arbol!=NULL)
    {     
          if( Arbol->Cedula == x ){            
            long long Cedula ;string Nombre ;string FechaNacimiento ;long long Salario;string Opcion;string Numero;system("cls");
            gotoxy(70,8);  cout<<"SELECCIONE LOS DATOS DEL EMPLEADO QUE DESEA MODIFICAR";
            gotoxy(87,11); cout<<"0. CEDULA";
            gotoxy(87,13); cout<<"1. EMPRESA A DONDE LABORA";
            gotoxy(87,15); cout<<"2. NOMBRE COMPLETO";
            gotoxy(87,17); cout<<"3. FECHA DE NACIMIENTO";
            gotoxy(87,19); cout<<"4. DEPARTAMENTO";
            gotoxy(87,21); cout<<"5. SALARIO DEL EMPLEADO";
            gotoxy(70,24);cout<<"Seleccione EL Departamento Deacuerdo Al Numero -> ";fflush( stdin );cin>>Opcion;cout<<Opcion<<endl;getch();            if(Opcion=="0"){system("cls");
            gotoxy(72,19); cout<<"INGRESE LA CEDULA DEL NUEVO EMPLEADO : ";fflush( stdin );cin>>Numero;int P=Posicion(Numero,B2);Cedula = Convertir(Numero);
            if(P!=-1){system("cls");gotoxy(50,12);printf("I N G R E S E  U N A  C E D U L A  N O  R E P E T I D A");getch();exit(1);}else{Auxiliar[0]=Numero;}
            if(Opcion=="1"){system("cls"); cout<<"Hola mundo";}
            if(Opcion=="2"){system("cls");gotoxy(72,19); cout<<"INGRESE EL NOMBRE DEL NUEVO EMPLEADO : ";fflush( stdin );getline(cin,Nombre);Vacio(Nombre);Auxiliar[2]=Nombre;}
            if(Opcion=="3"){system("cls");gotoxy(59,16);cout<<"INGRESE LA FECHA DE NACIMIENTO DEL NUEVO EMPLEADO : ";fflush( stdin );getline(cin,FechaNacimiento);Vacio(FechaNacimiento);Fecha(FechaNacimiento);Auxiliar[3]=FechaNacimiento;}
            if(Opcion=="4"){system("cls");Departamento1();}
            if(Opcion=="5"){system("cls");gotoxy(72,19);cout<<"INGRESE EL SALARIO DEL NUEVO EMPLEADO : ";fflush( stdin );getline(cin,Numero);Salario=Convertir(Numero);Auxiliar[5]=Numero;}
          //  cout<<"HOLA MUNDO"<<endl;
          for(int i=0;i<Auxiliar.size();i++) cout<<Auxiliar[i]<<endl;
            getch();
          }
          MOD(Arbol->izq,x);
          MOD(Arbol->der,x);
    }
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
    fflush( stdin );fflush( stdin );fflush( stdin );string Cedula;  Auxiliar.clear();
    BaseFichero();//for(int i=0;i<B1.size();i++)// cout<<" este es el valor de "<<B1[i]<<endl;
    BaseArbol();Empresa1();
    /*cout<<"Ingrese La Cedula Que Desea Modificar ";cin>>Cedula;cout<<endl;
    int P = Posicion(Cedula,B2);string Arbol = Parbol(Cedula,B2);
    if(P!=-1){
    if("Abb1"==Arbol){Encontro(Abb1,Convertir(B2[P])); }
    if("Abb2"==Arbol){Encontro(Abb2,Convertir(B2[P])); }
    if("Abb3"==Arbol){Encontro(Abb3,Convertir(B2[P])); }
    }else{
      system("cls");
      gotoxy(50,12);gotoxy(72,20);printf("::: LA CEDULA NO SE ENCUENTRA EN EL SISTEMA :::");
      getch();
      exit(-1); 
    }
    
    
    //int P = Posicion("123000",B2);
  //  cout<<B2[P]<<" "<<P<<endl;
    
    
  
  //PreOrden(Abb1);PreOrden(Abb2);PreOrden(Abb3);    
    /*cout<<"Ingrese La Cedula Que Desea Modificar ";cin>>Cedula;cout<<endl;
    int P = Posicion(Cedula,B2);
    if(P!=-1){
  //  Encontro(Empleados *&Arbol,long long x);
     }else{
      system("cls");
      gotoxy(50,12);gotoxy(72,20);printf("::: LA CEDULA NO SE ENCUENTRA EN EL SISTEMA :::");
      getch();
      exit(1);
    }*/
  //  cout<<"Hola mundo"<<endl;*/
	getch();
}







int arbol;string Departamento;string NombreEmpresa;int Opcion; int a=0 ;
void Empresa1(){
system("cls");cin.clear();fflush( stdin );
gotoxy(65,8);cout<<"SELECCIONE LA EMPRESA QUE VA A AFILIAR AL EMPLEADO";
gotoxy(75,11); cout<<"1. EMPRESA A (ECOPETROL)";
gotoxy(75,13); cout<<"2. EMPRESA B (BAVARIA)";
gotoxy(75,15); cout<<"3. EMPRESA C  (CEMENTOS ARGOS)";
gotoxy(68,17);cout<<"Seleccione La Empresa Deacuerdo Al Numero -> ";fflush( stdin );cin.clear();cin>>Opcion;
if(Opcion==1){
fflush( stdin );NombreEmpresa="ECOPETROL EMPRESA A";
}else if(Opcion==2){
fflush( stdin );NombreEmpresa="BAVARIA EMPRESA B";
}else if(Opcion==3){
fflush( stdin );NombreEmpresa="CEMENTOS ARGOS EMPRESA C";
}else{
    system ("cls");
    gotoxy(72,20);printf("::: I N G R E S O  N U M E R O  V A L I D O :::");getch();
    gotoxy(42,15);exit(-1);
}
Auxiliar[1]=NombreEmpresa;
arbol=1;
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
if(Opcion==1){
fflush( stdin );Departamento="SISTEMA";
}else if(Opcion==2){
fflush( stdin );Departamento="NOMINA";
}else if(Opcion==3){
fflush( stdin );Departamento="GESTION HUMANA";
}else if(Opcion==4){
fflush( stdin );Departamento="PRODUCCION";
}else if(Opcion==5){
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



