#include "Intern.hpp"

int	main( void )
{
	std::cout << "---RobotomyRequestForm---" << std::endl;
	{
		Bureaucrat	Boss("Boss", 1);
		Intern		intern;

		Form* robotform = intern.makeForm("RobotomyRequestForm", "weird_contract");
		Boss.signForm(*robotform);
		Boss.executeForm(*robotform);

		delete robotform;
	}
	std::cout << "---ShrubberyCreationForm---" << std::endl;
	{
		Bureaucrat	Boss("Boss", 1);
		Intern		intern;

		Form* shrubform = intern.makeForm("ShrubberyCreationForm", "weird_contract");
		Boss.signForm(*shrubform);
		Boss.executeForm(*shrubform);

		delete shrubform;
	}
	std::cout << "---PresidentialPardonForm---" << std::endl;
	{
		Bureaucrat	Boss("Boss", 1);
		Intern		intern;

		Form* presform = intern.makeForm("PresidentialPardonForm", "weird_contract");
		Boss.signForm(*presform);
		Boss.executeForm(*presform);

		delete presform;
	}
	std::cout << "---NoFORM---" << std::endl;
	{
		Bureaucrat	Boss("Boss", 1);
		Intern		intern;

		Form* NoFORM = intern.makeForm("NoFORM", "weird_contract");
		if (NoFORM)
		{
			Boss.signForm(*NoFORM);
			Boss.executeForm(*NoFORM);
			delete NoFORM;
		}
	}
	return (0);
}
