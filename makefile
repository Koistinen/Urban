all: ddj unddj

ddj: main.c init.c hash.c backhash.c setpoint.c send.c sendbits.c shift.c sendbit.c flush.c head.h var.h
	gcc -O -o ddj main.c

unddj: main.c init.c hash.c backhash.c setpoint.c send.c sendbits.c shift.c sendbit.c flush.c head.h getbit.c var.h
	gcc -O -DUN -o unddj main.c