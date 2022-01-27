// 3 sem lab 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Stack
{
public:
    Stack* l;
    double a[5];
    Stack operator=(Stack);
    Stack operator++();
    Stack operator++(int);

};
class MyException 
{
public:
    char massage[50];
    MyException( const char* h) 
    {
        strcpy(massage, h);
    };
    void display()
    {
        cout << massage;
    }
};
Stack* new1(Stack* s)
{
    if (!(s = new Stack)) throw MyException("\n\nERROR:Memory nit allocated!!!");
    return s;
}
void  my_term()
{
    cout << "\nMy function-handler";
    exit(1);
}
void my_unexpected()

{
    cout << "my_unexpected handler" << endl;

    throw Stack();                    //  возбуждение исключения типа объект

}
Stack Stack::operator=(Stack m)

{
    for (int i = 0; i < 5; i++)
        a[i] = m.a[i];
   
    return *this;
}
Stack Stack::operator++()      // перегрузка операции ++A

{
    for (int i = 0; i < 5; i++)
    {
        a[i] += 3;
    }
    return *this;

}
Stack Stack::operator++(int)  // перегрузка операции A++
{
    for (int i = 0; i < 5; i++)
    {
        a[i] += 3;
    }
    return *this;
}
Stack* push(Stack* s)
{
    Stack* s1 = s;
    int j=1 ;
    do
    {
        try
        {
            s = new1(s);
        }
        catch(MyException e)
        {
            e.display();
        }
        //s = new Stack;
        (s)->l = s1;
        s1 = s;
        cin.exceptions(cin.failbit);
        for (int i = 0; i < 5; i++)
        {
            set_terminate(my_term);
            try {
                cout << "\n\nENTER a[" << i << "] = ";
                cin >> s->a[i];
            }
            catch (const exception& ex)
            {
                cout << "ERROR:Uncorrect enter!" << endl;
                cout << ex.what() << endl;
                cin.clear();
                cin.ignore(10, '\n');
                i--;
            }
        }
        cout << "Do you want to continue typing(1/0)?";
        for (int i = 0; i < 1; i++)
        {
            try
            {
                cin >> j;
                if (!(j > -1 && j < 2)) throw 1;
            }
            catch (const exception& ex)
            {
                cout << "ERROR:Uncorrect enter!" << endl;
                cout << ex.what() << endl;
                cin.clear();
                cin.ignore(10, '\n');
                i--;
            }
            catch (int)
            {
                cout << "ERROR:Uncorrect enter,enter 1 or 0!" << endl;
                cin.clear();
                cin.ignore(10, '\n');
                i--;
            }
        }
        if (j == 0) break;
    } while (1);
    return s;
}

void show(Stack* s)
{
    int k = 0;
    if (!s)
    {
        cout<<"Error!";
        return;
    }
    do
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "\n\nOBJ("<<k <<") a[" << i << "] = "<< s->a[i];
        }
        cout << "\n\n----------------";
        (s) = (s)->l;
        k++;
    } while (s);
}
void search(struct Stack* s)
{
  double g;
  int k = 0;
  int flag = 0;
  if (!s)
    {
        cout<<"Error!";
        return;
    }
    cout << "\n\nEnter the number for searching: ";
    cin.exceptions(cin.failbit);
    for (int i = 0; i < 1; i++)
    {
        set_unexpected(my_unexpected);
        try {
            cin >> g;
        }
        catch (const exception& ex)
        {
            cout << "ERROR:Uncorrect enter!" << endl;
            cout << ex.what() << endl;
            cin.clear();
            cin.ignore(10, '\n');
            i--;
        }
    }
  
    while (s)
    {
        for (int i = 0; i < 5; i++)
        {
            if (s->a[i] == g)
            {
                flag = 1;
                for (int j = 0; j < 5; j++)
                {
                    cout << "\n\nOBJ(" << k << ") a[" << j << "] = " << s->a[j];
                }
                break;
            }
        }
        k++;
        s = s->l;
        
    }
    if (flag == 0) cout << "\nNOT FOUND!!!";
    
}

Stack* deleteALL(Stack* h)
{
    int j = 0;
    int i = 2;
    int r=0;
    Stack* x = h;
    if (!h)
    {
        cout << "ERROR!";
        return h;
    }
    do
    {
        r++;
        (x) = (x)->l;
    }
    while (x) ;
    cout<<"\nEnter the numbr of obj to delete: ";
    for (int i = 0; i < 1; i++)
    {
        try {
            cin >> j;
            if (!(j > -1 && j < r)) throw 1;
        }
        catch (const exception& ex)
        {
            cout << "ERROR:Uncorrect enter!" << endl;
            cout << ex.what() << endl;
            cin.clear();
            cin.ignore(10, '\n');
            i--;
        }
        catch (int)
        {
            cout << "ERROR:Uncorrect enter!" << endl;
            cin.clear();
            cin.ignore(10, '\n');
            i--;
        }
    }
    j++;
    Stack* curr = h->l;
    Stack* prev = h;
    if (j == 1)
    {
        delete h;
        return curr;
    }
    while (i != j && curr && j > 1)
    {
        prev = curr;
        curr = curr->l;
        i++;
    }

    if (!curr)
    {
        cout<<"ERROR!";
        return h;
    }

    if (j > 1) prev->l = curr->l;
    return h;
}
int main()
{
    Stack* s = nullptr;
    Stack* g = nullptr;
   int j = 1;
   while (j != 0)
   {
       printf("\n\nSelect an action:\n0--EXIT\n1--ADD A STACK\n2--SHOW STACK\n3--DELETE AN ELEMENT FROM THE STACK\n4--STACK SEARCH\n5--S[0]=S[1]\n6--(++S[0])\n7--(S[0]++)\n\nCHOOSE(0-7): ");

       for (int i = 0; i < 1; i++)
       {
           try
           {
               cin >> j;
               if (!(j > -1 && j < 8)) throw 1;
           }
           catch (const exception& ex)
           {
               cout << "ERROR:Uncorrect enter!" << endl;
               cout << ex.what() << endl;
               cin.clear();
               cin.ignore(10, '\n');
               i--;
           }
           catch (int)
           {
               cout << "ERROR:Uncorrect enter!" << endl;
               cin.clear();
               cin.ignore(10, '\n');
               i--;
           }
       }
       switch (j)
       {
       case 0:
           break;
           break;
       case 1:
           s = push(s);
           break;
       case 2:
           show(s);
           break;
       case 3:
           s = deleteALL(s);
           break;
       case 4:
           search(s);
           break;
       case 5:
           try { if (!s) throw 1; }
           catch (int)
           {
               cout << "ERROR!";
               break;
           }
           try
           {
               if (!(s->l)) throw 1;
           }
           catch (int)
           {
               cout << "ERROR!";
               break;
           }
           g = s->l;
           s[0] = g[0];
           break;
       case 6:
           try
           {
               if (!s) throw 1;
           }
           catch (int)
           {
               cout << "ERROR!";
               break;
           }
           ++s[0];
           break;
       case 7:
           try
           {
               if (!s) throw 1;
           }
           catch (int)
           {
               cout << "ERROR!";
               break;
           }
           s[0]++;
           break;
       }
   }
    return 0;
}
