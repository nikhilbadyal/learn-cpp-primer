#include<iostream>
using std::cin; using std::cout;
using std::istream; using std::ostream;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include <cstddef>
using std::size_t;


class Quote;
double print_total(ostream &, const Quote &, size_t );
class Quote{
public:
    Quote() = default;
    Quote(const string &book , int Sale_price)
              : bookNo(book) , price(Sale_price) {}

    virtual ~Quote() = default;
    string isbn() const {return bookNo;}

    virtual double net_price(size_t n) const
           { return n*price;}

private:
    string bookNo = " ";
protected:
    double price = 0.0;
};
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(string &book, double cost , size_t quantity , double dis)
              : Quote(book,cost), min_quantity(quantity),discount(dis){}
    double net_price(size_t) const = 0;
    std::pair<size_t , double>discout_policy() const
             { return {quantity,discount};}
private:
    size_t min_quantity = 0 ;
    double discount = 0.0;
};
class Bulk_Quote : public Disc_quote{
public:
    Bulk_Quote() = default;
    Bulk_Quote(string &book, double p, size_t n , double q )
          : Disc_quote(book,p,n,q){}
    double net_price( size_t  ) const override;
};
double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os<<" ISBN : "<<item.isbn()
                <<" #Sold "<<n<<" Total due "<<ret;
    return ret;
}
Quote *baseP;
double undiscounted = baseP->Quote::net_price(42);
int main()
{
    Quote basic;
    Bulk_Quote bulk;
//    Disc_quote   disc; //error no object of abstract class
   // print_total(cout,basic,10);
   // print_total(cout,bulk,10);
}
double Bulk_Quote::net_price(size_t count) const
{
    if(count>=min_quantity)
        return count*(1-discount)*price;
    return count*price;
}

