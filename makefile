forc: 
	g++ -fPIC -c BigInt.cpp
	g++ -shared -o libBigInt.so BigInt.o
	LD_LIBRARY_PATH=./ g++ main.cpp -lBigInt -I. -Wl,-rpath,. -L. -o test
	rm -f *.o
	
forp:
	swig -c++ -python BigInt.i
	g++ -fPIC -c BigInt.cpp
	g++ -fPIC -c BigInt_wrap.cxx -I/usr/include/python2.7
	g++ -shared BigInt.o BigInt_wrap.o -o _BigInt.so
	rm -f *.o
	rm BigInt_wrap.cxx
	
	
