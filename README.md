# C++ Bloom Filter
C++ Bloom Filter implementation

## Usage
Compiles a command line interface "./bloom" with insert/lookup/print filter functionality
```
$ make
```
or
```
$ make bloom
```
./bloom takes one command line argument <filter_size>
```
$ ./bloom 42
```
Running bloom with <42> allocates a new bloom filter with size 42*64 bits.
```
$ ./bloom 42
> i dog
> i cat
> l dog
TRUE
> p filter
00001000...
```
> i <string>: inserts the specified string into the bloom filter
  
> l <string>: lookups the specified string in the bloom filter
  
> p: prints all the bits in the bloom filter
## Test
Includes user defined test cases inserting 0-1000 words with piped output to export.txt
```
$ python3 run_example.py
```
Additional tests can be compiled using
```
$ make src_test
```
Because this package is lightweight, compiling with -Ofast will garner best results
## Cleanup
```
$ make clean
```
## Notes
This implementation uses google's cityhash which is included in the src/cityhash directory



