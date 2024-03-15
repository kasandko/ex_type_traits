#pragma once

#include "detectors.h"

#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>
#include <complex>
#include <valarray>
#include <tuple>
#include <variant>
#include <optional>

namespace exttr::stdc {

EXTTR_CONT_DETECTOR(is_vector, std::vector)
EXTTR_CONT_DETECTOR(is_vector, std::array)
EXTTR_CONT_DETECTOR(is_vector, std::map)
EXTTR_CONT_DETECTOR(is_vector, std::unordered_map)
EXTTR_CONT_DETECTOR(is_vector, std::set)
EXTTR_CONT_DETECTOR(is_vector, std::unordered_set)
EXTTR_CONT_DETECTOR(is_vector, std::list)
EXTTR_CONT_DETECTOR(is_vector, std::deque)
EXTTR_CONT_DETECTOR(is_vector, std::queue)
EXTTR_CONT_DETECTOR(is_vector, std::bitset)
EXTTR_CONT_DETECTOR(is_vector, std::stack)
EXTTR_CONT_DETECTOR(is_vector, std::complex)
EXTTR_CONT_DETECTOR(is_vector, std::valarray)
EXTTR_CONT_DETECTOR(is_vector, std::slice_array)
EXTTR_CONT_DETECTOR(is_vector, std::gslice_array)
EXTTR_CONT_DETECTOR(is_vector, std::mask_array)
EXTTR_CONT_DETECTOR(is_vector, std::indirect_array)
EXTTR_CONT_DETECTOR(is_vector, std::tuple)
EXTTR_CONT_DETECTOR(is_vector, std::pair)
EXTTR_CONT_DETECTOR(is_vector, std::variant)
EXTTR_CONT_DETECTOR(is_vector, std::optional)

} // exttr::stdc
