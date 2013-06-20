template <typename Object>
class List
{
    private:
        struct Node
        {
            Object data;
            Node *prev;
            Node *next;

            Node( const Object & d = Object(), Node *p = NULL, Node *n = NULL )
                : data(d), prev(p), next(n); { }
        }

    public:
            class const_iterator
            {
                public:
                    const_iterator() : current(NULL)
                    {  }

                    const Object & operator* () const
                    { return  retrieve(); }

                    const_iterator & operator++ ()
                    {
                        current = current->next;;
                        return *this;
                    }

                    const_iterator operator++ (int)
                    {
                        const_iterator old = *this;
                        ++(* this);
                        return old;
                    }

                    bool operator== (const const_iterator & rhs) const
                    { return current == rhs.current; }
                    bool operator!= (const const_iterator * rhs) const
                    { return !( *this == rhs ); }

                protected:
                    Node *current;

                    Object & retrieve() const
                    { return current->data; }

                    const_iterator(Node *p ) : current(p)
                    {  }

                    friend class List<Object>;
            }

            class iterator : public const_iterator
                { }

    public:
            List()
            {}
            List(const List & rhs)
            {}
            ~List()
            {}

            iterator begin()
            { return iterator (head->next); }
            const_iterator begin() const
            { return const_iterator(head->next); }
            iterator end()
            { return iterator(tail); }
            const_iterator end()
            { return const_iterator(tail); }

            int size() const
            { return theSize; }
            bool empty() const
            { return size() == 0; }

            void clear()
            {
                while(!empty())
                    pop_front();
            }

            Object & front()
            { return *begin(); }
            const Object & front() const
            { return *begin(); }
            Object & back()
            { return *--end(); }
            const Object & back() const
            { return *--end(); }
            void push_front(const Object & x)
            { insert(begin(), x); }
            void push_back(const Object & x)
            { insert(end(), x); }
            void pop_front()
            { erase(begin()); }
            void pop_back()
            { erase(--end()); }

            iterator insert(iterator itr, const Object & x)

            iterator erase( iterator itr)

            iterator erase(iterator start, iterator end)

    private:
            int theSize;
            Node *head;
            Node *tail;

            void init()
            {}
}
