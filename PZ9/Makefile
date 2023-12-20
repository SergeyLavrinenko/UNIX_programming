all: mem_test_1 mem_test_2 mem_test_3 check_sanitizer clean

mem_test_1:mem_test_1.o
	g++ mem_test_1.o -o mem_test_1 -fsanitize=address -static-libasan
mem_test_1.o:mem_test_1.cpp
	g++ -c mem_test_1.cpp -fsanitize=address -g

mem_test_2:mem_test_2.o
	g++ mem_test_2.o -o mem_test_2 -fsanitize=address -static-libasan
mem_test_2.o:mem_test_2.cpp
	g++ -c mem_test_2.cpp -fsanitize=address -g

mem_test_3:mem_test_3.o
	g++ mem_test_3.o -o mem_test_3 -fsanitize=address -static-libasan
mem_test_3.o:mem_test_3.cpp
	g++ -c mem_test_3.cpp -fsanitize=address -g

check_sanitizer:check_sanitizer.o
	g++ check_sanitizer.o -o check_sanitizer -fsanitize=address -static-libasan
check_sanitizer.o:check_sanitizer.cpp
	g++ -c check_sanitizer.cpp -fsanitize=address -g

clean:
	rm -rf *.o 