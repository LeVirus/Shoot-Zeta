SRC= Sources
HEAD= Headers
OBJ= objets
CXX= g++ -fPIC

libCollision.so: $(OBJ)/Point.o $(OBJ)/Figure.o $(OBJ)/Cercle.o $(OBJ)/Polygone.o 
	$(CXX) -shared  -o $@ $^
$(OBJ)/Point.o: $(SRC)/Point.cpp $(HEAD)/Point.hpp
	$(CXX) -c $(SRC)/Point.cpp -o $@
$(OBJ)/Figure.o: $(SRC)/Figure.cpp $(HEAD)/Figure.hpp  
	$(CXX) -c $(SRC)/Figure.cpp -o $@
$(OBJ)/Cercle.o: $(SRC)/Cercle.cpp $(HEAD)/Cercle.hpp
	$(CXX) -c $(SRC)/Cercle.cpp -o $@
$(OBJ)/Polygone.o:$(SRC)/Polygone.cpp $(HEAD)/Polygone.hpp  
	$(CXX) -c $(SRC)/Polygone.cpp -o $@
	
clean:
	rm -f objet/*.o 
