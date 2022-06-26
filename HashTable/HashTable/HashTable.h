#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H
struct Student {
    unsigned age;
    unsigned weight;
    Student();
    Student(unsigned age, unsigned weight);
    friend bool operator==(Student& a, Student& b);
};

typedef std::string Key;
typedef Student Value;
enum {alphabet_size = 256, hash_border = 9223372036854775};
long long int CalcHash(const Key& k);


class HashTable
{
private:
    class ChainLink
    {
    private:
        Key name;
        Value parameters;
        long long int hash;
        ChainLink* next = nullptr;
    public:
        ChainLink(const Key& k, const Value& v, ChainLink* next = nullptr, long long int hash = 0);
        explicit ChainLink(const Key& k);
        Key GetName();
        Value& GetParameters();
        long long int GetHash() const;
        ChainLink* GetNext();
        void SetParameters(const Value& v);
        void SetNext(ChainLink* next);
    };
    std::vector <ChainLink*> table;
    size_t table_size;
    long long int amount_of_elements = 0;
    void balanceTable();
public:
    explicit HashTable(long long int table_size);
    HashTable();
    ~HashTable();

    HashTable(const HashTable& b);
    HashTable(HashTable&& b) noexcept;

    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable&& b) noexcept;

    friend long long int CalcHash(const Key& k);

    void swap(HashTable& b);

    void clear();

    bool erase(const Key& k);
    void insert(const Key& k, const Value& v);


    bool contains(const Key& k) const;
    Value& operator[](const Key& k);
    Value& at(const Key& k);
    const Value& at(const Key& k) const;
    void print_table() const;

    size_t size() const;
    size_t number_of_elements() const;

    bool empty() const;

    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);
};
#endif //HASHTABLE_HASHTABLE_H

