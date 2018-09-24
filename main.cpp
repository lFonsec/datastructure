#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
    class no{

    public:
        no<T> *proximo;
        no<T> *anterior;
        int valor;

        no(T v): valor(v),proximo(NULL),anterior(NULL){};

    };

template <typename T>
    class DIA{

    public:

        no<T> *primeiro;
        no<T> *atual;

        DIA(): primeiro(NULL),atual(NULL){};



    bool inserir_dia(int valor){
            no<T> *novo = new no<T>(valor);
            no<T> *temp = new no<T>(0);
            temp = NULL;
            atual=primeiro;
            novo->proximo=atual;

            if(temp){
            temp->proximo=novo;
            }else{
            primeiro=novo;
           }
            if(atual){
            novo->anterior=atual->anterior;
            atual->anterior=novo;
                }

        return true;
        }

  bool remover_dia(T valor) {
    no<T> *anterior = NULL;
    no<T> *atual = primeiro;
    while (atual && atual->valor < valor) {
      anterior = atual;
      atual = atual->proximo;
    }

    if (atual == NULL || atual->valor != valor)
      return false;

    if (anterior)
      anterior->proximo = atual->proximo;
    else
      primeiro = atual->proximo;

    delete atual;

    return true;
  }



    void imprime_dia(){
        if(!primeiro){
            cout<<"Nao existe dias a ser impresso "<<endl;
            }else{
            atual = primeiro;
                cout<<"Imprimindo dias "<<endl;
                while(atual != NULL){
                cout<<atual->valor<<endl;
                atual=atual->proximo;

                }

            }

        }


    };
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
