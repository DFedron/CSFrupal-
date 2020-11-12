CXX = g++
CXXFLAGS = -lncurses

OBJS = main.o map.o hero.o

Frupal: $(OBJS)
	$(CXX) $(OBJS) -o Frupal $(CXXFLAGS)


main.o: main.cpp

map.o: map.h map.cpp

hero.o: hero.h hero.cpp

clean:
	rm *.o Frupal
