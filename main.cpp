#include "Menu.H"
#include "WINDLOGTYPE.H"
#include <map>
#include "BinarySearchTree.h"

int main()
{
    std::map<std::string, WindLogType> WindLogMap;
    BST<monthTotalStruct> WindLogBST;
    BST<std::pair<std::string, WindLogType>> WindLogDayBST;

    std::string fileName= "met_index.txt";

    IOHelpers::ReadFileMap(WindLogMap, fileName);
    IOHelpers::StoreMapToMonthTree(WindLogBST, WindLogMap);
    IOHelpers::StoreMapToDayTree(WindLogDayBST, WindLogMap);

    menu::Menu(WindLogBST, WindLogDayBST);


    return 0;
}

