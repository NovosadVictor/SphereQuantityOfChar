#include <iostream>
#include <map>
#include <string>
#include <vector>


int main()
{
	std::map<char, int> m;
	std::vector<char> Vc;
	std::vector<int> Vi;
	std::string s;
	std::getline(std::cin, s);
	for (size_t i = 0; i < s.size(); ++i)
		if (s[i] != ' ')
		{
			auto it = m.find(s[i]);
			if (it != m.end())
				++(it->second);
			else
				m.insert(std::pair<char, int>(s[i], 1));
		}
	//for (auto it = m.begin(); it != m.end(); ++it)
		//std::cout << it->first << " " << it->second << std::endl;
	//std::cout << std::endl;
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		Vc.push_back(it->first);
		Vi.push_back(it->second);
	}
	for (size_t i = 0; i < Vi.size(); ++i)
	{
		int jmax = i;
		int max = Vi[i];
		for (size_t j = i; j < Vi.size(); ++j)
			if (Vi[j] > max)
			{
				jmax = j;
				max = Vi[j];
			}
		char c = Vc[i];
		Vc[i] = Vc[jmax];
		Vc[jmax] = c;
		int C = Vi[i];
		Vi[i] = max;
		Vi[jmax] = C;
	}
	for (size_t i = 0; i < Vc.size(); ++i)
		for (size_t j = i; j < Vc.size(); ++j)
		if ((Vi[i] == Vi[j]) && (Vc[i] > Vc[j]))
		{
			char c = Vc[i];
			Vc[i] = Vc[j];
			Vc[j] = c;
		}
	for (size_t i = 0; i < Vi.size(); ++i)
		std::cout << Vc[i] << " " << Vi[i] << std::endl;

		/*for (auto it1 = m.begin(); it1 != m.end(); ++it1)
	{
		auto it = m.begin();
		int max = it->second;
		for (auto it2 = it1; it2 != m.end(); ++it2)
			if (it2->second > max)
			{
				max = it2->second;
				it = it2;
			}
		std::cout << it->first << " " << max << std::endl;
		m.erase(it);
	}*/



	//system("pause");
	return 0;
}