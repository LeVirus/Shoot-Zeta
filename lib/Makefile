DEBUG_WARNING=yes

ifeq ($(DEBUG_WARNING), yes)
	CXXFLAGS=-std=c++11 -Wall -Wextra -pedantic -g
else
	CXXFLAGS=-std=c++11 -march=native -O2
endif

LDFLAGS= 
CXX= g++ -fPIC
OBJ_DIR=objets/
SRC_DIR=Sources/
INCLUDE_DIR=Headers/
LIB_DIR=.
BIN_DIR=.

SRC=$(wildcard $(SRC_DIR)*.cpp)
#wildcard pour pouvoir utiliser le joker *
SRC_BIS=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC)) 
#remplacer SRC_DIR par OBJ_DIR dans variable SRC
OBJ=$(SRC_BIS:.cpp=.o)
#remplacer .cpp par .o dans variable SRC_BIS
EXE=libCollision.so


all: $(EXE)

$(EXE):$(OBJ)
	$(CXX) -shared $(CXXFLAGS) $^ -I $(INCLUDE_DIR) -L $(LIB_DIR) $(LDFLAGS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE_DIR)%.hpp
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -c $<  $(LDFLAGS) -o $@

	
.PHONY: clean mrproper

clean:
	rm -f $(OBJ_DIR)*.o

mrproper: clean
	rm -f $(EXE)
