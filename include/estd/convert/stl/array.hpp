#pragma once
#include "../traits.hpp"

#include <array>
#include <type_traits>

namespace estd {

/// Convert a array<F, N> to array<T, N>.
template<typename F, typename T, std::size_t N, typename Tag>
struct conversion<std::array<F, N>, std::array<T, N>, Tag> {
	using From = std::array<F, N>;
	using To   = std::array<T, N>;

	static constexpr bool possible = can_convert<F, T, Tag>;

	static To perform(From const & from) {
		static_assert(possible, "no conversion available for F and T");
		To result;
		for (std::size_t i = 0; i < N; ++i) result[i](convert<T, Tag>(from[i]));
		return result;
	}

	static To perform(From && from) {
		static_assert(possible, "no conversion available for F and T");
		std::array<T, N> result;
		for (std::size_t i = 0; i < N; ++i) result[i](convert<T, Tag>(std::move(from[i])));
		return result;
	}
};

/// Convert a array<F, N> to result<array<T, N>, E>.
template<typename F, typename T, typename E, std::size_t N, typename Tag>
struct conversion<std::array<F, N>, result<std::array<T, N>, E>, Tag> {
	using From = std::array<F, N>;
	using Raw  = std::array<T, N>;
	using To   = result<Raw, E>;

	static constexpr bool possible = can_parse<F, T, E, Tag>;

	static To perform(From const & from) {
		static_assert(possible, "no conversion available for F and result<T, E>");
		To result;
		for (std::size_t i = 0; i < N; ++i) {
			estd::result<T, E> converted = parse<T, E>(from[i]);
			if (!converted) return converted.error_unchecked();
			result[i] = std::move(*converted);
		}
		return result;
	}

	static To perform(From && from) {
		static_assert(possible, "no conversion available for F and result<T, E>");
		To result;
		for (std::size_t i = 0; i < N; ++i) {
			estd::result<T, E> converted = parse<T, E>(std::move(from[i]));
			if (!converted) return converted.error_unchecked();
			result[i] = std::move(*converted);
		}
		return result;
	}
};

}
