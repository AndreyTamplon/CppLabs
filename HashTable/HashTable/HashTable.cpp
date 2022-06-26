#include <iostream>
#include <vector>
#include <exception>
#include "HashTable.h"


HashTable::ChainLink::ChainLink(const Key& k, const Value& v, ChainLink* next, long long int hash) : name(k), parameters (v), next(next)
{
    if(hash == 0)
    {
        this->hash = CalcHash(k);
    }
    else
    {
        this->hash = hash;
    }
}

HashTable::ChainLink::ChainLink(const Key& k) : name(k), parameters(), hash(CalcHash(k))
{

}

Key HashTable::ChainLink::GetName()
{
    return name;
}

Value& HashTable::ChainLink::GetParameters()
{
    return parameters;
}

long long int HashTable::ChainLink::GetHash() const
{
    return hash;
}

HashTable::ChainLink* HashTable::ChainLink::GetNext()
{
    return  next;
}

void HashTable::ChainLink::SetParameters(const Value& v)
{
    this->parameters = v;
}

void HashTable::ChainLink::SetNext(ChainLink* next)
{
    this->next = next;
}

void HashTable::print_table() const
{
    for(int i = 0; i < table_size; ++i)
    {
        ChainLink* link = table[i];
        while (link != nullptr)
        {
            std::cout << "i = " << i << " Name = " << link->GetName() << " age = "
                      << link->GetParameters().age << " weight = " << link->GetParameters().weight << "\n";
            link = link->GetNext();
        }
    }
}

void HashTable::balanceTable()
{
    if(table_size == 0)
    {
        this->table_size = 11;
        for(int i = 0; i < table_size; ++i)
        {
            table.push_back(nullptr);
        }
        return;
    }
    size_t old_table_size = table_size;
    std::vector<ChainLink*> old_table = table;
    std::vector<ChainLink*> new_table(2 * table_size, nullptr);
    for(int i = 0; i < old_table_size; ++i)
    {
        ChainLink* link = old_table[i];
        while(link != nullptr)
        {
            if(new_table[link->GetHash() % (2 * table_size)] == nullptr)
            {
                new_table[link->GetHash() % (2 * table_size)] = new ChainLink(link->GetName(), link->GetParameters(), nullptr, link->GetHash());
            }
            else
            {
                ChainLink* new_link = new_table[link->GetHash() % (2 * table_size)];
                while (new_link->GetNext() != nullptr)
                {
                    new_link = new_link->GetNext();
                }
                new_link->SetNext(new ChainLink(link->GetName(), link->GetParameters(), nullptr, link->GetHash()));

            }
            link = link->GetNext();
        }
    }
    long long int buffer_for_amount = this->amount_of_elements;
    size_t buffer_for_size = table_size;
    this->clear();
    table_size = 2 * buffer_for_size;
    amount_of_elements = buffer_for_amount;
    table = std::move(new_table);
}

long long int CalcHash(const Key& k)
{
    long long int hash = 0, power = 1;
    for(auto i : k)
    {
        if(i < 0)
        {
            throw std::invalid_argument("Need ascii string to work");
        }
        else
        {
            hash = (hash + (i * (power))) % hash_border;
            power = (power * (alphabet_size + 1)) % hash_border;
        }
    }
    return hash;
}

void HashTable::insert(const Key& k, const Value& v)
{
    if(table_size == 0)
    {
        balanceTable();
    }
    long long int hash = (CalcHash(k));
    if(table[hash % table_size] == nullptr)
    {
        table[hash % table_size] =  new ChainLink(k, v, nullptr, hash);
    }
    else
    {
        ChainLink* link = table[hash % table_size];
        while(link != nullptr)
        {
            if(link->GetName() == k)
            {
                link->SetParameters(v);
                return;
            }
            if(link->GetNext() == nullptr)
            {
                break;
            }
            link = link->GetNext();
        }
        link->SetNext(new ChainLink(k, v, nullptr, hash));
    }
    amount_of_elements++;
    if(static_cast<double>(amount_of_elements) / static_cast<double>(table_size) >= 1.0)
    {
        balanceTable();
    }
}

bool HashTable::erase(const Key &k)
{
    if(table_size == 0)
    {
        return false;
    }
    long long int hash = CalcHash(k) % table_size;
    if(table[hash] == nullptr)
    {
        return false;
    }
    ChainLink* to_delete = table[hash];
    ChainLink* prev = table[hash];
    while(to_delete->GetName() != k)
    {
        if(to_delete->GetNext() == nullptr)
        {
            return false;
        }
        prev = to_delete;
        to_delete = to_delete->GetNext();
    }
    if(prev == to_delete)
    {
        table[hash] = nullptr;
    }
    prev->SetNext(to_delete->GetNext());
    amount_of_elements--;
    delete to_delete;
    return true;
}

void HashTable::clear()
{
    for(int i = 0; i < table_size; ++i)
    {
        while(table[i] != nullptr)
        {
            ChainLink* to_delete = table[i];
            table[i] = table[i]->GetNext();
            delete to_delete;
        }
    }
    table.clear();
    table_size = 0;
    amount_of_elements = 0;
}

bool HashTable::contains(const Key &k) const
{
    if(amount_of_elements == 0)
    {
        return false;
    }
    long long int hash = CalcHash(k) % table_size;
    if(table[hash] != nullptr)
    {

        ChainLink* link = table[hash];
        while(link != nullptr)
        {
            if(link->GetName() == k)
            {
                return true;
            }
            link = link->GetNext();
        }
    }
    return false;
}

HashTable::HashTable(long long int table_size)
{
    this->table_size = table_size;
    table = std::vector<ChainLink*>(table_size, nullptr);
}

HashTable::HashTable()
{
    this->table_size = 11;
    for(int i = 0; i < table_size; ++i)
    {
        table.push_back(nullptr);
    }
}

HashTable::~HashTable()
{
    this->clear();
}

void HashTable::swap(HashTable& b)
{
    std::swap(this->table, b.table);
    std::swap(this->table_size, b.table_size);
    std::swap(this->amount_of_elements, b.amount_of_elements);
}

HashTable::HashTable(const HashTable& b)
{
    this->table.resize(b.table_size);
    this->table_size = b.table_size;
    this->amount_of_elements = b.amount_of_elements;
    for(int i = 0; i < this->table_size; ++i)
    {
        if(b.table[i] == nullptr)
        {
            this->table[i] = nullptr;
        }
        else
        {
            this->table[i] = new ChainLink(b.table[i]->GetName(), b.table[i]->GetParameters(), nullptr, b.table[i]->GetHash());
            ChainLink* link_a = this->table[i], *link_b = b.table[i]->GetNext();
            while (link_b != nullptr)
            {
                link_a->SetNext(new ChainLink(link_b->GetName(), link_b->GetParameters(), nullptr, link_b->GetHash()));
                link_a = link_a->GetNext();
                link_b = link_b->GetNext();
            }
        }
    }
}

HashTable::HashTable(HashTable&& b) noexcept
{
    this->table = std::move(b.table);
    this->table_size = b.table_size;
    this->amount_of_elements = b.amount_of_elements;
    b.table = std::vector<ChainLink*>(0, nullptr);
    b.amount_of_elements = 0;
    b.table_size = 0;
}

HashTable& HashTable::operator=(const HashTable& b)
{
    if(*this == b)
    {
        return *this;
    }
    this->clear();
    this->table.resize(b.table_size);
    this->table_size = b.table_size;
    this->amount_of_elements = b.amount_of_elements;
    for(int i = 0; i < this->table_size; ++i)
    {
        if(b.table[i] == nullptr)
        {
            this->table[i] = nullptr;
        }
        else
        {
            this->table[i] = new ChainLink(b.table[i]->GetName(), b.table[i]->GetParameters(), nullptr, b.table[i]->GetHash());
            ChainLink* link_a = this->table[i], *link_b = b.table[i]->GetNext();
            while (link_b != nullptr)
            {
                link_a->SetNext(new ChainLink(link_b->GetName(), link_b->GetParameters(), nullptr, link_b->GetHash()));
                link_a = link_a->GetNext();
                link_b = link_b->GetNext();
            }
        }
    }
    this->amount_of_elements = b.amount_of_elements;
    return *this;
}

HashTable& HashTable::operator=(HashTable&& b) noexcept
{
    if(*this == b)
    {
        return *this;
    }
    this->clear();
    this->table = std::move(b.table);
    this->table_size = b.table_size;
    this->amount_of_elements = b.amount_of_elements;
    b.table = std::vector<ChainLink*>(0, nullptr);
    b.amount_of_elements = 0;
    b.table_size = 0;
    return *this;
}

size_t HashTable::size() const
{
    return static_cast<unsigned long long int> (table_size);
}

size_t HashTable::number_of_elements() const
{
    return static_cast<unsigned long long int> (amount_of_elements);
}

bool HashTable::empty() const
{
    for(int i = 0; i < table_size; ++i)
    {
        if(table[i] != nullptr)
        {
            return false;
        }
    }
    return amount_of_elements == 0;
}

Value& HashTable::operator[](const Key& k)
{
    if(table_size == 0)
    {
        this->insert(k, Value());
    }
    long long int hash = CalcHash(k) % table_size;
    ChainLink* link = table[hash];
    if(link != nullptr)
    {
        while(link != nullptr)
        {
            if(link->GetName() == k)
            {
                return link->GetParameters();
            }
            if(link->GetNext() == nullptr)
            {
                break;
            }
            link = link->GetNext();
        }
        link->SetNext(new ChainLink(k));
        link = link->GetNext();
    }
    else
    {
        link = new ChainLink(k);
    }
    return link->GetParameters();
}

Value& HashTable::at(const Key& k)
{
    if(table_size != 0)
    {
        long long int hash = CalcHash(k) % table_size;
        ChainLink* link = table[hash];
        if (link != nullptr)
        {
            while (link != nullptr)
            {
                if (link->GetName() == k)
                {
                    return link->GetParameters();
                }
                link = link->GetNext();
            }
        }
    }
    throw std::out_of_range("No matching element");
}

const Value& HashTable::at(const Key& k) const
{
    if(table_size != 0)
    {
        long long int hash = CalcHash(k) % table_size;
        ChainLink *link = table[hash];
        if (link != nullptr)
        {
            while (link != nullptr)
            {
                if (link->GetName() == k)
                {
                    return link->GetParameters();
                }
                link = link->GetNext();
            }
        }
    }
    throw std::out_of_range("No matching element");
}

bool operator==(const HashTable& a, const HashTable& b)
{
    if(a.table_size != b.table_size || a.amount_of_elements != b.amount_of_elements)
    {
        return false;
    }
    for(int i = 0; i < a.table_size; ++i)
    {
        HashTable::ChainLink* a_link = a.table[i];
        HashTable::ChainLink* b_link = b.table[i];
        while(a_link != nullptr)
        {
            bool match = false;
            Key a_key = a_link->GetName();
            Value a_student = a_link->GetParameters();
            b_link = b.table[i];
            while(b_link != nullptr)
            {
                if(b_link->GetName() == a_key && b_link->GetParameters() == a_student)
                {
                    match = true;
                }
                b_link = b_link->GetNext();
            }
            if(!match)
            {
                return false;
            }
            a_link = a_link->GetNext();
        }
        if(a_link != b_link)
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const HashTable& a, const HashTable& b)
{
    return !(a == b);
}

bool operator==(Student& a, Student& b)
{
    return (a.age == b.age && a.weight == b.weight);
}

Student::Student()
{
    age = 0;
    weight = 0;
}
Student::Student(unsigned age, unsigned weight) : age(age), weight(weight)
{

}