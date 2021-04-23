#pragma once

#include "../../asserts.hpp"

constexpr size_t INITIAL_CAPACITY = 2;
constexpr size_t GROWTH_FACTOR = 2;

namespace algae
{
	template<class dynamic_array>
	class dynamic_array_iterator
	{
	public:
		using value_type = typename dynamic_array::value_type;
	public:
		dynamic_array_iterator(value_type* ptr) 
			: m_ptr(ptr) {}

		dynamic_array_iterator& operator ++() 
		{
			m_ptr++;
			return *this;
		}

		dynamic_array_iterator operator ++(int)
		{
			dynamic_array_iterator it = *this;
			++(*this);
			return it;
		}

		dynamic_array_iterator& operator --()
		{
			m_ptr--;
			return *this;
		}

		dynamic_array_iterator operator --(int)
		{
			dynamic_array_iterator it = *this;
			--(*this);
			return it;
		}

		value_type& operator [](int index) { return *(m_ptr + index); }

		value_type* operator ->() { return m_ptr; }

		value_type& operator *() { return *m_ptr; }

		bool operator ==(const dynamic_array_iterator& other) const 
		{
			return m_ptr == other.m_ptr;
		}

		bool operator !=(const dynamic_array_iterator& other) const
		{
			return !(*this == other);
		}

	private:
		value_type* m_ptr;
	};

	template<class T>
	class dynamic_array
	{
	public:
		using value_type = T;
		using iterator = dynamic_array_iterator<dynamic_array<value_type>>;
	public:
		dynamic_array() noexcept : m_capacity(INITIAL_CAPACITY), m_size(0)
		{
			resize(m_capacity);
		}

		dynamic_array(size_t capacity) noexcept : m_capacity(capacity), m_size(0)
		{
			ASSERT_MSG(m_capacity >= 0, "Illegal Capacity!");
			resize(m_capacity);
		}

		~dynamic_array() 
		{
			clear();
			::operator delete(m_array, m_capacity * sizeof(value_type)); 
		}

		constexpr size_t size() const { return m_size; }

		constexpr bool empty() const { return m_size == 0; }

		constexpr size_t capacity() const { return m_capacity; }

		value_type& operator [](size_t index) noexcept
		{
			ASSERT_MSG(index <= m_size, "Index out of bounds!");
			return m_array[index];
		}

		const value_type& operator [](size_t index) const noexcept
		{
			ASSERT_MSG(index <= m_size , "Index out of bounds!");
			return m_array[index];
		}

		void push_back(const value_type& element)
		{
			if (m_size >= m_capacity) resize(m_capacity*GROWTH_FACTOR);
			m_array[m_size++] = element;
		}

		void push_back(value_type&& element)
		{
			if (m_size >= m_capacity) resize(m_capacity*GROWTH_FACTOR);
			new(&m_array[m_size++]) value_type(std::move(element));
		}

		template<typename... Args>
		value_type& emplace_back(Args&&... args)
		{
			if (m_size >= m_capacity) resize(m_capacity*GROWTH_FACTOR);
			new(&m_array[m_size]) value_type(std::forward<Args>(args)...);
			return m_array[m_size++];
		}

		void insert_at(size_t index)
		{
			//TODO
		}

		value_type pop_back()  
		{
			if (m_size > 0)
			{
				value_type element = m_array[m_size-1];
				m_size--;
				m_array[m_size].~value_type();
				return element;
			}
		}

		void remove_at(size_t index)
		{
			//TODO
		}

		void remove(value_type& element)
		{
			//TODO
		}

		void clear()
		{
			for (size_t i = 0; i < m_size; i++)
				m_array[i].~value_type();

			m_size = 0;
		}

		iterator begin() { return iterator(m_array); }

		iterator end() { return iterator(m_array + m_size); }

	private:
		void resize(size_t capacity)
		{
			value_type* temp = (value_type*)::operator new(capacity * sizeof(value_type));
	
			if (capacity < m_size) m_size = capacity;

			for (size_t i = 0; i < m_size; i++)
				new(&temp[i]) value_type(std::move(m_array[i]));

			for (size_t i = 0; i < m_size; i++)
				m_array[i].~value_type();

			::operator delete(m_array, m_capacity * sizeof(T));
			m_array = temp;
			m_capacity = capacity;
		}

	private:
		value_type* m_array = nullptr;
		size_t m_capacity, m_size;
	};
}
