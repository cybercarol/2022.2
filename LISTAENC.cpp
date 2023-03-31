#include <iostream>
using namespace std;


struct no{
public:
int conteudo; no *next;
};

struct no *head = NULL;

// 1. Criação da lista vazia;
no* lista_inicializa(void){
  return NULL;
}

//2. Verificar se a lista está vazia;
int verifica(no* n){
  if(n == NULL){
    cout << "Lista vazia "<<endl;
    return 1;}
  else{
    cout << "Lista não vazia"<<endl;
    return 0;
    }
}

//3. Obter o tamanho da lista;
int tamanho(no* n){
  no* c;
  int tam = 0;
  if(n == NULL){
    cout << "Lista vazia, tamanho 0 "<<endl;
    return 0;}
  else{
  for (c = head; c!=NULL; c = c->next){
    tam = tam+1;
  }
    cout << "\nTamanho: " << tam;
    return tam;
  }
}

//4. Obter/modificar o valor do elemento de uma determinada posição na lista;
no* achar_alterar(no* n, int a, int b){
  no* c;
  for (c = n; c!=NULL; c = c->next){
    if (c->conteudo == a)
      cout << "Valor " << a << " encontrado" << endl;
      c->conteudo = b;
      cout << "Valor " << a << " alterado por " << b << endl;
      return c;
  cout << "Valor não encontrado" << endl;
  return NULL;
  }
}


// 5. Inserir um elemento em uma determinada posição;
no* inserirInicio(no* n, int c){
  no* novo = (no*)malloc(sizeof(no));
  novo->conteudo = c;
  novo->next = head;
  head = novo;
  cout << "Inserido " << c << " no começo."<<endl;
  return novo;
}

no* inserirFinal(no* n, int c){
  no *novo = new no();
  novo->conteudo = c;
  novo->next = NULL;
  if (head == NULL){head = novo;}
  else { 
      no *aux = head; 
      while (aux->next != NULL)
        {aux = aux->next;}
      aux->next = novo;
       }
  
  cout << "Inserido "<< c <<" no final!"<<endl;
  return novo;
}

// 6. Retirar um elemento de uma determinada posição.

no* apagarFinal(no* n){
  no *aux = n; no *antes = NULL;
  if (head == NULL){cout << "A lista está vazia!"<<endl;}
  else{
    if (head->next == NULL){
      aux = head; head = NULL;           free(aux);
    }
    else{
    while(aux->next!=NULL){
      antes = aux;
      aux = aux->next;
    }
    antes->next = NULL;
    free(aux);
    }
    cout << "\nApagado elemento do final"<<endl;
  }
  return NULL;
}

//7. Imprimir os elementos de toda a lista.
void prints(no* n){
  no* aux;
  for (aux = n; aux!=NULL; aux = aux->next){
    printf("i = %d ", aux->conteudo);}
  
}

void liberamem(no* n){
  no* m = n;
  while (m != NULL){
    no* ref = m->next;
    free(m);
    m = ref;
  }
  cout << "\n~~Memória liberada~~"<<endl;
}

int main(void) {
  no *head;
  no* Lista;
  
  cout << "\n     Iniciado\n"<<endl;
  
  Lista = lista_inicializa();
  verifica(Lista);
  apagarFinal(Lista);
  Lista = inserirInicio(Lista, 0);
  Lista = inserirFinal(Lista, 1);
  Lista = inserirFinal(Lista, 3);
  achar_alterar(Lista, 3, 2);
  Lista = inserirInicio(Lista, -1);
  prints(Lista);
  tamanho(Lista);
  apagarFinal(Lista);
  prints(Lista);
  tamanho(Lista);
  liberamem(Lista);
  
  cout << "\n    Programa encerrado\n"<<endl;
  
  //cout << dois->conteudo << endl;
  return 1;
}
