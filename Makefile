src_test: 
	g++ -g -Wall -o src_test src/cityhash/city.cc src/bloom.cpp src/main_example.cpp

clean: 
	$(RM) src_test
	$(RM) export.txt
