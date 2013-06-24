temple <typename Object>
class Stack
{
    public:
        explicit Stack(int initSize = 0); :
            theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
        { objects = new Object[theCapacity]; }

        Stack(const Stack & rhs) : objects(NULL)
        { operator=(rhs);}

        ~Stack();
        { delete [] objects; }

        const Stack & operator= ( const Stack & rhs )
        {
            if(this != rhs){
                delete [] objects;
                theSize = rhs.size;
                theCapacity = rhs.theCapacity;

                objects = new Object[theCapacity()];
                for(int k = 0; k < size(); k++)
                    objects[k] = rhs.objects[k];
            }
            return * this;
        }
        void size()
        { return theSize; }

        void resize(int newSize)
        {
            if( newSize > theCapacity)
                reserve(newSize * 2 + 1);
            theSize = newSize;
        }

        void reserve(int newCapacity)
        {
            if(newCapacity < theSize)
                return ;

            Object *oldArray =objects;

            objects = new Object[newCapacity];

            for(int k = 0; k < theCapacity; k++)
                objects[k] = oldArray[k];

            theCapacity = newCapacity;

            delete [] oldArray;
        }

        Object & operator[] (int index)
        { return objects [index]; }

        const Object & operator[] (int index) const
        { return objects[index]; }

        bool empty() const
        { return size() == 0;}

        int capacity() const
        { return theCapacity; }

        void push_back(const Object & x)
        {
            if( theSize == theCapacity)
                reserve(2 * theCapacity + 1);
            objects[theSize++] = x;
        }

        void pop_back(const Object & x)
        { return objects[theSize - 1]; }

        const Object & back() const
        { return objects[thesize - 1]; }

        enum { SPARE_CAPACITY = 16 };
    private:
        int theSize;
        int theCapacity;
        Object * objects;
}
