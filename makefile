FILES :=                            \
    darwin-tests/ryw86-RunDarwin.in   \
    darwin-tests/ryw86-RunDarwin.out  \
    darwin-tests/ryw86-TestDarwin.c++ \
    darwin-tests/ryw86-TestDarwin.out \
    Darwin.c++                      \
    Darwin.h                        \
    Darwin.log                      \
    html                            \
    RunDarwin.c++                   \
    RunDarwin.out                   \
    TestDarwin.c++                  \
    TestDarwin.out

CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
# GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

darwin-tests:
	git clone https://github.com/cs371p-spring-2016/darwin-tests.git

html: Doxyfile Darwin.h Darwin.c++ RunDarwin.c++ TestDarwin.c++
	doxygen Doxyfile

Darwin.log:
	git log > Darwin.log

Doxyfile:
	doxygen -g

RunDarwin: Species.h Creature.h Creature.c++ Darwin.h Darwin.c++ RunDarwin.c++
	$(CXX) $(CXXFLAGS) $(GPROFFLAGS) Creature.c++ Darwin.c++ RunDarwin.c++ -o RunDarwin

RunDarwin.tmp: RunDarwin
	./RunDarwin > RunDarwin.tmp
	diff RunDarwin.tmp RunDarwin.out
	# $(GPROF) ./RunDarwin

TestDarwin: Species.h Creature.h Creature.c++ Darwin.h Darwin.c++ TestDarwin.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Creature.c++ Darwin.c++ TestDarwin.c++ -o TestDarwin $(LDFLAGS)

TestDarwin.tmp: TestDarwin
	$(VALGRIND) ./TestDarwin                                      >  TestDarwin.tmp 2>&1
	$(GCOV) -b Creature.c++     | grep -A 5 "File 'Creature.c++'"     >> TestDarwin.tmp
	$(GCOV) -b Darwin.c++     | grep -A 5 "File 'Darwin.c++'"     >> TestDarwin.tmp
	$(GCOV) -b TestDarwin.c++ | grep -A 5 "File 'TestDarwin.c++'" >> TestDarwin.tmp
	cat TestDarwin.tmp

check:
	@not_found=0;                                 \
    for i in $(FILES);                            \
    do                                            \
        if [ -e $$i ];                            \
        then                                      \
            echo "$$i found";                     \
        else                                      \
            echo "$$i NOT FOUND";                 \
            not_found=`expr "$$not_found" + "1"`; \
        fi                                        \
    done;                                         \
    if [ $$not_found -ne 0 ];                     \
    then                                          \
        echo "$$not_found failures";              \
        exit 1;                                   \
    fi;                                           \
    echo "success";

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunDarwin
	rm -f RunDarwin.tmp
	rm -f TestDarwin
	rm -f TestDarwin.tmp

config:
	git config -l

log: Darwin.log

scrub:
	make clean
	rm -f  Darwin.log
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: RunDarwin.tmp TestDarwin.tmp

tests: darwin-tests
