#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import BigInt
def usage():
	print "\n1.txt op 2.txt out.txt -b\n"
	sys.exit(-1);

tmp = BigInt.BigInt();
itog = BigInt.BigInt();
b1 = "";
b2 = "";
binary = False;
if len(sys.argv) < 5 or len(sys.argv) > 6:
	usage();
elif len(sys.argv) == 6:
	if sys.argv[5] == "-b":
		binary = True;
	else:
			usage();
if binary == False:
		b1 = tmp.readNumberFromFile(sys.argv[1], 's');
		b2 = tmp.readNumberFromFile(sys.argv[3], 's');
else:
		b1 = tmp.readNumberFromFile(sys.argv[1],'b');
		b2 = tmp.readNumberFromFile(sys.argv[3]),'b';




if sys.argv[2] == "+":
	itog = BigInt.BigInt(b1) + BigInt.BigInt(b2);
elif sys.argv[2] == "-":
	itog = BigInt.BigInt(b1) - BigInt.BigInt(b2);
elif sys.argv[2] == "x":
	itog = BigInt.BigInt(b1) * BigInt.BigInt(b2);
elif sys.argv[2] == "/":
	itog = BigInt.BigInt(b1) / BigInt.BigInt(b2);
elif sys.argv[2] == "%":
	itog = BigInt.BigInt(b1) % BigInt.BigInt(b2);
elif sys.argv[2] == "^":
	itog = BigInt.BigInt(b1) ^ BigInt.BigInt(b2);
else:
	usage();

if binary == False:
	tmp.writeNumberToFilE(sys.argv[4], itog, 's');
else:
	tmp.writeNumberToFilE(sys.argv[4], itog , 'b');