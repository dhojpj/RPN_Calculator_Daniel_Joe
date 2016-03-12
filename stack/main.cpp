//#include "Queue.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Parser.h"
using namespace std;

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int main()
{




    int (*i)(int,int) = NULL;
//    int (*j)(int,int) = &sub;
//    int ans = i(5,6);

//    void (*ans)(int,int) = *i;

    i = &add;

    cout << "i = &add" << endl;
    cout << "&i = " << &i << endl
         << "i = " << i << endl
            << "*(*i) = " << *(*i) << endl;


//    cout << "(int*)ans(5,6) = i == " << (int*)ans(5,6) << endl;
//    << (*i)(5,56) << endl << endl;


//    cout << "j = &sub" << endl;
//    cout << "&j = " << &j << endl
//         << "j = " << j << endl
//            << "*j = " << *j << endl << endl;

//    ans = j;

//    cout << "(int*)ans(5,6) = j == " << (int*)ans(5,6) << endl;

//    << (*j)(5,56) << endl << endl;




//    cout << "i == j?\t" << (i == j) << endl;
    cout << "i == i?\t" << (i == i) << endl;

//    cout << "p = " << p << endl
//         << "&p = " << &p << endl
//         << "*(int *)p = " << *(int *)p << endl;

//    void *fptr = add;

//    cout << fptr(i,j) << endl;





    // calling code

    return 0;

}


/*************baseNode.h SAMPLE RUN

    baseNode<int>* b = new baseNode<int>;

    cin>>*b;
    cout << * b << endl;

  ------------------

Enter data: 452345
Data: 452345
Press <RETURN> to close this window...




***************linkedList.h SAMPLE RUN

// NOTE: In order to run this, void insert(T data) needs to be public (not protected)

    srand(time(NULL));

    linkedList<int>* l = new linkedList<int>;

    int j;

    for (int i = 0; i < 10; ++i)
    {
        j = rand() % 100;

        cout << "j = " << j << endl;

        l->insert(j);
    }
    cout << endl << *l << endl;

---------------------
j = 91
j = 64
j = 42
j = 75
j = 29
j = 24
j = 0
j = 13
j = 89
j = 3

Data: 0
Data: 3
Data: 13
Data: 24
Data: 29
Data: 42
Data: 64
Data: 75
Data: 89
Data: 91

Press <RETURN> to close this window...

************************

    srand(time(NULL));

    linkedList<int>* l = new linkedList<int>;

    for (int i = 0; i < 10; ++i)
    {


        l->insert(rand() % 100);
    }


    cout << "\nl = " << l << endl << *l << endl;
    cout << l->size() << endl << endl;


    linkedList<int>* m = new linkedList<int>;

    *m = *l;

    cout << "m = " << m; //<< endl << *m << endl;
    cout << m->size() << endl << endl;

    l->resize(5);
    cout << "l = " << l << endl << *l << endl;
    cout << "l size = " << l->size() << "  l max = " << l->max_size() << endl << endl;

---------------------

0xb22e68   85
0xb22e78   57
0xb22f78   34
0xb22f88   10
0xb22f98   34
0xb22fa8   5
0xb22fb8   95
0xb22fc8   40
0xb22fd8   37
0xb20f88   13

l = 0xb22e50
0xb22fa8    5
0xb22f88    10
0xb20f88    13
0xb22f98    34
0xb22f78    34
0xb22fd8    37
0xb22fc8    40
0xb22e78    57
0xb22e68    85
0xb22fb8    95

10

0xb20fb0   5
0xb20fc0   10
0xb20fd0   13
0xb20fe0   34
0xb20ff0   34
0xb26d08   37
0xb21018   40
0xb21028   57
0xb21038   85
0xb21048   95
copy the object 0xb20f98
0xb21058   5
0xb21068   10
0xb21078   13
0xb21088   34
0xb21098   34
0xb210a8   37
0xb210b8   40
0xb210c8   57
0xb210d8   85
0xb210e8   95
destructed 0x28fe84
m = 0xb20f9810

l = 0xb22e50

l size = 0  l max = 5

Press <RETURN> to close this window...

************************

cout!
0x572fa8    24352
0x572f98    1
0x572f88    452345
0x572f78    666
0x572f38    555
0x572f28    245

z = 24352
Press <RETURN> to close this window...

    -------------------

    linkedList<int> *m = new linkedList<int>;

    *m << 245 << 555 << 666 << 452345 << 1 << 24352;

    cout << *m << endl;

    int z;

    *m >> z;

    cout << "z = " << z << endl;

************************

    baseNode<int> *b = new baseNode<int>;


    *b << 555;
    cout << *b << endl;

    int c;

    *b >> c;

    cout << "c = " << c << endl;

---------

Data: 555
c = 555
Press <RETURN> to close this window...







************************

    ifstream fin;

    fin.open("num.txt");


    if(!fin.is_open())
    {
        cout << "fin error\n";
        exit(1);
    }
    else
        cout << "fin opened!\n";


    linkedList<int> *m = new linkedList<int>;

    fin >> *m;

    cout << *m << endl;


    ofstream fout;

    fout.open("num2.txt");

    fout << *m;


    if(!fout.is_open())
    {
        cout << "fout error\n";
        exit(1);
    }
    else
        cout << "fout opened!\n";

    fin.close();
    fout.close();

    *********************************

    Stack<int> *m = new Stack<int>;


    ifstream fin;

    fin.open("num.txt");


    if(!fin.is_open())
    {
        cout << "fin error\n";
        exit(1);
    }
    else
        cout << "fin opened!\n";


try
    {
        fin >> *m;

    }
    catch(...)
    {
        cout << "Too much data\n";
    }

    cout << *m << endl;


    ofstream fout;

    fout.open("num2.txt");

    fout << *m;


    if(!fout.is_open())
    {
        cout << "fout error\n";
        exit(1);
    }
    else
        cout << "fout opened!\n";

    fin.close();
    fout.close();



    cout << endl;

    cout << *m << endl;

    cout << "popping\n";

    int j = m->size();

        for(size_t i = 0; i < j; ++i)
        {
            cout << i << "\t" << m->pop() << endl;
        }


*********************************

    srand(time(NULL));


    Stack<int> *s = new Stack<int>;

    int j;
    for (unsigned int i = 0; i < s->max_size(); ++i)
    {
        j = rand() % 155;
        s->push(j);
        cout << i << "\t" << s->peek() << endl;
    }

    cout << *s << endl;

    cout << "popping\n";


        for(size_t i = 0; i < s->max_size(); ++i)
        {
            cout << i << "\t"  << s->pop() << endl;
        }



*********************************


    Queue<int>* q = new Queue<int>;

    int j;
    for (unsigned int i = 0; i < q->getMaxSize(); ++i)
    {
        j = rand() % 1555;
        q->enqueue(j);
        cout << i << "\t" << j << "\t" << q->back() << endl;
    }

    cout << "cout q\n";
    cout << *q << endl;


    // copying
    Queue<int>*m = new Queue<int>;

    *m = *q;

    cout << "cout m\n";
    cout << *m << endl;


cout << "dequeueing\n";

    for (unsigned int i = 0; i < q->getMaxSize(); ++i)
    {

        cout << i << "\t" << q->dequeue() << endl;
                cout << i << "\t" << m->dequeue() << endl;
    }

//    cout << "dequeuing\n";


//        for(size_t i = 0; i < s->max_size(); ++i)
//        {
//            cout << i << "\t"  << s->pop() << endl;
//        }





*********************************



*********************************


*********************************



 */
