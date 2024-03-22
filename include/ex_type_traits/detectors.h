#pragma once

#include "func_traits.h"

#undef EXTTR_CONT_DETECTOR
#define EXTTR_CONT_DETECTOR(NAME, TNAME)                                        \
    template<typename T>                                                        \
    class NAME                                                                  \
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

#undef EXTTR_BIN_OP_DETECTOR
#define EXTTR_BIN_OP_DETECTOR(NAME, OPERATION)                                                          \
    template <typename TResult, typename TLhs, typename TRhs>                                           \
    struct NAME                                                                                         \
    {                                                                                                   \
    private:                                                                                            \
        static void detect(...);                                                                        \
        template <typename TL, typename TR>                                                             \
        static decltype(std::declval<TL>() OPERATION std::declval<TR>()) detect(const TL&, const TR&);  \
    public:                                                                                             \
        using RType = decltype(detect(std::declval<TLhs>(), std::declval<TRhs>()));                     \
    static constexpr bool value = std::is_same<TResult, RType>::value;                                  \
    };                                                                                                  \
    template <typename TResult, typename TLhs, typename TRhs>                                           \
    inline constexpr bool NAME##_v = NAME<TResult, TLhs, TRhs>::value;

#undef EXTTR_BIN_MUT_OP_DETECTOR
#define EXTTR_BIN_MUT_OP_DETECTOR(NAME, OPERATION)                                                          \
    template <typename TResult, typename TLhs, typename TRhs>                                               \
    struct NAME                                                                                             \
    {                                                                                                       \
    private:                                                                                                \
        static void detect(...);                                                                            \
        template <typename TL, typename TR>                                                                 \
        static decltype(exttr::func::declref<TL>() OPERATION std::declval<TR>()) detect(TL&, const TR&);    \
    public:                                                                                                 \
        using RType = decltype(detect(exttr::func::declref<TLhs>(), std::declval<TRhs>()));                 \
        static constexpr bool value = std::is_same<TResult, RType>::value;                                  \
    };                                                                                                      \
    template <typename TResult, typename TLhs, typename TRhs>                                               \
    inline constexpr bool NAME##_v = NAME<TResult, TLhs, TRhs>::value;

#undef EXTTR_ASSIGNMENT_OP_DETECTOR
#define EXTTR_ASSIGNMENT_OP_DETECTOR(NAME, BASE_NAME)                           \
    template <typename TResult, typename TRhs>                                  \
    struct NAME : public BASE_NAME<TResult&, TResult, TRhs> {};                 \
    template <typename TResult, typename TRhs>                                  \
    inline constexpr bool NAME##_v = BASE_NAME##_v<TResult&, TResult, TRhs>;

#undef EXTTR_UN_PRE_OP_DETECTOR
#define EXTTR_UN_PRE_OP_DETECTOR(NAME, OPERATION)                           \
    template <typename TResult, typename TRhs>                              \
    struct NAME                                                             \
    {                                                                       \
    private:                                                                \
        static void detect(...);                                            \
        template <typename TR>                                              \
        static decltype(OPERATION std::declval<TR>()) detect(const TR&);    \
    public:                                                                 \
        using RType = decltype(detect(std::declval<TRhs>()));               \
        static constexpr bool value = std::is_same<TResult, RType>::value;  \
    };                                                                      \
    template <typename TResult, typename TRhs>                              \
    inline constexpr bool NAME##_v = NAME<TResult, TRhs>::value;

#undef EXTTR_UN_MUT_PRE_OP_DETECTOR
#define EXTTR_UN_MUT_PRE_OP_DETECTOR(NAME, OPERATION)                       \
    template <typename TResult, typename TRhs>                              \
    struct NAME                                                             \
    {                                                                       \
    private:                                                                \
        static void detect(...);                                            \
        template <typename TR>                                              \
        static decltype(OPERATION exttr::func::declref<TR>()) detect(TR&);  \
    public:                                                                 \
        using RType = decltype(detect(exttr::func::declref<TRhs>()));       \
        static constexpr bool value = std::is_same<TResult, RType>::value;  \
    };                                                                      \
    template <typename TResult, typename TRhs>                              \
    inline constexpr bool NAME##_v = NAME<TResult, TRhs>::value;

#undef EXTTR_UN_POST_OP_DETECTOR
#define EXTTR_UN_POST_OP_DETECTOR(NAME, OPERATION)                          \
    template <typename TResult, typename TRhs>                              \
    struct NAME                                                             \
    {                                                                       \
    private:                                                                \
        static void detect(...);                                            \
        template <typename TR>                                              \
        static decltype(exttr::func::declref<TR>() OPERATION) detect(TR&);  \
    public:                                                                 \
        using RType = decltype(detect(exttr::func::declref<TRhs>()));       \
        static constexpr bool value = std::is_same<TResult, RType>::value;  \
    };                                                                      \
    template <typename TResult, typename TRhs>                              \
    inline constexpr bool NAME##_v = NAME<TResult, TRhs>::value;

#undef EXTTR_COMPARISON_DETECTOR
#define EXTTR_COMPARISON_DETECTOR(NAME, BASE_NAME)                          \
    template <typename TLhs, typename TRhs>                                 \
    struct NAME : public BASE_NAME<bool, TLhs, TRhs> {};                    \
    template <typename TLhs, typename TRhs>                                 \
        inline constexpr bool NAME##_v = BASE_NAME##_v<bool, TLhs, TRhs>;

#undef EXTTR_METHOD_DETECTOR
#define EXTTR_METHOD_DETECTOR(NAME, METHOD_NAME)                                                                    \
    template <typename T, typename TResult, typename... TArg>                                                       \
    struct NAME                                                                                                     \
    {                                                                                                               \
    private:                                                                                                        \
        static void detect(...);                                                                                    \
        template <typename TT, typename... TA>                                                                      \
        static decltype(std::declval<TT>().METHOD_NAME(std::declval<TA>()...)) detect(const TT&, const TA &...);    \
    public:                                                                                                         \
        using RType = decltype(detect(std::declval<T>(), std::declval<TArg>()...));                                 \
        static constexpr bool value = std::is_same<TResult, RType>::value;                                          \
    };                                                                                                              \
    template <typename T, typename TResult, typename... TArg>                                                       \
    inline constexpr bool NAME##_v = NAME<T, TResult, TArg...>::value;                                              \
