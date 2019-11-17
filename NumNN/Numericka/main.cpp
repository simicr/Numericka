#include <iostream>
#define brojcvorova 5
using namespace std;
float podeljena_razlika(float x[], float y[], int pocetni, int krajni)
{
    if (pocetni== krajni) return y[pocetni];
    else return(podeljena_razlika(x,y,pocetni+1,krajni)-podeljena_razlika(x,y,pocetni,krajni-1))/(x[krajni]-x[pocetni]);
}
void generacija_podeljene_razlike(float x[], float y[], float yx[])
{
    for(int i=0;i<brojcvorova;i++)
        yx[i]=podeljena_razlika(x,y,0,i);
}
void inicijalizacija_polinoma(float polinom[])
{
    for(int i=0;i<brojcvorova;i++)
        polinom[i]=(float)0;
}
void mnozenje_polinoma(float proizvod[], float polinom_a[], float polinom_b[])
{
    int i,j;
    inicijalizacija_polinoma(proizvod);
    for(i=0;i<brojcvorova;i++)
        for(j=0;j<brojcvorova;j++)
        {
            proizvod[i+j] += polinom_a[i]*polinom_b[j];
        }
}
void izjednaci_polinomba(float polinom_a[], float polinom_b[])
{
    for(int i=0;i<brojcvorova;i++)
        polinom_a[i]=polinom_b[i];
}
void generacija_tabele_polinoma(float tabela_polinoma[][brojcvorova], float x[])
{
    int i,j;
    float trenutni_polinom[2];
    float pomocni_polinom[brojcvorova];
    float pomocni_polinom2[brojcvorova];
    trenutni_polinom[0]=-x[0];
    trenutni_polinom[1]=1;
    inicijalizacija_polinoma(pomocni_polinom);
    pomocni_polinom[0]=1;
    tabela_polinoma[0][0] = 1;
    for(i=1;i<brojcvorova;i++)
    {
        mnozenje_polinoma(pomocni_polinom2,pomocni_polinom,trenutni_polinom);
        for(j=0;j<brojcvorova;j++)
        {
            tabela_polinoma[i][j]=pomocni_polinom2[j];
        }
        izjednaci_polinomba(pomocni_polinom,pomocni_polinom2);
        trenutni_polinom[0]=-x[i];
    }
}
void generacija_njutnovog_polinoma(float tabela_polinoma[][brojcvorova], float podeljene_razlike[], float polinom[])
{
    int i,j;
    for (i=0;i<brojcvorova;i++)
        for(j=i;j<brojcvorova;j++)
        {
            polinom[i] += podeljene_razlike[j]*tabela_polinoma[j][i];
        }
}
void ispis_polinoma(float polinom[])
{
    for(int i=0;i<brojcvorova;i++)
    {
        cout<<polinom[i]<<"*X^"<<i;
        if(i != brojcvorova-1)
        {
            cout<<" + ";
        }
    }
}
void inicijalizacija_tabele_polinoma(float tabela_polinoma[][brojcvorova])
{
    int i,j;
    for(i=0;i<brojcvorova;i++)
        for(j=0;j<brojcvorova;j++)
            tabela_polinoma[i][j]=(float)0;
}
void ispis(float p[][brojcvorova])
{
    int i,j;
    for(i=0;i<brojcvorova;i++)
    {
        for(j=0;j<brojcvorova;j++)
            cout<<p[i][j]<<"     ";
        cout<<endl;
    }
}
int main()
{
    float Nn[brojcvorova];
    float x[brojcvorova]={0,1,4,3,5};
    float y[brojcvorova]={0,1,8,27,64};
    float podeljene_razlike[brojcvorova];
    float tabela_polinoma[brojcvorova][brojcvorova];
    generacija_podeljene_razlike(x,y,podeljene_razlike);
    inicijalizacija_tabele_polinoma(tabela_polinoma);
    generacija_tabele_polinoma(tabela_polinoma,x);
    inicijalizacija_polinoma(Nn);
    generacija_njutnovog_polinoma(tabela_polinoma,podeljene_razlike,Nn);
    ispis_polinoma(Nn);
    //ispis(tabela_polinoma);
    return 0;
}
