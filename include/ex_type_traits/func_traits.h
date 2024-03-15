#pragma once

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

} // exttr::func
