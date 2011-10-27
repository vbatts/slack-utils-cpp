
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;


void show_string_sort()
{
	vector<string> vs;

	vs.push_back("cat");
	vs.push_back("antelope");
	vs.push_back("puppy");
	vs.push_back("bear");

	sort(
		vs.begin(),
		vs.end(),
		[](const string& left, const string& right) {
			return left.size() < right.size();
		}
	);

	for (auto i = vs.begin(); i != vs.end(); ++i)
	{
		cout << *i << endl;
	}

	vs.clear();
}

void show_int_sort()
{
	vector<int> v;

	v.push_back(22);
	v.push_back(11);
	v.push_back(44);
	v.push_back(33);
	v.push_back(77);
	v.push_back(55);
	v.push_back(66);

	sort(v.begin(), v.end());

	for (size_t i = 0; i < v.size() ; i++)
	{
		cout << v[i] << endl;
	}

	for (vector<int>::iterator i = v.begin(); i != v.end() ; i++)
	{
		cout << *i << endl;
	}

	v.clear();
}

int main()
{

	show_int_sort();
	show_string_sort();

	return 0;
}


