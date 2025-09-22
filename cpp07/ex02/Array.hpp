#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <class T>
class	Array {
	public:
		Array(): m_arr(NULL), m_size(0) {
		}

		Array(unsigned n): m_size(n) {
			m_arr = new T[m_size]();
		}

		~Array() {
			delete [] m_arr;
		}

		Array(const Array<T>& oth): m_size(oth.m_size) {
			m_arr = new T[m_size]();
			for (size_t i = 0; i < m_size; ++i)
				m_arr[i] = oth.m_arr[i];
		}

		Array<T>& operator=(const Array<T>& oth) {
			if (this != &oth) {
				delete [] m_arr;
				m_size = oth.m_size;
				m_arr = new T[m_size];
				for (size_t i = 0; i < m_size; ++i)
					m_arr[i] = oth.m_arr[i];
			}
			return *this;
			}
		const T&	operator[](size_t n) const {
			if (n >= m_size)
				throw std::out_of_range("Invalid index");
			return m_arr[n];
		}

		T&	operator[](size_t n) {
			if (n >= m_size)
				throw std::out_of_range("Invalid index");
			return m_arr[n];
		}

		inline size_t	size() const throw() {
			return m_size;
		}
	private:
		T*		m_arr;
		size_t	m_size;
};

#endif
