

#include <bits/stdc++.h>
#include "Brand.cpp"
using namespace std;

class Product : public Brand
{
private:
    string productName;
    string category;
    int productId;
    int availabilityCount;
    int cost;

public:
    // Constructor
    Product()
    {
    }
    Product(string productName, string category, int productId, int availabilityCount, int cost, string brandName, int brandId)
        : Brand(brandName, brandId)
    {
        this->productName = productName;
        this->availabilityCount = availabilityCount;
        this->category = category;
        this->cost = cost;
        this->productId = productId;
        this->brandId = brandId;
        this->brandName = brandName;
    }

    // Setters
    void setProductId(int productId)
    {
        this->productId = productId;
    }
    void setBrandId(int brandId)
    {
        this->brandId = brandId;
    }
    void setAvailabilityCount(int availabilityCount)
    {
        this->availabilityCount = availabilityCount;
    }
    void setCost(int cost)
    {
        this->cost = cost;
    }
    void setProductName(string productName)
    {
        this->productName = productName;
    }
    void setCategory(string category)
    {
        this->category = category;
    }
    void setBrandName(string brandName)
    {
        this->brandName = brandName;
    }

    // Getters
    int getProductId()
    {
        return this->productId;
    }
    int getCost()
    {
        return this->cost;
    }
    int getBrandId()
    {
        return this->brandId;
    }
    int getAvailabilityCount()
    {
        return this->availabilityCount;
    }
    string getProductName()
    {
        return this->productName;
    }
    string getCategory()
    {
        return this->category;
    }
    string getBrandName()
    {
        return this->brandName;
    }

    void printProductDetails()
    {
        cout << "Product ID: " << this->productId << "\n";
        cout << "Product Name: " << this->productName << "\n";
        cout << "Product Brand: " << this->brandName << "\n";
        cout << "Category: " << this->category << "\n";
        cout << "Available Units: " << this->availabilityCount << "\n";
        cout << "Cost: " << this->cost << "\n";
        cout << "--------------------------\n";
    }
};
