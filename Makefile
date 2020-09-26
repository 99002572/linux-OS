all:	Sender	receiver
Sender:	Sender.c
	gcc Sender.c -o Sender -lpthread
receiver:	reciever.c
	gcc receiver.c -o receiver -lpthread
