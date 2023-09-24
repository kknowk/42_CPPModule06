/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:37:21 by khorike           #+#    #+#             */
/*   Updated: 2023/09/24 14:24:10 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

// color
#define END             "\033[0m"
#define BOLD            "\033[1m"
#define BLACK           "\033[30m"
#define RED             "\033[31m"
#define GREEN           "\033[32m"
#define YELLOW          "\033[33m"
#define BLUE            "\033[34m"
#define MAGENTA         "\033[35m"
#define CYAN            "\033[36m"
#define WHITE           "\033[37m"
#define UNDERLINE       "\033[4m"
#define BOLD_UNDERLINE  "\033[1;4m"


enum IntConversionStatus
{
	NORMAL_INT,
	GO_TO_FLOUT,
	INVALID_INT,
	OUT_OF_RANGE_INT,
	UNKNOWN_ERROR
};

class ScalarConverter
{
public:

	static void convert(const std::string& literal);

private:
	// インスタンス化できないように設計されている
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);

	// 文字列が各スカラータイプに変換可能かどうかをチェックするヘルパー関数
	static bool isChar(const std::string& literal);
	static IntConversionStatus isInt(const std::string& literal);
	static bool isFloat(const std::string& literal, int& num);
	static bool isDouble(const std::string& literal, int& num);

	// 値をchar, int, float, doubleのそれぞれに変換し、結果を出力するヘルパー関数
	static void displayAsChar(double value);
	static void displayAsInt(double value);
	static void displayAsFloat(double value, int num);
	static void displayAsDouble(double value, int num);

	// void displayConversions(double value);
};

#endif
