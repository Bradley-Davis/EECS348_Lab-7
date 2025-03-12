CC := gcc

football.exe: football_main.c football.c football.h
	$(CC) -o football.exe football_main.c football.c

report.exe: report_main.c report.c report.h
	$(CC) -o report.exe report_main.c report.c