#include <iostream>
#include <memory>


class Animal
{

};

class Cat : public Animal
{
public:
	Cat() : mAge(0)
	{
		std::cout << "cat constructor" << std::endl;
	}
	~Cat()
	{
		std::cout << "cat destructor" << std::endl;
	}

private:
	int mAge;
};

class Dog : public Animal
{
};

class Zoo
{
public:
	Zoo(int n)
	{
		if (n == 1)
		{
			mAnimal = std::make_unique<Cat>();
		}
		else
		{
			mAnimal = std::make_unique<Dog>();
		}
	}
private:
	//Animal* mAnimal;

	std::unique_ptr<Animal> mAnimal;
};