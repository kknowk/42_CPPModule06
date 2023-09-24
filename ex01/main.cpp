/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:57:15 by khorike           #+#    #+#             */
/*   Updated: 2023/09/24 14:09:49 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// main.cpp
#include "Serializer.hpp"
#include <iostream>
#include <cassert>

int main()
{
	// static なのでコンパイルできない
	// Serializer Serializer;

	Data myData = {42, 3.14};
	// Data myData = {-2147483648 , 3.14};

	uintptr_t serialized = Serializer::serialize(&myData);
	Data* deserialized = Serializer::deserialize(serialized);

	// アドレスが元に戻ったかどうか
	assert(deserialized == &myData);
	// 中身も確認するテスト
	assert(deserialized->value == myData.value);
	assert(deserialized->anotherValue == myData.anotherValue);

	std::cout << BLUE << "test value " << END << std::endl;

	std::cout << GREEN << "myData.value " << myData.value << std::endl;
	std::cout << "deserialized->value " << deserialized->value << std::endl;
	
	std::cout << "myData.anotherValue " << myData.anotherValue<< std::endl;
	std::cout << "deserialized->anotherValue " << deserialized->anotherValue << std::endl;
	

	std::cout << "Serialization and deserialization successful!" << END << std::endl;
	return 0;
}

// assert 関数は一致していなかったらプログラムを即座に終了します。
// エラーなら
// Assertion failed: (deserialized == &myData), function main, file main.cpp, line 27.
// zsh: abort      ./convert
// みたいなのが出る