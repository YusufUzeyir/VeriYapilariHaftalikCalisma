
/* 211307012 Yusuf Üzeyir Kaya */

// 1.Sorunun Cevabı

#include <iostream>
using namespace std;

struct Dugum
{
    int veri;
    struct Dugum* sol, * sag;

    Dugum(int data)
    {
        this->veri = data;
        sol = sag = NULL;
    }
};

// Preorder (kök-sol-sağ) dolaşma
void preOrder(Dugum* dugum)
{
    if (dugum == NULL)
        return;

    cout << dugum->veri << " ";
    preOrder(dugum->sol);
    preOrder(dugum->sag);
}

// Inorder (sol-kök-sağ) dolaşma
void inOrder(Dugum* dugum)
{
    if (dugum == NULL)
        return;

    inOrder(dugum->sol);
    cout << dugum->veri << " ";
    inOrder(dugum->sag);
}

// Postorder (sol-sağ-kök) dolaşma
void postOrder(Dugum* dugum)
{
    if (dugum == NULL)
        return;

    postOrder(dugum->sol);
    postOrder(dugum->sag);
    cout << dugum->veri << " ";
}

// Ağacın düğüm sayısını hesaplama
int dugumSayisi(Dugum* dugum)
{
    if (dugum == NULL)
        return 0;
    else
        return 1 + dugumSayisi(dugum->sol) + dugumSayisi(dugum->sag);
}

// Ağacın yüksekliğini hesaplama
int yukseklik(Dugum* dugum)
{
    if (dugum == NULL)
        return 0;
    else {
        int solYukseklik = yukseklik(dugum->sol);
        int sagYukseklik = yukseklik(dugum->sag);

        if (solYukseklik > sagYukseklik)
            return solYukseklik + 1;
        else
            return sagYukseklik + 1;
    }
}

int main()
{
    Dugum* agac = new Dugum(27);
    agac->sol = new Dugum(18);
    agac->sag = new Dugum(39);
    agac->sol->sol = new Dugum(14);
    agac->sol->sol->sol = new Dugum(2);
    agac->sol->sag = new Dugum(22);
    agac->sol->sag->sol = new Dugum(17);
    agac->sag->sol = new Dugum(29);
    agac->sag->sag = new Dugum(42);
    agac->sag->sag->sol = new Dugum(24);
    agac->sag->sag->sol->sol = new Dugum(15);

    cout << "Dugum Sayisi: " << dugumSayisi(agac) << endl;
    cout << "Agacin Yuksekligi: " << yukseklik(agac) << endl;

    cout << "Preorder Dolasma: ";
    preOrder(agac);
    cout << endl;

    cout << "Inorder Dolasma: ";
    inOrder(agac);
    cout << endl;

    cout << "Postorder Dolasma: ";
    postOrder(agac);
    cout << endl;

    return 0;
}
