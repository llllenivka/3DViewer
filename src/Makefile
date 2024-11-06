GCC = g++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++17

#sources viewer
FILES_BACK = ./Model/parser/parser.cc ./Model/strategy/strategy.cc
FILES_BACK_H = ./Model/parser/parser.h ./Model/strategy/strategy.h ./Model/*.h
SOURCES_TEST = ./Test/test_parser.cc ./Test/test_strategy.cc
SOURCES_VIEW_CPP = ./View/*.cpp ./Controller/controller.cpp
SOURCES_VIEW_H = ./View/*.h ./Controller/controller.h



OS = $(shell uname)

ifeq ($(OS),Linux)
    det_OS = -lgtest  -lm -lrt -lpthread -lsubunit
	project = View.pro
	inst_desk = cd View && qmake && make && rm Makefile && mkdir -p ./../../build && mv $(project) $(UI_BIN) ./../../build/
else
    det_OS = -lgtest -lm -lpthread
	project = View.app
	inst_desk = cd View && qmake && make && rm Makefile && mkdir -p ./../build && mv $(project) $(UI_BIN) ./../build/
endif

all: uninstall clean install dist dvi test gcov_report fix_clang_viewer clang_check

install: 
	$(inst_desk)

dvi:
	open ./documentation.md

dist: install
	mkdir dist_3d_viewer
	tar -czvf dist_3d_viewer/3Dviewer_the_archive.tgz ./build/View.app documentation.md

uninstall:
	rm -rf build

test: clean
	$(GCC) $(CPP_FLAGS) --coverage $(SOURCES_TEST) $(FILES_BACK) -o tests $(det_OS)
	./tests
	rm -rf temp_test_file.obj

gcov_report: clean test
	lcov -t "result" -o res.info  --ignore-errors inconsistent -c -d .
	lcov --remove res.info /c++/13 /usr/local/include/gtest -o filtered_coverage.info
	genhtml -o report filtered_coverage.info
	open report/index.html

fix_clang_viewer:
	cp ../materials/linters/.clang-format .
	clang-format -style=Google -i $(FILES_BACK) $(SOURCES_TEST) $(SOURCES_VIEW_CPP) $(SOURCES_VIEW_H) $(FILES_BACK_H)
	rm .clang-format

clang_check:
	cp ../materials/linters/.clang-format .
	clang-format -style=Google -n $(FILES_BACK) $(SOURCES_TEST) $(SOURCES_VIEW_CPP) $(SOURCES_VIEW_H) $(FILES_BACK_H)
	rm .clang-format

clean:
	rm -rf tests report *.gc* *.o *.info *.a tests build dist_3d_viewer ./Model/parser/*.o ./Model/strategy/*.o ./Test/*.o

rebuild: clean all
