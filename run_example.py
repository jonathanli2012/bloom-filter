import os
import subprocess

#add_count < 1000


def write_test_file(file_name, add_count, b_size):
    open('test.cpp', 'w').close()
    file1 = open('test/names.txt', 'r')
    names = file1.readlines()

    with open(file_name, 'a') as f:
        print("#include \"src/bloom.h\"", file=f)
        print("#include \"src/cityhash/city.h\"", file=f)
        print("#include <iostream>", file=f)
        print("\nusing namespace std;", file=f)
        print("\nint main() {", file=f)
        print("  BloomFilter *new_b = new BloomFilter(" + str(b_size) + ");", file=f)
        for i in range(0, add_count):
            print("  new_b->add_string(\"" + names[i][:-1] + "\");", file=f)
        print("  std::cout << \"filter print: \" << new_b->expose_filter() << \"\\n\";", file=f)
        for i in range(0, 1000):
            print("  std::cout << \"filter lookup: \" << \"" +
                  names[i][:-1] + " \" << new_b->lookup(\"" + names[i][:-1] + "\") << \"\\n\";", file=f)
        print("  return 0;", file=f)
        print("}", file=f)


add_count = int(input("input value 1-999 for strings inserted: "))
b_size = int(input("input value for bloom filter size: "))

write_test_file("test.cpp", add_count, b_size)

os.system("g++ src/cityhash/city.cc src/bloom.cpp test.cpp")

os.system("./a.out > export.txt")

os.remove("test.cpp")
os.remove("./a.out")

file1 = open('export.txt', 'r')
names = file1.readlines()

print("") #new line
count = 0
for i in names:
    if(i.startswith("filter lookup:")):
        if(i.endswith("1\n")):
            count += 1

correct = True
for i in names[1:add_count + 1]:
    if(i.endswith("0\n")):
      print("filter correctness test failed")
      correct = False

if(correct):
  print("filter correctness test passed")
            

print("filter lookup miss rate: " + str((count - add_count)/(1000-add_count)))
print("filter lookup miss count: " + str(count - add_count))
