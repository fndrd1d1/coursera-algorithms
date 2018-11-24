#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string; using std::vector; using std::cin;

class HashTable {
    int bucket_count;
    vector<vector<string> > hash_table;

    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }
public:
    explicit HashTable(int bucket_count)
    : bucket_count(bucket_count)
    , hash_table(bucket_count)
    {}

    void find(string s)
    {
        long long q = hash_func(s);
        for(unsigned int i = 0U; i < hash_table[q].size(); i++)
        {
            if(s == hash_table[q][i])
            {
                std::cout << "yes\n";
                return;
            }
        }
        std::cout << "no\n";
    }

    void add(string s)
    {
        long long q = hash_func(s);
        for(unsigned int i = 0U; i < hash_table[q].size(); i++)
        {
            if(s == hash_table[q][i])
                return;
        }
        hash_table[q].push_back(s);
    }

    void del(string s)
    {
        long long q = hash_func(s);
        for(unsigned int i = 0U; i < hash_table[q].size(); i++)
        {
            if(s == hash_table[q][i])
            {
                hash_table[q].erase(hash_table[q].begin() + i);
                return;
            }
        }
    }
};

int main() {
    int bucket_count;
    cin >> bucket_count;
    HashTable ht(bucket_count);
    ht.add("test");
    ht.find("test");
    return 0;
}
