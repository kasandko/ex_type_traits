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
*a: is_indirect
&a: is_addressable

Postfix unary ops:
a++: is_pos_incrementable
a--: is_pos_decrementable

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

#undef BIN_OP_DETECTOR
#define BIN_OP_DETECTOR(NAME, OPERATION)                                                                                                \
    template <typename TResult, typename TLhs, typename TRhs>                                                                           \
    struct NAME                                                                                                                         \
        {                                                                                                                               \
        private:                                                                                                                        \
            static void detect(...);                                                                                                    \
            template <typename TL, typename TR>                                                                                         \
            static decltype(std::declval<TL>() OPERATION std::declval<TR>()) detect(const TL&, const TR&);                              \
        public:                                                                                                                         \
            static constexpr bool value = std::is_same<TResult, decltype(detect(std::declval<TLhs>(), std::declval<TRhs>()))>::value;   \
    };                                                                                                                                  \
    template <typename TResult, typename TLhs, typename TRhs>                                                                           \
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


#undef UN_PRE_OP_DETECTOR
#define UN_PRE_OP_DETECTOR(NAME, OPERATION)                                                                     \
    template <typename TResult, typename TRhs>                                                                  \
    struct NAME                                                                                                 \
        {                                                                                                       \
        private:                                                                                                \
            static void detect(...);                                                                            \
            template <typename TR>                                                                              \
            static decltype(OPERATION std::declval<TR>()) detect(const TR&);                                    \
        public:                                                                                                 \
            static constexpr bool value = std::is_same<TResult, decltype(detect(std::declval<TRhs>()))>::value; \
    };                                                                                                          \
    template <typename TResult, typename TRhs>                                                                  \
    inline constexpr bool NAME##_v = NAME<TResult, TRhs>::value;

UN_PRE_OP_DETECTOR(is_positvable, +)
UN_PRE_OP_DETECTOR(is_negativable, -)

UN_PRE_OP_DETECTOR(is_pre_incrementable, ++)
UN_PRE_OP_DETECTOR(is_pre_decrementable, --)

UN_PRE_OP_DETECTOR(is_bit_inversible, ~)
UN_PRE_OP_DETECTOR(is_inversible, !)

UN_PRE_OP_DETECTOR(is_a_summative, +=)
UN_PRE_OP_DETECTOR(is_a_subtractive, -=)
UN_PRE_OP_DETECTOR(is_a_multiplicative, *=)
UN_PRE_OP_DETECTOR(is_a_dividable, /=)
UN_PRE_OP_DETECTOR(is_a_modulative, %=)
UN_PRE_OP_DETECTOR(is_a_bit_conjunctionable, &=)
UN_PRE_OP_DETECTOR(is_a_bit_disjunctionable, |=)
UN_PRE_OP_DETECTOR(is_a_bit_ex_disjunctionable, |=)
UN_PRE_OP_DETECTOR(is_a_lshiftable, <<=)
UN_PRE_OP_DETECTOR(is_a_rshiftable, >>=)

UN_PRE_OP_DETECTOR(is_indirect, *)
UN_PRE_OP_DETECTOR(is_addressable, &)

#undef UN_OP_DETECTOR


#undef UN_POS_OP_DETECTOR
#define UN_POS_OP_DETECTOR(NAME, OPERATION)                                                                     \
    template <typename TResult, typename TRhs>                                                                  \
    struct NAME                                                                                                 \
        {                                                                                                       \
        private:                                                                                                \
            static void detect(...);                                                                            \
            template <typename TR>                                                                              \
            static decltype(std::declval<TR>() OPERATION) detect(const TR&);                                    \
        public:                                                                                                 \
            static constexpr bool value = std::is_same<TResult, decltype(detect(std::declval<TRhs>()))>::value; \
    };                                                                                                          \
    template <typename TResult, typename TRhs>                                                                  \
    inline constexpr bool NAME##_v = NAME<TResult, TRhs>::value;

UN_POS_OP_DETECTOR(is_pos_incrementable, ++)
UN_POS_OP_DETECTOR(is_pos_decrementable, --)

#undef UN_POS_OP_DETECTOR


#undef COMPARISON_DETECTOR
#define COMPARISON_DETECTOR(NAME, OPERATION)                                                                                        \
    template <typename TLhs, typename TRhs>                                                                                         \
    struct NAME                                                                                                                     \
        {                                                                                                                           \
        private:                                                                                                                    \
            static void detect(...);                                                                                                \
            template <typename TL, typename TR>                                                                                     \
            static decltype(std::declval<TL>() OPERATION std::declval<TR>()) detect(const TL&, const TR&);                          \
        public:                                                                                                                     \
            static constexpr bool value = std::is_same<bool, decltype(detect(std::declval<TLhs>(), std::declval<TRhs>()))>::value;  \
    };                                                                                                                              \
    template <typename TLhs, typename TRhs>                                                                                         \
    inline constexpr bool NAME##_v = NAME<TLhs, TRhs>::value;

COMPARISON_DETECTOR(is_equ, ==)
COMPARISON_DETECTOR(is_neq, !=)
COMPARISON_DETECTOR(is_lss, <)
COMPARISON_DETECTOR(is_leq, <=)
COMPARISON_DETECTOR(is_gtr, >)
COMPARISON_DETECTOR(is_geq, >=)

#undef COMPARISON_DETECTOR

// Is the comparison operations (>, <, >=, <=, ==, !=) available?
template <typename TLhs, typename TLhs>
struct is_comparable
{
    static constexpr bool value =
        is_equ<TLhs, TLhs>::value &&
        is_neq<TLhs, TLhs>::value &&
        is_lss<TLhs, TLhs>::value &&
        is_leq<TLhs, TLhs>::value &&
        is_gtr<TLhs, TLhs>::value &&
        is_geq<TLhs, TLhs>::value;
};
template <typename TLhs, typename TRhs>
inline constexpr bool is_comparable_v = is_comparable<TLhs, TRhs>::value;

template <typename T, typename TArg>
struct is_indexical
{
private:
    static void detect(...);
    template <typename TT, typename TA>
    static decltype((std::declval<TT>())[std::declval<TA>()]) detect(const TT&, const TA&);

public:
    static constexpr bool value = std::is_same<bool, decltype(detect(std::declval<T>(), std::declval<TArg>()))>::value;
};

template <typename T, typename TArg>
inline constexpr bool is_indexical_v = is_indexical<T, TArg>::value;

} // namespace exttr::op
