#include <iostream>
#include "fraction.h"
#include "mixed.h"
#include <string>

using namespace std;
void test_constructor();
void test_boolean_double();
void addition();
void operatorTest1();

/// when all three parameters are negative for mixed number
/// constructor there's a strange result

int main()
{

    double d = 42345.4235;
    mixed m = d;
//    fraction a (0.933333333);
//    cout<<a<<endl;
cout << m << endl;
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
