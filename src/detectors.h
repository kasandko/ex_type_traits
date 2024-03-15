#pragma once

#undef EXTTR_CONT_DETECTOR
#define EXTTR_CONT_DETECTOR(NAME, TNAME)                                        \
    template<typename T>                                                        \
class NAME                                                                      \
    {                                                                           \
    private:                                                                    \
    template <typename... TValue>                                               \
    	static constexpr bool check(TNAME<TValue...>*) { return true; }         \
    	static constexpr bool check(...) { return false; }                      \
    public:                                                                     \
    static const bool value = check((T*) 0);                                    \
    };                                                                          \
    template<typename T>                                                        \
    inline constexpr bool NAME##_v = NAME<T>::value; 