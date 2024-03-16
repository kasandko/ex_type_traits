#pragma once

#include <type_traits>

/*
Binary ops:
a = b: std::is_assignable
a + b: is_b_summative
a - b: is_b_subtractive
a * b: is_b_multiplicative
a / b: is_b_dividable
a % b: is_b_modulative
a == b: is_b_equ
a != b: is_b_neq
a > b: is_b_gtr
a < b: is_b_lss
a >= b: is_b_geq
a <= b: is_b_leq
a && b: is_conjunctionable
a || b: is_disjunctionable
a & b: is_b_bit_conjunctionable
a | b: is_b_bit_disjunctionable
a ^ b: is_b_bit_ex_disjunctionable
a << b: is_b_lshiftable
a >> b: is_b_rshiftable

Comparable ops:
bool r = a == b: is_equ
bool r = a != b: is_neq
bool r = a > b: is_gtr
bool r = a < b: is_lss
bool r = a >= b: is_geq
bool r = a <= b: is_leq

Prefix unary ops:
+a: is_positvable
-a: is_negativable
++a: is_pre_incrementable
--a: is_pre_decrementable
!a: is_inversible
~a: is_bit_inversible
*a: is_indirect
&a: is_addressable

// Assignment ops:
a += b: is_a_summative
a -= b: is_a_subtractive
a *= b: is_a_multiplicative
a /= b: is_a_dividable
a %= b: is_a_modulative
a &= b: is_a_bit_conjunctionable
a |= b: is_a_bit_disjunctionable
a ^= b: is_a_bit_ex_disjunctionable
a <<= b: is_a_lshiftable
a >>= b: is_a_rshiftable

Postfix unary ops:
a++: is_post_incrementable
a--: is_post_decrementable

Other:
a[b]: is_indexical
a->b: 
a->*b: 
a(b1, b2): std::is_invocable (?)
"a"_b: 
(R) a: std::is_convertible
a, b: 

*/

namespace exttr::op {

template <typename T>
std::add_lvalue_reference_t<T> declref() noexcept;

#undef BIN_OP_DETECTOR
#define BIN_OP_DETECTOR(NAME, OPERATION)                                                                \
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

// Is the binary sum operation available?
BIN_OP_DETECTOR(is_b_summative, +)

// Is the binary subtraction operation available?
BIN_OP_DETECTOR(is_b_subtractive, -)

// Is the binary multiplication operation available?
BIN_OP_DETECTOR(is_b_multiplicative, *)

// Is the binary division operation available?
BIN_OP_DETECTOR(is_b_dividable, /)

// Is the binary mod operation available?
BIN_OP_DETECTOR(is_b_modulative, %)

// Is the binary bitwise conjunction operation available?
BIN_OP_DETECTOR(is_b_bit_conjunctionable, &)

// Is the binary bitwise disjunction operation available?
BIN_OP_DETECTOR(is_b_bit_disjunctionable, |)

// Is the binary XOR operation available?
BIN_OP_DETECTOR(is_b_bit_ex_disjunctionable, ^)

// Is the binary conjunction operation available?
BIN_OP_DETECTOR(is_conjunctionable, &&)

// Is the binary disjunction operation available?
BIN_OP_DETECTOR(is_disjunctionable, ||)

// Is the binary shifts operations available?
BIN_OP_DETECTOR(is_b_lshiftable, <<)
BIN_OP_DETECTOR(is_b_rshiftable, >>)

// Is the binary comparison operations available?
BIN_OP_DETECTOR(is_b_equ, ==)
BIN_OP_DETECTOR(is_b_neq, !=)
BIN_OP_DETECTOR(is_b_lss, <)
BIN_OP_DETECTOR(is_b_leq, <=)
BIN_OP_DETECTOR(is_b_gtr, >)
BIN_OP_DETECTOR(is_b_geq, >=)

#undef BIN_OP_DETECTOR


#undef BIN_MUT_OP_DETECTOR
#define BIN_MUT_OP_DETECTOR(NAME, OPERATION)                                                \
    template <typename TResult, typename TLhs, typename TRhs>                               \
    struct NAME                                                                             \
    {                                                                                       \
    private:                                                                                \
        static void detect(...);                                                            \
        template <typename TL, typename TR>                                                 \
        static decltype(declref<TL>() OPERATION std::declval<TR>()) detect(TL&, const TR&); \
    public:                                                                                 \
        using RType = decltype(detect(declref<TLhs>(), std::declval<TRhs>()));              \
        static constexpr bool value = std::is_same<TResult, RType>::value;                  \
    };                                                                                      \
    template <typename TResult, typename TLhs, typename TRhs>                               \
    inline constexpr bool NAME##_v = NAME<TResult, TLhs, TRhs>::value;

BIN_MUT_OP_DETECTOR(is_ab_summative, +=)
BIN_MUT_OP_DETECTOR(is_ab_subtractive, -=)
BIN_MUT_OP_DETECTOR(is_ab_multiplicative, *=)
BIN_MUT_OP_DETECTOR(is_ab_dividable, /=)
BIN_MUT_OP_DETECTOR(is_ab_modulative, %=)
BIN_MUT_OP_DETECTOR(is_ab_bit_conjunctionable, &=)
BIN_MUT_OP_DETECTOR(is_ab_bit_disjunctionable, |=)
BIN_MUT_OP_DETECTOR(is_ab_bit_ex_disjunctionable, ^=)
BIN_MUT_OP_DETECTOR(is_ab_lshiftable, <<=)
BIN_MUT_OP_DETECTOR(is_ab_rshiftable, >>=)

#undef BIN_MUT_OP_DETECTOR


#undef ASSIGNMENT_OP_DETECTOR
#define ASSIGNMENT_OP_DETECTOR(NAME, BASE_NAME)                                 \
    template <typename TResult, typename TRhs>                                  \
    struct NAME : public BASE_NAME<TResult&, TResult, TRhs> {};                 \
    template <typename TResult, typename TRhs>                                  \
    inline constexpr bool NAME##_v = BASE_NAME##_v<TResult&, TResult, TRhs>;

ASSIGNMENT_OP_DETECTOR(is_a_summative, is_ab_summative)
ASSIGNMENT_OP_DETECTOR(is_a_subtractive, is_ab_subtractive)
ASSIGNMENT_OP_DETECTOR(is_a_multiplicative, is_ab_multiplicative)
ASSIGNMENT_OP_DETECTOR(is_a_dividable, is_ab_dividable)
ASSIGNMENT_OP_DETECTOR(is_a_modulative, is_ab_modulative)
ASSIGNMENT_OP_DETECTOR(is_a_bit_conjunctionable, is_ab_bit_conjunctionable)
ASSIGNMENT_OP_DETECTOR(is_a_bit_disjunctionable, is_ab_bit_disjunctionable)
ASSIGNMENT_OP_DETECTOR(is_a_bit_ex_disjunctionable, is_ab_bit_ex_disjunctionable)
ASSIGNMENT_OP_DETECTOR(is_a_lshiftable, is_ab_lshiftable)
ASSIGNMENT_OP_DETECTOR(is_a_rshiftable, is_ab_rshiftable)

#undef ASSIGNMENT_OP_DETECTOR


#undef UN_PRE_OP_DETECTOR
#define UN_PRE_OP_DETECTOR(NAME, OPERATION)                                 \
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

UN_PRE_OP_DETECTOR(is_positvable, +)
UN_PRE_OP_DETECTOR(is_negativable, -)

UN_PRE_OP_DETECTOR(is_bit_inversible, ~)
UN_PRE_OP_DETECTOR(is_inversible, !)

UN_PRE_OP_DETECTOR(is_indirect, *)

#undef UN_OP_DETECTOR


#undef UN_MUT_PRE_OP_DETECTOR
#define UN_MUT_PRE_OP_DETECTOR(NAME, OPERATION)                             \
    template <typename TResult, typename TRhs>                              \
    struct NAME                                                             \
    {                                                                       \
    private:                                                                \
        static void detect(...);                                            \
        template <typename TR>                                              \
        static decltype(OPERATION declref<TR>()) detect(TR&);               \
    public:                                                                 \
        using RType = decltype(detect(declref<TRhs>()));                    \
        static constexpr bool value = std::is_same<TResult, RType>::value;  \
    };                                                                      \
    template <typename TResult, typename TRhs>                              \
    inline constexpr bool NAME##_v = NAME<TResult, TRhs>::value;

UN_MUT_PRE_OP_DETECTOR(is_pre_incrementable, ++)
UN_MUT_PRE_OP_DETECTOR(is_pre_decrementable, --)
UN_MUT_PRE_OP_DETECTOR(is_addressable, &)

#undef UN_MUT_PRE_OP_DETECTOR


#undef UN_POST_OP_DETECTOR
#define UN_POST_OP_DETECTOR(NAME, OPERATION)                                \
    template <typename TResult, typename TRhs>                              \
    struct NAME                                                             \
    {                                                                       \
    private:                                                                \
        static void detect(...);                                            \
        template <typename TR>                                              \
        static decltype(declref<TR>() OPERATION) detect(TR&);               \
    public:                                                                 \
        using RType = decltype(detect(declref<TRhs>()));                    \
        static constexpr bool value = std::is_same<TResult, RType>::value;  \
    };                                                                      \
    template <typename TResult, typename TRhs>                              \
    inline constexpr bool NAME##_v = NAME<TResult, TRhs>::value;

UN_POST_OP_DETECTOR(is_post_incrementable, ++)
UN_POST_OP_DETECTOR(is_post_decrementable, --)

#undef UN_POST_OP_DETECTOR


#undef COMPARISON_DETECTOR
#define COMPARISON_DETECTOR(NAME, BASE_NAME)                            \
template <typename TLhs, typename TRhs>                                 \
struct NAME : public BASE_NAME<bool, TLhs, TRhs> {};                    \
template <typename TLhs, typename TRhs>                                 \
    inline constexpr bool NAME##_v = BASE_NAME##_v<bool, TLhs, TRhs>;

COMPARISON_DETECTOR(is_equ, is_b_equ)
COMPARISON_DETECTOR(is_neq, is_b_neq)
COMPARISON_DETECTOR(is_lss, is_b_lss)
COMPARISON_DETECTOR(is_leq, is_b_leq)
COMPARISON_DETECTOR(is_gtr, is_b_gtr)
COMPARISON_DETECTOR(is_geq, is_b_geq)

#undef COMPARISON_DETECTOR

// Is the comparison operations (>, <, >=, <=, ==, !=) available?
template <typename TLhs, typename TRhs>
struct is_comparable
{
    static constexpr bool value =
        is_equ<TLhs, TRhs>::value &&
        is_neq<TLhs, TRhs>::value &&
        is_lss<TLhs, TRhs>::value &&
        is_leq<TLhs, TRhs>::value &&
        is_gtr<TLhs, TRhs>::value &&
        is_geq<TLhs, TRhs>::value;
};
template <typename TLhs, typename TRhs>
inline constexpr bool is_comparable_v = is_comparable<TLhs, TRhs>::value;

template <typename T, typename TResult, typename TArg>
struct is_indexical
{
private:
    static void detect(...);
    template <typename TT, typename TA>
    static decltype((declref<TT>())[declref<TA>()]) detect(const TT&, const TA&);

public:
    using RType = decltype(detect(declref<T>(), declref<TArg>()));
    static constexpr bool value = std::is_same<TResult, RType>::value;
};

template <typename T, typename TResult, typename TArg>
inline constexpr bool is_indexical_v = is_indexical<T, TResult, TArg>::value;

} // namespace exttr::op
