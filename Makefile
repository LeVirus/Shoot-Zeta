DEBUG=yes
ifeq ($(DEBUG),yes)
	CXXFLAGS=-std=c++11 -Wall -Wextra -pedantic -g
else
	CXXFLAGS=-std=c++11 -march=native -O2
endif

LDFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lCollision
CXX= g++ -fPIC
OBJ_DIR=objet/
SRC_DIR=Source/
INCLUDE_DIR=Header/
LIB_DIR=lib/
BIN_DIR=

SRC=$(wildcard $(SRC_DIR)*.cpp)
SRC_BIS=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC))
OBJ=$(SRC_BIS:.cpp=.o)

EXE=exe

all: $(EXE)

$(EXE):main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -L $(LIB_DIR) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE_DIR)%.hpp
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

.PHONY: clean mrproper

clean:
	rm -f $(OBJ_DIR)*.o

mrproper: clean
	rm -f $(EXE)
