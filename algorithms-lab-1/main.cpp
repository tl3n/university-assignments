#include <iostream>
#include <vector>

const int textSize = 3;
const int patternSize = 2;

int pow(int base, int power)
{
    if (power <= 0)
        return 1;
    
    int result = base;
    for (int i = 1; i < power; ++i)
        result *= base;

    return result;
}

unsigned long long findHash(std::vector<char>& text, int index = 0)
{   
    int m = patternSize - 1;
    int hash = 0;
    for (int i = 0; i < patternSize; ++i)
    {
        hash += (text[index] * pow(10, m));
        ++index;
        --m;
    }

    return hash;
}

bool rabinKarp(std::vector<std::vector<char>>& text, std::vector<std::vector<char>>& pattern)
{   
    unsigned long long patternHashFirstRow = findHash(pattern[0]);

    std::pair index{0,0};
    bool found = false;
    for (int i = 0; i <= textSize - patternSize && found == false; ++i)
    {   
        unsigned long long textHash = 0;
        unsigned long long patternHash = patternHashFirstRow; 
        for (int j = 0; j <= textSize - patternSize; ++j)
        {
            textHash = findHash(text[i], j);
            int patternRow = 1;
            if (textHash == patternHash)
            {
                index.first = i;
                index.second = j;
                for (int k = i + 1; k < textSize && patternRow < patternSize; ++k)
                {
                    textHash = findHash(text[k], j);
                    patternHash = findHash(pattern[patternRow]);
                    
                    if (textHash != patternHash)
                    {   
                        found = false;
                        break;
                    }

                    found = true;
                    ++patternRow;
                }
            }
        }
    }

    if (found)
        std::cout << "Pattern found at " << index.first << " row, " << index.second << " column.\n"; 
    else
        std::cout << "Pattern not found in text\n";
    return found;
}

int main()
{   
    std::vector<std::vector<char>> text{{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'j', 'h'}};
    std::vector<std::vector<char>> pattern{{ 'a', 'b' }, {'d', 'e'}};
    rabinKarp(text, pattern);
    return 0;
}