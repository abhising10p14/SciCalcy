#include"Symmetric.cpp"
#include <iostream>


int main()
{
  Eigen:: MatrixXd m(4,4);
// Can be stored in this formt also:
  m << 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16;
  std::cout<<"m :"<<"\n"<<m<<"\n"<<"\n";
/* simillar to m =
                   1  2  3  4
                   5  6  7  8
                   9  10 11 12
                   13 14 15 16 
*/



  Eigen:: Matrix<float,4,4>mi_7;                            //You can also pass a float type Eigen::Eigen:: Matrix
  mi_7 << 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16;
  std::cout<<"mi_7 :"<<"\n"<<mi_7<<"\n"<<"\n";
  SymMat<float> sandy(mi_7); 
  std::cout<<"Sandy:\n"<<sandy;  


  Eigen:: MatrixXd m2(4,4);
  m2 << -1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16;
  std::cout<<"m2:\n"<<m2<<"\n"<<"\n";
  SymMat<double> s(m);                                  //The data type of both the SymMat must be same
  SymMat<double> s2(m2);
  std::cout<<"s SymMat matrix is: \n"<<s;                     //prints the SymMat matrix 
  


  /********************************************************
  Testng for the Addition
  *********************************************************/
  

  std::cout<<"s(1,2): "<<s(1,2)<<"\n"<<"\n";            //To access the s(i,j) simillar to the accessor of Eigen::Eigen:: Matrix 
                        
 SymMat<double> s_temp = s;                            //checking the = operator
 std::cout<<s_temp<<"\n";
  SymMat<double> s3  = s + s;                           //Addition of Two SymMat
 std::cout<<s3<<"\n";
                                                        
  Eigen:: MatrixXd m3(4,4);
  m3  = s + m;                                           //Addition of SymMat and Eigen::Eigen:: Matrix
  std::cout<<"s is:"<<"\n"<<s<<"\n"<<"\n";                    
  std::cout<<"s+m = m3 is : "<<"\n"<<m3<<"\n"<<"\n";

  
/********************************************************
  Testng for the Difference
  *********************************************************/

  SymMat<double> s4  = s3 - s2;                          //Difference of Two SymMat
  
  std::cout<<"The s3 SymMat matrix is:\n"<<s3<<"\n";
  Eigen:: MatrixXd m4(4,4);
  m4  = s - m;                                           //Difference of SymMat and Eigen::Eigen:: Matrix
  std::cout<<"s SymMat matrix is: \n"<<s;
  std::cout<<"m is:"<<"\n"<<m<<"\n"<<"\n";
  std::cout<<"s-m = m4 is : "<<"\n"<<m4<<"\n"<<"\n";

  
  /********************************************************
  Testng for the Multipliction
  *********************************************************/


  Eigen:: MatrixXd m5 = s3*m;                                    //SymMat * Eigen::Eigen:: Matrix
  std::cout<<"m5 = s3*m :"<<"\n"<<m5<<"\n"<<"\n";        

   Eigen:: MatrixXd m6 = s3*s;                                   //SymMat * Eigen::Eigen:: Matrix
   std::cout<<"m6 = s3*s :"<<"\n"<<m6<<"\n"<<"\n";       


   /*****************************************
    testing for:
    1.transopse()
    2.transposeInPlace()

   ******************************************/
   std::cout<<"s3 : \n"<<s3<<"\n s3': \n"<<s3.transpose();
   std::cout<<"\n"<<"s3' inplace : \n"<<s3.transposeInPlace();

   /*****************************************
    testing for the:
    trace();

   ******************************************/
   std::cout<<"trace: \n"<<s3.trace()<<"\n";
}


