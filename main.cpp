#include "BigInt.h"

void usage()
{
    cout << "Usage: file_1 +-x/%^ file_2 file_3 [ - b ]" << endl;

    exit(-1);
}

int main( int argc, char *argv[] )
{
    string firstFile, secondFile, resultFile;
    BigInt tmp;

    char flag = 's';
    char operation;

    if (argc > 6 || argc < 5)
        usage();
    else
    {
        firstFile = argv[ 1 ];
        secondFile = argv[ 3 ];
        resultFile = argv[ 4 ];
        operation = argv[ 2 ][ 0 ];
        if ( argc == 6 )
            flag = argv[ 5 ][ 1 ];
    }
    
    string firstNumber = tmp.readNumberFromFile( firstFile.c_str(), flag );
    string secondNumber = tmp.readNumberFromFile( secondFile.c_str(), flag );
	BigInt res;
    try
    {
        switch ( operation )
        {
            case '+' : {
                    res = BigInt( firstNumber ) + BigInt( secondNumber );
                } break;
            case '-' : {
                    res = BigInt( firstNumber ) - BigInt( secondNumber );
                } break;
            case 'x' : {
                    res = BigInt( firstNumber ) * BigInt( secondNumber );
                } break;
            case '/' : {
                    if ( BigInt( secondNumber ) == 0 )
                        throw out_of_range( "Division by zero" );
                    res = BigInt( firstNumber ) / BigInt( secondNumber );
                } break;
            case '%' : {
                    res = BigInt( firstNumber ) % BigInt( secondNumber );
                } break;
            case '^' : {
                    if ( BigInt( secondNumber ) < 0 )
                        throw out_of_range( "a^(-b)" );
                    res = BigInt( firstNumber ) ^ BigInt( secondNumber );
                } break;
        }
    }
    catch ( exception &e )
    {
        cout << "What? " << e.what() << endl;
        usage();
    }
	tmp.writeNumberToFilE(resultFile.c_str(), res, flag);
    return 0;
}
