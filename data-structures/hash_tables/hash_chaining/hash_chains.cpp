#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
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
    explicit QueryProcessor(int bucket_count)
    : bucket_count(bucket_count)
    , hash_table(bucket_count)
    {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for(int i = hash_table[query.ind].size() - 1; i >= 0; i--)
            {
                    std::cout << hash_table[query.ind][i] << " ";
            }
            std::cout << "\n";
            
        } else {
            if (query.type == "find")
            {
                long long q = hash_func(query.s);
                for(int i = 0; i < hash_table[q].size(); i++)
                {
                    if(query.s == hash_table[q][i])
                    {
                        std::cout << "yes\n";
                        return;
                    }
                }
                std::cout << "no\n";
            }
            else if (query.type == "add") {
                long long q = hash_func(query.s);
                for(int i = 0; i < hash_table[q].size(); i++)
                {
                    if(query.s == hash_table[q][i])
                    {
                        return;
                    }
                }
                hash_table[q].push_back(query.s);
            } else if (query.type == "del") {
                long long q = hash_func(query.s);
                for(int i = 0; i < hash_table[q].size(); i++)
                {
                    if(query.s == hash_table[q][i])
                    {
                        hash_table[q].erase(hash_table[q].begin() + i);
                        return;
                    }
                }
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
