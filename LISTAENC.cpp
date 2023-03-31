#include <iostream>
using namespace std;

struct no{
public:
int info; no *next;
};

struct no *head = NULL;

void inserir(int conteudo){
  no *novo = new no;
  novo->info = conteudo;
  *novo->next = *head;
  *head = *novo;
  cout << "Inserido no começo!"<<endl;
  cout << conteudo << endl;
}
