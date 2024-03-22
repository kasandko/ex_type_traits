#pragma once

#include "detectors.h"

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

// Is the binary sum operation available?
EXTTR_BIN_OP_DETECTOR(is_b_summative, +)

// Is the binary subtraction operation available?
EXTTR_BIN_OP_DETECTOR(is_b_subtractive, -)

// Is the binary multiplication operation available?
EXTTR_BIN_OP_DETECTOR(is_b_multiplicative, *)

// Is the binary division operation available?
EXTTR_BIN_OP_DETECTOR(is_b_dividable, /)

// Is the binary mod operation available?
EXTTR_BIN_OP_DETECTOR(is_b_modulative, %)

// Is the binary bitwise conjunction operation available?
EXTTR_BIN_OP_DETECTOR(is_b_bit_conjunctionable, &)

// Is the binary bitwise disjunction operation available?
EXTTR_BIN_OP_DETECTOR(is_b_bit_disjunctionable, |)

// Is the binary XOR operation available?
EXTTR_BIN_OP_DETECTOR(is_b_bit_ex_disjunctionable, ^)

// Is the binary conjunction operation available?
EXTTR_BIN_OP_DETECTOR(is_conjunctionable, &&)

// Is the binary disjunction operation available?
EXTTR_BIN_OP_DETECTOR(is_disjunctionable, ||)

// Is the binary shifts operations available?
EXTTR_BIN_OP_DETECTOR(is_b_lshiftable, <<)
EXTTR_BIN_OP_DETECTOR(is_b_rshiftable, >>)

// Is the binary comparison operations available?
EXTTR_BIN_OP_DETECTOR(is_b_equ, ==)
EXTTR_BIN_OP_DETECTOR(is_b_neq, !=)
EXTTR_BIN_OP_DETECTOR(is_b_lss, <)
EXTTR_BIN_OP_DETECTOR(is_b_leq, <=)
EXTTR_BIN_OP_DETECTOR(is_b_gtr, >)
EXTTR_BIN_OP_DETECTOR(is_b_geq, >=)


EXTTR_BIN_MUT_OP_DETECTOR(is_ab_summative, +=)
EXTTR_BIN_MUT_OP_DETECTOR(is_ab_subtractive, -=)
EXTTR_BIN_MUT_OP_DETECTOR(is_ab_multiplicative, *=)
EXTTR_BIN_MUT_OP_DETECTOR(is_ab_dividable, /=)
EXTTR_BIN_MUT_OP_DETECTOR(is_ab_modulative, %=)
EXTTR_BIN_MUT_OP_DETECTOR(is_ab_bit_conjunctionable, &=)
EXTTR_BIN_MUT_OP_DETECTOR(is_ab_bit_disjunctionable, |=)
EXTTR_BIN_MUT_OP_DETECTOR(is_ab_bit_ex_disjunctionable, ^=)
EXTTR_BIN_MUT_OP_DETECTOR(is_ab_lshiftable, <<=)
EXTTR_BIN_MUT_OP_DETECTOR(is_ab_rshiftable, >>=)


EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_summative, is_ab_summative)
EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_subtractive, is_ab_subtractive)
EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_multiplicative, is_ab_multiplicative)
EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_dividable, is_ab_dividable)
EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_modulative, is_ab_modulative)
EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_bit_conjunctionable, is_ab_bit_conjunctionable)
EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_bit_disjunctionable, is_ab_bit_disjunctionable)
EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_bit_ex_disjunctionable, is_ab_bit_ex_disjunctionable)
EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_lshiftable, is_ab_lshiftable)
EXTTR_ASSIGNMENT_OP_DETECTOR(is_a_rshiftable, is_ab_rshiftable)


EXTTR_UN_PRE_OP_DETECTOR(is_positvable, +)
EXTTR_UN_PRE_OP_DETECTOR(is_negativable, -)

EXTTR_UN_PRE_OP_DETECTOR(is_bit_inversible, ~)
EXTTR_UN_PRE_OP_DETECTOR(is_inversible, !)

EXTTR_UN_PRE_OP_DETECTOR(is_indirect, *)


EXTTR_UN_MUT_PRE_OP_DETECTOR(is_pre_incrementable, ++)
EXTTR_UN_MUT_PRE_OP_DETECTOR(is_pre_decrementable, --)
EXTTR_UN_MUT_PRE_OP_DETECTOR(is_addressable, &)


EXTTR_UN_POST_OP_DETECTOR(is_post_incrementable, ++)
EXTTR_UN_POST_OP_DETECTOR(is_post_decrementable, --)


EXTTR_COMPARISON_DETECTOR(is_equ, is_b_equ)
EXTTR_COMPARISON_DETECTOR(is_neq, is_b_neq)
EXTTR_COMPARISON_DETECTOR(is_lss, is_b_lss)
EXTTR_COMPARISON_DETECTOR(is_leq, is_b_leq)
EXTTR_COMPARISON_DETECTOR(is_gtr, is_b_gtr)
EXTTR_COMPARISON_DETECTOR(is_geq, is_b_geq)


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
    static decltype((func::declref<TT>())[func::declref<TA>()]) detect(const TT&, const TA&);

public:
    using RType = decltype(detect(func::declref<T>(), func::declref<TArg>()));
    static constexpr bool value = std::is_same<TResult, RType>::value;
};

template <typename T, typename TResult, typename TArg>
inline constexpr bool is_indexical_v = is_indexical<T, TResult, TArg>::value;

} // namespace exttr::op
