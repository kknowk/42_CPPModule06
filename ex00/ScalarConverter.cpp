/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:37:23 by khorike           #+#    #+#             */
/*   Updated: 2023/09/24 15:54:12 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <iomanip>


ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
	return *this;
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && (std::isprint(literal[0]) || std::isspace(literal[0]))
									&& !std::isdigit(literal[0]);
}

// 小数点は入らないようにする
IntConversionStatus ScalarConverter::isInt(const std::string& literal)
{
	try {
		size_t pos = 0; // 変換後の文字の位置を保存するための変数
		std::stoi(literal, &pos); // pos には変換されなかった最初の文字の位置が格納される
		if (pos == literal.size())
			return NORMAL_INT;
		return GO_TO_FLOUT;
	} catch (const std::invalid_argument&) {
		return INVALID_INT;
	} catch (const std::out_of_range&) {
		return OUT_OF_RANGE_INT;
	} catch (...) {
		return UNKNOWN_ERROR;
	}
}

bool ScalarConverter::isFloat(const std::string& literal, int& num)
{
	// 最後がfかどうか
	if (literal.back() != 'f')
		return false;
	size_t idx;
	try {
		std::stof(literal, &idx);
		if (idx != literal.length() - 1)
			return false;
		size_t pos = literal.find('.');
		if (pos != std::string::npos) {
			num = literal.length() - pos - 2;
		} else {
			num = 0;
		}
		return true;
	} catch (...) {
		return false;
	}
}

bool ScalarConverter::isDouble(const std::string& literal, int& num)
{
	size_t idx;
	try {
		std::stod(literal, &idx);
		if (idx != literal.length())
			return false;
		size_t pos = literal.find('.');
		if (pos != std::string::npos) {
			num = literal.length() - pos - 1;
		} else {
			num = 0;
		}
		return true;
	} catch (...) {
		return false;
	}
}

void ScalarConverter::displayAsChar(double value)
{
	// NaN の場合: value != value が true になる
	if (value != value)
	{
		std::cout << RED << "char: impossible" << END << std::endl;
		return;
	}
	// 無限大の場合: value が float の最大値より大きいか、最小値より小さい
	if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
		std::cout << RED << "char: impossible" << END << std::endl;
		return;
	}
	else if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || !std::isprint(static_cast<char>(value)))
		std::cout << RED << "char: Non displayable" << END << std::endl;
	else
		std::cout << GREEN << "char: '" << static_cast<char>(value) << "'" << END << std::endl;
}

void ScalarConverter::displayAsInt(double value)
{
	if (value != value)
	{
		std::cout << RED << "int: impossible" << END << std::endl;
		return;
	}
	// 無限大の場合: value が float の最大値より大きいか、最小値より小さい
	if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
		std::cout << RED << "int: impossible" << END << std::endl;
		return;
	}
	// INT_MIN INT_MAX check
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << RED << "int: impossible" << END << std::endl;
		return;
	}
	else
		std::cout << GREEN << "int: " << static_cast<int>(value) << END << std::endl;
}

// max min 比較
void ScalarConverter::displayAsFloat(double value, int num)
{
	// この中でのみfixed
	std::ios_base::fmtflags original_flags = std::cout.flags();
	{
		// printf("aaa%f\n", value);
		if (value != value)
		{
			std::cout << GREEN << "float: nanf" << END << std::endl;
			return;
		}
		if (value < std::numeric_limits<float>::lowest() || value > std::numeric_limits<float>::max())
		{
			std::cout << GREEN << "float: " << (value > 0 ? "+inff" : "-inff") << END << std::endl;
			return;
		}
		if (value > pow(10, -308) && value < pow(10, -7))
		{
			std::cout << GREEN << "float: " << std::scientific << static_cast<double>(value) << "f" << END << std::endl;
			return;
		}
		std::cout << std::fixed << std::setprecision(num);
		std::cout << GREEN << "float: " << static_cast<float>(value) << "f" << END << std::endl;
	}
	std::cout.flags(original_flags);
}

void ScalarConverter::displayAsDouble(double value, int num)
{
	// この中でのみfixed
	std::ios_base::fmtflags original_flags = std::cout.flags();
	{
		if (value != value)
		{
			std::cout << GREEN << "double: nan" << END << std::endl;
			return;
		}
		if (value < std::numeric_limits<double>::lowest() || value > std::numeric_limits<double>::max())
		{
			std::cout << GREEN << "double: " << (value > 0 ? "+inf" : "-inf") << END << std::endl;
			return;
		}
		if (value > pow(10, -308) && value < pow(10, -7))
		{
			std::cout << GREEN << "double: " << std::scientific << static_cast<double>(value) << END << std::endl;
			return;
		}
		std::cout << std::fixed << std::setprecision(num);
		std::cout << GREEN << "double: " << static_cast<double>(value) << END << std::endl;
	}
	std::cout.flags(original_flags);
}

void ScalarConverter::convert(const std::string& literal)
{
	int num = 1;

	if (isChar(literal))
	{
		char value = literal[0];
		displayAsChar(static_cast<double>(value));
		displayAsInt(static_cast<double>(value));
		displayAsFloat(static_cast<double>(value), 1);
		displayAsDouble(static_cast<double>(value), 1);
	}
	else if (isInt(literal) == NORMAL_INT)
	{
		int value = std::stoi(literal);
		displayAsChar(static_cast<double>(value));
		displayAsInt(static_cast<double>(value));
		displayAsFloat(static_cast<double>(value), 1);
		displayAsDouble(static_cast<double>(value), 1);
	}
	else if (isFloat(literal, num))
	{
		float value = std::stof(literal);
		displayAsChar(static_cast<double>(value));
		if (isInt(literal) == OUT_OF_RANGE_INT)
			std::cout << RED << "int: impossible" << END << std::endl;
		else
			displayAsInt(static_cast<double>(value));
		displayAsFloat(static_cast<double>(value), num);
		displayAsDouble(static_cast<double>(value), num);
	} 
	else if (isDouble(literal, num))
	{

		double value = std::stod(literal);

		displayAsChar(value);
		displayAsInt(value);
		displayAsFloat(value, num);
		displayAsDouble(value, num);
	}
	else
		std::cout << RED << "Invalid input." << END << std::endl;
}
