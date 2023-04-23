#include <iostream>
#include <cassert>
#include <numeric>
#include <stdexcept>
#include <random>
using namespace std;


constexpr int const_3 = 3;
constexpr double half = 0.5;

static_assert(half < const_3,"Yipe");

constexpr char title_fixative[] = "grout";
static_assert(title_fixative[5] == '\0',"Yipe"); 

void free_func()
{
	constexpr float pi = 3.14159265;
	
	static_assert((3.1 < pi) && (pi <3.2),"Yipe");
}

struct my_struct
{
	static constexpr char who[]="Gabriel Doss Reis";
	static_assert(who[0] =='G',"Yipe");
	
	
	static constexpr const char* a =&who[1];
	static_assert(*a == 'a',"Yipe");	 
};

constexpr double half_of(double x)
{
	return x/2;
}
  
constexpr double constexpr_cpp11_int_to_double(int x)
{
	return x * 1.0;
}

namespace constexpr_pow_int_cpp11_detail
{
	constexpr double pow_int_cpp11(double base,int exp)
	{
		return (exp ==0? 1.0: base * pow_int_cpp11(base, exp-1));
	}
 } 
 
 constexpr double  constexpr_pow_int_cpp11(double base, int exp)
 {
 	using namespace constexpr_pow_int_cpp11_detail;
 	return (exp > 100) || (exp < -100)?
	 	throw std::range_error{"abs(exp) exceeds 100"}:
		 exp >= 0?
		 pow_int_cpp11(base,exp):         // exp [base ...]
		 pow_int_cpp11(1.0/base,-1 * exp); //exp [1/base...]
 }
 
 
 // can use local variable
// constexpr double constexpr_pow_int_cpp14(double base, int exp)
// {
// 	if((exp > 100) || (exp < -100))
// 		throw std::range_error{"abse(exp) exceeds 100"};
// 		
// 	if(exp < 0)
// 	{
// 		base = 1.0/base;
// 		exp = -1 * exp;
//	}
//	
//	double result = 1.0;
//	for(int i = exp; i >0;--i)
//	{
//		result *= base;
//	}
//		
//	return result; 	
// }

template<typename T= std::uint32_t>
constexpr T constexpr11_bin(const char* t, 
							std::size_t b =0,  // bit count 
							T x=0)             // accumulator 
{
	return *t =='\0'?x:
		b >= std::numeric_limits<T>::digits?
			throw std::overflow_error{"Too many bits"}:
			*t ==','? constexpr11_bin<T>(t+1,b,x):
			*t == '0'? constexpr11_bin<T>(t+1,b+1,(x*2)+0):
			*t == '1'? constexpr11_bin<T>(t+1,b+1,(x*2)+1):
			throw std::domain_error("Only '0','1', and ',' may be used"); 
}

constexpr long long factor_cpp11(int n)
{
	return n <= 2?1: factor_cpp11(n -1 ) + factor_cpp11(n-2);
}

int main()
{
	
	cout<<constexpr_cpp11_int_to_double(100)<<"\n";
	 
	
	using u8_t = std::uint8_t;
	constexpr u8_t maskA = constexpr11_bin<u8_t>("1110,0000");
	constexpr u8_t maskB = constexpr11_bin<u8_t>("0001,1000");
	constexpr u8_t maskC = constexpr11_bin<u8_t>("0000,0110");
	constexpr u8_t maskD = constexpr11_bin<u8_t>("0000,0001");
	static_assert(maskA + maskB + maskC + maskD == 0xFF,"Yipe");
	
	cout<<factor_cpp11(10)<<"\n";
	
//	constexpr double d  constexpr11_bin<double>("1000");
//	static_assert(d == 8.0,"Yipe");
	
	
	cout<<"pow(3,5)="<< constexpr_pow_int_cpp11(3,5)<<"\n";
	cout<<"pow(3,-5)="<< constexpr_pow_int_cpp11(3,-5)<<"\n";
	
	
	//cout<<"pow(3,5)="<< constexpr_pow_int_cpp14(3,5)<<"\n";
	
	
//	cout<<"pow(3,-5)="<< constexpr_pow_int_cpp14(3,-5)<<"\n";
	
	
	constexpr double half = half_of(1.0);
	static_assert((half < 0.51) && (half > 0.49),"Yipe");
	
	cout<<half<<"\n";
	
	char c;
	std::cin>>c;
	const double run = half_of(c);
	assert(run == (c * 0.5));
	
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0,1);
	
	const double r = dis(gen);
	assert(constexpr_pow_int_cpp11(r,2) == r * r);
	
	return 0;
}
