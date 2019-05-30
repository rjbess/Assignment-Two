//BinarySearchTree.h

//---------------------------------------------------------------------------------

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

//---------------------------------------------------------------------------------
template<typename T>
using flTyp= void (*)( T &);


    /**
	 * @class BST
	 * @brief  Creates a binary search tree
	 *
	 * When created in client the rootnode pointer attribute will be set to
	 * nullptr. The client will then use the public methods to insert, search,
	 * remove values of the tree or print the tree, In Order, Post Order or Pre Order
	 * These public methods call the private methods counterpart which will interact with the data.
	 * The node struct which holds the data as well as pointer to its children and parent, is
	 * encapsulated in the private field.
	 *
	 * @author Robert Bessell
	 * @version 01
	 * @date 16/05/2019 Robert Bessell
	 *
	 * @todo Implement a balancing system
	 * @todo Implement a input validation system
	 * @bug The tree can become unbalanced
	 * @bug Remove function cannot handle inputted values
	 *      that arent in the tree and will delete a leaf
	 */

template <class T>
class BST
{
    private:
            /// Defines a single node used in the tree
        struct node
        {
                ///Data input stored
            T data;
                ///Position of the left child node
            node *leftPointer;
                ///Position of the right child node
            node *rightPointer;
                ///Position of the parent node
            node *parentPointer;
        };
            ///A node pointer which is used to find the base node of the tree
        node *rootNode;

            /**
             * @brief  Deletes all nodes in the tree
             *
             * Called by the destructor is is passed in the root node
             * and will recursively traverse the tree left to right deleting the nodes.
             *
             * @param  inNode - The rootnode pointer
             * @return void
             */
        void DeleteTree(node *inNode);
            /**
             * @brief  Creates a new tree on the heap equal to a pass
             *
             * Invoked by the Copy Constructor and the operator = methods.
             * Works by being passed in the rootNode of the tree wanting to be copied.
             * Then creating a new node struct on the heap, copying the data value over.
             * It then recusively calls itself for the left and
             * right pointers.
             * It at the end it returns the newly created tree back to the caller method
             * to be set as the new trees rootnode.
             *
             * @param  inRootNode - Pointer to the root node of the tree wanting to be copied
             * @return node*    - A node pointer that is the same as the copied pointer.
             */
        node* CopyTree(node* inNode);
            /**
             * @brief  Adds a newly created node to the tree
             *
             * Invoked by the public insert method. Takes in two node pointers, one the rootnode
             * and also the newly created node. It the will check if the data is less or greater
             * then the rootnode data and then will search if the relevant pointer position
             * is available ie equal to null pointer. If its available it will set the
             * rootnodes pointer to it and its parent pointer to rootnode. IF the position is not available
             * it will call itself using the relevant rootnode direction pointer and the new node until
             * a free spot is available.
             *
             * @param  inRootNode - Pointer to the root node, inNode - The newly created node struct.
             * @return void
             */
        void Insert(node  *inRootNode, node *inNode);
            /**
             * @brief  Adds a newly created node to the tree
             *
             * Invoked by the public remove method. Takes in one the rootnode
             * and the data to be removed. Checks if the current node data is equal to the inputted data
             * if not it will recursively call itself using the relevant rootnode position pointer and
             * the inputted data until it finds the node with the required data. Once the node is found
             * it seperated into 3 options- If the node has no children it simply deletes the node
             *  and alters the parents node pointers. If it has only one child it changes the structure so
             * that the nodes parent points to the child and vice versa, then then node is deleted.
             * Finally if the node has two children it finds the next sequential node ie the node
             * on the further left of the targeted nodes right child. It the copies the value of
             * the sequential node into the targeted node and recursivly calls itself to delete
             * the sequential node.
             *
             * @param  inRootNode - Pointer to the root node, inNode - The newly created node struct.
             * @return void
             */
        void Remove(node* &inRootNode, const T inData);
            /**
             * @brief  Searches the tree for the inputed value
             *
             * Invoked by the public search method. Takes in one the rootnode
             * and the data to be search. Checks if the wanted data is in the inputed node
             * if so it returns the position of that node. If it isnt it call itself again
             * with the relevant position pointer of the inputed node and the wanted value.
             * It will search itself until the value is found and then will return that
             * nodes position or if it isnt found will return nullptr.
             *
             * @param  inRootNode - Pointer too the root node, inData - The wanted value.
             * @return node* - The Position of the wanted value
             */
        node* Search(node *inNode, T inData)const;
            /**
             * @brief  Prints Out the Trees Data in Order
             *
             * Invoked by the public method. Passed in the root node it will call itself
             * and printed the content of the tree right far left to far right.
             * From smallest data members to largest.
             *
             * @param  inRootNode - Pointer too the root node
             * @return void
             */
        void InOrderTrav(node *inNode, flTyp<T> fl)const;
            /**
             * @brief  Prints Out the Trees Data From Top to Bottom, Left to Right
             *
             * Invoked by the public method. Passed in the root node it will call itself
             * and printed the content of the tree starting at the base working
             * itselft down the left and then to the right. Once the left side is complete
             * It will work down the right from top to bottom left and then right.
             *
             * @param  inRootNode - Pointer too the root node
             * @return void
             */
        void PreOrderTrav(node *inNode, flTyp<T> fl)const;
            /**
             * @brief  Prints Out the Trees Data From Bottom to Top, Left to Right
             *
             * Invoked by the public method. Passed in the root node it will call itself
             * and printed the content of the tree starting at the bottom left leaf, working
             * itselft up  then to the right. Once the left side is complete
             * It will work down the right from bottom left to right. Once both sides are
             * complete the base data is printed
             *
             * @param  inRootNode - Pointer too the root node
             * @return void
             */
        void PostOrderTrav(node *inNode, flTyp<T> fl)const;
            /**
             * @brief  Finds the Node with the Smallest Data Value Connect to a Child of the Inputted Node
             *
             * Invoked by the public method. Passed in a node pointer and will
             * recursivly search for the lowest left data member. ie when a node
             * has no left child it is deem as the lowest value.
             * Used in the remove function when a node has two children.
             *
             * @param  inNode- Pointer too the starting node
             * @return node* - Position of the minimum value
             */
        node* Minimum(node *inNode);
            /**
             * @brief  Sets the children node to the inputted node
             *
             * Invoked by the Copy Constructor and the overloaded = operator.
             * Takes in a node and creates a temporary node pointer.
             * Checks to see if the inputed node has a left child. If so
             * sets the temperory node to that and then sets the temporary
             * nodes parent pointer to the inputted node. Then will recursvily
             * call itself until a left children = nullptr. Ten it will check the right side
             * and recursivly call and set itself.
             *
             * @param  inNode - The parent pointer of the node to be set
             * @return void
             */

        void SetCopyParentPtr(node* inNode);

    public:
            /**
             * @brief  Constructor
             *
             * Sets rootNode to nullptr.
             * @return void
             */
        BST();
            /**
             * @brief  Destructor
             *
             * Passes in the rootnode to the deletetree function
             * @return void
             */
        ~BST();
            /**
             * @brief  Copy Constructor
             *
             * Passed in the reference to the old tree. It sets the new trees
             * rootNode to nullptr, it then sets root to a copy of the old tree
             * by passing the old trees rootNode into the CopyTree function.
             *
             * @param oldTree- Constant reference to the tree wanting to be copied.
             * @return void
             */
        BST(const BST<T> &oldTree);
            /**
             * @brief  Overloaded = Operator
             *
             * Firstly deletes the contents of the Left hand side tree by
             * passing its rootNode to the DeleteTree function.
             * Then passings in the oldTrees rootNode into the CopyTree
             * method and sets the rootNode of the left hand side to the
             * the right hand side. It the returns the dereferenced pointer
             *
             * @param oldTree- Constant reference to the tree wanting to be copied.
             * @return *this
             */
        BST<T>&operator =(const BST<T>&);
            /**
             * @brief  Creates a new node and passes it to be inserted in the tree
             *
             * Creates a new node on the heap. Sets the data value equal to the inputed value
             * and pointers to nullptr. Checks to see in rootptr equals nulltpr ie empty.
             * If so sets the new node to it else passes the rootptr and new node to the private
             * insert method.
             *
             * @param inData- T data value to be inserted.
             * @return void
             */
        void Insert(const T inData);
            /**
             * @brief  Calls the private remove method
             *
             * Takes in the data to be removed. Then passes then rootnode
             * and data to the private remove method.
             *
             * @param inData- T data value to be removed.
             * @return void
             */
        void Remove(const T inData);
            /**
             * @brief  Searches Tree for value, Prints out relevant message
             *
             * Creates a temp node pointer equal to nullptr. Then calles the private Search function
             * passing in the rootnode and wanted data. That will either return the position of the node
             * or nulltptr depending on whether the data is in the tree, temp node is set to that return.
             * If node wasnt found prints out 'Input not found' else prints out the position of the node
             *
             * @param inData- T data value to be searched.
             * @return void
             */
        T Search(T inData);
            /**
             * @brief  Calls the private In Order Traversal method
             *
             * Calls the private In Order traversal passing in the rootnode so it
             * prints all of the tree.
             * @param
             * @return void
             */
        void InOrderTrav(flTyp<T> fl)const;
            /**
             * @brief  Calls the private Pre Order Traversal method
             *
             * Calls the private Pre Order traversal passing in the rootnode so it
             * prints all of the tree.
             * @param
             * @return void
             */
        void PreOrderTrav(flTyp<T> fl)const;
            /**
             * @brief  Calls the private Post Order Traversal method
             *
             * Calls the private Post Order traversal passing in the rootnode so it
             * prints all of the tree.
             * @param
             * @return void
             */
        void PostOrderTrav(flTyp<T> fl)const;
};
template <typename T>
BST<T>::BST()
{
    rootNode=nullptr;
}
template <typename T>
BST<T>::~BST()
{
    DeleteTree(rootNode);
}
template <typename T>
BST<T>::BST(const BST<T> &oldTree)
{
    rootNode=nullptr;
    rootNode=CopyTree(oldTree.rootNode);
    SetCopyParentPtr(rootNode);
}
template <typename T>
typename BST<T>::node* BST<T>::CopyTree(node* inNode)
{
    if(inNode==nullptr)
    {
        return nullptr;
    }
    node* newTreeNode= new node;
    newTreeNode->data=inNode->data;
    newTreeNode->leftPointer= nullptr;
    newTreeNode->rightPointer= nullptr;
    newTreeNode->parentPointer=nullptr;

    newTreeNode->leftPointer=CopyTree(inNode->leftPointer);
    newTreeNode->rightPointer=CopyTree(inNode->rightPointer);

    return newTreeNode;
}
template <typename T>
BST<T>& BST<T>::operator =(const BST<T> &oldTree)
{
    DeleteTree(rootNode);
    rootNode=nullptr;
    rootNode= CopyTree(oldTree.rootNode);
    SetCopyParentPtr(rootNode);
    return *this;
}
template <typename T>
void BST<T>::DeleteTree(node *inNode)
{
    if(inNode!=nullptr)
    {
        DeleteTree(inNode->leftPointer);
        DeleteTree(inNode->rightPointer);
        delete inNode;
    }
}
template <typename T>
void BST<T>::Insert(const T inData)
{
    node * tempNode= new node ;
    tempNode->data= inData;
    tempNode->leftPointer= nullptr;
    tempNode->rightPointer= nullptr;
    tempNode->parentPointer=nullptr;

    if(rootNode==nullptr)
    {
        rootNode=tempNode;
    }
    else
    {
        Insert(rootNode, tempNode);
    }
}
template <typename T>
void BST<T>::Insert(node  *inRootNode, node  *inNode)
{
    if(inNode->data<inRootNode->data && inRootNode->leftPointer==nullptr)
    {
        inRootNode->leftPointer=inNode;
        inNode->parentPointer=inRootNode;
    }
    else if(inNode->data>inRootNode->data && inRootNode->rightPointer==nullptr)
    {
        inRootNode->rightPointer=inNode;
        inNode->parentPointer=inRootNode;
    }
    if(inNode->data<inRootNode->data && inRootNode->leftPointer!=nullptr)
    {
        Insert(inRootNode->leftPointer, inNode);
    }
    else if(inNode->data>inRootNode->data && inRootNode->rightPointer!=nullptr)
    {
        Insert(inRootNode->rightPointer, inNode);
    }
}
template <typename T>
void BST<T>::Remove(const T inData)
{
    Remove(rootNode, inData);
}
template <typename T>
void BST<T>::Remove(node* &inRootNode, const T inData)
{
    node* tempPtr=nullptr;
    node* tempPtrTwo=nullptr;
    node* tempPtrThree=nullptr;
    if(inData<inRootNode->data && inRootNode->leftPointer!=nullptr)
    {
        Remove(inRootNode->leftPointer, inData);
    }
    else if(inData>inRootNode->data && inRootNode->rightPointer!=nullptr)
    {
        Remove(inRootNode->rightPointer, inData);
    }
    else
    {
        if(inRootNode->leftPointer==nullptr && inRootNode->rightPointer==nullptr)
        {
            tempPtr=inRootNode;
            tempPtrTwo=inRootNode->parentPointer;
            if(tempPtr->data<tempPtrTwo->data)
            {
                tempPtrTwo->leftPointer=nullptr;
                delete tempPtr;
                inRootNode=nullptr;

            }
            else if(tempPtr->data>=tempPtrTwo->data)
            {
                tempPtrTwo->rightPointer=nullptr;
                delete tempPtr;
                inRootNode=nullptr;
            }
        }
        else if(inRootNode->leftPointer!=nullptr && inRootNode->rightPointer==nullptr)
        {
            tempPtr=inRootNode;
            tempPtrTwo=inRootNode->parentPointer;
            tempPtrThree=inRootNode->leftPointer;

            if(tempPtr->data<tempPtrTwo->data)
            {
                tempPtrTwo->leftPointer=tempPtrThree;
            }
            else if(tempPtr->data>=tempPtrTwo->data)
            {
                tempPtrTwo->rightPointer=tempPtrThree;
            }
            tempPtrThree->parentPointer=tempPtrTwo;

            delete tempPtr;
            tempPtr=nullptr;
        }
        else if(inRootNode->leftPointer==nullptr && inRootNode->rightPointer!=nullptr)
        {
            tempPtr=inRootNode;
            tempPtrTwo=inRootNode->parentPointer;
            tempPtrThree=inRootNode->rightPointer;

            if(tempPtr->data<tempPtrTwo->data)
            {
                tempPtrTwo->leftPointer=tempPtrThree;
            }
            else if(tempPtr->data>=tempPtrTwo->data)
            {
                tempPtrTwo->rightPointer=tempPtrThree;
            }
            tempPtrThree->parentPointer=tempPtrTwo;

            delete tempPtr;
            tempPtr=nullptr;
        }
        else
        {
            tempPtr= Minimum(inRootNode->rightPointer);
            inRootNode->data=tempPtr->data;

            Remove(tempPtr, tempPtr->data);
        }
    }
}
template <typename T>
T BST<T>::Search(const T inData)
{
    node* tempNode=nullptr;
    tempNode= Search(rootNode, inData);

    return tempNode->data;
}
template <typename T>
typename BST<T>::node* BST<T>::Search(node *inNode, T inData)const
{
    if(inNode==nullptr || inData==inNode->data)
    {
        return inNode;
    }
    if(inData<inNode->data)
    {
        return Search(inNode->leftPointer, inData);
    }
    else
    {
        return Search(inNode->rightPointer, inData);
    }
}
template <typename T>
void BST<T>::InOrderTrav(flTyp<T> fl)const
{
    InOrderTrav(rootNode, fl);
}
template <typename T>
void BST<T>::InOrderTrav(node  *inNode, flTyp<T> fl)const
{
    if(inNode!=nullptr)
    {
        InOrderTrav(inNode->leftPointer, fl);

        fl(inNode->data);

        InOrderTrav(inNode->rightPointer, fl);
    }
}
template <typename T>
void BST<T>::PreOrderTrav(flTyp<T> fl)const
{
    PreOrderTrav(rootNode, fl);
}
template <typename T>
void BST<T>::PreOrderTrav(node  *inNode, flTyp<T> fl)const
{
    if(inNode!=nullptr)
    {
        fl(inNode->data);

        PreOrderTrav(inNode->leftPointer, fl);

        PreOrderTrav(inNode->rightPointer, fl);
    }
}
template <typename T>
void BST<T>::PostOrderTrav(flTyp<T> fl)const
{
    PostOrderTrav(rootNode, fl);
}
template <typename T>
void BST<T>::PostOrderTrav(node  *inNode, flTyp<T> fl)const
{
    if(inNode!=nullptr)
    {
        PostOrderTrav(inNode->leftPointer, fl);

        PostOrderTrav(inNode->rightPointer, fl);

        fl(inNode->data);
    }
}
template <typename T>
typename BST<T>::node* BST<T>::Minimum(node *inNode)
{
    while(inNode->leftPointer!=nullptr)
    {
       inNode=Minimum(inNode->leftPointer);
    }
    return inNode;
}
template <typename T>
void BST<T>::SetCopyParentPtr(node* inNode)
{
    node* tempPtr=nullptr;

    if(inNode->leftPointer!=nullptr)
    {
        tempPtr=inNode->leftPointer;
        tempPtr->parentPointer=inNode;
        SetCopyParentPtr(tempPtr);
    }
    if(inNode->rightPointer!=nullptr)
    {
        tempPtr=inNode->rightPointer;
        tempPtr->parentPointer=inNode;
        SetCopyParentPtr(tempPtr);
    }
}
#endif // BinarySearchTree_h
