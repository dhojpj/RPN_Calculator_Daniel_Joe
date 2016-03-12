#include "fraction.h"
#include <string>

using namespace std;


// constructor//?????????????????????????????????????????????????
fraction::fraction(long n, int d)
{
    setNum((int)n,d);
//    int sign = 1;
//    if(d == 0)
//        throw ZERO_DENOM;
//    denom < 0  ? sign = -1:sign = 1;
//    denom = sign*d;
//    num = sign*n;
}

// destructor
fraction::~fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(int x)
{

    num = x;
    denom = 1;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction::fraction(double x)
{
    //stringMethod slower but will not have to round
    stringMethod(x);

    // faster but will have error due to the way doubles are store
    // have to break menually because the double != (int) double sometime
    ///whileLoopMethod(x);
    reduce();
}


fraction::fraction(const fraction &other)
{
    num = other.get_num();
    denom = other.get_denom();
    //copy(other);
}

fraction& fraction::operator=(const fraction &other)
{
    if (this != &other)
    {
        num = other.num;
        denom = other.denom;
    }
    return *this;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction& fraction::operator=(int other)
{
    setNum(other, 1);
    return *this;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction& fraction::operator=(double other)
{
    fraction temp(other);
    num = temp.numerator();
    denom = temp.denominator();
    return *this;
}

int fraction::get_num() const
{
    return num;
}

int fraction::get_denom() const
{
    return denom;
}

void fraction::setValue(int n, int d)
{
    setNum(n,d);
}

fraction& fraction::operator+=(const fraction &other)
{   // (a*d+b*c)/b*d
    num = num*other.denom+denom*other.num;
    denom = denom*other.denom;
    this->reduce();
    return *this;
}

fraction& fraction::operator-=(const fraction &other)
{
    this->num = (this->num*other.denom)-(this->denom*other.num);
    this->denom = this->denom*other.denom;
    this->reduce();
    return *this;
}
fraction& fraction::operator*=(const fraction &other)
{
    num = num*other.num;
    denom = denom*other.denom;

    this->reduce();
    return *this;
}
fraction& fraction::operator/=(const fraction &other)
{
    num = num*other.denom;
    denom = denom*other.num;
    this->reduce();
    return *this;
}
fraction& fraction::operator^=(const fraction &other)
{
    double power = (double) other.get_num()/(double) other.get_denom();
    double a = (double)pow(this->get_num(),power)/pow(this->get_denom(),power);
    fraction temp(a);
    this->setValue(temp.get_num(),temp.get_denom());
    return *this;
}


fraction& fraction::operator+=(int other)
{
    fraction c(other,1);
    return *this+=c;
}
fraction& fraction::operator-=(int other)
{
    fraction c(other,1);
    return *this-=c;
}
fraction& fraction::operator*=(int other)
{
    fraction c(other,1);
    return *this*=c;
}
fraction& fraction::operator/=(int other)
{
    fraction c(other,1);
    return *this/=c;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction& fraction::operator^=(int other)
{
    double a = pow(this->get_num(),other)/pow(this->get_denom(),other);
    fraction temp(a);
    this->setValue(temp.get_num(),temp.get_denom());
    return *this;
}


fraction& fraction::operator+=(double other)
{
    fraction doubleOther(other);
    return *this+=doubleOther;

}
fraction& fraction::operator-=(double other)
{
    fraction doubleOther(other);
    return *this-=doubleOther;
}

fraction& fraction::operator*=(double other)
{
    fraction doubleOther(other);
    return *this*=doubleOther;
}

fraction& fraction::operator/=(double other)
{
    fraction doubleOther(other);
    return *this/=doubleOther;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++
fraction& fraction::operator^=(double other)
{
    double a = pow(this->get_num(),other)/pow(this->get_denom(),other);
    fraction temp(a);
    this->setValue(temp.get_num(),temp.get_denom());
    return *this;
}



void fraction::reduce()
{
    int g = abs(gcd(this->num, this->denom));
    if (g > 1)
    {
        this->num /= g;
        this->denom /= g;
    }
}

void fraction::setNum(int n, int d)
{
    int sign = 1;
    if(d == 0)
        throw ZERO_DENOM;

    // if the denom is negative make it positive and change num to negative
    sign = (d < 0  ? -1: 1);
    denom = sign*d;
    num = sign*n;

}

int& fraction::numerator()
{
    return num;
}

int& fraction::denominator()
{
    return denom;
}


void fraction::copy(const fraction& other)
{
    num = other.num;
    denom = other.denom;
}


int fraction::gcd(int p, int q)
{
    return !q ? p : gcd(q,p%q);
}

void fraction::stringMethod(double x)
{
    // change the double to string
    std::string aa = patch::to_string(x);

    //incase there are no decimal in the double
    aa += ".";

    //find the position of the first.
    unsigned int index = aa.find_first_of(".");
//    if( index == -1)
//    {
//        denom = 1;
//        num = x;
//        return;
//    }

    //-2 will remove the "." and account for starting at 0
    std::string dec = aa.substr(index+1,aa.length()-2-index);
    std::string intPart = aa.substr(0, index);

    // convert the string back to integer using stringstream
    //
    int intN, decN;
    if (!(istringstream(dec) >> decN)) decN = 0;
    if (!(istringstream(intPart) >> intN)) intN = 0;

    denom = pow(10, dec.length());

    //check the sign for negative or positive num
    int sign = intN<0 ? -1:1;
    num = sign*(abs(intN*denom)+decN);
}

void fraction::whileLoopMethod(double x)
{
    denom = 1;
    double tempX = x;
    while(tempX != (int) tempX)
    //while(abs(tempX) - abs((int) tempX) < 0.0001 )
    {
        tempX=tempX*10;
        denom *=10;

        if(tempX > 90000000 || tempX < -90000000)
            break;
    }
    num = tempX;
}


// need to remove the first const
fraction operator+(const fraction &x, const fraction &y)
{
    int n = x.get_num()*y.get_denom()+x.get_denom()*y.get_num();
    int d = x.get_denom()*y.get_denom();
    fraction a(n,d);
    a.reduce();
    return a;
}

//fraction& fraction::operator+(const fraction &y)
//{

//    int n = this->get_num()*y.get_denom()+this->get_denom()*y.get_num();
//    int d = this->get_denom()*y.get_denom();
//    fraction *a = new fraction(n,d);
//    cout<<"fraction + "<<endl;
//    return *a;
//}


fraction operator-(const fraction &x, const fraction &y)
{
    int n = x.num*y.denom-x.denom*y.num;
    int d = x.denom*y.denom;
    fraction a(n,d);
    a.reduce();
    return a;
}

fraction operator*(const fraction &x, const fraction &y)
{
    int n = x.num*y.num;
    int d = x.denom*y.denom;
    fraction a (n,d);
    a.reduce();
    return a;
}

fraction operator/(const fraction &x, const fraction &y)
{
    int n = x.num*y.denom;
    int d = x.denom*y.num;
    fraction a (n,d);
    a.reduce();
    return a;
}

//+++++++++++++++++++++++++++++++++++++
fraction operator^(const fraction &x, const fraction &y)
{
    double power = (double) y.get_num() / (double) y.get_denom();
    double a = (pow(x.get_num(),power)/pow(x.get_denom(),power));
    fraction temp (a);
    //this->setValue(temp.get_num(),temp.get_denom());
    //return *this;
    return temp;
}


fraction operator+(const fraction &x, int y)
{
    fraction fraX(y);
    return (x+fraX);
}

fraction operator-(const fraction &x, int y)
{
    fraction c(y,1);
//    this->num = x.num*c.denom-x.denom*c.num;
//    this->denom = x.denom*c.denom;
//    cout<<c<<endl;
//    cout<<x<<endl;
//    cout<<"dd: "<<(x - c);
    return (x - c);
}

fraction operator*(const fraction &x, int y)
{
    fraction fraX(y);
    return (x*fraX);
}

fraction operator/(const fraction &x, int y)
{
    fraction fraX(y);
    return (x/fraX);
}

fraction operator^(const fraction &x, int y)
{
    double a = pow(x.get_num(),y)/pow(x.get_denom(),y);
    fraction temp(a);
    //this->setValue(temp.get_num(),temp.get_denom());
    //return *this;
    return temp;
}

fraction operator+(int x, const fraction &y)
{
    fraction fraX(x*y.get_denom()+y.get_num(),y.get_denom());
    fraX.reduce();
    return (fraX);
}

fraction operator-(int x, const fraction &y)
{
    fraction fraX(x*y.get_denom()-y.get_num(),y.get_denom());
    fraX.reduce();
    return (fraX);
}

fraction operator*(int x, const fraction &y)
{
    fraction fraX(x*y.get_num(),y.get_denom());
    return (fraX);
}

fraction operator/(int x, const fraction &y)
{
    fraction fraX(y.get_num(),y.get_num()*x);
    fraX.reduce();
    return (fraX);
}


////++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction operator^(int x, const fraction &y)
{

    double power = (double)y.get_num()/(double) y.get_denom();
    double a = pow(x, power)/pow(1, power);
    cout<<"here"<<a<<endl;
    fraction temp(a);
    //this->setValue(temp.get_num(),temp.get_denom());
    //return *this;
    return temp;
}


fraction operator+(const fraction &x, double y)
{
    fraction fraX(y);
   //cout<<"fraction operator+(const fraction &x, double y)"<<endl;
    return (x+fraX);
}

fraction operator-(const fraction &x, double y)
{
    fraction fraX(y);
    //cout<<"fraction operator-(const fraction &x, double y)"<<endl;
    return (x-fraX);
}

fraction operator*(const fraction &x, double y)
{
    fraction fraX(y);
    return (x*fraX);
}

fraction operator/(const fraction &x, double y)
{
    fraction fraX(y);
    return (x/fraX);
}

////++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction operator^(const fraction &x, double y)
{
    double a = pow(x.get_num(),y)/pow(x.get_denom(),y);
    fraction temp(a);
    return temp;
}

fraction operator+(double x, const fraction &y)
{
    fraction fraX(x);
    return (fraX+y);
}

fraction operator-(double x, const fraction &y)
{
    fraction fraX(x);
    return (fraX-y);
}

fraction operator*(double x, const fraction &y)
{
    fraction fraX(x);
    return (fraX*y);
}

fraction operator/(double x, const fraction &y)
{
    fraction fraX(x);
    return (fraX/y);
}


///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
fraction operator^(double x, const fraction &y)
{
    double yy = ((double) y.get_num())/y.get_denom();
    double a = pow(x,yy)/pow(1,yy);
    fraction temp(a);
    return temp;
}


bool operator==(const fraction &x, const fraction &y)
{
    // x.num*y.denom == x.denom*y.num;
    return (x.num*y.denom == x.denom*y.num);
}

bool operator!=(const fraction &x, const fraction &y)
{
    return (x.num*y.denom != x.denom*y.num);
}

bool operator<=(const fraction &x, const fraction &y)
{
    return (x.num*y.denom <= x.denom*y.num);
}

bool operator>=(const fraction &x, const fraction &y)
{
    return (x.num*y.denom >= x.denom*y.num);
}

bool operator<(const fraction &x, const fraction &y)
{
    return (x.num*y.denom < x.denom*y.num);
}

bool operator>(const fraction &x, const fraction &y)
{
    return (x.num*y.denom > x.denom*y.num);
}


bool operator==(const fraction &x, int y)
{
//    fraction tempFra(y);
//    return(x == tempFra);
      return( x.get_num() == y*x.get_denom());
}

bool operator!=(const fraction &x, int y)
{
//    fraction tempFra(y);
//    return(x != tempFra);
    return( x.get_num() != y*x.get_denom());
}

bool operator<=(const fraction &x, int y)
{
//    fraction tempFra(y);
//    return(x <= tempFra);
      return( x.get_num() <= y*x.get_denom());
}

bool operator>=(const fraction &x, int y)
{
//    fraction tempFra(y);
//    return(x >= tempFra);
    return( x.get_num() >= y*x.get_denom());
}

bool operator<(const fraction &x, int y)
{
//    fraction tempFra(y);
//    return(x < tempFra);
      return( x.get_num() < y*x.get_denom());
}

bool operator>(const fraction &x, int y)
{
//    fraction tempFra(y);
//    return(x > tempFra);
    return( x.get_num() > y*x.get_denom());
}

bool operator==(int x, const fraction &y)
{
//    fraction tempFra(x);
//    return(tempFra == y);
      return(x*y.get_denom() == y.get_num());
}

bool operator!=(int x, const fraction &y)
{
    //    fraction tempFra(x);
    //    return(tempFra != y);
    return(x*y.get_denom() != y.get_num());
}

bool operator<=(int x, const fraction &y)
{
//    fraction tempFra(x);
//    return(tempFra <= y);
    return(x*y.get_denom() <= y.get_num());
}

bool operator>=(int x, const fraction &y)
{
//    fraction tempFra(x);
//    return(tempFra >= y);
    return(x*y.get_denom() >= y.get_num());
}

bool operator<(int x, const fraction &y)
{
//    fraction tempFra(x);
//    return(tempFra < y);
    return(x*y.get_denom() < y.get_num());
}

bool operator>(int x, const fraction &y)
{
//    fraction tempFra(x);
//    return(tempFra > y);
    return(x*y.get_denom() > y.get_num());
}


bool operator==(const fraction &x, double y)
{
    fraction tempFra(y);
    return (x==tempFra);
}


bool operator!=(const fraction &x, double y)
{
    fraction tempFra(y);
    return (x!=tempFra);
}


bool operator<=(const fraction &x, double y)
{
    fraction tempFra(y);
    return (x<=tempFra);
}


bool operator>=(const fraction &x, double y)
{
    fraction tempFra(y);
    return (x>=y);
}


bool operator<(const fraction &x, double y)
{
    fraction tempFra(y);
    return (x<y);
}


bool operator>(const fraction &x, double y)
{
    fraction tempFra(y);
    return (tempFra>x);
}

bool operator==(double x, const fraction &y)
{
    fraction tempFra(x);
    return (tempFra==y);
}


bool operator!=(double x, const fraction &y)
{
    fraction tempFra(x);
    return (tempFra!=y);
}


bool operator<=(double x, const fraction &y)
{
    fraction tempFra(x);
    return (tempFra>y);
}

bool operator>=(double x, const fraction &y)
{
    fraction tempFra(x);
    return (tempFra>=y);
}

bool operator<(double x, const fraction &y)
{
    fraction tempFra(x);
    return (tempFra<y);
}

bool operator>(double x, const fraction &y)
{
    fraction tempFra(x);
    return (tempFra>y);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ostream& operator<<(ostream& out, const fraction &frac)
{

    if(frac.get_num() == 0 || frac.get_denom() == 1)
        out<<frac.get_num()<<" ";
    else
        out<<frac.get_num()<<"/"<<frac.get_denom()<<" ";
    return out;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
istream& operator>>(istream& in, fraction &frac)
{
    char c;
    if (&in == &cin)
    {
        in >> frac.num >>c>> frac.denom;
    }
    return in;
}
