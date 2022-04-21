#include <utility>
#include <iostream>
#include <deque>

template<typename T, typename Container = std::deque<T>>
class stack
{
public:
	T& top()
	{
		return m.back();
	}
	template<typename t>
	void push(t&& a)
	{
		m.push_back(std::forward<t>(a));
	}
	void pop()
	{
		m.pop_back();
	}
	size_t size()
	{
		return m.size();
	}

	size_t empty()
	{
		return m.size() == 0;
	}

private:
	Container m;
};

int main()
{
	stack<int> s;
	s.push(1);
	s.push(3);
	s.push(4);
	while(!s.empty())
	{
		std::cout << s.top() << ' ';
		s.pop();
	}
}

