#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>

class	PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe&	operator=(const PmergeMe&);
	public:
		template <typename T>
		T	operator()(T& container) const {
			size_t size = container.size();
			if (size <= 1)
				return container;
			return sortFord_Johnson(container);
		}
	private:
		/*
		template <typename T>
		T smartMerge(T l, T g) const {
			typedef typename T::reverse_iterator	reverse_iterator;
			if (l.empty())
				return g;
			else if (*l.rbegin() <= *g.begin())
				l.insert(l.end(), g.begin(), g.end());
			else
				while (!g.empty()) {
					typename T::value_type	value = g.front();
					g.erase(g.begin());
					for (reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
						if (*it <= value) {
							l.insert(it.base(), value);
							break;
						}
				}
			return l;
		}
		*/
		
		template <typename T>
		T smartMerge(T l, T g) const {
			typedef typename T::reverse_iterator	reverse_iterator;
			typedef typename T::iterator			iterator;
			if (l.empty())
				return g;
			else
				while (!g.empty()) {
					bool	inserted = false;
					iterator	first = g.begin();
					for (reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
						if (*it <= *first) {
							l.insert(it.base(), *first);
							inserted = true;
							break;
						}
					if (!inserted)
						l.insert(l.begin(), *first);
					g.erase(first);
				}
			return l;
		}
		
		template <typename T>
		T	sortFord_Johnson(T& m_data) const {
			typedef typename T::iterator	const_iterator;
			bool	is_sorted = true;
			if (m_data.size() <= 1)
				return m_data;
			T	l, g;
			for (const_iterator it = m_data.begin(); it != m_data.end(); ++it) {
			   const_iterator	p = it++;
			   if (it == m_data.end()) {
				   g.push_back(*p);
				   break ;
			   }
			   if (*p > *it) {
				   l.push_back(*it);
				   g.push_back(*p);
				   is_sorted = false;
			   }
			   else {
				   l.push_back(*p);
				   g.push_back(*it);
			   }
			}
			if (is_sorted)
				return m_data;
			l = sortFord_Johnson(l);
		//	g = sortFord_Johnson(g);
			return smartMerge(l, g);
		}
};


#endif
