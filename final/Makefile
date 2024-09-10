all: program.exe

program.exe: sensor_data.o report.o
	gcc -Wall -Wextra -std=c99 -o program.exe sensor_data.o report.o

sensor_data.o: sensor_data.c sensor_data.h
	gcc -Wall -Wextra -std=c99 -c sensor_data.c

report.o: report.c sensor_data.h
	gcc -Wall -Wextra -std=c99 -c report.c

clean:
	del /Q *.o program.exe
