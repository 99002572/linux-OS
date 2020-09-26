all:	Sender	receiver	main
Sender:	Sender.c
	gcc Sender.c -o Sender -lpthread
receiver:	receiver.c
	gcc receiver.c -o receiver -lpthread
main:	main.c
	gcc main.c -o main -lpthread
