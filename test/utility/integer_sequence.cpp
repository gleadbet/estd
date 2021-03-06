/* Copyright 2017-2018 Fizyr B.V. - https://fizyr.com
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "utility/integer_sequence.hpp"

#include "../static_assert_same.hpp"

#include <type_traits>

namespace estd {

void tests() {

static_assert_same<decltype(concat(std::integer_sequence<int, 1, 2, 3>{}, std::integer_sequence<int, 4>{})), std::integer_sequence<int, 1, 2, 3, 4>>();
static_assert_same<decltype(concat(std::integer_sequence<int, 1, 2, 3>{}, std::integer_sequence<int>{})),    std::integer_sequence<int, 1, 2, 3>>();

static_assert_same<decltype(concat(
		std::integer_sequence<int, 1>{},
		std::integer_sequence<int, 2>{},
		std::integer_sequence<int, 3>{}
)), std::integer_sequence<int, 1, 2, 3>>();

static_assert_same<decltype(concat(
		std::integer_sequence<int, 1, 2>{},
		std::integer_sequence<int>{},
		std::integer_sequence<int, 3, 4>{},
		std::integer_sequence<int, 5>{},
		std::integer_sequence<int>{}
)), std::integer_sequence<int, 1, 2, 3, 4, 5>>();

static_assert_same<decltype(remove_front<0>(std::integer_sequence<int, 1, 2, 3>{})), std::integer_sequence<int, 1, 2, 3>>();
static_assert_same<decltype(remove_front<1>(std::integer_sequence<int, 1, 2, 3>{})), std::integer_sequence<int,    2, 3>>();
static_assert_same<decltype(remove_front<2>(std::integer_sequence<int, 1, 2, 3>{})), std::integer_sequence<int,       3>>();
static_assert_same<decltype(remove_front<3>(std::integer_sequence<int, 1, 2, 3>{})), std::integer_sequence<int         >>();

static_assert_same<decltype(remove_back<0>(std::integer_sequence<int, 1, 2, 3>{})), std::integer_sequence<int, 1, 2, 3>>();
static_assert_same<decltype(remove_back<1>(std::integer_sequence<int, 1, 2, 3>{})), std::integer_sequence<int, 1, 2   >>();
static_assert_same<decltype(remove_back<2>(std::integer_sequence<int, 1, 2, 3>{})), std::integer_sequence<int, 1      >>();
static_assert_same<decltype(remove_back<3>(std::integer_sequence<int, 1, 2, 3>{})), std::integer_sequence<int         >>();

static_assert_same<decltype(slice< 0    >(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int, 0, 1, 2, 3, 4>>();
static_assert_same<decltype(slice< 0,  5>(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int, 0, 1, 2, 3, 4>>();
static_assert_same<decltype(slice< 1, -1>(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int,    1, 2, 3   >>();
static_assert_same<decltype(slice<-1    >(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int,             4>>();
static_assert_same<decltype(slice<-1, -1>(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int               >>();
static_assert_same<decltype(slice<-2, -1>(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int,          3   >>();
static_assert_same<decltype(slice< 2    >(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int,       2, 3, 4>>();
static_assert_same<decltype(slice< 3    >(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int,          3, 4>>();
static_assert_same<decltype(slice< 5    >(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int               >>();
static_assert_same<decltype(slice< 5,  5>(std::integer_sequence<int, 0, 1, 2, 3, 4>{})), std::integer_sequence<int               >>();

}

}
