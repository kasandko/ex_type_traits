#include "test_op_traits.h"
#include "tests.h"
#include "ex_type_traits/op_traits.h"

#include <vector>

enum class TFalse
{
};

/* Function for debug.
template <typename T>
void printType()
{
    TH_MESSAGE(__FUNCSIG__);
}
*/

bool testBinOpsTrivial()
{
    // Positive tests.
    TH_ASSERT_TRUE((exttr::op::is_b_summative_v<int, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_subtractive_v<int, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_multiplicative_v<int, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_dividable_v<int, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_modulative_v<int, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_bit_conjunctionable_v<int, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_bit_disjunctionable_v<int, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_bit_ex_disjunctionable_v<int, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_conjunctionable_v<bool, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_disjunctionable_v<bool, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_lshiftable_v<int, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_rshiftable_v<int, int, int>), "");

    TH_ASSERT_TRUE((exttr::op::is_b_equ_v<bool, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_neq_v<bool, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_lss_v<bool, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_leq_v<bool, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_gtr_v<bool, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_b_geq_v<bool, int, int>), "");

    // Negative tests.
    TH_ASSERT_FALSE((exttr::op::is_b_summative_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_subtractive_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_multiplicative_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_dividable_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_modulative_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_bit_conjunctionable_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_bit_disjunctionable_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_bit_ex_disjunctionable_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_conjunctionable_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_disjunctionable_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_lshiftable_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_rshiftable_v<int, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_conjunctionable_v<int, int, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_disjunctionable_v<int, int, int>), "");

    TH_ASSERT_FALSE((exttr::op::is_b_equ_v<bool, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_neq_v<bool, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_lss_v<bool, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_leq_v<bool, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_gtr_v<bool, int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_b_geq_v<bool, int, TFalse>), "");

    return true;
}

bool testBinMutOpsTrivial()
{
    // Positive tests.
    TH_ASSERT_TRUE((exttr::op::is_ab_summative_v<int&, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_ab_subtractive_v<int&, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_ab_multiplicative_v<int&, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_ab_dividable_v<int&, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_ab_modulative_v<int&, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_ab_bit_conjunctionable_v<int&, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_ab_bit_disjunctionable_v<int&, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_ab_bit_ex_disjunctionable_v<int&, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_ab_lshiftable_v<int&, int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_ab_rshiftable_v<int&, int, int>), "");

    // Negative tests.
    TH_ASSERT_FALSE((exttr::op::is_ab_summative_v<int, bool, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_ab_subtractive_v<int, bool, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_ab_multiplicative_v<int, bool, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_ab_dividable_v<int, bool, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_ab_modulative_v<int, bool, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_ab_bit_conjunctionable_v<int, bool, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_ab_bit_disjunctionable_v<int, bool, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_ab_bit_ex_disjunctionable_v<int, bool, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_ab_lshiftable_v<int, bool, int>), "");
    TH_ASSERT_FALSE((exttr::op::is_ab_rshiftable_v<int, bool, int>), "");

    return true;
}

bool testAssignmentOpsTrivial()
{
    // Positive tests.
    TH_ASSERT_TRUE((exttr::op::is_a_summative_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_a_subtractive_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_a_multiplicative_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_a_dividable_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_a_modulative_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_a_bit_conjunctionable_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_a_bit_disjunctionable_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_a_bit_ex_disjunctionable_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_a_lshiftable_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_a_rshiftable_v<int, int>), "");

    // Negative tests.
    TH_ASSERT_FALSE((exttr::op::is_a_summative_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_a_subtractive_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_a_multiplicative_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_a_dividable_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_a_modulative_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_a_bit_conjunctionable_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_a_bit_disjunctionable_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_a_bit_ex_disjunctionable_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_a_lshiftable_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_a_rshiftable_v<int, TFalse>), "");

    return true;
}

bool testUnPreOpsTrivial()
{
    // Positive tests for immutable.
    TH_ASSERT_TRUE((exttr::op::is_positvable_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_negativable_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_bit_inversible_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_inversible_v<bool, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_indirect_v<int&, int*>), "");

    // Positive tests for mutable.
    TH_ASSERT_TRUE((exttr::op::is_pre_incrementable_v<int&, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_pre_decrementable_v<int&, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_addressable_v<int*, int>), "");

    // Negative tests for immutable.
    TH_ASSERT_FALSE((exttr::op::is_positvable_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_negativable_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_bit_inversible_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_inversible_v<bool, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_indirect_v<int&, TFalse>), "");

    // Negative tests for mutable.
    TH_ASSERT_FALSE((exttr::op::is_pre_incrementable_v<int&, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_pre_decrementable_v<int&, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_addressable_v<int*, TFalse>), "");

    return true;
}

bool testUnPostOpsTrivial()
{
    // Positive tests.
    TH_ASSERT_TRUE((exttr::op::is_post_incrementable_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_post_decrementable_v<int, int>), "");

    // Negative tests.
    TH_ASSERT_FALSE((exttr::op::is_post_incrementable_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_post_decrementable_v<int, TFalse>), "");

    return true;
}

bool testComparisonOpsTrivial()
{
    // Positive tests.
    TH_ASSERT_TRUE((exttr::op::is_equ_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_neq_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_lss_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_leq_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_gtr_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_geq_v<int, int>), "");
    TH_ASSERT_TRUE((exttr::op::is_comparable_v<int, int>), "");

    // Negative tests.
    TH_ASSERT_FALSE((exttr::op::is_equ_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_neq_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_lss_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_leq_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_gtr_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_geq_v<int, TFalse>), "");
    TH_ASSERT_FALSE((exttr::op::is_comparable_v<int, TFalse>), "");

    return true;
}

bool testOtherOps()
{
    using Vector = std::vector<int>;

    // Positive tests.
    TH_ASSERT_TRUE((exttr::op::is_indexical_v<Vector, Vector::value_type&, Vector::size_type>), "");

    // Negative tests.
    TH_ASSERT_FALSE((exttr::op::is_indexical_v<Vector, bool, Vector::size_type>), "");

    return true;
}
