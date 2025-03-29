#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "item.hpp"
#include "HashTable.hpp"

using namespace std;

string removeQuotes(string line)
{
    while((line.front() == '"' || line.front() == ' ' || line.back() == '"' || line.back() == ' ') && !line.empty())
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
    int pos;
    string token;
    vector<string> Category;
    
    while((pos = catLine.find('|')) != string::npos)
    {
        token = removeQuotes(catLine.substr(0, pos));
        if (!token.empty()) {
           Category.push_back(token);
        }
        catLine.erase(0, pos + 1);
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
        infile.close();
 
}


void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line, HashTable<Item> IDHash, HashTable<Item> CatHash)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
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
        line.erase(0, line.find("<") + 1);
        line.erase(line.find(">"));
        cout << "Searching for all items with category: " << line << "..."<< endl;
        Item printItem;
        List<Item> newList;
        Node<Item>* printNode;
        newList = CatHash.searchBucket(line);
        printNode = newList.getHead();
        while(printNode != nullptr)
        {
            for (auto i : printNode->getData().getCategory())
            {
                printItem = printNode->getData();
                if(i == line)
                {
                    cout << printItem << endl;
                    break;
                }
            }
            printNode = printNode->getNext();
        }
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        //cout << "YET TO IMPLEMENT!" << endl;
    }
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
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
