Symmetric-Matrix
--------------------------------------------------------------------------------------------------------------
This repository deals with the problem of reducing  space complexity of Symmetric Matrix using Eigen
(a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms).
Both the Upper and Lower Triangular matrices of a Symmetric Matrix are identical. Therefore a huge amount of
memory can be saved if only one of the upper and lower triangular matrix is stored(upper Triangular matrix 
in this case).

Suppose there is Symmetric Square Matrix of size 10^19 by 10^19. And let's assume that it stores double values
in it. As a single double value is of 8 bytes, total amount of memory used if we store all the elements of this matrix is 8x10^38 bytes which is =~ 6.4 × 10^27 Tb and on and on .................
So, It can be seen that around 3.2 × 10^27 Tb of memory will be saved if we  save the space by just storing the upper or lower triangular part of a Symmetric Matrix and could perform all the basic Matrix arithmetic easily.


This is the [link](https://github.com/StewMH/GSoC2018/blob/master/evaluation_test.pdf) for the evaluation test.
This is [link](https://github.com/abhising10p14/Symmetric-Matrix/blob/master/Project_proposal.pdf) for the project Proposal
 

How it is being implemented?
----------------------------------------------------------------------------------------------------------------
A standalone C++ class for a symetric matrix(SymMat in this case) has been created. It is simmilar to 
the Eigen::Matrix class of Eigen library.
The class consists of the following function:
1. A constructor to make a SymMat from an Eigen::Matrix
2. Accessors for S(i,j): S(j,i) should of course return the same as S(i,j). where S is a Symmetric matrix.
3. Functions for matrix addition:

   (i)  SymMat +/- SymMat
   (ii) SymMat +/- Eigen::Matrix
4. Functions for matrix multiplication:

   (i)  SymMat∗SymMat
   (ii) SymMat∗Eigen::Matrix


**It has been assumed that the user provides anEigen::Matrix from which a symmetric matrix has to be extracted and stored.**

This repository consists of the following folders:
-----------------------------------------------------------------------------------------------------------------
1. src :  It consists of the header file Symmetric.h and the source file  Symmetric.cpp:

   i) C++ header file Symmetric.h

   The Header file consist of a SymMat class whose members have been described in the comments in the file itself.
   The SymMat class consist of the following memebers :

   1. **```_Rows```**								     The Number of Rows
   2. **```_Cols```**									 The Number of Columns which is same as number of rows
   3. **```std::vector  Scalar symmatrix```**			 To store the upper Diagonal only. It reduces  the storage
   4. **```SymMat()```**							     Default Constructor
   5. **```SymMat(Eigen::Matrix<type,r,c>M)```**  		 Parameterized Constructors , type is the data type of
   														 Eigen::Matrix
   6. **```_Scalar  operator()(ll i,ll j)```**			 The S(i,j) operator
   7. **```operator <<(ostream &out, const SymMat<Y> & m)```**  '<<' Operator overloading for output of the matrix 
   																   Same as the cout<< m ;(where m is a Eigen::Matrix)
   8. **Other operator overloadings like =,-,+,* etc**

   ii) A C++ source file Symmetric.cpp

	The source file consists of the implementation of all the member function of the class SymMat as well as the operator overloading declared in the class.
    There is one important thing to note in the source file that for the multiplication of SymMat with Eigen::Matrix, two methods have been used. If the size of the matrices is >=50(this benchmark can be changed) and the code compiles under c++11, the multiplication happens using 4 threads. If the size if the matrices is less than 50, or if the code doesn't cmpiles under c++11 but under c++98, then the basic method for multiplication runs.
    This has been done because that the multithreading option is requiured only if the size of the matrices are large. For smaller matrices, single thread works fine. This can be seen in the plot provided.
2. test: It consists of the unit test file test_file.cpp

	This test file contains all the required test cases which checks the utility of all the inbuilt functions where both the SymMat and the Eigen::Matrix have been used.

3. plot :

          This folder contains the files checking_the_time.cpp,data_of_time,plot_1&2.py
          These files have been used to compare the speed of multithreading with 4 threads  with the speed of Eigen::Matrix functions. The file checking_the_time.cpp compares the time taken for performing operations like multiplications of very large sized matrices. The results have been saved as .png files.
   
4. multi_threading : This explains how the multithreading has been implemented.

5. build : 
      
          This is an empty directory which uses the file CMakeLists.txt to build a static library which can be used by other 
          users. To build this library perform the following steps.
          

          Make sure you have CMake installed on your system. If not then just paste the following command in the cmd:**
            
            sudo apt-get install cmake
            This will install Cmake on your system.

            After this go to this directory and do the following steps to build this library on your system:

            cd build
            cmake ..
            make
            sudo make install

            You are ready to use this library by just including "Symmetric.cpp" in your program.
          

How to use this class and compile it?
--------------------------------------------------------------------------------------------------------------------

To use this class you just have to include this following in your main program.
   
   #include"Symmetric.cpp"

And then to run/compile a file type :
**```g++  file_name.cpp```**

   To create an object of the SymMat class 
   SymMat<_Scalar> s2(m);
   
   Here, _Scalar can be any datatype supported in the C++
   	     m is the Eigen::matrix which is  provided by the user and from which Symmetric  matrix has to be extracted.
   	 e.g

   	 	Eigen::MatrixXd m(4,4);
   	 	SymMat<double> s(m);
   	 		
**You can pass any type of Eigen::Matrix as argument to the SymMat constructor**



 
**If fatal error:Eigen/Dense: No such file or directory
	occurs  while compiling, then comment the line:
	#include <eigen3/Eigen/Dense>  
	and	remove the comment from:
	#include <Eigen/Dense> from the file Symmetric.h**



**Current Limitations:**

Currently, very basic algorithms have been implemented for the test evaluation point of purpose.And due to which the time copmlexity of several Operations like multiplication is cubic
 
The output of the file **checking_the_time.cpp** indicates that currently the multiplication of SymMat class isn't as efficient as the Eigen:: Matrix. So the current need is to use faster Matrix Multiplication methods liked BLASS GEMM, BLIS etc.

 But there are lots of  functions as well as a lot of optimization is needed to be made to the Symmetric Matrix operation. 
Functions like:

      .dot()
      .vector()
      .mean()
      .trace()
      .minCoeff()
      .maxCoeff()
      .transpose()
      .noalias()
      .Random()
      Constant()
      Zero()

Operations like :
   
     Joining of two Symmetric Matrices together
     Multithreading in case of large multiplications
     has to be implemented



**Update 1:  
I have updated the multiplication function of SymMat with a Eigen::Matrix. I have used multithreading this time to reduce the time required for multiplication of larger metrices.
Earlier,  to multiply one SymMat with an Eigen:: Matrix of size 100 by 100, time taken was 317.748 milliseconds
And now, After using four threads for the same purpose, it takes 232.278 millisecond i.e a decrease in initial time by 27%.
 I am looking for more better methods than the current method. My current approach is to use the CBLASS and the LAPACK for matrix operation.**



# Turns out that my proposal hasn't been selected in the Gsoc 2018. Though I feel demotivated and sad as I put a lot of hard work and hope in this, but on the other hand I feel happy as I learnt a lot from it. The markdown language, ways to write a good project proposal, how to talk to the mentors, multithreading and a lot more. I learnt that just writing a simple logic in your code isn't coding actually. You have to check and work on other constraints too.


**Any sort of Advice or Suggestion regarding this project is always welcome**


      




	

