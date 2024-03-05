#ifndef SDA1_LIST_H
#define SDA1_LIST_H

template <class T>
class List;

template <class T>
class Node
{
    T data{};
    Node<T>* next{};

  public:
    Node():next(nullptr) // numai daca este necesar
    {
        //. . . .
    }

    explicit Node(T _data):data(_data),next(nullptr)  // numai daca este necesar
    {
        //. . . .
    }

    ~Node() // numai daca este necesar
    {
        //. . . . .
    }

    Node<T>* Next() {
        return this->next;
    }

    bool isEnd()
    {
        return next==nullptr;
    }

    T Data()
    {
        return data;
    }

    friend class List<T>;
};

template <class T>
class List
{
    Node<T>* head{}; /// inc

  public:
    List() // numai daca este necesar
    {
        head=nullptr;
        //. . . . .
    }

    ~List() // numai daca este necesar
    {
        if(head)
        {
            Node<T> *tmp;
            while(head->next)
            {
                tmp=head;
                head=head->next;
                delete tmp;
            }
            delete head;
            head=nullptr;
        }
        //. . . . .
    }

    void push_front(T data) //adaugare nod la inceputul listei
    {
        Node<T> *tmp=new Node<T>(data);
        if(head==nullptr)
        {
            head=tmp;
            head->next=nullptr;
            return;
        }
        tmp->next=head;
        head=tmp;
        return;
       //. . . .
    }

    Node<T>* begin() // intoarce pointer la primul nod din lista
    {
        return head;
        //. . . . .
    }

    void Prelucrare(int P1, int P2) // functia ceruta in problema
    {

        if(head==nullptr)
            return;
        if(head->next==nullptr)
            return;
         /// daca lista nu avea elemente sau avea doar 1 element
        bool adv=true;
        while(adv) /// repeta prelucrarea pana nu se mai poate
        {
            bool st=false;

            Node<T> *s=head,*f=head;
            f=f->next;
            while(s->next != nullptr) /// s->next != nullptr
            {
                int dif=s->data-f->data;
                if(dif<0)
                    dif=(-1)*dif;

                if(dif>P1)
                {
                    st=true;

                    Node<T> *newNode=new Node<T>(((s->data+f->data)/2));
                    newNode->next=f;
                    s->next=newNode;

                    s=newNode; /// problema aici dupa adaugare ? f / s
                }
                else if(dif<P2) /// if sau if-else ?
                {
                    st=true;

                    if(f->next==nullptr) /// caz cand f este ultimul element ?
                    {
                        delete f;
                        s->next=nullptr;
                    }
                    else
                    {
                        Node<T> *t=f;
                        f=f->next;
                        s->next=f;
                        delete t;
                    }
                }
                else
                {
                    s=s->next;
                    if(f->next==nullptr)
                        break;
                    f=f->next;
                }

            }


            if(st==false)
                adv=false;
        }
        //. . . . . .
    }

};

#endif
