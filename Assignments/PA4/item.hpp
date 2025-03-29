#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
    public:
    Item();
    Item(const string& newUniqID, const string& newName, const string& newBrand, const string& newAsin, const vector<string>& newCategory, const string& newUpc, const string& newLPrice, const string& newSPrice, const string& newQuantity, const string& newModelNum, const string& newAbout, const string& newSpec, const string& newTechDet, const string& newShipWeight, const string& newProdDims, const string& newImage, const string& newVariants, const string& newSku, const string& newProdUrl, const string& newStock, const string& newProdDet, const string& newDimensions, const string& newColor, const string& newIngredients, const string& newDirections, const string& newIsAmznSeller, const string& newSizeQuantVar, const string& newProdDes);
    Item(const Item& other); // Copy constructor
    ~Item();

    string getID() const;
    vector<string> getCategory() const;

    friend ostream &operator<<(ostream &os, const Item &rhs)
    {
        os << rhs.mUniqID << " " << rhs.mName << endl;
        return os;
    }

    private:
    string mUniqID;
    string mName;
    string mBrand;
    string mAsin;
    vector<string> mCategory;
    string mUpc;
    string mLPrice;
    string mSPrice;
    string mQuantity;
    string mModelNum;
    string mAbout;
    string mSpec;
    string mTechDet;
    string mShipWeight;
    string mProdDims;
    string mImage;
    string mVariants;
    string mSku;
    string mProdUrl;
    string mStock;
    string mProdDet;
    string mDimensions;
    string mColor;
    string mIngredients;
    string mDirections;
    string mIsAmznSeller;
    string mSizeQuantVar;
    string mProdDes;
};

Item::Item()
{
    mUniqID = "Empty Item";
    mName = "";
    mBrand = "";
    mAsin = "";
    mCategory = {""};
    mUpc = "";
    mLPrice = "";
    mSPrice = "";
    mQuantity = "";
    mModelNum = "";
    mAbout = "";
    mSpec = "";
    mTechDet = "";
    mShipWeight = "";
    mProdDims = "";
    mImage = "";
    mVariants = "";
    mSku = "";
    mProdUrl = "";
    mStock = "";
    mProdDet = "";
    mDimensions = "";
    mColor = "";
    mIngredients = "";
    mDirections = "";
    mIsAmznSeller = "";
    mSizeQuantVar = "";
    mProdDes = "";
}

Item::Item(const string& newUniqID, const string& newName, const string& newBrand, const string& newAsin, const vector<string>& newCategory, const string& newUpc, const string& newLPrice, const string& newSPrice, const string& newQuantity, const string& newModelNum, const string& newAbout, const string& newSpec, const string& newTechDet, const string& newShipWeight, const string& newProdDims, const string& newImage, const string& newVariants, const string& newSku, const string& newProdUrl, const string& newStock, const string& newProdDet, const string& newDimensions, const string& newColor, const string& newIngredients, const string& newDirections, const string& newIsAmznSeller, const string& newSizeQuantVar, const string& newProdDes)
{
    mUniqID = newUniqID;
    mName = newName;
    mBrand = newBrand;
    mAsin = newAsin;
    mCategory = newCategory;
    mUpc = newUpc;
    mLPrice = newLPrice;
    mSPrice = newSPrice;
    mQuantity = newQuantity;
    mModelNum = newModelNum;
    mAbout = newAbout;
    mSpec = newSpec;
    mTechDet = newTechDet;
    mShipWeight = newShipWeight;
    mProdDims = newProdDims;
    mImage = newImage;
    mVariants = newVariants;
    mSku = newSku;
    mProdUrl = newProdUrl;
    mStock = newStock;
    mProdDet = newProdDet;
    mDimensions = newDimensions;
    mColor = newColor;
    mIngredients = newIngredients;
    mDirections = newDirections;
    mIsAmznSeller = newIsAmznSeller;
    mSizeQuantVar = newSizeQuantVar;
    mProdDes = newProdDes;
}
    
Item::Item(const Item& other)
{
    mUniqID = other.mUniqID;
    mName = other.mName;
    mBrand = other.mBrand;
    mAsin = other.mAsin;
    mCategory = other.mCategory;
    mUpc = other.mUpc;
    mLPrice = other.mLPrice;
    mSPrice = other.mSPrice;
    mQuantity = other.mQuantity;
    mModelNum = other.mModelNum;
    mAbout = other.mAbout;
    mSpec = other.mSpec;
    mTechDet = other.mTechDet;
    mShipWeight = other.mShipWeight;
    mProdDims = other.mProdDims;
    mImage = other.mImage;
    mVariants = other.mVariants;
    mSku = other.mSku;
    mProdUrl = other.mProdUrl;
    mStock = other.mStock;
    mProdDet = other.mProdDet;
    mDimensions = other.mDimensions;
    mColor = other.mColor;
    mIngredients = other.mIngredients;
    mDirections = other.mDirections;
    mIsAmznSeller = other.mIsAmznSeller;
    mSizeQuantVar = other.mSizeQuantVar;
    mProdDes = other.mProdDes;
}

Item::~Item()
{
    
}

string Item::getID() const{

    return this->mUniqID;
}

vector<string> Item::getCategory() const{
    return this->mCategory;
}