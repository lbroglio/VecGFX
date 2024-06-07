CC= g++
LIBNAME= vecgfx
FLAGS= -Wall -Werror -fPIC
OBJECTS= bin/vec.o bin/mat.o bin/util.o
TEST_OBJECTS = bin/vgfxTest.o
VERSION= 0.1.0

.PHONY: clean docu dist installDocu

dist: bin/lib$(LIBNAME).so

install: bin/lib$(LIBNAME).so installDocu
	sudo cp bin/lib$(LIBNAME).so /usr/lib/aarch64-linux-gnu/lib$(LIBNAME).so
	if [ ! -d "/usr/include/$(LIBNAME)" ]; then \
		sudo mkdir /usr/include/$(LIBNAME); fi; \
	for file in lib/*.hpp; do \
		sudo cp $$file /usr/include/$(LIBNAME)/$${file##*/}; done\

installDocu:
	for file in docs/man/VecGFX.3/* ; do \
        gzip -k $$file; \
		sudo cp $$file.gz /usr/share/man/man3; \
		rm $$file.gz; done \

bin/lib$(LIBNAME).so: $(OBJECTS)
	$(CC) $^  -shared -Wl,-soname,lib$(LIBNAME).so -o bin/lib$(LIBNAME).so

test: $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(TEST_OBJECTS) -o bin/test -lcppunit

$(OBJECTS): bin/%.o : lib/%.cpp bin
	$(CC) $(FLAGS) -c $< $(LIB_PATH) $(LIBS) -o $@

$(TEST_OBJECTS): bin/%.o : test/%.cpp bin
	$(CC) $(FLAGS) -c $< $(LIB_PATH) $(LIBS) -o $@

bin: 
	mkdir bin

clean:
	rm -rf bin 

docu:
	rm -rf docs
	doxygen config/docConfig