#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

class BigInt
{
    private:
        char *digits;
        int size;
        int capacity;
        int sign;

    public:
        BigInt( int n, int cap );

        BigInt( int n );

        BigInt( long double d );

        BigInt();

        BigInt( string s );

        BigInt( const char s[] );

        BigInt( const BigInt &n );

        const BigInt &operator=( const BigInt &n );
        const BigInt &operator=( int n );

        ~BigInt();

        void normalize();

        static int sig( int n );

        static int sig( long double n );

        inline int length() { return size; }

        BigInt operator++();
        BigInt operator++( int );
        BigInt operator--();
        BigInt operator--( int );
        BigInt operator-();
        BigInt operator+ ( int n    );
        BigInt operator+ ( BigInt n );
        BigInt&operator+=( int n    );
        BigInt&operator+=( BigInt n );
        BigInt operator- ( int n    );
        BigInt operator- ( BigInt n );
        BigInt&operator-=( int n    );
        BigInt&operator-=( BigInt n );
        BigInt operator* ( int n    );
        BigInt operator* ( BigInt n );
        void   operator*=( int n    );
        void   operator*=( BigInt n );
        BigInt operator/ ( int n    );
        BigInt operator/ ( BigInt n );
        void   operator/=( int n    );
        void   operator/=( BigInt n );
        int    operator% ( int n    );
        BigInt operator% ( BigInt n );
        void   operator%=( int n    );
        void   operator%=( BigInt n );
        int divide( int n );
        BigInt divide( BigInt n );
        BigInt operator* ( long double n );
        void   operator*=( long double n );

        BigInt operator<< ( int n    );
        void   operator<<=( int n    );
        BigInt operator>> ( int n    );
        void   operator>>=( int n    );

        BigInt operator^  ( BigInt n );

        BigInt operator,( int n );
        BigInt operator,( BigInt n );

        bool operator!();
        operator bool();
        operator string();

        bool operator<( BigInt n );
        bool operator>( BigInt n );
        bool operator==( BigInt n );
        bool operator<=( BigInt n );
        bool operator>=( BigInt n );
        bool operator<( int n );
        bool operator>( int n );
        bool operator==( int n );
        bool operator<=( int n );
        bool operator>=( int n );
        int compare( BigInt n );

        int toInt();

        string toString();

        void print();

        void printWithCommas( ostream &out );

        string readNumberFromFile(const char *fileName, char flag = 's');

        void writeNumberToFilE(const char *fileName, BigInt &n, char flag);

    private:
        void grow();

        friend istream &operator>>( istream &in, BigInt &n );
        friend ostream &operator<<( ostream &out, BigInt n );
};
