########################################
##
## Makefile
## LINUX compilation 
##
##############################################





#FLAGS
C++FLAG = -g -std=c++0x -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.





#Rule for .cpp files
# .SUFFIXES : .cpp.o 

.cpp.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@




#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#ZEROTH PROGRAM
ALL_OBJ0=TestPolynomial.o
PROGRAM_0=TestPolynomial
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

#FIRST PROGRAM
#ALL_OBJ1=TestLinkedBag.o
#PROGRAM_1=TestLinkedBagProgram
#$(PROGRAM_1): $(ALL_OBJ1)
#	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)

#SECOND PROGRAM
#ALL_OBJ2=TestLinkedBag2.o
#PROGRAM_2=TestLinkedBagProgram2
#$(PROGRAM_2): $(ALL_OBJ2)
#	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ2) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM_0)
#		make $(PROGRAM_1)
#		make $(PROGRAM_2)

#Clean obj files

clean:
	(rm -f *.o;)



(:
