#include "Menu.H"
#include "WINDLOGTYPE.H"
#include <map>
#include "BinarySearchTree.h"


void print(monthTotalStruct &inData)
{
    std::cout<<inData.key<<" "<<inData.totalAirTemp<<'\n';
}
int main()
{
    std::map<std::string, WindLogType> WindLogMap;
    BST<monthTotalStruct> WindLogBST;
    std::string fileName= "met_index.txt";
    IOHelpers::ReadFileMap(WindLogMap, fileName);
    IOHelpers::StoreMapToTree(WindLogBST, WindLogMap);

    menu::Menu(WindLogBST, WindLogMap);

    //WindLogBST.InOrderTrav(print);
    //std::cout<<"Post Order"<<'\n';
    //WindLogBST.PostOrderTrav(print);
    return 0;
}

