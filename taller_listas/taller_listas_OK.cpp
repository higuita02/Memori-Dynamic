#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;


// DEFINICION DE UNA ESTRUCTURA TIPO NODO
struct nodo{
	
	int dato;
	nodo *liga;
	
};


//DECLARACION DE NODO CABEZERA
nodo *cabezera=NULL;

//FIFRMAS DE FUNCIONES O PRECEDIMIENTOS
void menu(void);
void insertar_ordenadamente(void);
void recorrido(nodo *L);

void recorrido_detalle(nodo *L);


nodo *buscar_donde(nodo *L,int x);
void insertar(nodo *L,nodo *pos,int x);
void insertar_final(nodo *L);
void insertar_principio(nodo *L);
nodo *buscar_principio(nodo *L,int x);
void ordenar_ascendente(nodo *L);
void ordenar_descendente(nodo *L);
void buscar_dato(nodo *L,int x);
void buscar_dato_borrar(nodo *L,int dato);

void buscar_dato_borrar_repetido(nodo *L,int x);



nodo *nodo_anterior(nodo *L,int dato);
nodo *posicion_actual(nodo *pos);
void liberar_actual(nodo *anterior,nodo *actual);
void llamado_borrar(nodo *L,int dato);
void liberar_lista(nodo *L);





int ejemplo(int dato);

main(){
	menu();
}



void menu(void){
	int opcion;
	int dat;
	int otro=0;
	
	do{
		cout<<"\n\t1-  Isertar datos al final"<<endl;
		cout<<"\n\t2-  Isertar datos al principio"<<endl;
		cout<<"\n\t3-  Isertar datos ordenadamente"<<endl;
		cout<<"\n\t4-  Borrar un dato"<<endl;
		cout<<"\n\t5-  Borrar un dato repetidamente"<<endl;
		cout<<"\n\t6-  Liberar lista"<<endl;
		cout<<"\n\t7-  Mostrar lista"<<endl;
		cout<<"\n\t8-  Mostrar lista con detalle"<<endl;
		cout<<"\n\t9-  Buscar dato"<<endl;
		cout<<"\n\t10- Ordenar lista ascendentemente"<<endl;
		cout<<"\n\t11- Ordernar lista descendentemente"<<endl;
		cout<<"\n\t0-  SALIR"<<endl;
		
		cin>>opcion;
		
		
		switch(opcion){
			
			case 0: cout<<"\n Finaliza el programa y libera la memoria"<<endl;
			getch();
			exit(0);
			
			
			case 1:  insertar_final(cabezera);
			break;
			
			
			case 2:  insertar_principio(cabezera);
			break;
			
			
			case 3: insertar_ordenadamente();
			break;
			
			
			case 4: cout<<"Ingrese el dato a borrar"<<endl;
					cin>>dat;
					buscar_dato_borrar(cabezera,dat);					
			break;
			
			
			case 5:	cout<<"Ingrese el dato a borrar"<<endl;
					cin>>dat;			
			 		buscar_dato_borrar_repetido(cabezera,dat);
			break;
			
			
			case 6: liberar_lista(cabezera);
				
			break;
		
			
			case 7:  recorrido(cabezera);
			break;
				
			
			case 8:  recorrido_detalle(cabezera);
			break;
			
			
			
			case 9: 
					cout<<"Ingrese el dato a buscar"<<endl;
					cin>>dat;
					buscar_dato(cabezera,dat); 
			break;
			
			
			case 10: ordenar_ascendente(cabezera);
			break;
			
			
			case 11: ordenar_descendente(cabezera);
			break;			
			default:
			cout<<"\n OPCION NO VALIDA"<<endl;			
		}
	}
	
	
	
	
	
	
	
	
	
	
	while(opcion);
}


void insertar_ordenadamente(void){
	int cantidad,dato;
	int i=0;
	
	cout<<"\ndigite la cantidad de nodos: ";
	cin>>cantidad;
	
	while(i<cantidad){
		cout<<"\ningrese del dato"<<i+1<<": ";
		cin>>dato;
		
	
	
		nodo *y=NULL;
		y=buscar_donde(cabezera,dato);
		insertar(cabezera,y,dato);
		i++;
	}	
}

nodo *buscar_donde(nodo *L, int x){
	nodo *y=NULL;
	nodo *p=L;
	
/*	cout<<"L, por referencia: "<<L<<endl;
	cout<<"Cabezera: "<<cabezera<<endl;
	cout<<"El auxiliar p: "<<p<<endl;
	
	
	cout<<"L, direccion de memoria:  "<<&L<<endl;
	cout<<"Cabezera: direccion de memoria: "<<&cabezera<<endl;
	cout<<"El auxiliar p direccion de memoria: "<<&p<<endl; */
	
	
	
	while((p!=NULL)&&(p->dato<x)){		
	
	//	cout<<"cabezera apunta a : "<<p<<endl;
		y=p;
		p=p->liga;		
	}
	
	return y;
	
	
}


void insertar(nodo *L,nodo *pos,int x){
	
	nodo *nuevo=NULL;
	nuevo=(nodo *)malloc(sizeof(nodo));
	nuevo->dato=x;
	nuevo->liga=NULL;	
	//cout<<"direccion de memoria de nuevo: "<<&nuevo<<endl;
	//cout<<"donde apunta nuevo:"<<nuevo<<endl;
	
	
	
	if(pos==NULL){
		
		
		nuevo->liga=L;
		cabezera=nuevo;
	
//	cout<<"dentro del if"<<endl;	
//	cout<<"donde apunta nuevo: "<<&nuevo->liga<<endl;
//	cout<<"direccion de memoria de cabezera: "<<&cabezera<<endl;
		
	}else{
		nuevo->liga=pos->liga;
		pos->liga=nuevo;
	}	
	
}

void recorrido(nodo *L){
	if(L==0){
		cout<<" la lista esta vacia"<<endl;
	}
	else{
		
		nodo *recorre=NULL;
		recorre=L;
		
		//cout<<"-------------------------------"<<endl;
		//cout<<"la lista esta de la siguiente manera"<<endl;
		
		while(recorre!=0){
			
			cout<<"\n";
			cout<<"Dato: "<<recorre->dato<<endl;
		/*	cout<<"Esta en la posicion: "<<recorre<<endl;
			cout<<"Apunta hacia: "<<recorre->liga<<endl; */
			
			recorre=recorre->liga;
		}
		
	}
	
	
}


void insertar_final(nodo *L){
	
	int cantidad,dato;
	int i=0;
	
	cout<<"\ndigite la cantidad de nodos: ";
	cin>>cantidad;
	
	while(i<cantidad){
		cout<<"\ningrese del dato"<<i+1<<": ";
		cin>>dato;
		
	
	
		//nodo *y=NULL;
		//y=buscar_donde(cabezera,dato);
		insertar(cabezera,NULL,dato);
		i++;
	}	
	

	
}



nodo *buscar_principio(nodo *L,int x){
	
	nodo *y=NULL;
	nodo *p=L;
	
	/*cout<<"L, por referencia: "<<L<<endl;
	cout<<"Cabezera: "<<cabezera<<endl;
	cout<<"El auxiliar p: "<<p<<endl;
	
	
	cout<<"L, direccion de memoria:  "<<&L<<endl;
	cout<<"Cabezera: direccion de memoria: "<<&cabezera<<endl;
	cout<<"El auxiliar p direccion de memoria: "<<&p<<endl; */
	
	
	
	while(p!=NULL){		
	
		
		y=p;
		p=p->liga;		
	}
	
	return y;	
}





void insertar_principio(nodo *L){
	
	int cantidad,dato;
	int i=0;
	
	cout<<"\ndigite la cantidad de nodos: ";
	cin>>cantidad;
	
	while(i<cantidad){
		cout<<"\ningrese del dato"<<i+1<<": ";
		cin>>dato;
		
	
	
		nodo *y=NULL;
		y=buscar_principio(cabezera,dato);
		insertar(cabezera,y,dato);
		i++;
	}		
} 



void ordenar_ascendente(nodo *L){
	
	int menor=0;
	nodo *p=NULL;
	nodo *q=NULL;
	
	if(L==NULL){
		cout<<"lista vacia";
	}else{	
			
						
			p=L;
		
			while((p->liga)!=(NULL)){
				
						
				q=p->liga;
				//cout<<"entre al primer while"<<endl;	
				while(q!=NULL){
					//cout<<"entre al segundo while"<<endl;	
					if((p->dato)>(q->dato)){
						
					//cout<<"valor de p.dato"<<p->dato;
					//	cout<<"valor de q.dato"<<q->dato;
					
				
						menor=p->dato;
						p->dato=q->dato;
						q->dato=menor;
					}
					q=q->liga;			
					
				}
				p=p->liga;	
			}
		}
}  




void ordenar_descendente(nodo *L){
	
	int menor=0;
	nodo *p=NULL;
	nodo *q=NULL;
	
	if(L==NULL){
		cout<<"lista vacia";
	}else{	
			
						
			p=L;
		
			while((p->liga)!=(NULL)){
				
						
				q=p->liga;
				//cout<<"entre al primer while"<<endl;	
				while(q!=NULL){
					//cout<<"entre al segundo while"<<endl;	
					if((p->dato)<(q->dato)){
						
					//cout<<"valor de p.dato"<<p->dato;
					//	cout<<"valor de q.dato"<<q->dato;
					
				
						menor=p->dato;
						p->dato=q->dato;
						q->dato=menor;
					}
					q=q->liga;			
					
				}
				p=p->liga;	
			}
		}
}  



void buscar_dato(nodo *L,int x){
	
	int ban=0;
//	int contado=0;
	
	if(L==0){
		cout<<" la lista esta vacia"<<endl;
	}
	else{
		
		nodo *recorre=NULL;
		recorre=L;
		
		while(recorre!=0){
			if((recorre->dato)==(x)){
				ban=1;
			//	contador++;
				cout<<"el dato : "<<x<<" esta en la posicion : "<<recorre<<endl;				
			}
				
			recorre=recorre->liga;
		}
		
		if(ban==0){
			
			cout<<"el dato: "<<x<<"no se encuentra en la lista"<<endl;
		}
		
	}
	
	
}


void buscar_dato_borrar(nodo *L,int x){
	
	
	nodo *recorre=NULL,*y=NULL;
	recorre=L;
	
	if(recorre==NULL){
		cout<<"la lista esta vacia"<<endl;		
	}
	
	while((recorre!=NULL)&&((recorre->dato)!=x)){
		
		
		y=recorre;
		recorre=recorre->liga;	
	}
	
	if(recorre==NULL){
		cout<<"el dato : "<<x<<"No se encuentra en la lista"<<endl;
	}else if(y==NULL){
		
		cabezera=recorre->liga;
		cout<<"El dato : "<<x<<" Fue borrado de la lista"<<endl;
		
	}else{
		y->liga=recorre->liga;
		cout<<"el dato : "<<x<<"fue borrado de lla lista"<<endl;
	}
	
	
	
	free(recorre);
}


void buscar_dato_borrar_repetido(nodo *L,int x){	
	
	
	nodo *recorre=NULL,*y=NULL;
	recorre=L;
	int cont=0;


	if(recorre==NULL){
		cout<<"la lista esta vacia"<<endl;		
	}
	
	while((recorre)!=(0)&&(recorre->liga!=0)){
		//cout<<"entre al while 1"<<endl;
		
		if((L==recorre)&&((recorre->dato)==(x)&&((recorre)!=(NULL)))){
		//	cout<<"entre al if"<<endl;
			
			while((recorre->dato)==(x)&&((recorre->liga)!=(NULL))){   //aqui tengo que meter 	while((recorre->dato)==(x)&&recorre!=NULL)

		//		cout<<"entre al while 2"<<endl;				
				cabezera=recorre->liga;
				//cabezera=cabezera->liga;
				
				
				cout<<"dato :"<<recorre->dato<<" en : "<<recorre<<" a sido borrado"<<endl;
				free(recorre);
				recorre=cabezera;
				recorrido(cabezera);
			}
		}
		else{	
		
		//	cout<<"entre al else"<<endl;
			y=recorre;
			recorre=recorre->liga;			
			
			recorrido(cabezera);
		}
		
		while((recorre->dato)==(x)&&((recorre)!=(NULL))){
			
		//	cout<<"entre al while 3";
			y->liga=recorre->liga;
			free(recorre);
			recorre=y;
			
			recorrido(cabezera);
		}		
	}
	
	//recorrido(cabezera);
	
		
	
}







int ejemplo(int dato){
	
	if(dato==1){
		return 1;
	}
	
	
	if(dato==0){
		return 0;
	}
	
}


void recorrido_detalle(nodo *L){
	
	
	if(L==0){
		cout<<" la lista esta vacia"<<endl;
	}
	else{
		
		nodo *recorre=NULL;
		recorre=L;
		
		
		cout<<"\n\n\n";
		cout<<"-------------------------------"<<endl;
		cout<<"la lista esta de la siguiente manera"<<endl;
		
		while(recorre!=0){
			cout<<"Dato: "<<recorre->dato<<endl;
			cout<<"Esta en la posicion: "<<recorre<<endl;
			cout<<"Apunta hacia: "<<recorre->liga<<endl;
			cout<<"-------------------------------"<<endl;
			cout<<"\n";
			
			recorre=recorre->liga;
		}
	}	
	
}


void liberar_lista(nodo* L){
	nodo *x=NULL;
	x=L;
	
	while(x!=0){
		
		cabezera=cabezera->liga;
		//cout<<"x esta apuntando a: "<<x;	
		free(x);
		x=cabezera;	
		//cout<<"x esta apuntando a: "<<x;	
	}
		cout<<"x esta apuntando a: "<<x;
	//cabezera=NULL;	

}
