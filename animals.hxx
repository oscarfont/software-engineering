#ifndef animals_hxx
#define animals_hxx

/*
   - ara afegim un nou atribut a la base de tipus std::string
   - afegim accessors d'escriptura i de lectura
 */

#include <iostream>
#include <string>

class Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "...indefinida..." << std::endl;
	}
	void nom(std::string elNom)
	{
		_nom = elNom;
	}
	std::string& nom()
	{
		return _nom;
	}

private:
	std::string _nom;
};

class Elefant : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "Elefant" << std::endl;
	}
};

class Granota : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "Granota" << std::endl;
	}
};

class Gat : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "Gat" << std::endl;
	}
};

class Lleo : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "Lleó" << std::endl;
	}
};

class Pingui : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "Pingüí" << std::endl;
	}
};

#endif
