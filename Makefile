
FinalProject: FinalProject.o test_FinalProject.o
	gcc test_FinalProject.o FinalProject.o -o FinalProject

FinalProject.o: FinalProject.c FinalProject.h
	gcc -c FinalProject.c

test_FinalProject.o: test_FinalProject.c FinalProject.h
	gcc -c test_FinalProject.c
