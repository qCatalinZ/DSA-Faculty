#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using  namespace std;

struct coords
{
    double x;
    double y;

    coords()=default;
    coords(double a,double b):x(a),y(b){}

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    void read()
    {
        cin>>x;
        cin>>y;
    }

};

template <class T>
class List;

template <class T>
class Node
{
    T data;
    Node<T>*next;

public:

    Node():next(nullptr){}
    Node(const T&x):data(x),next(nullptr){}
    ~Node()
    {
        if(next)
            delete next;
    }

    friend class List<T>;
};

template<class T>
class List
{
    Node<T>*head; //inc
    Node<T>*tail; // sf

public:

    List():head(nullptr),tail(nullptr){}
    ~List()
    {
        if(head)
            delete head;
    }

    void push_back(const T&x)
    {
        if(head== nullptr) {
            head = new Node<T>(x);
            tail = head;
            return;
        }

        Node<T>*tmp=new Node<T>(x);
        tmp->next= nullptr;
        tail->next=tmp;
        tail=tail->next;
        tail->next= nullptr;
    }

    void print()
    {
        if(head)
        {
            auto crt=head;
            while(crt)
            {
                cout<<crt->data<<" ";
                if(crt->next)
                {
                    crt=crt->next;
                } else break;
                cout<<endl;
            }
        }
    }


    void makeCiruar()
    {
        tail->next=head;
    }

    void makeLiniar()
    {
        tail->next= nullptr;
    }



    double calcPeri()
    {
        double peri=0;

        auto slow=head; // a
        auto fast=slow->next;     // b


        while(fast)
        {
            double dist=0;
            double x,y;

            x= slow->data.getX() - fast->data.getX();
            x=x*x;
            y=slow->data.getY() - fast->data.getY();
            y=y*y;

            dist=x+y;
            dist=sqrt(dist);
            peri=peri+dist;
            if(fast->next)
            {
                fast=fast->next;
                slow=slow->next;
            }
            else break;
        }
        double dist=0;
        double x,y;

        x=head->data.getX() - tail->data.getX();
        x=x*x;
        y=head->data.getY() - tail->data.getY();
        y=y*y;

        dist=x+y;
        dist=sqrt(dist);
        peri=peri+dist;


        return peri;
    }

};


int main()
{

    int n;
    cin>>n;
    List<coords> l;
    double perimeru=0;
    for(int i=0;i<n;++i)
    {
        coords aux;
        aux.read();
        l.push_back(aux);
    }
    perimeru= l.calcPeri() ;
    cout<<setprecision(2)<<fixed<<perimeru;
    
    return 0;
}
