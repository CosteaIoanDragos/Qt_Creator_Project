#include "Repo.h"
/*****************************************************************//**
 * \file   Repo.cpp
 * \brief  A repository to manage Electronics
 * 
 * \author Ioan
 * \date   May 2022
 *********************************************************************/
/**
 * Adds an element into the repository.
 * 
 * \param a
 */
void Repo::addElectronics(Electronics* a)
{
    data.push_back(a);
}
/**
 * Removes the last element from the repository.
 * 
 */
void Repo::popBack()
{
     data.pop_back();
    
}
/**
 *removes an element from the repository at a given index.
 * 
 * \param index
 */
void Repo::remove(int index)
{
    data.erase(data.begin()+index);
}
/**
 * edits an element from the repository.
 * 
 * \param index
 */
void Repo::edit(int index)
{
    this->data[index]->edit();
}



/**
 * <<Operator overload Displays the items from the repository.
 * 
 * \param s
 * \param arr
 * \return 
 */
ostream& operator<<(ostream& s, const Repo& arr)
{
    for (int i = 0; i < arr.data.size(); i++)
    {
        s << arr.data[i]->ToString() << "\n";
    }
    return s;
}




