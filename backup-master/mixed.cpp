#include "mixed.h"

mixed::mixed(int w, int n, int d)
{
    ///not sure what to do when all three number are negative
    //setValue((n+w*d),d);
    value(w,n,d);
    reduce();
}

mixed::mixed(const fraction& x)
{
    this->setValue(x.get_num(),x.get_denom());

}

mixed::mixed(long x)
{
    setValue((int)x,1);
}

mixed::mixed(double x)
{
    fraction temp(x);
    this->setValue(temp.get_num(),temp.get_denom());
}

mixed::mixed(const mixed &x):fraction(x.get_num(),x.get_denom())
{

}

mixed::mixed(int x, const fraction &f)
{
    //int*denom+num/ denom
    this->setValue((x*f.get_denom()+f.get_num()),f.get_denom());
    reduce();
}

mixed& mixed::operator=(const mixed &other)
{
    this->setValue(other.get_num(), other.get_denom());
    return *this;
}

mixed& mixed::operator=(int x)
{
    this->setValue(x,1);
    return *this;
}
mixed& mixed::operator=(double x)
{
   fraction temp(x);
   this->setValue(temp.get_num(), temp.get_denom());
   return *this;
}

mixed& mixed::operator=(const fraction &x)
{
    this->setValue(x.get_num(), x.get_denom());
    return *this;
}

mixed::~mixed()
{
    this->setValue(0,1);
}

void mixed::value(int w, int n, int d)
{
    int sign = (w<0 || n < 0) ? -1:1; // check the sign of the while number and store for next line
    this->setValue(sign*(abs(w*d)+abs(n)),d);
}


void mixed::value(double x)
{
    fraction xx(x);
    this->setValue(xx.get_num(),xx.get_denom());
}


void mixed::value(const fraction &x)
{
    this->setValue(x.get_num(), x.get_denom());
}

ostream& operator<<(ostream& out, const mixed &number)
{
    if(number.get_num() == 0 || number.get_denom() == 1)
        out<<number.get_num();
    else
        out<<number.get_num()<<"/"<<number.get_denom();
    return out;
}

istream& operator>>(istream& in, mixed &number)
{
    //3 1/2
    int w, n, d;
    char space, c;

    in>>w>>n>>c>>d;

    cout<<"w: "<<w<<"space: "<<space<<"n: "<<n<<"d: "<<endl;

    number.value(w,n,d);
    return in;
}






void mixed::add(const mixed &y)
{
    this->setValue(this->get_num() * y.get_denom() + y.get_num() * this->get_denom(),
                   this->get_denom() * y.get_denom());
    this->reduce();

//    cout << "\nmixed added = " << *this << endl;

}
void mixed::subtract(const mixed &y)
{
    this->setValue(this->get_num() * y.get_denom() - y.get_num() * this->get_denom(),
                   this->get_denom() * y.get_denom());
    this->reduce();
}

void mixed::multiply(const mixed &y)
{
    this->setValue(this->get_num() * y.get_num(), this->get_denom() * y.get_denom());
    this->reduce();
}

void mixed::divide(const mixed &y)
{
    this->setValue(this->get_num() * y.get_denom(), this->get_denom() * y.get_num());
    this->reduce();
}
void mixed::raiseTo(const mixed &y)
{
    double power = (double)y.get_num() / y.get_denom();

    this->setValue(pow(this->get_num(), power),
                   pow(this->get_denom(), power));
    this->reduce();
}


//mixed& add(const mixed &x, const mixed &y)
//{
//    mixed *m = new mixed;

//    m->setValue(x.num + y.num, x.denom + y.denom);
//    m->reduce();

//    return m;
//}


mixed subtract(const mixed &x, const mixed &y){}
mixed multiply(const mixed &x, const mixed &y){}
mixed divide(const mixed &x, const mixed &y){}
mixed power(const mixed &x, const mixed &y){}
