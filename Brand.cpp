#include <bits/stdc++.h>
using namespace std;

class Brand
{
private:
    int productCount;
    set<int> productIds;

protected:
    string brandName;
    int brandId;

public:
    // Constructor
    Brand()
    {
    }
    Brand(string brandName, int brandId)
    {
        this->brandId = brandId;
        this->brandName = brandName;
    }

    // Setters
    void setBrandId(int brandId)
    {
        this->brandId = brandId;
    }
    void setProductCount(int productCount)
    {
        this->productCount = productCount;
    }
    void setBrandName(string brandName)
    {
        this->brandName = brandName;
    }

    // Getters
    int getBrandId()
    {
        return this->brandId;
    }
    int getProductCount()
    {
        return this->productCount;
    }
    string getBrandName()
    {
        return this->brandName;
    }
    set<int> getProductList()
    {
        return this->productIds;
    }

    // Functions
    void addProductToList(int productId)
    {
        this->productIds.insert(productId);
    }

    void eraseProductFromList(int productId)
    {
        if (this->productIds.find(productId) != this->productIds.end())
        {
            this->productIds.erase(productId);
        }

    }

    void displayBrandDetails()
    {
        cout << "Brand Name: " << this->brandName << "\n";
        cout << "Brand ID: " << this->brandId << "\n";
        cout << "Number of Products: " << this->productIds.size() << "\n";
        cout << "......................\n";
    }
};
