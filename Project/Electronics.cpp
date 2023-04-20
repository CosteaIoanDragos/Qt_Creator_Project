#include "Electronics.h"
/*****************************************************************//**
 * \file   Electronics.cpp
 * \brief  Virutal class
 * 
 * \author Ioan
 * \date   May 2022
 *********************************************************************/
Electronics::Electronics()
{
	brand = "NoNameBrand";
	price = 0;
	p_freq = 0;
}
/**
 * .
 * Constructor
 * \param brand1
 * \param price1
 * \param freq
 */
Electronics::Electronics(string brand1, float price1,float freq)
{
	brand = brand1;
	price = price1;
	p_freq = freq;
}
/**
 * CopyConstructor
 * 
 * \param other
 */
Electronics::Electronics(const Electronics& other)
{
	this->brand = other.brand;
	this->price = other.price;
	this->p_freq = other.p_freq;
}
/**
 * .= caracter overload
 * 
 * \param other
 * \return Electronics
 */
Electronics& Electronics::operator=(const Electronics& other)
{
	this->brand = other.brand;
	this->price = other.price;
	this->p_freq = other.p_freq;
	return *this;
}
/**
 * .
 * Default constructor
 */
Phone::Phone()
{
	brand = "NoNameBrand";
	price = 0;
	camera_MP = 0;
	p_freq = 0;
	s_size = 0;
}
/**
 * .
 * Constructor
 * \param brand1
 * \param price1
 * \param freq
 * \param camera
 * \param size
 */
Phone::Phone(string brand1, float price1, float freq, int camera, int size)
{
	this->brand = brand1;
	this->price = price1;
	this->camera_MP = camera;
	this->p_freq = freq;
	this->s_size = size;

}
/**
 * .CopyConstructor
 * 
 * \param other
 */

Phone::Phone(const Phone& other)
{
	this->brand = other.brand;
	this->price = other.price;
	this->p_freq = other.p_freq;
	this->camera_MP = other.camera_MP;
	this->s_size = other.s_size;

}

Phone& Phone::operator=(const Phone& other)
{
	this->brand = other.brand;
	this->price = other.price;
	this->p_freq = other.p_freq;
	this->camera_MP = other.camera_MP;
	this->s_size = other.s_size;
	return *this;
}
/**
 * .Edit function from the virtual base class electronics
 * it gives new values to all the class components
 * 
 */
void Phone::edit()
{
	int camera, size;
	float price1, freq;
	string brand1;
	cout << "Brand:\n";
	cin >> brand1;
	cout << "Pret:\n";
	cin >> price1;
	cout << "Frecventa proccesor:\n";
	cin >> freq;
	cout << "Mp camera:\n";
	cin >> camera;
	cout << "Marime:\n";
	cin >> size;
	brand = brand1;
	price = price1;
	p_freq = freq;
	camera_MP = camera;
	s_size = size;
}



/**
 * operator<< overload.
 * 
 * \param s
 * \param p
 * \return string
 */



ostream& operator<<(ostream& s, const Phone&p)
{
	s << "Phone:" << p.brand << " price:" << p.price << " processor freq:" << p.p_freq << " Camera:" << p.camera_MP << "mp screen size:" << p.s_size<< " inch";
	return s;
}
/**
 * operatro overload.
 * 
 * \param s
 * \param p
 * \return string
 */
ostream& operator<<(ostream& s, const Tablet&p)
{
	s << "Tablet:" << p.brand << " price:" << p.price << " processor freq:" << p.p_freq << " Camera:" << p.camera_MP << "mp screen size:" << p.s_size << " inch";
	return s;
}
ostream& operator<<(ostream& s, const Leptop& p)
{
	s << "Leptop:" << p.brand << " price:" << p.price << " processor freq:" << p.p_freq << " Color:" << p.color << " size:" << p.size << " inch";
	return s;
}
/**
 * operator overload.
 * 
 * \param s
 * \param p
 * \return string
 */
ostream& operator<<(ostream& s, const Processor& p)
{
	s << "Processor:" << p.brand << " price:" << p.price << " processor freq:" << p.p_freq << " Nr of Cores:" << p.nr_cores;
	return s;
}
/**
 * operator overload.
 * 
 * \param s
 * \param p
 * \return string
 */
ostream& operator<<(ostream& s, const GPU& p)
{
	s << "GPU:" << p.brand << " price:" << p.price << " processor freq:" << p.p_freq << " Nr of vCores:" << p.nr_vcores;
	return s;
}

/**
 * Constructor .
 * 
 */
Tablet::Tablet()
{
	brand = "NoNameBrand";
	price = 0;
	camera_MP = 0;
	p_freq = 0;
	s_size = 0;
}
/**
 * constructor.
 * 
 * \param brand1
 * \param price1
 * \param freq
 * \param camera
 * \param size
 */
Tablet::Tablet(string brand1, float price1, float freq, int camera, int size)
{
	this->brand = brand1;
	this->price = price1;
	this->camera_MP = camera;
	this->p_freq = freq;
	this->s_size = size;
}
/**
 * CopyConstrcutor.
 * 
 * \param other
 */
Tablet::Tablet(const Tablet& other)
{
	this->brand = other.brand;
	this->price = other.price;
	this->p_freq = other.p_freq;
	this->camera_MP = other.camera_MP;
	this->s_size = other.s_size;
}
/**
 * = operator overload.
 * 
 * \param other
 * \return Tablet object
 */
Tablet& Tablet::operator=(const Tablet& other)
{
	this->brand = other.brand;
	this->price = other.price;
	this->p_freq = other.p_freq;
	this->camera_MP = other.camera_MP;
	this->s_size = other.s_size;
	return *this;
}
/**
 * It edits all the atributs in the class.
 * 
 */
void Tablet::edit()
{
	int camera, size;
	float price1, freq;
	string brand1;
	cout << "Brand:\n";
	cin >> brand1;
	cout << "Pret:\n";
	cin >> price1;
	cout << "Frecventa proccesor:\n";
	cin >> freq;
	cout << "Mp camera:\n";
	cin >> camera;
	cout << "Marime:\n";
	cin >> size;
	brand = brand1;
	price = price1;
	p_freq = freq;
	camera_MP = camera;
	s_size = size;
}
/**
 * Default constructor.
 * 
 */
Leptop::Leptop()
{
	brand = "NoNameBrand";
	price = 0;
	p_freq = 0;
	color = "Null";
	this->size = 0;
}
/**
 * Constructor.
 * 
 * \param brand1
 * \param price1
 * \param freq
 * \param size1
 * \param color1
 */
Leptop::Leptop(string brand1, float price1,float freq, int size1, string color1)
{
	brand = brand1;
	price = price1;
	p_freq = freq;
	this->size = size1;
	this->color = color1;
}
/**
 * Copy Constructor.
 * 
 * \param other
 */
Leptop::Leptop(const Leptop& other)
{
	brand = other.brand;
	price = other.price;
	p_freq = other.p_freq;
	this->size = other.size;
	this->color = other.color;
}
/**
 * =operator overload.
 * 
 * \param other
 * \return leptop class
 */
Leptop& Leptop::operator=(const Leptop& other)
{
	brand = other.brand;
	price = other.price;
	p_freq = other.p_freq;
	this->size = other.size;
	this->color = other.color;
	return *this;
}
/**
 * Edits all the atributes in the class.
 * 
 */
void Leptop::edit()
{
	string color1,brand1;
	float price1, freq;
	int size1;
	cout << "Brand:\n";
	cin >> brand1;
	cout << "Pret:\n";
	cin >> price1;
	cout << "Frecventa proccesor:\n";
	cin >> freq;
	cout << "Marime:\n";
	cin >> size1;
	cout << "Culoare:\b";
	cin >> color1;

	brand = brand1;
	price = price1;
	p_freq = freq;
	this->size = size1;
	color = color1;
}
/**
 * Default constructor.
 * 
 */
Processor::Processor()
{
	brand = "NoNameBrand";
	p_freq = 0;
	price = 0;
}
/**
 * Constructor.
 * 
 * \param brand1
 * \param price1
 * \param freq
 * \param nr_cores1
 */

Processor::Processor(string brand1, float price1, float freq, int nr_cores1)
{
	brand = brand1;
	price = price1;
	p_freq = freq;
	nr_cores = nr_cores1;
}
/**
 * Copy Constructor.
 * 
 * \param other
 */
Processor::Processor(const Processor& other)
{
	brand = other.brand;
	price = other.price;
	this->p_freq = other.p_freq;
	nr_cores = other.nr_cores;
}
/**
 * =operator overload.
 * 
 * \param other
 * \return 
 */
Processor& Processor::operator=(const Processor& other)
{
	brand = other.brand;
	price = other.price;
	this->p_freq = other.p_freq;
	nr_cores = other.nr_cores;
	return *this;

}
/**
 * edits all the class atributes.
 * 
 */
void Processor::edit()
{
	string brand1;
	float price1, freq;
	int cores1;
	cout << "Brand:\n";
	cin >> brand1;
	cout << "Pret:\n";
	cin >> price1;
	cout << "Frecventa proccesor:\n";
	cin >> freq;
	cout << "Nr of cores:\n";
	cin >> cores1;
	
	brand = brand1;
	price = price1;
	p_freq = freq;
	nr_cores = cores1;
}
/**
 * default constructor.
 * 
 */
GPU::GPU()
{
	brand = "NoNameBrand";
	price = 0;
	p_freq = 0;
	nr_vcores = 0;
}

/**
 * constructor.
 * 
 * \param brand1
 * \param price1
 * \param freq
 * \param nr_vcores1
 */
GPU::GPU(string brand1, float price1, float freq, int nr_vcores1)
{
	brand = brand1;
	price = price1;
	p_freq = freq;
	nr_vcores = nr_vcores1;

}
/**
 * copy constructor.
 * 
 * \param other
 */
GPU::GPU(const GPU& other)
{
	brand = other.brand;
	price = other.price;
	p_freq = other.p_freq;
	nr_vcores = other.nr_vcores;
}
/**
 * = operator overload.
 * 
 * \param other
 * \return 
 */
GPU& GPU::operator=(const GPU& other)
{
	brand = other.brand;
	price = other.price;
	p_freq = other.p_freq;
	nr_vcores = other.nr_vcores;
	return *this;
}
/**
 * edits all the atributes of the class.
 * 
 */
void GPU::edit()
{
	string brand1;
	float price1, freq;
	int cores;
	cout << "Brand:\n";
	cin >> brand1;
	cout << "Pret:\n";
	cin >> price1;
	cout << "Frecventa proccesor:\n";
	cin >> freq;
	cout << "Nr of vcores:\n";
	cin >> cores;
	brand = brand1;
	price = price1;
	p_freq = freq;
	nr_vcores = cores;
}
