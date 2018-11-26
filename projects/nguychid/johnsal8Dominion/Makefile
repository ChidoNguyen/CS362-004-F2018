CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

#Ass3 Testing#
unittest1: unittest1.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g unittest1.c dominion.o rngs.o -o unittest1

unittest2: unittest2.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g unittest2.c dominion.o rngs.o -o unittest2

unittest3: unittest3.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g unittest3.c dominion.o rngs.o -o unittest3

unittest4: unittest4.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g unittest4.c dominion.o rngs.o -o unittest4

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g cardtest1.c dominion.o rngs.o -o cardtest1

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g cardtest2.c dominion.o rngs.o -o cardtest2

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g cardtest3.c dominion.o rngs.o -o cardtest3

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g cardtest4.c dominion.o rngs.o -o cardtest4

unittestresults: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 > unittestresults.out
	echo >>unittestresults.out
	./unittest2 >> unittestresults.out
	echo >>unittestresults.out
	./unittest3 >> unittestresults.out
	echo >>unittestresults.out
	./unittest4 >> unittestresults.out
	echo >>unittestresults.out
	./cardtest1 >> unittestresults.out
	echo >>unittestresults.out
	./cardtest2 >> unittestresults.out
	echo >>unittestresults.out
	./cardtest3 >> unittestresults.out
	echo >>unittestresults.out
	./cardtest4 >> unittestresults.out
	echo >>unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	echo >>unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestadventurer: randomtestadventurer.c rngs.o dominion.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g randomtestadventurer.c dominion.o rngs.o -o randomtestadventurer
randomtestadventurer.out: randomtestadventurer
	./randomtestadventurer > randomtestadventurer.out
	echo >> randomtestadventurer.out
	gcov -b -f randomtestadventurer.c >> randomtestadventurer.out
	echo >>randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	
randomtestcard1: randomtestcard1.c rngs.o dominion.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g randomtestcard1.c dominion.o rngs.o -o randomtestcard1
randomtestcard1.out: randomtestcard1
	./randomtestcard1 > randomtestcard1.out
	echo >> randomtestcard1.out
	gcov -b -f randomtestcard1.c >> randomtestcard1.out
	echo >>randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out
	
randomtestcard2: randomtestcard2.c rngs.o dominion.o
	gcc -fprofile-arcs -ftest-coverage ${CFLAGS} -g randomtestcard2.c dominion.o rngs.o -o randomtestcard2
randomtestcard2.out: randomtestcard2
	./randomtestcard2 > randomtestcard2.out
	echo >> randomtestcard2.out
	gcov -b -f randomtestcard2.c >> randomtestcard2.out
	echo >>randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out
	

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
