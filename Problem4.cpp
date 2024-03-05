#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

class Elev
{
    string nume;
    int notaMate;
    int notaRomana;
    int notaFizica;

public:

    Elev()=default;

    double medie()
    {
        double m=(double)notaRomana;
        m=m+(double)notaMate;
        m=m+(double)notaFizica;
        m=(double)(m/3);
        return (double )m;
    }

    int getMate()
    {
        return notaMate;
    }

    int getRomana()
    {
        return notaRomana;
    }

    bool operator<(Elev n) // a > b
    {
        if( medie() > n.medie() )
        {
            return true;
        }
        else if( medie() < n.medie() )
        {
            return false;
        }
        else
        {
            if(notaMate > n.notaMate)
            {
                return true;
            }
            else if(notaMate < n.notaMate)
            {
                return false;
            }
            else
            {
                if(notaRomana > n.notaRomana )
                {
                    return true;
                }
                else if(notaRomana < n.notaRomana )
                {
                    return false;
                }
                else
                {
                    if(nume<n.nume)
                    {
                        return true;
                    }
                    else if(nume>n.nume)
                    {
                        return false;
                    }

                }
            }
        }


    }

    void read()
    {
        cin>>nume;
        cin>>notaMate;
        cin>>notaRomana;
        cin>>notaFizica;
    }

    void printALL()
    {
        cout<<nume<<" "<<notaMate<<" "<<notaRomana<<" "<<notaFizica<<endl;
    }

    void print()
    {
        cout<<nume;
    }
};

template<typename T>
void quicksort(T *t,int n)
{
    if(n==1)
        return;
    int i=0,j=n-1;
    T pivot=t[n/2];

    while(i < j)
    {
        while(t[i]<pivot)
        {
            i++;
        }
        while(t[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            T aux=t[i];
            t[i]=t[j];
            t[j]=aux;
        }
    }
    if(i>j)
        i=j;
    if(i>0)
        quicksort(t,i);
    if(n-i>0)
        quicksort(&t[i],n-i);
}

template<typename T>
void srt(T *v, int n)
{
    int ord;
    do
    {
        ord=1;
        for(int i=0;i<n-1;++i)
        {
            if(v[i]>v[i+1])
            {
                T aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                ord=0;
            }}}while(ord==0);
}

template <typename T>
void bubleSort(T *v,int n)
{
    bool flag=false;
    while(!flag)
    {
        flag=true;
        for(int i=1;i<n;++i)
        {
            if( v[i]<v[i-1])
            {
                T aux=v[i-1];
                v[i-1]=v[i];
                v[i]=aux;
                flag=false;
            }
        }
        n--;
    }
}

int main()
{
    int n;
    Elev students[1000];
    cin>>n;
    for(int i=0;i<n;++i)
    {
        students[i].read();
    }

    bubleSort(students,n);

    if(n%2==1)
        students[n/2].print();
    else if(n%2==0)
        students[n/2-1].print();


    return 0;
}
