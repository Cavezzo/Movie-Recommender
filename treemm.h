//
//  treemm.h
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#ifndef treemm_h
#define treemm_h

#include <vector>


template <typename KeyType, typename ValueType>
class TreeMultimap
{

    struct Node
    {
        Node( const KeyType& k ) : key(k)
        {
            left = right = nullptr;
        }
        const KeyType key;
        std::vector<ValueType> values;
        Node* left;
        Node* right;
    };

  public:
    class Iterator
    {
      public:
        Iterator()
        {
            isValid = false;
        }
        Iterator( Node * ptr )
        {
            COUNT = 0;
            vals = ptr->values;
            i = vals.begin();
            isValid = true;
        }

        ValueType& get_value() const
        {
            return *i;
        }

        bool is_valid() const
        {
            return isValid;
        }

        void advance()
        {
            COUNT++;
            if ( COUNT >= vals.size() )
                isValid = false;
            else
                i++;
        }

      private:
        std::vector<ValueType> vals;
        typename std::vector<ValueType>::iterator i;
        bool isValid;
        int COUNT;
    };

    TreeMultimap()
    {
        rootPtr = nullptr;
    }

    ~TreeMultimap()
    {
        freeTree(rootPtr);

    }

    void insert(const KeyType& key, const ValueType& value)
    {
        if ( rootPtr == nullptr )
        {
            rootPtr = new Node(key);
            rootPtr->values.push_back(value);
            return;
        }

        Node* p = rootPtr;
        while ( p != nullptr )
        {
            if ( p->key == key )
            {
                p->values.push_back(value);
                return;
            }
            else
            {
                if ( key < p->key )
                {
                    if ( p->left != nullptr )
                        p = p->left;
                    else
                    {
                        p->left = new Node(key);
                        p->left->values.push_back(value);
                        return;
                    }
                }
                else if ( key > p->key )
                {
                    if ( p->right != nullptr )
                        p = p->right;
                    else
                    {
                        p->right = new Node(key);
                        p->right->values.push_back(value);
                        return;
                    }
                }
            }
        }

    }

    Iterator find(const KeyType& key) const
    {

        Node* p = rootPtr;
        while ( p != nullptr )
        {
            if ( key == p->key )
                return Iterator( p );
            else if ( key < p->key )
            {
                p = p->left;
            }
            else if ( key > p->key )
            {
                p = p->right;
            }
        }

        return Iterator();

    }

  private:
    Node* rootPtr;

    void freeTree( Node* n )
    {
        if ( n == nullptr )
            return;
        freeTree( n->left);
        freeTree(n->right);

        delete n;
    }
};


#endif /* treemm_h */
