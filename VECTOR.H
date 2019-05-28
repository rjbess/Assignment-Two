//Vector.h

//---------------------------------------------------------------------------------

#ifndef VECTOR_H
#define VECTOR_H

//---------------------------------------------------------------------------------

/**
	 * @class Vector
	 * @brief A template class which creates a dynamic array of input type
	 * on the heap. It does this holding a T** private attribute and pointing that to
	 * an array of pointers initially of size 10. It will then create a new T Object on the heap
	 * and point the relevant T* to it. Once the T* array has been filled it will creates
	 * a new T* array of double the size, point the T objects of the old array into the new and
	 * and initialises the remaining T* indexes to nullptr.
	 * It then deletes the old T* array by deleting the individual indexes, then the T* array and then sets the T** attribute
	 * to point to the new T* array.
	 *
	 * @author Robert Bessell
	 * @version 01
	 * @date 08/04/2019
	 *
	 */

template <class T>
class Vector
{
    public:
        Vector();
        ~Vector();
        Vector(const Vector& other);

        /**
		 * @brief  Overloads the [] operator so Vector can be used like an array.
		 *
		 * @param Index- Takes in  an int which corresponds to an index in the tArray array.
		 * @return T- The value at index
		 */
        T& operator[](const unsigned index)const;

        /**
		 * @brief  Doubles tSizeCurrent. Creates a new array of T* and points the
		 *       objects of the old T* array to the new. Deletes the old array, sets
		 * tArray to point to the new array and then initialises the new members of the array
		 *
		 * @return void
		 */
        void expand();

        /**
		 * @brief  From the tNumElements to tSizeCurrent sets tArray[index] to nullptr.
		 *
		 * @return void
		 */

        void initialise();

        /**
		 * @brief  Adds a new T object on heap and points the T* array to it
		 *
		 * Takes in a element of type T. Checks if the tNumElements is greater or equal to tSizeCurrent
		 * if so runs expand().
		 * After check it it will call tArray[index] to point the relevant T* index to the new object
		 *
		 * @param inElement- Take in a T& value.
		 * @return void
		 */

        void add(const T& inElement);

        /**
		 * @brief  Returns the number of elements in tArray
		 *
		 * @return tNumElements- Returns the current size of tArray.
		 */
        unsigned GetSize()const;

    private:
        T **tArray=nullptr; ///tArray which is a pointer to T* array
        unsigned tSizeCurrent; ///TsizeCurrent is an int of the current maximum size of tArray.
        unsigned tNumElements; ///TNumElements is the current number of indexes of the T* array.
};
template<class T>
Vector<T>::Vector()
{
    tSizeCurrent=10;
    tNumElements=0;
    tArray = new T*[tSizeCurrent];

    initialise();
}
template<class T>
Vector<T>::~Vector()
{
    for(unsigned index=0; index<tSizeCurrent;index++)
    {
        delete tArray[index];
    }
    delete [] tArray;
    tArray=nullptr;
}
template<class T>
void Vector<T>::initialise()
{
    for(unsigned index=tNumElements;index<tSizeCurrent;index++)
    {
        tArray[index]=nullptr;
    }
}
template<class T>
void Vector<T>::expand()
{
    tSizeCurrent*=2;

    T **tempTArray= new T*[tSizeCurrent];
    for(unsigned index=0;index<tNumElements;index++)
    {
        tempTArray[index]=new T(*tArray[index]);
    }
    for(unsigned index=0; index<tNumElements;index++)
    {
        delete tArray[index];
    }
    delete [] tArray;

    tArray=nullptr;

    tArray=tempTArray;

    initialise();
}
template<class T>
void Vector<T>::add(const T& inElement)
{
    if(tNumElements>=tSizeCurrent)
    {
        expand();
    }
    tArray[tNumElements++]=new T(inElement);
}
template<class T>
T& Vector<T>::operator[](const unsigned index)const
{
    if(index<0||index>tSizeCurrent)
    {
        throw("Out of bounds");
    }
    return *tArray[index];
}
template<class T>
unsigned Vector<T>::GetSize()const
{
    return tNumElements;
}
#endif // VECTOR_H
