/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:42:31 by khorike           #+#    #+#             */
/*   Updated: 2023/09/20 20:04:24 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Serializer.cpp
#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer&) {}

Serializer& Serializer::operator=(const Serializer&)
{
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
	// (void)ptr;
	// return 0;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
	// (void)raw;
	// return 0;
}

// reinterpret_cast は、任意のポインタ型を別のポインタ型、
// または整数型にキャストするためのC++のキャスト演算子です。
// この場合、Data* ポインタを uintptr_t にキャストしています。

// このキャストにより、ポインタの実際のアドレス値を整数値として取得できます。
// これにより、後でこの整数値を再びポインタに戻すことができるようになります。