LDFLAGS= -lsfml-graphics -lsfml-window -lsfml-system
SRC= Source
HEAD= Header
OBJ= objet
CXX= g++ -fPIC

exe: $(OBJ)/main.o $(OBJ)/Entite.o $(OBJ)/Tir.o $(OBJ)/Vaisseau.o $(OBJ)/VJoueur.o $(OBJ)/Niveau.o $(OBJ)/Jeu.o lib/libCollision.so
	$(CXX) -I lib/Headers -L lib $^ $(LDFLAGS) -o exe
$(OBJ)/main.o: $(SRC)/main.cpp
	$(CXX) -c $(SRC)/main.cpp -o $@
$(OBJ)/Entite.o: $(SRC)/Entite.cpp $(HEAD)/Entite.hpp
	$(CXX) -c $(SRC)/Entite.cpp -o $@
$(OBJ)/Vaisseau.o: $(SRC)/Vaisseau.cpp $(HEAD)/Vaisseau.hpp 
	$(CXX) -c $(SRC)/Vaisseau.cpp -o $@
$(OBJ)/VJoueur.o: $(SRC)/VJoueur.cpp $(HEAD)/Vaisseau.hpp 
	$(CXX) -c $(SRC)/VJoueur.cpp -o $@
$(OBJ)/Jeu.o: $(SRC)/Jeu.cpp $(HEAD)/Jeu.hpp
	$(CXX) -c $(SRC)/Jeu.cpp -o $@
$(OBJ)/Niveau.o: $(SRC)/Niveau.cpp $(HEAD)/Niveau.hpp 
	$(CXX) -c $(SRC)/Niveau.cpp -o $@
$(OBJ)/Tir.o: $(SRC)/Tir.cpp $(HEAD)/Tir.hpp 
	$(CXX) -c $(SRC)/Tir.cpp -o $@
	
clean:
	rm -f objet/*.o