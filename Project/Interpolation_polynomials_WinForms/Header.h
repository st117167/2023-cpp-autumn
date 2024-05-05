#pragma once


#include<iostream>
#include<vector>
#include<sstream>


std::string lagrangePolynomial(std::vector<float> x, std::vector<float> y)
{
    std::ostringstream output;

    int n = x.size();
    float coef = 1;

    output << "L(x) = ";
    for (int i = 0; i < n; i++)
    {
        coef = coef * y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                coef = coef / (x[i] - x[j]);
            }
        }

        if (coef < 0)
        {
            output << "(" << coef << ")";
        }
        else
        {
            output << coef;
        }

        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (x[j] >= 0)
                {
                    output << " * (x - " << x[j] << ")";
                }
                else
                {
                    output << " * (x + " << (-1) * x[j] << ")";
                }
            }
        }
        if (i != n - 1)
        {
            output << " + ";
        }
        coef = 1;
    }

    return output.str();
}


std::string newtonPolynomial(std::vector<float> x, std::vector<float> y)
{
    int n = x.size();
    std::vector<std::vector<float>> divided_differences(n, std::vector<float>(n));
    std::ostringstream output;

    for (int i = 0; i < n; i++)
    {
        divided_differences[i][0] = y[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            divided_differences[i][j] = (divided_differences[i + 1][j - 1] - divided_differences[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    output << "N(x) = " << divided_differences[0][0];
    for (int j = 1; j < n; j++)
    {
        if (divided_differences[0][j] != 0)
        {
            output << " + ";
            output << divided_differences[0][j];
            for (int k = 0; k < j; k++)
            {
                if (x[k] >= 0)
                {
                    output << " * (x - " << x[k] << ")";
                }
                else
                {
                    output << " * (x + " << (-1) * x[k] << ")";
                }
            }
        }
    }

    return output.str();
}


void convert(const std::string& str, std::vector<float>& arr) {
    std::istringstream iss(str);
    std::string token;

    while (std::getline(iss, token, ',')) {
        arr.push_back(std::stod(token));
    }
}


float search(std::vector<float> x, std::vector<float> y, double argumentX)
{
    float res = 0;
    for (int i = 0; i < x.size(); i++)
    {
        float term = y[i];
        for (int j = 0; j < x.size(); j++)
        {
            if (j != i) {
                term *= (argumentX - x[j]) / (x[i] - x[j]);
            }
        }
        res += term;
    }
    return res;
}
