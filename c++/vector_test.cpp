#include <iostream>
#include <vector>
#include <string.h>
#include <map>

int test(){}

int main(int argc, char*argv[])
{
	std::vector<std::pair<std::string, int>> errors;
	#define CHECKCALL(x) \
	if((x) != 0) errors.emplace_back(#x " failed", errno);
	
	CHECKCALL(test());
	CHECKCALL(1);
	for(auto&[error_string, error_errno] : errors)
		std::cout <<error_string <<" " << strerror(error_errno) <<std::endl;
	
	
	std::map<std::string, int> kv;
	kv.insert(std::pair<std::string, int>("xiaomi", 1000));
	kv.insert(std::pair<std::string, int>("jingdong", 2000));
	
	for(auto& item : kv)
		std::cout<<"name: " <<item.first <<" value: "<< item.second <<std::endl;
	return 0;
}
