finalP3: series.o
	clang -o finalP3 series.o -lm
series.o: series.c
	clang -g -O0 -c series.c

clean:
	rm -f *.o

veryclean: clean
	rm -f finalP3
