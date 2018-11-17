# Parallel_programming_UPV

Repository contains tasks for parallel classes on UPV. 
Programs are written in C with OpenMP and MPI libraries.

## Task
Tasks are written in cpa-p*.pdf files.

## Object
Obcject of two first projects is to learn parallisation of loops, using differents schedulings and parallel sections, with measuring execution time.

Object of rest projects is to learn parallesation using Message-Passing Model.

## Building
$ gcc -fopenmp -Wall -o program_output program.c -lm

## Requirements
- C compatible compiler
- OpenMP library
- MPI library
- Multi core processor


## Running
As programs requariers many threads it is advised to run with the OMP NUM THREADS environment variable as follows: 

$ OMP_NUM_THREADS=n ./program 

