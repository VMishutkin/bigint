#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import bint as lib

def usage():
	print "\nИспользование: TCProgLab входной_файл1.txt (+-x/%^) входной_файл2.txt файл_результата.txt -b(бинарный режим, если необходимо)\n";
	sys.exit(-1);

b1 = lib.bint();
b2 = lib.bint();
b3 = lib.bint();

binary = False;

if len(sys.argv) < 5 or len(sys.argv) > 6:
	usage();
elif len(sys.argv) == 6:
	if sys.argv[5] == "-b":
		binary = True;
	else:
		usage();

if binary == False:
	b1 = lib.bint(b1.read(sys.argv[1]));
	b2 = lib.bint(b2.read(sys.argv[3]));
else:
	b1 = b1.readbin(sys.argv[1]);
	b2 = b2.readbin(sys.argv[3]);

if sys.argv[2] == "+":
	b3 = b1 + b2;
elif sys.argv[2] == "-":
	b3 = b1 - b2;
elif sys.argv[2] == "x":
	b3 = b1 * b2;
elif sys.argv[2] == "/":
	b3 = b1 / b2;
elif sys.argv[2] == "%":
	b3 = b1 % b2;
elif sys.argv[2] == "^":
	b3 = b1 ^ b2;
else:
	usage();

if binary == False:
	b3.write(b3.st(), sys.argv[4]);
else:
	b3.writebin(b3, sys.argv[4]);
