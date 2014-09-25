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

    try
    {
        switch ( operation )
        {
            case '+' : {
                    BigInt res = BigInt( firstNumber ) + BigInt( secondNumber );
                    tmp.writeNumberToFilE(resultFile.c_str(), res, flag);
                } break;
            case '-' : {
                    BigInt res = BigInt( firstNumber ) - BigInt( secondNumber );
                    tmp.writeNumberToFilE(resultFile.c_str(), res, flag);
                } break;
            case 'x' : {
                    BigInt res = BigInt( firstNumber ) * BigInt( secondNumber );
                    tmp.writeNumberToFilE(resultFile.c_str(), res, flag);
                } break;
            case '/' : {
                    if ( BigInt( secondNumber ) == 0 )
                        throw out_of_range( "Division by zero" );
                    BigInt res = BigInt( firstNumber ) / BigInt( secondNumber );
                    tmp.writeNumberToFilE(resultFile.c_str(), res, flag);
                } break;
            case '%' : {
                    BigInt res = BigInt( firstNumber ) % BigInt( secondNumber );
                    tmp.writeNumberToFilE(resultFile.c_str(), res, flag);
                } break;
            case '^' : {
                    if ( BigInt( secondNumber ) < 0 )
                        throw out_of_range( "a^(-b)" );
                    BigInt res = BigInt( firstNumber ) ^ BigInt( secondNumber );
                    tmp.writeNumberToFilE(resultFile.c_str(), res, flag);
                } break;
        }
    }
    catch ( exception &e )
    {
        cout << "What? " << e.what() << endl;
        usage();
    }

    return 0;
}
