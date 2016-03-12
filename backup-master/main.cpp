#include <iostream>
#include "fraction.h"
#include "mixed.h"
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Parser.h"
#include "memory.h"

enum letters {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

using namespace std;
void test_constructor();
void test_boolean_double();
void addition();
void operatorTest1();
void voidPointerTest();
bool isString(void* temp);
string getUserInput();
string trimBoth(string str);

void clearMemory(mixed memory[],int s);
void clearMemoryPos(mixed memory[],int size, int pos);
mixed getMemory(mixed memory[], int size, int pos);
void setMemory(mixed memory[], int size, int pos, mixed data);
/// when all three parameters are negative for mixed number
/// constructor there's a strange resu

struct twin
{
    string s;
    void* p;
};

int main()
{
    fraction ttt(1,2);
    void* vp;
    vp = &ttt;

    twin ttpair;
    ttpair.s = typeid(ttt).name();
    ttpair.p = vp;

    Stack<mixed> *stk = new Stack<mixed>(100);
    Stack<twin> st(100);

    st.push(ttpair);

    twin tempt = ttpair;
    twin temps =  st.pop();
    string str3 = temps.s;
    if(str3=="8fraction")
    {
        cout<<" asdfa go itadsf"<<endl;
        fraction tempmixed = (fraction*) temps.p;
    }

    cout<<"typestr3: "<<str3<<endl;



    stk->push(mixed(1,2,3));
    stk->push(fraction(1,2));
    cout<<"peek "<<stk->peek();
    cout<<"pop "<<stk->pop();
    cout<<"pop "<<stk->pop();
    //std::array<std::pair<std::string, int>, 3> test{{"a", 1}, {"b", 2}, {"c", 3}};



    memory m(30),kk ;
    fraction dd(1,2);
    cout<<m<<endl;
    m.setMemory(A,dd);
    m.setMemory(Z,dd);
    cout<<m<<endl;

    //string for the memory slot
    string memoryVar;
    string str;

    //mixed fraction array
    mixed memory[30];
    fraction half(1,2);

    cout<<"type: "<<(typeid(half).name())<<endl;

    for(int i=0; i<30;i++)
    {
        memory[i] = mixed(i+.2);
    }

    for(int i = 0; i < 30; i++)
    {
        cout<<memory[i]<<" ";
    }

    clearMemoryPos(memory,30, A);

//    clearMemory(memory, 30);
    for(int i = 0; i < 30; i++)
    {
        cout<<memory[i];
    }


    // ask the user for input
    // will convert everything to upper case

//    str= getUserInput();

//    //find the index of =
//    indexOfEqual = str.find_first_of("=");


//    if(indexOfEqual <0)
//        cout<<"not here"<<endl;
//    else
//        memoryVar = str.substr(0,indexOfEqual);

//    //trim the spaces
//    memoryVar = trimBoth(memoryVar);

    //find the right hand side of the string
//    string rhsStr = str.substr(indexOfEqual,str.size());

//    // check if there are any letter in the string
//    //replace the letter with the contain from the memory array

//    if((rhsStr.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ")!=-1)) // there are letter in the string
//    {
//      // replace the letter with
//    }else
//    {
//        //no letter in the string
//        // prase it to stack and queue
//    }


      return 0;
}

void test_constructor()
{
    int     one = 1;
    int     two = 2;

    //    int& numerator();
    //    int& denominator();
    cout<<"Created fraction 1/2 using numerator = "<<one<<", denominator = "<<two<<". "<<endl;
    fraction half(one,two);
    cout<<"Fraction output: "<<half<<endl<<endl;

    cout<<"Created fraction 1/2 using numerator = 1, denominator = -2.  "<<endl;
    fraction negative_half(1,-2);
    cout<<"Fraction output: "<<negative_half<<endl<<endl;

    cout<<"Created fraction 1/2 using numerator = -1, denominator = -2. "<<endl;
    fraction __half(-1,-2);
    cout<<"Fraction output: "<<__half<<endl<<endl;

    cout<<"Created fraction 1/2 using numerator = -1, denominator = 2. "<<endl;
    fraction __1half(-1,2);
    cout<<"Fraction output: "<<__1half<<endl<<endl;

    cout<<"Created fraction using integer 2.0. "<<endl;
    fraction double_F(2.0);
    cout<<"Fraction output: "<<double_F<<endl<<endl;

    cout<<"Created fraction using 2.22222. "<<endl;
    fraction double_A(2.22222);
    cout<<"Fraction output: "<<double_A<<endl<<endl;

    cout<<"Created fraction using -2.333. "<<endl;
    fraction double_nega(-2.333);
    cout<<"Fraction output: "<<double_nega<<endl<<endl;

    cout<<"Created fraction using double 4.444. "<<endl;
    fraction double_pos(4.444);
    cout<<"Fraction output: "<<double_pos<<endl<<endl;

    //444 is consider type long
    // had trouble with int and double cuz the ambiguous error
    cout<<"Created fraction using double 444. "<<endl;
    fraction int_p(444);
    cout<<"Fraction output: "<<int_p<<endl<<endl;

    cout<<"Created fraction using double -88888. "<<endl;
    fraction int_p2(-88888);
    cout<<"Fraction output: "<<int_p2<<endl<<endl;

    cout<<"Created fraction using double 0. "<<endl;
    fraction int_p3(0);
    cout<<"Fraction output: "<<int_p3<<endl<<endl;

    ///mixed constructors
    cout<<"Created mixed fraction using double 0. "<<endl;
    mixed mixed_0(0);
    cout<<"Fraction output: "<<mixed_0<<endl<<endl;

    cout<<"Created mixed fraction using integer 3. "<<endl;
    mixed mixed_1(3);
    cout<<"Fraction output: "<<mixed_1<<endl<<endl;

    cout<<"Created mixed fraction using integer -3. "<<endl;
    mixed mixed_2(-3);
    cout<<"Fraction output: "<<mixed_2<<endl<<endl;

    cout<<"Created mixed fraction using 3.0. "<<endl;
    mixed mixed_3(3.0);
    cout<<"Fraction output: "<<mixed_3<<endl<<endl;

    cout<<"Created mixed fraction using double -3.0. "<<endl;
    mixed mixed_4(-3.0);
    cout<<"Fraction output: "<<mixed_4<<endl<<endl;

    cout<<"Created mixed fraction using w=0, n =1, d=2. "<<endl;
    mixed mixed_5(0, 1,2);
    cout<<"Fraction output: "<<mixed_5<<endl<<endl;

    cout<<"Created mixed fraction using using w=2, n =1, d=2. "<<endl;
    mixed mixed_6(2,1,2);
    cout<<"Fraction output: "<<mixed_6<<endl<<endl;



    try
    {
        fraction (2, 0);
    }catch(FRACTION_ERRORS)
    {
        cout<<"Zero division error!"<<endl;
    }


    try
    {
        mixed (2,1,0);
    }catch(FRACTION_ERRORS)
    {
        cout<<"mixed fractino zero division error!"<<endl;
    }

    cout<<"Created mixed fraction using using w=-2, n =-1, d=-2. "<<endl;
    mixed mixed_8(-2,-1,-2);
    cout<<"Fraction output: "<<mixed_8<<endl<<endl;

    cout<<"Created mixed fraction using using w=2, n =-1, d=-2. "<<endl;
    mixed mixed_9(2,-1,-2);
    cout<<"Fraction output: "<<mixed_9<<endl<<endl;

    cout<<"Created mixed fraction using using w=0, n =0, d=2. "<<endl;
    mixed mixed_10(0,0,2);
    cout<<"Fraction output: "<<mixed_10<<endl<<endl;

    cout<<"Created mixed fraction using using w=1, n =0, d=2. "<<endl;
    mixed mixed_11(1,0,2);
    cout<<"Fraction output: "<<mixed_11<<endl<<endl;

    cout<<"Created mixed fraction using using w=-1, n =0, d=2. "<<endl;
    mixed mixed_12(-1,0,2);
    cout<<"Fraction output: "<<mixed_12<<endl<<endl;

    cout<<"Created mixed fraction using using w=1, n =1, d=1. "<<endl;
    mixed mixed_13(1,1,1);
    cout<<"Fraction output: "<<mixed_13<<endl<<endl;

    cout<<"Created mixed fraction using double 0. "<<endl;
    mixed mixed_7(0);
    cout<<"Fraction output: "<<mixed_7<<endl<<endl;

}

void test_boolean_double()
{
    fraction two_two(2.2);
    fraction half(1,2);
    fraction n_half(-1,2);
    fraction _11_5(11,5);
    fraction _3(3);
    fraction _3_33(3.3);

    cout<<"==Testing for double with greater than sign \">\""<<endl;
    cout<<"2.2 > 1/2: "<<(2.2 > half ? "true.":"false.")<<endl;
    cout<<"2.2 > -1/2: "<<(2.2 > n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 > -1/2: "<<(-2.2 > n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 > 1/2: "<<(-2.2 > half ? "true.":"false.")<<endl;
    cout<<"0.5 > 1/2: "<<(0.5 > half ? "true.":"false.")<<endl;
    cout<<"-2 > 1/2: "<<(-2 > half ? "true.":"false.")<<endl;
    cout<<"2 > 1/2: "<<(2 > half ? "true.":"false.")<<endl;

    cout<<endl<<endl;
    cout<<"==Testing for double with greater than or equal sign \">=\""<<endl;
    cout<<"2.2 >= 1/2: "<<(2.2 >= half ? "true.":"false.")<<endl;
    cout<<"2.2 >= -1/2: "<<(2.2 >= n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 >= -1/2: "<<(-2.2 >= n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 >= 1/2: "<<(-2.2 >= half ? "true.":"false.")<<endl;
    cout<<"0.5 >= 1/2: "<<(0.5 >= half ? "true.":"false.")<<endl;

    cout<<endl<<endl;
    cout<<"==Testing for double with greater than sign \"<\""<<endl;
    cout<<"2.2<1/2: "<<(2.2 < half ? "true.":"false.")<<endl;
    cout<<"2.2 < -1/2: "<<(2.2 < n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 < -1/2: "<<(-2.2 < n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 < 1/2: "<<(-2.2 < half ? "true.":"false.")<<endl;
    cout<<"0.5 < 1/2: "<<(0.5 < half ? "true.":"false.")<<endl;

    cout<<endl<<endl;
    cout<<"==Testing for double with greater than or equal sign \"<=\""<<endl;
    cout<<"2.2 <= 1/2: "<<(2.2 <= half ? "true.":"false.")<<endl;
    cout<<"2.2 <= -1/2: "<<(2.2 <= n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 <= -1/2: "<<(-2.2 <= n_half ? "true.":"false.")<<endl;
    cout<<"-2.2 <= 1/2: "<<(-2.2 <= half ? "true.":"false.")<<endl;
    cout<<"0.5 <= 1/2: "<<(0.5 >= half ? "true.":"false.")<<endl;
    cout<<"2.2 == 1/2: "<<(2.2 == half ? "true.":"false.")<<endl;




}

void addition()
{
    fraction half(1,2);
    fraction one_third(1,3);
    fraction one(1);
    fraction two(2);
    fraction n_two(-2);
    fraction n_half(-1,2);
    fraction n_double(-1.2);
    fraction n_double2(-3.202);
    fraction double1(1.201);
    fraction double2(3.202);
    fraction double4(-3);

    cout<<double4 +2<<endl;
    ///fraction + fraction
    cout<<"1/2 + 1/2 = 1: "<<(half + half)<<endl;
    cout<<"1/3 + 1/3 = 2/3: "<<(one_third + one_third)<<endl;
    cout<<"1/2 + 1/3 = 5/6: "<<half + one_third<<endl;
    cout<<"1 + 1/2 = 3/2: "<<one + half<<endl;
    cout<<"1 + -1.2= -1/5: "<<one + n_double<<endl;
    cout<<"-1/2 + half = 0: "<<(half+n_half)<<endl;
    cout<<"3.202 + 1.201 = 4.403 or 4403/1000: "<<double1+double2<<endl;
    cout<<"3.202 + -1.2 = 2.202 or 1101/500: "<<double2+n_double<<endl;
    cout<<"1/2 + 2"<<half+2<<endl;

    ///fraction + int
    cout<<"1/2 + 1 = 3/2: "<<(half + 1)<<endl;
    cout<<"1/3 + 3 = 10/3: "<<(one_third + 3)<<endl;
    cout<<"1/2 + -1 = -1/2: "<<half + -1<<endl;

    ///bugs out the program
   // cout<<"1 + 1/2 = 3/2: "<<1 + half<<endl;
    cout<<"-1 + 1/2= -1/1: "<<-1 + 1/2<<endl;

    cout<<"-0.5 + 1/2 = 0: "<<(-0.5+n_half)<<endl;

    cout<<"3.202 + 1.201 = 4.403 or 4403/1000: "<<(3.202+double2)<<endl;
    cout<<"-3.202 + -1.2 = -2.202 or 1101/500: "<<(-3.202+n_double)<<endl;
   // cout<<"-3 + half = -5/2: "<<-3 + half<<endl;
}


void operatorTest1()
{
    int one(1), two(2), three(2), none(-1);
    int aa(1), bb(2);
    double dtwo(2.1);

    fraction half(1,2);
    fraction a(one,two);
    fraction b(one,three);
    fraction na(none,two);
    fraction nb(none,three);

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<one<<"/"<<two<<" + "<<one<<"/"<<three<<" = "<<(a+b)<<endl;
    cout<<one<<"/"<<two<<" - "<<one<<"/"<<three<<" = "<<(a-b)<<endl;
    cout<<one<<"/"<<two<<" * "<<one<<"/"<<three<<" = "<<(a*b)<<endl;
    cout<<one<<"/"<<two<<" / "<<one<<"/"<<three<<" = "<<(a/b)<<endl;
    cout<<one<<"/"<<two<<" ^ "<<one<<"/"<<three<<" = "<<(a^b)<<endl;


    cout<<endl;
    cout<<"======fraction operator 2"<<endl;
    one = 2;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<aa<<"/"<<bb<<" + "<<one<<" = "<<(a+one)<<endl;
    cout<<aa<<"/"<<bb<<" - "<<one<<" = "<<(a-one)<<endl;
    cout<<aa<<"/"<<bb<<" * "<<one<<" = "<<(a*one)<<endl;
    cout<<aa<<"/"<<bb<<" / "<<one<<" = "<<(a/one)<<endl;
    cout<<aa<<"/"<<bb<<" ^ "<<one<<" = "<<(a^one)<<endl;

    cout<<endl;
    cout<<"======fraction operator 2"<<endl;
    one = -2;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<aa<<"/"<<bb<<" + "<<one<<" = "<<(a+one)<<endl;
    cout<<aa<<"/"<<bb<<" - "<<one<<" = "<<(a-one)<<endl;
    cout<<aa<<"/"<<bb<<" * "<<one<<" = "<<(a*one)<<endl;
    cout<<aa<<"/"<<bb<<" / "<<one<<" = "<<(a/one)<<endl;
    cout<<aa<<"/"<<bb<<" ^ "<<one<<" = "<<(a^one)<<endl;

    cout<<endl;
    cout<<"======fraction operator 2"<<endl;
    one = 0;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<aa<<"/"<<bb<<" + "<<one<<" = "<<(a+one)<<endl;
    cout<<aa<<"/"<<bb<<" - "<<one<<" = "<<(a-one)<<endl;
    cout<<aa<<"/"<<bb<<" * "<<one<<" = "<<(a*one)<<endl;
    try
    {
        cout<<aa<<"/"<<bb<<" / "<<one<<" = "<<(a/one)<<endl;
    }
    catch(FRACTION_ERRORS)
    {
        cout<<"zero division error!"<<endl;
    }
    cout<<aa<<"/"<<bb<<" ^ "<<one<<" = "<<(a^one)<<endl;

    cout<<endl;
    cout<<"======fraction operator= 2"<<endl;
    one = 2;
    two = 2;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    a = half;
    b = half;
    cout<<half<<" += "<<b<<" = " <<(a+=b)<<endl;
    a = half;
    b = half;

    cout<<half<<" -= "<<b<<" = " <<(a-=b)<<endl;
    a = half;
    b = half;
    cout<<half<<" *= "<<b<<" = " <<(a*=b)<<endl;
    a = half;
    b = half;
    cout<<half<<" /= "<<b<<" = " <<(a/=b)<<endl;
    a = half;
    b = half;
    cout<<half<<" ^= "<<b<<" = " <<(a^=b)<<endl;


    ////////////////////fraction - double
    cout<<endl;
    cout<<"======fraction operator 2.1"<<endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<aa<<"/"<<bb<<" + "<<dtwo<<" = "<<(a+dtwo)<<endl;
    cout<<aa<<"/"<<bb<<" - "<<dtwo<<" = "<<(a-dtwo)<<endl;
    cout<<aa<<"/"<<bb<<" * "<<dtwo<<" = "<<(a*dtwo)<<endl;
    try
    {
        cout<<aa<<"/"<<bb<<" / "<<dtwo<<" = "<<(a/dtwo)<<endl;
    }
    catch(FRACTION_ERRORS)
    {
        cout<<"zero division error!"<<endl;
    }
    cout<<aa<<"/"<<bb<<" ^ "<<dtwo<<" = "<<(a^dtwo)<<endl;


    ////////////fraction - negative double
    cout<<endl;
    dtwo = -2.1;
    cout<<"======fraction operator -2.1"<<endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<aa<<"/"<<bb<<" + "<<dtwo<<" = "<<(a+dtwo)<<endl;
    cout<<aa<<"/"<<bb<<" - "<<dtwo<<" = "<<(a-dtwo)<<endl;
    cout<<aa<<"/"<<bb<<" * "<<dtwo<<" = "<<(a*dtwo)<<endl;
    try
    {
        cout<<aa<<"/"<<bb<<" / "<<dtwo<<" = "<<(a/dtwo)<<endl;
    }
    catch(FRACTION_ERRORS)
    {
        cout<<"zero division error!"<<endl;
    }
    cout<<aa<<"/"<<bb<<" ^ "<<dtwo<<" = "<<(a^dtwo)<<endl;




    ////////////fraction - negative double
    cout<<endl;
    dtwo = -2.1;
    cout<<"======-2.1 operator fraction(1,2)"<<endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<dtwo<<" + "<<aa<<"/"<<bb<<" = "<<(dtwo+a)<<endl;
    cout<<dtwo<<" - "<<aa<<"/"<<bb<<" = "<<(dtwo-a)<<endl;
    cout<<dtwo<<" * "<<aa<<"/"<<bb<<" = "<<(dtwo*a)<<endl;
    try
    {
            cout<<dtwo<<" / "<<aa<<"/"<<bb<<" = "<<(dtwo/a)<<endl;
    }
    catch(FRACTION_ERRORS)
    {
        cout<<"zero division error!"<<endl;
    }
    cout<<dtwo<<" ^ "<<aa<<"/"<<bb<<" = "<<(dtwo^a)<<endl;


    ////////////fraction - negative double
    cout<<endl;
    dtwo = 2.1;
    cout<<"======2.1 operator fraction(1,2)"<<endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<dtwo<<" + "<<aa<<"/"<<bb<<" = "<<(dtwo+a)<<endl;
    cout<<dtwo<<" - "<<aa<<"/"<<bb<<" = "<<(dtwo-a)<<endl;
    cout<<dtwo<<" * "<<aa<<"/"<<bb<<" = "<<(dtwo*a)<<endl;
    try
    {
            cout<<dtwo<<" / "<<aa<<"/"<<bb<<" = "<<(dtwo/a)<<endl;
    }
    catch(FRACTION_ERRORS)
    {
        cout<<"zero division error!"<<endl;
    }
        cout<<dtwo<<" ^ "<<aa<<"/"<<bb<<" = "<<(dtwo^a)<<endl;
    }

void voidPointerTest()
{
    fraction d(1,2);
    string s("str");
    double n(2.2);

    void* vFra = &d, *vStr=&s, *vDou=&n;
    void* vTemp;

    Queue<int> t2;
    t2.enqueue(3);
    cout<<t2<<endl;
    Queue<void*> temp;


    temp.enqueue(vFra);
    temp.enqueue(vStr);
    temp.enqueue(vDou);


    cout<<"type: "<<temp.getType()<<endl;
    temp.dequeue();
    cout<<"type: "<<temp.getType()<<endl;

}

bool isString(void* temp)
{
    try
    {
        fraction *s;
        s = (fraction*) temp;
        cout<<*s<<endl;
    }catch(...)
    {
        cout<<"ss: "<<endl;
        return false;
    }
    return true;
}


string getUserInput()
{
    string temp;
    cout<<"Enter an exptression: ";
    getline(cin,temp,'\n');

    for(unsigned int a = 0; a<temp.length(); a++)
    {
        temp.at(a) = toupper(temp.at(a));
    }

    return temp;
}

string trimBoth(string str)
{
    str.erase(0, str.find_first_not_of(" \n\r\t"));
    str.erase(str.find_last_not_of(" \n\r\t")+1);
    return str;
}

void clearMemory(mixed memory[], int s)
{
    for(int i=0; i<s;i++)
    {
        memory[i] = 0;
    }
}

void clearMemoryPos(mixed memory[],int size, int pos)
{
    if(pos>size-1||size<0)
        exit(1); // should throw some kind of error

    memory[pos] = 0;
}

mixed getMemory(mixed memory[], int size, int pos)
{
    if(pos>size-1||size<0)
        exit(1); // should throw some kind of error
    return memory[pos];
}

void setMemory(mixed memory[], int size, int pos, mixed data)
{
    if(pos>size-1||size<0)
        exit(1); // should throw some kind of error
    memory[pos] = data;
}
