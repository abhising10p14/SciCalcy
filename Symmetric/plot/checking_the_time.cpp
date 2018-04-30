#include"Symmetric.cpp"
#include <iostream>
#include <time.h>
using namespace std;
int main()
{

  /********************************************************
	Declaring an Eigen:: Eigen::Matrix of size 100 by 100
	which stores number from 1 to 10000 repectively
  *********************************************************/
	cout<<"creation_Ei		"<<"creation_sy		"<<"multipli_my_my	"<<"multipli_sy_my"<<endl;
for (int i = 0;i<=40;i++)
{
	  Eigen::MatrixXd m_10(4,4);
	  //cout<<m_10<<endl<<endl;
	 clock_t start1 = clock();
	 m_10 << 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16;
	 clock_t stop1 = clock();
	 double elapsed1 = (double)(stop1 - start1) * 1000.0 / CLOCKS_PER_SEC;
	 //cout <<"The time to create the Eigen:: Eigen::Matrix is  is: \n";
	 //std::cout << elapsed1<<endl<<endl; 

	 Eigen::MatrixXd m_11(4,4);
	clock_t start4 = clock();
	m_11 = m_10;						//m_11 is same as m_10
	 clock_t stop4 = clock();
	double elapsed4 = (double)(stop4 - start4) * 1000.0 / CLOCKS_PER_SEC;


	clock_t start5 = clock();
	 Eigen::MatrixXd M_ans = m_11 * m_10;
	clock_t stop5 = clock();
	 double elapsed5 = (double)(stop5 - start5) * 1000.0 / CLOCKS_PER_SEC;
	
	/**************************************************
		Now checking for the Symmat:

	***************************************************/
	  //for sym * Eigen matrix
	 clock_t start3 = clock();
	  SymMat<double> s_10(m_10);
	  clock_t stop3 = clock();	
	 double elapsed3 = (double)(stop3 - start3) * 1000.0 / CLOCKS_PER_SEC;
	 
	 clock_t start2 = clock();
	   Eigen::MatrixXd m_prod = s_10*m_10;	
	 clock_t stop2 = clock();	
	 double elapsed2 = (double)(stop2 - start2) * 1000.0 / CLOCKS_PER_SEC;
	 cout<<elapsed1<<"		"<<elapsed3<<"		"<<elapsed5<<"		"<<elapsed2<<"\n";
	
  }
}