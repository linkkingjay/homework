#include<vector>
#include<iostream>
int main()
{
    std::vector<double> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    for (int i = 0; i < a.size(); i++)
	std::cout << a[i] << std::endl;
    return 0;
}
