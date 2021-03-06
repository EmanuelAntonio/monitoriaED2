#include "Trie_MultiWay.h"

Trie_MultiWay::Trie_MultiWay(int tamAlfabeto)
{
    raiz = new No_MW(tamAlfabeto);
    alfabeto = tamAlfabeto;
}
void Trie_MultiWay::insere(char* c, int tam){

    No_MW *aux;
    aux = raiz;
    if(verificaString(c,tam)){

        for(int i = 0; i < tam; i++){

            aux = aux->setChar(c[i]);

        }
        aux->setChave(true);

    }else{

        cout << "Essa String nao esta dentro do alfabeto de tamanho " << alfabeto << endl;

    }

}
void Trie_MultiWay::imprime(){

    string s;
    imprimeMW(s,raiz);

}
void Trie_MultiWay::imprimeMW(string s, No_MW* n){

    for(char i = 97; i < (alfabeto + 97); i++){

        if(n->getChar(i) != NULL){

            s.push_back(i);
            if(n->getChar(i)->getChave()) {

                cout << s <<endl;

            }
            imprimeMW(s,n->getChar(i));
            s.erase(s.end()-1);

        }

    }

}
void Trie_MultiWay::remove(char* c, int tam){

    removeMW(raiz,c,0,tam);

}
bool Trie_MultiWay::removeMW(No_MW *n, char* c, int idI, int idF){

    bool r;
    if(idI != idF){

        r = removeMW(n->getChar(c[idI]),c,idI+1,idF);
        if(r == true){

            n->setChar(c[idI],NULL);

        }

    }else{

        n->setChave(false);

    }
    if(n->ehNULL()){

        delete n;
        return true;

    }
    return false;


}
bool Trie_MultiWay::busca(char* c, int tam){

    No_MW *aux;
    aux = raiz;
    for(int i = 0; i < tam; i++){

        aux = aux->getChar(c[i]);
        if(aux == NULL){

            return false;

        }

    }
    if(aux->getChave()){

        return true;

    }else{

        return false;

    }

}
No_MW** Trie_MultiWay::getRaiz(){

    return &raiz;

}
bool Trie_MultiWay::verificaString(char *c, int tam){

    for(int i = 0; i < tam; i++){

        if(c[i] >= alfabeto + 97) return false;

    }
    return true;
}
void Trie_MultiWay::deleteH(No_MW *n){

    for(int i = 0; i < n->getTamAlfa(); i++){

        if(n->getChar(97 + i) != NULL){

            deleteH(n->getChar(97 + i));

        }

    }
    delete n;
}
int Trie_MultiWay::alturaMW(No_MW* n){

    int alt = 0, aux;
    for(int i = 0; i < n->getTamAlfa(); i++){

        if(n->getChar(97 + i) != NULL){

            aux = alturaMW(n->getChar(97 + i));
            if(aux > alt){

                alt = aux;

            }

        }

    }
    return (alt + 1);

}
int Trie_MultiWay::alturaMW(){

    return alturaMW(raiz);

}
Trie_MultiWay::~Trie_MultiWay()
{
    delete raiz;

}
