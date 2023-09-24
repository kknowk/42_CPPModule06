/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:57:15 by khorike           #+#    #+#             */
/*   Updated: 2023/09/24 15:56:13 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

void	test_Success(void)
{
	std::cout << YELLOW << "test Success ver !!!!!!!" << END << std::endl;
	std::cout << "------------------------" << std::endl;
	
	std::cout << BLUE << "test a !!!!!!!" << END << std::endl;
	ScalarConverter::convert("a");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test 0 !!!!!!!" << END << std::endl;
	ScalarConverter::convert("0");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test 42 !!!!!!!" << END << std::endl;
	ScalarConverter::convert("42");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test -42 !!!!!!!" << END << std::endl;
	ScalarConverter::convert("-42");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test -42.0 !!!!!!!" << END << std::endl;
	ScalarConverter::convert("-42.0");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test -42.0f !!!!!!!" << END << std::endl;
	ScalarConverter::convert("-42.0f");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test nan !!!!!!!" << END << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test nanf !!!!!!!" << END << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test inf !!!!!!!" << END << std::endl;
	ScalarConverter::convert("inf");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test inff !!!!!!!" << END << std::endl;
	ScalarConverter::convert("inf");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test -inf !!!!!!!" << END << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test -inff !!!!!!!" << END << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "\n------------------------\n" << std::endl;
}

void	test_Max_Min(void)
{
	std::cout << YELLOW << "test Max_Min ver !!!!!!!" << END << std::endl;
	std::cout << "------------------------" << std::endl;
	
	std::cout << BLUE << "test CHAR_MAX (126)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("126");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test CHAR今回のギリギリ (32)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("32");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test INT_MAX (2147483647)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test INT_MIN (-2147483648)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test float max (3.40282e+37f)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("3.40282e+37f");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test float min(1.17549e-37f)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("1.17549e-37f");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test double max (1.79769e+308)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("1.79769e+308");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test double min(2.2257e-308)!!!!!" << END << std::endl;
	ScalarConverter::convert("2.2257e-308");
	std::cout << "\n------------------------\n" << std::endl;
}

void	test_invaild(void)
{
	std::cout << YELLOW << "test invaild !!!!!!!" << END << std::endl;
	std::cout << "------------------------" << std::endl;
	
	std::cout << BLUE << "test string (hello)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("hello");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test mix (42.0f42.0f)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("42.0f42.0f");
	std::cout << "\n------------------------\n" << std::endl;

	std::cout << BLUE << "test 紛らわしい (42.of)!!!!!!!" << END << std::endl;
	ScalarConverter::convert("42.of");
	std::cout << "\n------------------------\n" << std::endl;
}

int main(int argc, char *argv[])
{
	// static なのでコンパイルできない
	// ScalarConverter ScalarConverter;

	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <string>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	// (void)argc;
	// (void)argv;
	// test_Success();
	// test_Max_Min();
	// test_invaild();
	return 0;
}

// int main() {
//     std::string str = "1.17549e-37";
//     try {
//         float value = std::stof(str);
//         std::cout << "Parsed value: " << value << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
//     return 0;
// }


// nan と inf は、浮動小数点数の特別な値を表すための略語です。

// nan: "Not a Number" の略で、数値として表現できない結果を示します。
// 例えば、0.0 で除算される、または無限大から無限大を引くなどの演算は nan として評価されます。

// inf: "Infinity" の略で、正の無限大を示します。
// また、-inf は負の無限大を示します。浮動小数点数の計算でオーバーフローが発生すると、
// 結果はしばしば無限大 (inf または -inf) として表されます。
// 例えば、非常に大きな正の数を別の非常に大きな正の数で除算すると、inf が返されます。

// これらの値は、IEEE 754 浮動小数点数の標準で定義されており、
// 多くのプログラム言語や計算機のアーキテクチャでサポートされています。


// flout の最大値
// 3.402823 * 10**38
// $(python -c "print(3.402823 * 10**38)")

// IEEEアイ・トリプル・イー 754 — 浮動小数点演算に関する標準規格
// NaN は数値的には他のどの値とも等しくない
// 自分自身との比較も含まれる