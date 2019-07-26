#include <iostream>
#include <cstdint>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

#if __cplusplus <= 201103L
  #error This program needs at least a C++11 compliant compiler
#endif


void fizzbuzz( int64_t maxNumber)
{
    auto generator = [=]() -> std::string 
    {
        static int i = 1;
        std::string ret;
        
        if ( !( i%3 ) ) ret+="fizz"; 
        if ( !( i%5 ) ) ret+="buzz";
        ++i;

        return ret.empty() ? std::to_string(i-1) : ret ;
    };
    std::vector<std::string> a(maxNumber);

    std::generate(a.begin(), a.end(),generator);
    std::copy(a.begin(), a.end(), std::ostream_iterator<std::string>(std::cout,"\n"));


}
int main(int argc, char** argv)
{
    if ( argc != 2 )
    {
        std::cerr <<"need one argument " << '\n';
        return -1;
    }

    int64_t input = std::stoll(argv[1]);
    std::cout <<"input : " << input <<'\n';
    fizzbuzz(input);


    return 0;
}

