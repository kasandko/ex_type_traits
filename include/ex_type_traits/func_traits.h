#pragma once

#include <type_traits>

namespace exttr::func {

template <typename TCont>
struct may_be_empty
{
private:
	static void detect(...);

	template <typename TCont2>
	static decltype(std::empty(std::declval<TCont2>())) detect(const TCont2&);

public:
	static constexpr bool value = !std::is_same<void, decltype(detect(std::declval<TCont>()))>::value;
};

template <typename T>
std::add_lvalue_reference_t<T> declref() noexcept;

template <typename T>
std::add_pointer_t<T> declptr() noexcept;

} // exttr::func
