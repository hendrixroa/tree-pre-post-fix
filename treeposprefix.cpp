#include <iostream> 
#include <fstream>
#include <string>
#include <stack>
#include <math.h>
#include <cstdlib>
#include <sstream>

using namespace std;

class Arbol{
	public:
	string valor;
	Arbol *HijoIzq;
	Arbol *HijoDer;
	
	Arbol(string val){//CONSTRUCTOR
	valor = val;
	HijoIzq = NULL;
	HijoDer	= NULL;
	}
	
	void PreOrden(Arbol *myTree, string &in){
		if(myTree != NULL){
			 in += myTree->valor;
		     PreOrden(myTree->HijoIzq,in);
		     PreOrden(myTree->HijoDer,in);
		}
	}
	
	void PosOrden(Arbol *myTree, string &in){
		if(myTree != NULL){
		     PosOrden(myTree->HijoIzq,in);
		     PosOrden(myTree->HijoDer,in);
		     in += myTree->valor;
		}
	}
			
	void Evaluar(Arbol *&myTree){
			  int x,y,res;
			  string aux1,aux2,buf;
				stringstream flujo;
			  
				  if(myTree != NULL && myTree->HijoIzq != NULL && (myTree->HijoIzq->valor == "+" 
				  || myTree->HijoIzq->valor == "*" || myTree->HijoIzq->valor == "-" || myTree->HijoIzq->valor == "/"
				  || myTree->HijoIzq->valor == "^" )){	  
		 			   Evaluar(myTree->HijoIzq);  
				  }
				  
				   if(myTree != NULL && myTree->HijoDer != NULL && (myTree->HijoDer->valor == "+" 
				  || myTree->HijoDer->valor == "*" || myTree->HijoDer->valor == "-" || myTree->HijoDer->valor == "/"
				  || myTree->HijoDer->valor == "^" )){	  
		 			   Evaluar(myTree->HijoDer); 
				  }
				
					  if(myTree != NULL && myTree->HijoIzq != NULL && myTree->HijoDer != NULL &&  
					  ((myTree->HijoIzq->valor >= "0" && myTree->HijoIzq->valor <= "9") || (myTree->HijoDer->valor >= "0" && 
					  myTree->HijoDer->valor <= "9")) && myTree->valor =="*"){
						  aux1 = myTree->HijoIzq->valor;
						  aux2 = myTree->HijoDer->valor;
						  x = atoi(aux1.c_str());
						  y = atoi(aux2.c_str()); 
						  res = x*y;
						  flujo << res; 
						  buf = flujo.str();
						  myTree->valor = buf;
						  flujo << "";
						  aux1 = aux2 = buf = "";
					  }
					
					   if(myTree != NULL && myTree->HijoIzq != NULL && myTree->HijoDer != NULL &&  
					   ((myTree->HijoIzq->valor >= "0" && myTree->HijoIzq->valor <= "9") || (myTree->HijoDer->valor >= "0" && 
					   myTree->HijoDer->valor <= "9")) && myTree->valor =="+"){
						  aux1 = myTree->HijoIzq->valor;
						  aux2 = myTree->HijoDer->valor;
						  x = atoi(aux1.c_str());
						  y = atoi(aux2.c_str()); 
						  res = x+y;
						  flujo << res; 
						  buf = flujo.str();
						  myTree->valor = buf;
						  flujo << "";
						  aux1 = aux2 = buf = "";
					  } 
					  
					  if(myTree != NULL && myTree->HijoIzq != NULL && myTree->HijoDer != NULL &&  
					  ((myTree->HijoIzq->valor >= "0" && myTree->HijoIzq->valor <= "9") || (myTree->HijoDer->valor >= "0" && 
					  myTree->HijoDer->valor <= "9")) && myTree->valor =="-"){
						  aux1 = myTree->HijoIzq->valor;
						  aux2 = myTree->HijoDer->valor;
						  x = atoi(aux1.c_str());
						  y = atoi(aux2.c_str()); 
						  res = x-y;
						  flujo << res; 
						  buf = flujo.str();
						  myTree->valor = buf;
						  flujo << "";
						  aux1 = aux2 = buf = "";   
					  }
					
					  if(myTree != NULL && myTree->HijoIzq != NULL && myTree->HijoDer != NULL &&  
					  ((myTree->HijoIzq->valor >= "0" && myTree->HijoIzq->valor <= "9") || (myTree->HijoDer->valor >= "0" && 
					  myTree->HijoDer->valor <= "9")) && myTree->valor =="/"){
						  aux1 = myTree->HijoIzq->valor;
						  aux2 = myTree->HijoDer->valor;
						  x = atoi(aux1.c_str());
						  y = atoi(aux2.c_str()); 
						  res = x/y;
						  flujo << res; 
						  buf = flujo.str();
						  myTree->valor = buf;
						  flujo << "";
						  aux1 = aux2 = buf = ""; 
					  } 
					  
					  if(myTree != NULL && myTree->HijoIzq != NULL && myTree->HijoDer != NULL &&  
					  ((myTree->HijoIzq->valor >= "0" && myTree->HijoIzq->valor <= "9") || (myTree->HijoDer->valor >= "0" && 
					  myTree->HijoDer->valor <= "9")) && myTree->valor =="^"){
						  aux1 = myTree->HijoIzq->valor;
						  aux2 = myTree->HijoDer->valor;
						  x = atoi(aux1.c_str());
						  y = atoi(aux2.c_str()); 
						  res = pow(x,y);
						  flujo << res; 
						  buf = flujo.str();
						  myTree->valor = buf;
						  flujo << "";
						  aux1 = aux2 = buf = "";	
					  }
		  }       
};

class nodo{ //Clase Nodo
	public:
		Arbol *valor;
		nodo *prox;
		nodo(Arbol  *a,nodo *b){ //Constructor de la clase nodo
			valor=a;
			prox=b;
		}	
};

class pila{
	public:
		nodo *primero;
		pila(){ //Constructor de la clase pila (inicializada en vacio)
			primero=NULL;
		}
		bool Vacia(){return !primero;} // Funcion que retorna si la lista es vacia o no dada la existencia del primer elemento
		void Apilar(Arbol *a){ //Apila, es decir, el primer elemento en la pila será el nuevo elemento.
			nodo *aux=primero;
			primero=new nodo(a,aux);
		}
		void Desapilar(){ //Desapilar, es decir, eliminará el primer elemento de la pila.
			nodo *aux=primero;
			primero=aux->prox;
			delete aux;
		}
		Arbol *Tope(){ //Función que devuelve el valor del que esta de primero en la lista
			return primero->valor;
		}
};

        void ArmarArbol_SiEsPrefija(pila &myStack, string exp){
		 int i,tam;
		 tam = exp.length();
		 string buf;
		 for(i=tam-1;i>=0;i--){
			 buf = exp[i];
          if(buf >= "0" && buf <= "9"){//si es operando
			  Arbol *t;
			  t = new Arbol(buf);
			  myStack.Apilar(t); 
		  }else{//si es operador
			  Arbol *p1,*p2;
			  p1 = myStack.Tope();
			   myStack.Desapilar();
			  p2 =  myStack.Tope();
			   myStack.Desapilar();
			  Arbol *t;
			  t = new Arbol(buf);
              t->HijoIzq = p1;
              t->HijoDer = p2;
              myStack.Apilar(t);
		  }			 
		 }
	 }  
	 
	     void ArmarArbol_SiEsPosfija(pila &myStack, string exp){
		 int i,tam;
		 string buf;
		 tam = exp.length();
		 for(i=0;i<tam;i++){
			 buf = exp[i];
          if(buf >= "0" && buf <= "9"){//si es operando
			  Arbol *t;
			  t = new Arbol(buf);
			  myStack.Apilar(t); 
		  }else{//si es operador
			  Arbol *p1,*p2;
			  p1 = myStack.Tope();
			   myStack.Desapilar();
			  p2 =  myStack.Tope();
			   myStack.Desapilar();
			  Arbol *t;
			  t = new Arbol(buf);
              t->HijoIzq = p2;
              t->HijoDer = p1;
              myStack.Apilar(t);
		  }			 
		 }
	 }

int main(){
	
	int N;
	Arbol *myTree;
	pila myStack;
	string in="",buffer;
	fstream file,fileout1;
	file.open("tarea2.in",ios::in);
	 fileout1.open("Hendrix_Roa.out",ios::out | ios::app );
	if(!file.is_open()){
		cout<<"Erro, no se pudo abrir el archivo!"<<endl;
	}else{
		while(!file.eof()){
	file >> N;
	string Expresiones[N];
	int i;
	for(i=0;i<N;i++){
		file >> Expresiones[i];
	}
	 if(file.eof()){
		break;
	}
	for(int j=0;j<N;j++){	
	   buffer = Expresiones[j];
	   if(buffer[0] >= '0' && buffer[0] <= '9'){//si es posfija
	           ArmarArbol_SiEsPosfija(myStack,buffer);
	           fileout1<<"Expresion "<<j+1<<endl;
	           myTree = myStack.Tope();
	           myTree->PreOrden(myTree,in);
	           myTree->Evaluar(myTree);
	           fileout1 <<"Evaluacion:"<<myTree->valor<<endl;
	           fileout1<<"Notacion Prefija:"<<in<<endl;  
	           in ="";
		   }else{//si es prefija
			  
		    ArmarArbol_SiEsPrefija(myStack,buffer);
		    fileout1<<"Expresion "<<j+1<<endl;
	           myTree = myStack.Tope();
	           myTree->PosOrden(myTree,in);
	           myTree->Evaluar(myTree);
	           fileout1 <<"Evaluacion:"<<myTree->valor<<endl;
	           fileout1 <<"Notacion Postfija:"<<in<<endl;   
	           in="";
		   }
		   buffer = "";
	}
  }
 }
	file.close();
	fileout1.close();
	return 0;
	}
