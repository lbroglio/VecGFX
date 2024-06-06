test: vec.o mat.o test.o util.o
	g++ bin/vec.o bin/mat.o bin/test.o bin/util.o -o bin/test -lcppunit

util.o: bin lib/util.cpp lib/util.hpp
		g++ lib/util.cpp -o bin/util.o -c 

test.o: bin test/vgfxTest.cpp
	g++ test/vgfxTest.cpp -o bin/test.o -c 

vec.o: bin lib/vec.cpp lib/vec.hpp
	g++ lib/vec.cpp -o bin/vec.o -c

mat.o: bin lib/mat.cpp lib/mat.hpp
	g++ lib/mat.cpp -o bin/mat.o -c

bin: 
	mkdir bin

clean:
	rm -rf bin 

docu:
	rm -rf docs
	doxygen config/docConfig
	for file in docs/man/VecGFX.3/* ; do \
        gzip -k $$file; \
		sudo cp $$file.gz /usr/share/man/man3; \
		rm $$file.gz; done \
