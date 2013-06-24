template <typedef Object>
class Queue
{
    public:
        explicit Queue(int initSize = 0) :
            theSize( initSize ), theCapacity(initSize + SPARE_CAPACITY)
    { objects = new Object[ theCapacity ]; }

    Queue( const Queue & rhs ) : Object( NULL )
    { operator=(rhs); }

    ~Queue()
    { delete [] objects; }

    const Queue & operator= (const Vector &rhs )
    {
        if(this != rhs ){
            delete [] objects;
            theSize = rhs.size;
            theCapacity = rhs.theCapacity;

            objects = new Object[ theCapacity() ];
            for(int k = 0; k < size(); k++)
                objects[k] = rhs.objects[k];
        }
        return *this;
    }

    Object & operator[] (int index)
    { return objects[ index ]; }

    Object & operator[] (int index) const
    { return objects [index ]; }

    void resize(int newSize)
    {
        if( newSize > theCapacity )
            reserve( newSize * 2 + 1 );
        theSize = newSize;
    }

    void reserve(int newCapacity)
    {
        if(newCapacity < theSize)
            return ;

        Object *oldArray = objects;

        objects  = new Object[ newCapacity ];
        for(int k = 0; k < theCapacity; k++)
            objects[k] = oldArray[k];

        theCapacity = newCapacity;

        delete [] oldArray;
    }

    bool empty() const
    { return size() == 0; }

    int size() const
    { return theSize; }

    int capacity() const
    { return theCapacity; }

    void push_back(const Object & x)
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        Objects[ theSize++ ] = x;
    }

     typedef Object * iterator;
     typedef Object * const_iterator;

     iterator pop_front()
     {
        if( size() == 0 )
            return ;

        return &objects[ --size() ];
     }

     enum { SPARE_CAPACITY = 16 };
}
