#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Electronics
{public:
	Electronics();
	Electronics(string brand1, float price1, float freq);
	inline float getPrice()const { return this->price;}
	inline string getBrand()const { return this->brand;}
	inline void setBrand(string brand1) { brand = brand1;}
	inline void setPrice(float price1) { price = price1;}
	inline void setFreq(float freq) { p_freq = freq; }
	inline float getFreq()const { return p_freq; }
	Electronics(const Electronics& other);
	Electronics& operator =(const Electronics& other);
	//friend ostream& operator<<(ostream& s, const Electronics& p);
	virtual string ToString() = 0;
	virtual string ToCSV() = 0;
	virtual void edit() = 0;

protected:
	string brand;
	float price;
	float p_freq;//procc

};
/**
 * 
 *Phone class (string,float,float,int ,int)
 * setters and getters
 * overloaded = and <<functions
 * 
 */
class Phone :public Electronics {
public:
	Phone();
	Phone(string brand1, float price1, float freq, int camera, int size);
	inline int getCamera()const { return camera_MP; }
	inline int getSize()const { return s_size; }
	inline void setCamera(int camera) { camera_MP = camera;}
	inline void setSize(int size) { s_size = size; }
	Phone(const Phone& other);
	Phone& operator=(const Phone& other);
	friend ostream& operator<<(ostream& s, const Phone& p);
	/** 
	 * \return a string
	 */
	string ToString(){
		stringstream ss;
		ss<<"Phone:" << this->brand << " price:" << this->price << " processor freq:" <<this->p_freq<< " Camera:" << this->camera_MP << "mp screen size:" << this->s_size << " inch";
		return ss.str();
	
	}
	/**
	 * .
	 * 
	 * \return a string ready for a csv file
	 */
	string ToCSV() {
		stringstream ss;
		ss << this->brand << "," << this->price << "," << this->p_freq << "," << this->camera_MP << "," << this->s_size;
		return ss.str();
	}
	void edit();
private:
	int camera_MP;
	int s_size;
	
};
/**
 *
 *Tablet class (string,float,float,int ,int)
 * setters and getters
 * overloaded = and <<functions
 *
 */
class Tablet :public Electronics {

public:
	Tablet();
	Tablet(string brand1, float price1, float freq, int camera, int size);
	inline int getCamera()const { return camera_MP; }
	inline int getSize()const { return s_size; }
	inline void setCamera(int camera) { camera_MP = camera; }
	inline void setSize(int size) { s_size = size; }
	Tablet(const Tablet& other);
	Tablet& operator=(const Tablet& other);
	friend ostream& operator<<(ostream& s, const Tablet&p);
	/**
 * \return a string
 */
	string ToString() {
		stringstream ss;
		ss << "Tablet:" << this->brand << " price:" << this->price << " processor freq:" <<this->p_freq<< " Camera:" << this->camera_MP << "mp screen size:" << this->s_size << " inch";
		return ss.str();

	}
	/**
 * .
 *
 * \return a string ready for a csv file
 */
	string ToCSV() {
		stringstream ss;
		ss << this->brand << "," << this->price << "," << this->p_freq << "," << this->camera_MP << "," << this->s_size;
		return ss.str();
	}
	void edit();
private:
	int camera_MP;
	int s_size;
};
/**
 *
 *Leptop class (string,float,float,int ,string)
 * setters and getters
 * overloaded = and <<functions
 *
 */
class Leptop :public Electronics {
public:
	Leptop();
	Leptop(string brand1, float price1, float freq, int size1,string color1);
	inline string getColor()const { return color; };
	inline int getSize()const { return size; }
	inline void setColor(string color1) { color = color1; }
	inline void setSize(int size1) { size = size1; }
	Leptop(const Leptop& other);
	Leptop& operator=(const Leptop& other);
	friend ostream& operator<<(ostream& s, const Leptop& p);
	/**
 * \return a string
 */
	string ToString() {
		stringstream s;
		s << "Leptop:" << this->brand << " price:" << this->price << " processor freq:" << this->p_freq << " Color:" << this->color << " size:" << this->size << " inch";
		return s.str();
	}
	/**
 * .
 *
 * \return a string ready for a csv file
 */
	string ToCSV() {
		stringstream ss;
		ss << this->brand << "," << this->price << "," << this->p_freq << "," << this->size << "," << this->color;
		return ss.str();
	}
	void edit();
private:
	int size;
	string color;
};
/**
 *
 *Processor class (string,float,float,int )
 * setters and getters
 * overloaded = and <<functions
 *
 */
class Processor :public Electronics {
public:
	Processor();
	Processor(string brand1, float price1, float freq,int nr_cores1);
	inline int getNrCores()const { return nr_cores; }
	inline void setNrCores(int nr1) { nr_cores = nr1; }
	Processor(const Processor& other);
	Processor& operator=(const Processor& other);
	friend ostream& operator<<(ostream& s, const Processor& p);
	/**
 * \return a string
 */
	string ToString() {
		stringstream s;
		s << "Processor:" << this->brand << " price:" << this->price << " processor freq:" << this->p_freq << " Nr of Cores:" << this->nr_cores;
		return s.str();
	}
	/**
 * .
 *
 * \return a string ready for a csv file
 */
	string ToCSV() {
		stringstream ss;
		ss << this->brand << "," << this->price << "," << this->p_freq << "," << this->nr_cores;
		return ss.str();
	}
	void edit();
private:
	int nr_cores;
};
/**
 *
 *GPU class (string,float,float,int )
 * setters and getters
 * overloaded = and <<functions
 *
 */
class GPU :public Electronics {
public:
	GPU();
	GPU(string brand1, float price1, float freq, int nr_vcores1);
	inline int getNrCores()const { return nr_vcores; }
	inline void setNrCores(int nr1) { nr_vcores = nr1; }
	GPU(const GPU& other);
	GPU& operator=(const GPU& other);
	friend ostream& operator<<(ostream& s, const GPU& p);
	/**
 * \return a string
 */
	string ToString() {
		stringstream s;
		s << "GPU:" <<this->brand << " price:" << this->price << " processor freq:" << this->p_freq << " Nr of vCores:" << this->nr_vcores;
		return s.str();
	}
	/**
 * .
 *
 * \return a string ready for a csv file
 */
	string ToCSV() {
		stringstream ss;
		ss << this->brand << "," << this->price << "," << this->p_freq << "," << this->nr_vcores;
		return ss.str();
	}
	void edit();
private:
	int nr_vcores;
};