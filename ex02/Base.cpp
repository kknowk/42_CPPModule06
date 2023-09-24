/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:12:30 by khorike           #+#    #+#             */
/*   Updated: 2023/09/24 14:04:07 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base::~Base() {};

template <typename T>
T* ft_new()
{
	T* obj = new (std::nothrow) T();
	if (!obj)
	{
		std::cerr << "Memory allocation failed." << '\n';
		std::exit(EXIT_FAILURE);
	}
	return obj;
}

Base *generate(void)
{
	int choice = std::rand() % 3;
	// %3 を消して見てみても面白いかも
	// printf("random %d\n", choice);
	switch (choice)
	{
		case 0:
			return ft_new<A>();
		case 1:
			return ft_new<B>(); 
		default:
			return ft_new<C>();
	}
}

// srand(time(0));はmainでやる

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "A" << END << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "B" << END << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "C" << END << std::endl;
	else
		std::cout << RED <<"Unknown type" << END << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << GREEN << "A" << END << std::endl;
		return;
	} catch (std::bad_cast&) {
	}

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << GREEN << "B" << END << std::endl;
		return;
	} catch (std::bad_cast&) {
	}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << GREEN << "C" << END << std::endl;
		return;
	} catch (std::bad_cast&) {
	}

	std::cout << RED <<"Unknown type" << END << std::endl;
}

// ポインタでは禁止されている。
// void identify(Base& p)
// {
// 	if (dynamic_cast<A*>(&p))
// 		std::cout << "A" << std::endl;
// 	else if (dynamic_cast<B*>(&p))
// 		std::cout << "B" << std::endl;
// 	else if (dynamic_cast<C*>(&p))
// 		std::cout << "C" << std::endl;
// 	else
// 		std::cout << "Unknown type" << std::endl;
// }

// typeinfoの場合

// #include <typeinfo>

// void identify(Base* p) {
//     const std::type_info& info = typeid(*p);

//     if (info == typeid(A)) {
//         std::cout << "A" << std::endl;
//     } else if (info == typeid(B)) {
//         std::cout << "B" << std::endl;
//     } else if (info == typeid(C)) {
//         std::cout << "C" << std::endl;
//     } else {
//         std::cout << "Unknown type" << std::endl;
//     }
// }

// void identify(Base& p) {
//     const std::type_info& info = typeid(p);

//     if (info == typeid(A)) {
//         std::cout << "A" << std::endl;
//     } else if (info == typeid(B)) {
//         std::cout << "B" << std::endl;
//     } else if (info == typeid(C)) {
//         std::cout << "C" << std::endl;
//     } else {
//         std::cout << "Unknown type" << std::endl;
//     }
// }