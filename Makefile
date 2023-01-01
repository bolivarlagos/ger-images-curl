all:
	gcc -o main.o main.c -lcurl

clean:
	rm *.o
	rm *.png
