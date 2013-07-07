#include <cstdarg>
template <class Object>
class Vector
{
    public:
        /*Constructors and Destructor*/
        explicit Vector(int initSize = 0) :
            theSize( initSize ), theCapacity(initSize + SPARE_CAPACITY)
        { objects = new Object[ theCapacity ]; }

        Vector(const Vector & rhs ) : objects( NULL )
        { operator=( rhs ); }

        Vector(int initSize, Object obj) :
            theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
        {
            objects = new Object[ initSize ];
            for(int i = 0; i < initSize; i++)
                objects[i] = obj;
        }

        ~Vector()
        { delete [] objects; }

        const Vector & operator= ( const Vector & rhs )
        {
            if( this != &rhs ){
                delete [] objects;
                theSize = rhs.size();
                theCapacity = rhs.theCapacity;

                objects = new Object[ capacity() ];
                for(int k = 0; k < size(); k++)
                    objects[k] = rhs.objects[k];
            }
            return *this;
        }

        Object & operator[] (int index)
        { return objects [ index ]; }

        const Object & operator[] (int index) const
        { return objects [ index ]; }

        /*Insert and Remove operations*/
        void resize(int newSize)
        {
            if( newSize > theCapacity )
                reserve( newSize * 2 + 1 );
            theSize = newSize;
        }

        void reserve(int newCapacity)
        {
            if (newCapacity < theSize)
                return ;

            Object *oldArray = objects;

            objects = new Object[ newCapacity ];
            for(int k = 0; k < theCapacity; k++)
                objects[k] = oldArray[k];

            theCapacity = newCapacity;

            delete [] oldArray;
        }

        bool empty() const
        { return size() == 0; }

        void clear()
        {
            int size = theSize;
        }

        void push_back(const Object & x)
        {
            if( theSize == theCapacity )
                reserve( 2 * theCapacity + 1);
            objects[ theSize++ ] = x;
        }

        void pop_back()
        { theSize--; }

       void shrink_to_fit()
       {
           if(theSize < theCapacity )
               theCapacity = theSize;
       }

        /*Nonmodifying operation*/
       typedef unsigned long size_t;

       bool operator==(const Vector & rhs)
       {
           if(size() != rhs.size())
               return false;
           else{
                for(int i = 0; i < theSize; i++){
                    if(objects[i] != rhs.objects[i])
                        return false;
                }
           }
           return true;
       }

       bool operator!=(const Vector & rhs)
       {
            if(size() != rhs.size())
                return true;
            else{
                for(int i = 0; i < theSize; i++){
                    if(objects[i] != rhs.objects[i])
                        return true;
                }
            }
            return false;
       }

       bool operator<=(const Vector & rhs);
       bool operator>=(const Vector & rhs);
       bool operator>(const Vector & rhs);
       bool operator<(const Vector & rhs);

       const size_t max_size()
       { return Object(-1) / sizeof(Object); }

       size_t size() const
       { return theSize; }

       size_t capacity() const
       { return theCapacity; }


       const Object & back () const
        { return objects[ theSize - 1 ]; }

        typedef Object * iterator;
        typedef const Object * const_iterator;

        iterator begin()
        { return &objects[0]; }

        const_iterator begin() const
        { return &objects[0]; }

        iterator end()
        { return &objects[ size() ]; }

        const_iterator end() const
        { return &objects[ size() ]; }

        enum { SPARE_CAPACITY = 16 };

    private:
        int theSize;
        int theCapacity;
        Object * objects;
};
