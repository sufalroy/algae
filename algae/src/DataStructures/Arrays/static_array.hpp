#pragma once

#include "../../asserts.hpp"

namespace algae
{
	template<class static_array>
	class static_array_iterator
	{
	public:
		using value_type = typename static_array::value_type;
	public:
		static_array_iterator(value_type* ptr)
			: m_ptr(ptr) {}

		static_array_iterator& operator ++()
		{
			m_ptr++;
			return *this;
		}

		static_array_iterator operator ++(int)
		{
			static_array_iterator it = *this;
			++(*this);
			return it;
		}

		static_array_iterator& operator --()
		{
			m_ptr--;
			return *this;
		}

		static_array_iterator operator --(int)
		{
			static_array_iterator it = *this;
			--(*this);
			return it;
		}

		value_type& operator [](int index) { return *(m_ptr + index); }

		value_type* operator ->() { return m_ptr; }

		value_type& operator *() { return *m_ptr; }

		bool operator ==(const static_array_iterator& other) const
		{
			return m_ptr == other.m_ptr;
		}

		bool operator !=(const static_array_iterator& other) const
		{
			return !(*this == other);
		}

	private:
		value_type* m_ptr;
	};

	template<class T, size_t S>
	class static_array
	{
	public:
		using value_type = T;
		using iterator = static_array_iterator<static_array<T, S>>;
	public:
		static_array() = default;
		
		constexpr size_t size() const { return S; }
		constexpr bool empty() const { return S == 0; }

		value_type& operator [](size_t index) noexcept
		{
			ASSERT_MSG(index <= S, "Index out of bounds!");
			return m_array[index]; 
		}

		const value_type& operator [](size_t index) const noexcept
		{
			ASSERT_MSG(index <= S, "Index out of bounds!");
			return m_array[index]; 
		}

		value_type* data() { return m_array; }
		
		const value_type* data() const { return m_array; }

		iterator begin() { return iterator(m_array); }
		iterator end() { return iterator(m_array + S); }

	private:
		value_type m_array[S];
	};
}