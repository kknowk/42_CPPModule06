/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:57:15 by khorike           #+#    #+#             */
/*   Updated: 2023/09/24 14:07:30 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	// シードの設定
	srand(time(0));

	Base* instance = generate();

	// test A
	delete instance;
	instance = new(A);

	std::cout << GREEN << "test A !!!!!" << END << std::endl;
	std::cout << GREEN <<"Pointer identification: " << END;
	identify(instance);

	std::cout << BLUE <<"Reference identification: " << END;
	identify(*instance);

	delete instance;
	std::cout << "\n------------------------\n" << std::endl;

	// test B
	instance = new(B);

	std::cout << GREEN << "test B !!!!!" << END << std::endl;
	std::cout << GREEN <<"Pointer identification: " << END;
	identify(instance);

	std::cout << BLUE <<"Reference identification: " << END;
	identify(*instance);

	delete instance;
	std::cout << "\n------------------------\n" << std::endl;

	// test C
	instance = new(C);

	std::cout << GREEN << "test C !!!!!" << END << std::endl;
	std::cout << GREEN <<"Pointer identification: " << END;
	identify(instance);

	std::cout << BLUE <<"Reference identification: " << END;
	identify(*instance);

	delete instance;
	std::cout << "\n------------------------\n" << std::endl;


	// test Unknown
	
	class D : public Base {};

	instance = new(D);

	std::cout << GREEN << "test Unknown type D !!!!!" << END << std::endl;
	std::cout << GREEN <<"Pointer identification: " << END;
	identify(instance);

	std::cout << BLUE <<"Reference identification: " << END;
	identify(*instance);

	delete instance;
	std::cout << "\n------------------------\n" << std::endl;


	// test NULL
	instance = NULL;

	std::cout << GREEN << "test Unknown type NULL !!!!!" << END << std::endl;
	std::cout << GREEN <<"Pointer identification: " << END;
	identify(instance);

	// NULLを参照として渡すと未定義の動作を引き起こすのでやらない
	// std::cout << BLUE <<"Reference identification: " << END;
	// identify(*instance);

	std::cout << "\n------------------------\n" << std::endl;

	// test random
	std::cout << GREEN << "test random !!!!!!!" << END << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		Base* Instance = generate();
		
		std::cout << GREEN <<"Pointer identification: " << END;
		// ポインタの関数が呼ばれる
		// オブジェクトのアドレスを直接渡す
		identify(Instance);
		
		std::cout << BLUE <<"Reference identification: " << END;
		// 参照の関数が呼ばれる
		// オブジェクト自体またはその参照を渡す
		identify(*Instance);

		delete Instance;
		std::cout << "\n------------------------\n" << std::endl;
	}
	return 0;
}

// __attribute__((destructor)) static void destructor(void)
// {
// 	system("leaks -q ex02");
// }
