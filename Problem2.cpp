#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

/*
 * do
{
ord=1;
for(int i=0;i<n-1;++i)
{
if(v[i]>v[i+1)
{
//interschimbare
}}}while(ord==0);
sort(v.begin(),v.end());
 */

#include <vector>

class Student
{
    char nume[30];
    double nota;

public:

    Student()=default;

    ~Student()=default;

    friend istream&operator>>(istream&,Student&);
/*
    Student operator=(Student s)
    {
       for(int i=0;)
        nota = s.nota;
        return  *this;

    }
*/
    bool operator>(Student s) // a > b
    {
        int clas,ex;
        clas= strlen(nume);
        ex= strlen(s.nume);
        if(clas<ex)
        {
            for(int i=0;i<clas;++i)
            {
                if(nume[i]<s.nume[i])
                {
                    return true;
                }
                if(nume[i]>s.nume[i])
                {
                    return false;
                }
                if(nume[i]==s.nume[i])
                {

                }
            }
            if(nota>s.nota)
                return true;
            else return false;
        }
        else if(clas>ex)
        {
            for(int i=0;i<ex;++i)
            {
                if(nume[i]<s.nume[i])
                {
                    return true;
                }
                if(nume[i]>s.nume[i])
                {
                    return false;
                }
                if(nume[i]==s.nume[i])
                {

                }
            }
            if(nota>s.nota)
                return true;
            else return false;
        }
        else if(clas==ex)
        {
            for(int i=0;i<clas;++i)
            {
                if(nume[i]<s.nume[i])
                {
                    return true;
                }
                if(nume[i]>s.nume[i])
                {
                    return false;
                }
                if(nume[i]==s.nume[i])
                {

                }
            }
            if(nota>s.nota)
                return true;
            else return false;
        }

    /*
        if(s.nume[0]>nume[0])
        {
            return false;
        }
        else if(s.nume[0]<nume[0])
        {
            return true;
        }
        else if(s.nume[0]==nume[0])
        {
            if(s.nota>=nota)
            {
                return true;
            }
            else return false;
        }
        */
    }

    void print()
    {
        for(int i=0;i<strlen(nume);i++)
        {
            cout<<nume[i];
        }
        cout<<" "<<nota;
    }
};

istream &operator>>(istream &is,Student &s)
{
    is>>s.nume;
    is>>s.nota;

    return is;
}




int main()
{
    int n;
    cin>>n;
    Student listaStudenti[1000];
    /*
    vector<Student> vecStudent;
    for(int i=0;i<n;++i)
    {
        Student tmp;
        cin>>tmp;
        vecStudent.push_back(tmp);
    }
    sort(vecStudent.begin(),vecStudent.end());
    cout<<vecStudent[0].print();
     */



    for(int i=0;i<n;++i)
    {
        cin>>listaStudenti[i];
    }
    Student aux=listaStudenti[0];
    for(int i=1;i<n;++i)
    {
        if( !(aux > listaStudenti[i]) )
        {
            aux=listaStudenti[i];
        }
    }
    aux.print();




    return 0;
}