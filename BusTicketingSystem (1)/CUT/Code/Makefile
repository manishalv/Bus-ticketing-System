a.out : main.o displaySeatMatrix.o displayRoutes.o displayFareMatrix.o bookTickets.o displayTickets.o
	gcc main.o displaySeatMatrix.o displayRoutes.o displayFareMatrix.o bookTickets.o displayTickets.o -o a.out

main.o: src/main.c include/header.h
	gcc -c src/main.c

displaySeatMatrix.o : src/displaySeatMatrix.c include/header.h
	gcc -c src/displaySeatMatrix.c

displayRoutes.o : src/displayRoutes.c 
	gcc -c src/displayRoutes.c

displayFareMatrix.o :src/displayFareMatrix.c
	gcc -c src/displayFareMatrix.c

bookTickets.o: src/bookTickets.c include/ticket.h
	gcc -c src/bookTickets.c

displayTickets.o:src/displayTickets.c 
	gcc -c src/displayTickets.c

clean :
	rm *.o 
	rm a.out
	rm ./data/ticket.txt

