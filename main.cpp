#include "Menu.H"
#include "WINDLOGTYPE.H"
#include <map>
#include "BinarySearchTree.h"

void print(std::pair<std::string, std::map<std::string, WindLogType>::iterator> &data)
{
    std::cout << data.first<<" "<<data.second->second<<'\n';
}

int main()
{
    std::map<std::string, WindLogType> WindLogMap;
    BST<std::pair<std::string, std::map<std::string, WindLogType>::iterator>> WindLogBST;
    std::string fileName= "met_index.txt";
    IOHelpers::ReadFileMap(WindLogMap, fileName);
    IOHelpers::StoreMapToTree(WindLogBST, WindLogMap);

    menu::Menu(WindLogBST, WindLogMap);

    //std::cout<<"InOrder"<<'\n';
    //WindLogBST.InOrderTrav(print);
    //std::cout<<"PreOrder"<<'\n';
    //WindLogBST.PreOrderTrav(print);
    //std::cout<<"PostOrder"<<'\n';
    //WindLogBST.PostOrderTrav(print);


    return 0;
}

