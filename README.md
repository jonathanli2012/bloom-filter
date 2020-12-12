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



