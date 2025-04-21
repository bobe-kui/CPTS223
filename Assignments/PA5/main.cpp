#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "item.hpp"
#include "HashTable.hpp"

using namespace std;

void testSort(string categorySearch, HashTable<Item> CatHash)
{
    clock_t start, end, k;    
    int size;

    List<Item> insert = CatHash.searchBucket(categorySearch);
    List<Item> insertDesc = CatHash.searchBucket(categorySearch);
    List<Item> merge = CatHash.searchBucket(categorySearch);
    List<Item> mergeDesc = CatHash.searchBucket(categorySearch);
    size = insert.listToVector().size();

    cout << "Searching for all items with category: " << categorySearch << "(" << size << " items)"<<  "..."<< endl;

    k = clock();
        do start = clock();
        while(start == k);
    insert = insert.insertionSort();
    end = clock();
    cout << "Sort Type: Insertion" << endl << "Time Elapsed: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s " << endl << endl;

    k = clock();
    do start = clock();
    while(start == k);
    insertDesc = insertDesc.insertionSortDesc();
    end = clock();
    cout << "Sort Type: Insertion Descending" << endl << "Time Elapsed: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s " << endl << endl;


    k = clock();
    do start = clock();
    while(start == k);
    merge = merge.mergeSort();
    end = clock();
    cout << "Sort Type: Merge" << endl << "Time Elapsed: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s " << endl << endl;


    k = clock();
    do start = clock();
    while(start == k);
    mergeDesc = mergeDesc.mergeSortDesc();
    end = clock();
    cout << "Sort Type: Descending" << endl << "Time Elapsed: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s " << endl << endl;

}

string removeQuotes(string line)
{
    while(!line.empty() && (line.front() == '"' || line.front() == ' ' || line.back() == '"' || line.back() == ' '))
    {
        if(line.front() == '"' || line.front() == ' ')
        {
            line.erase(0, 1);
        }
        if(line.back() == '"' || line.back() == ' ')
        {
            line.pop_back();
        }  
    }

    return line;
}

string parseInfo(string &readLine)
{
    string returnLine;
    int pos = 0;
    if(readLine.empty())
    {
        return "";
    }
    if(readLine.front() == '"')
    {
        readLine.erase(0,1);
        pos = readLine.find("\",") + 1;
    }
    else
    {
        pos = readLine.find(',');
    }
    returnLine = removeQuotes(readLine.substr(0, pos));
    readLine.erase(0, pos+1);
    return returnLine;
}

vector<string> parseCategories(string catLine)
{
    unsigned int pos;
    string token = "a";
    string duplicateCheck = "";
    vector<string> Category;
    
    while((pos = catLine.find('|')) != string::npos)
    {
        if(token == duplicateCheck)
        {
            break;
        }
        else{
            token = removeQuotes(catLine.substr(0, pos));
            duplicateCheck = token;
            if (!token.empty()) {
               Category.push_back(token);
            }
            catLine.erase(0, pos + 1);
        }

    }
    if (!catLine.empty()) {
        Category.push_back(removeQuotes(catLine));
    }
    return Category; // Ensure the function returns the vector
}

void readFile(HashTable<Item>& IDHash, HashTable<Item>& CatHash)
{
    ifstream infile("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv", ios::in);
    if (!infile.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    string newLine = "";
    vector<string> Category;
    string UniqID, Name, Brand, Asin, Upc, LPrice, SPrice, Quantity, ModelNum, About, Spec, TechDet, ShipWeight,
         ProdDims, Image, Variants, Sku, ProdUrl, Stock, ProdDet, Dimensions, Color, Ingredients, Directions, IsAmznSeller, SizeQuantVar, ProdDes;
    getline(infile, newLine, '\n');
    while(getline(infile, newLine, '\n'))
     {
        try
        {
            UniqID = parseInfo(newLine);
            Name = parseInfo(newLine);
            Brand = parseInfo(newLine);
            Asin = parseInfo(newLine);
            Category = parseCategories(parseInfo(newLine));
            Upc = parseInfo(newLine);
            LPrice = parseInfo(newLine);
            SPrice = parseInfo(newLine);
            Quantity = parseInfo(newLine);
            ModelNum = parseInfo(newLine);
            About = parseInfo(newLine);
            Spec = parseInfo(newLine);
            TechDet = parseInfo(newLine);
            ShipWeight = parseInfo(newLine);
            ProdDims = parseInfo(newLine);
            Image = parseInfo(newLine);
            Variants = parseInfo(newLine);
            Sku = parseInfo(newLine);
            ProdUrl = parseInfo(newLine);
            Stock = parseInfo(newLine);
            ProdDet = parseInfo(newLine);
            Dimensions = parseInfo(newLine);
            Color = parseInfo(newLine);
            Ingredients = parseInfo(newLine);
            Directions = parseInfo(newLine);
            IsAmznSeller = parseInfo(newLine);
            SizeQuantVar = parseInfo(newLine);
            ProdDes = parseInfo(newLine);
    
            Item newItem(UniqID, Name, Brand, Asin, Category, Upc, LPrice, SPrice, Quantity, ModelNum, About, Spec, TechDet, ShipWeight, ProdDims, Image, Variants, Sku, ProdUrl, Stock, ProdDet, Dimensions, Color, Ingredients, Directions, IsAmznSeller, SizeQuantVar, ProdDes);
            IDHash.insertItem(UniqID, newItem);
            for(const auto& i : Category)
            {
                CatHash.insertItem(i, newItem);
            }  
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error paring line: " << newLine << endl;
            cerr << "Exception: " << e.what() << endl;
        }
        

    }
        infile.close();
 
}


void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Sorts all of the items in a category in ascending order using insertion sort" << endl;
    cout << " 3. listInventory <category_string> desc - Sorts all of the items in a category in descending order using insertion sort" << endl;
    cout << " 4. listInventory <category_string> merge - Sorts all of the items in a category in ascending order using merge sort" << endl;
    cout << " 5. listInventory <category_string> merge desc - Sorts all of the items in a category in descending order using merge sort" << endl;
    cout << " 6. test - Directly compares the sorting algorithm times for Puzzles (Small Set) and Toys & Games (Large Set)" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0) ||
           (line.rfind("test") == 0);
}

void evalCommand(string line, const HashTable<Item>& IDHash, const HashTable<Item>& CatHash)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        if(line.find("<") == string::npos || line.find(">") == string::npos)
        {
            cout << "Invalid command format" << endl;
            return;
        }
        Item newItem;
        line.erase(0, line.find("<") + 1);
        line.erase(line.find(">"));
        // Look up the appropriate datastructure to find if the inventory exist
        cout << "Searching for: " << line << "..."<< endl;
        newItem = IDHash.searchItem(line);
        if(newItem.getID() == "Empty Item")
        {
            cout << "Item not found" << endl;
        }
        else
        {
            cout << newItem << endl;
        }
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {   
        if(line.find("<") == string::npos || line.find(">") == string::npos)
        {
            cout << "Invalid command format" << endl;
            return;
        }

        string categorySearch;

        categorySearch = line.substr(line.find("<") + 1);
        categorySearch.erase(categorySearch.find(">"));
        cout << "Searching for all items with category: " << categorySearch << "..."<< endl;
        
        Item printItem;
        Node<Item>* printNode;
        List<Item> newList = CatHash.searchBucket(categorySearch);
        if(!newList.isEmpty())
        {
            if(line.rfind("merge desc") != string::npos && line.rfind("merge desc") > line.rfind(">"))
            {
                newList = newList.mergeSortDesc();
            }
            else if(line.rfind("merge") != string::npos && line.rfind("merge") > line.rfind(">"))
            {
                newList = newList.mergeSort();
            }
            else if(line.rfind("desc") != string::npos && line.rfind("desc") > line.rfind(">"))
            {
                newList = newList.insertionSortDesc();
            }
            else
            {
                newList = newList.insertionSort();
            }
            printNode = newList.getHead();
            while(printNode != nullptr)
            {
                for (auto i : printNode->getData().getCategory())
                {
                    printItem = printNode->getData();
                    if(i == categorySearch)
                    {
                        cout << printItem << endl;
                        break;
                    }
                }
                printNode = printNode->getNext();
            }
        }
        else
        {
            cout << "Items with category: " << categorySearch << " not found" << endl;
        }
    }
    else if (line.rfind("test") == 0)
    {
        testSort("Puzzles", CatHash);
        testSort("Toys & Games", CatHash);
    }
    else
    {
        cout << "Command not supported. Enter :help for a list of supported commands" << endl;
    }
    
}


void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
}

int main(int argc, char const *argv[])
{
    HashTable<Item> IDHash, CatHash;
    string line;
    readFile(IDHash, CatHash);
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, IDHash, CatHash);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
