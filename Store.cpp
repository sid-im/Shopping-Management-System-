#pragma once
#include <bits/stdc++.h>
#include "Product.cpp"
using namespace std;
class Store
{
private:
    int turnOver;
    string storeName;
    map<string, Brand> brands;  // brandname to brand
    map<int, Product> products; // Id to product
public:
    Store(string storeName)
    {
        this->storeName = storeName;
    }

    bool addProduct(Product &prod)
    {
        int prodId = prod.getProductId();

        if (products.find(prodId) != products.end())
        {
            return false;
        }

        // Add product to productList
        products[prodId] = prod;

        // If brand already exists in brands list
        if (brands.find(prod.getBrandName()) != brands.end())
        {
            // append product to list of products for that brand
            brands[prod.getBrandName()].addProductToList(prodId);
        }
        else
        {
            // Else create a new brand object and then append
            Brand newBrand(prod.getBrandName(), 1039);
            brands[prod.getBrandName()] = newBrand;
            brands[prod.getBrandName()].addProductToList(prodId);
        }
        return true;
    }

    bool removeProduct(int prodId)
    {
        // If current product exists
        if (products.find(prodId) != products.end())
        {
            // Find product from brand list and erase it first
            string brandOfProduct = products[prodId].getBrandName();
            brands[brandOfProduct].eraseProductFromList(prodId);

            // Now erase product from products list
            products.erase(prodId);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool editProduct(Product &prod)
    {
        int prodId = prod.getProductId();

        if (products.find(prodId) == products.end())
        {
            return false;
        }

        // Set current product as edited product
        products[prodId] = prod;
        return true;
    }

    void displayAllProducts()
    {
        // Iterate over all products
        for (auto &it : products)
        {
            // Save into proper variables
            int prodId = it.first;
            Product prod(it.second);

            // Call printDetails function
            prod.printProductDetails();
        }
    }

    void displayProductsByBrand(string brandName)
    {
        // Extract list of procts of given brand
        set<int> prodList = brands[brandName].getProductList();

        for (auto &prodId : prodList)
        {
            // Iterate over all procts
            products[prodId].printProductDetails();
        }
    }

    void displayAllBrands()
    {
        for (auto &it : brands)
        {
            // Display details of each brand
            it.second.displayBrandDetails();
        }
    }

    // User speicific

    Product searchProductById(int prodId)
    {
        if (products.find(prodId) == products.end())
        {
            Product prod;
            return (prod);
        }
        else
            return products[prodId];
    }

    void searchProductByName(string inputString)
    {
        vector<pair<double, int>> mostRelevantId;
        for (auto &it : products)
        {
            string prodName = it.second.getProductName();
            int id = it.second.getProductId();
            double tot_len = prodName.length(), similarity = 0;

            // Prefix matching with 20% weightage
            int j = 0;
            for (int i = 0; i < prodName.length() and j < inputString.length(); i++)
            {
                if (inputString[j] == prodName[i])
                {
                    j++;
                }
                else
                    break;
            }

            similarity += ((double)j / tot_len) * 0.2;

            // Suffix matching with 20% weightage
            j = prodName.length() - 1;
            int k = 0;
            for (int i = inputString.length() - 1; i >= 0 and j >= 0; i--)
            {
                if (inputString[i] == prodName[j])
                {
                    j--;
                    k++;
                }
                else
                    break;
            }

            similarity += ((double)k / tot_len) * 0.2;

            // Find LCS using dynamic programming with 40% weightage
            int n = prodName.length(), m = inputString.length();
            int dp[n + 1][m + 1];
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int to_assign = 0;
                    if (prodName[i] == inputString[j])
                    {
                        to_assign = (1 + dp[i][j]);
                    }
                    to_assign = max(to_assign, dp[i + 1][j]);
                    to_assign = max(to_assign, dp[i][j + 1]);
                    dp[i + 1][j + 1] = to_assign;
                }
            }

            similarity += ((double)dp[n][m] / tot_len) * 0.4;

            // Check common characters with 20% weightage
            map<char, int> charStore;
            for (char ch : inputString)
            {
                charStore[ch]++;
            }
            int common = 0;
            for (char ch : prodName)
            {
                if (charStore[ch])
                {
                    common++;
                    charStore[ch]--;
                }
            }

            similarity += ((double)common / tot_len) * 0.2;

            mostRelevantId.push_back({similarity, id});
        }
        sort(mostRelevantId.begin(), mostRelevantId.end());
        reverse(mostRelevantId.begin(), mostRelevantId.end());

        while (mostRelevantId.size() > 5)
            mostRelevantId.pop_back();

        for (auto &it : mostRelevantId)
        {
            products[it.second].printProductDetails();
        }
    }

    bool bookproduct(int prodId, int units)
    {

        if (products.find(prodId) == products.end() or products[prodId].getAvailabilityCount() < units)
        {
            return false;
        }

        products[prodId].setProductCount(products[prodId].getAvailabilityCount() - units);
        cout << "Cost incurred is " << products[prodId].getCost() * units << "\n";
        cout << "for " << units << " unit(s)\n";
        cout << "Price per item: " << products[prodId].getCost() << " Rupees\n";
        return true;
    }


      std::map<int, Product> getProducts() {
        return products;

      }
};
