#include "test_op_traits.h"
#include "tests.h"
#include "ex_type_traits/op_traits.h"

enum class TFalse
{
};

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
