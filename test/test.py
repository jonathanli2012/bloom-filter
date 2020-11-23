import os
import subprocess

#add_count < 1000

def write_test_file(file_name, add_count):
  open('test.cpp', 'w').close()
  file1 = open('names.txt', 'r') 
  names = file1.readlines()

  with open(file_name, 'a') as f:
    print("#include \"bloom.h\"", file= f)
    print("#include \"city.h\"", file= f)
    print("#include <iostream>", file= f)
    print("\nusing namespace std;", file= f)
    print("\nint main() {", file= f)
    print("  BloomFilter *new_b = new BloomFilter(128);", file= f)
    for i in range(0, add_count):
      print("  new_b->add_string(\"" + names[i][:-1] + "\");", file= f)
    print("  std::cout << \"filter print: \" << new_b->expose_filter() << \"\\n\";", file= f)
    for i in range(add_count,1000):
      print("  std::cout << \"filter lookup: \" << \"" + names[i][:-1] + " \" << new_b->lookup(\"" + names[i][:-1] + "\") << \"\\n\";", file= f)
    print("  return 0;",file= f)
    print("}",file=f)
    

write_test_file("test.cpp", 100)

os.system("g++ city.cc bloom.cpp test.cpp")

os.system("./a.out > data.txt")