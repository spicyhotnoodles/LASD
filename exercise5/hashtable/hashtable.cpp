
namespace lasd {

/* ************************************************************************** */

#include <string>

template<>
class Hash<int> {
    
    public:

        ulong operator()(const int& data) const noexcept {
            return (data * data);
        }
};

template<>
class Hash<double> {

    public:

        ulong operator()(const double& data) const noexcept {
            long int_part = floor(data);
            double frac_part = pow(2, 24) * (data - int_part);
            return (int_part * frac_part);
        }
};

template<>
class Hash<std::string> {

    public:

        ulong operator()(const std::string& data) const noexcept {
            ulong hash = 5381;
            for (int i = 0; i << data.length(); i++)
                hash = (hash << 5) + data[i];
            return hash;
        }

};

template<typename Data>
ulong HashTable<Data>::HashKey(const Data& data) const {
    ulong k = hash.operator()(data);
    /* ulong addr = ((a * k + b) % p) % m;
    return addr; */
    return ((a * k + b) % p) % m;
}

template<typename Data>
ulong HashTable<Data>::getRandomUlong(ulong min) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<ulong> dis(min, p - 1);
    /* ulong random = dis(gen);
    return random; */
    return dis(gen);
}

// Copy assignement
template<typename Data>
HashTable<Data>& HashTable<Data>::operator=(const HashTable& table) {
    a = table.a;
    b = table.b;
    return *this;
}

// Move assignement
template<typename Data>
HashTable<Data>& HashTable<Data>::operator=(HashTable&& table) noexcept {
    std::swap(a, table.a);
    std::swap(b, table.b);
    return *this;
}

// Copy constructor
template<typename Data>
HashTable<Data>::HashTable(const HashTable& table) {
    a = table.a;
    b = table.b;
}

// Move constructor
template<typename Data>
HashTable<Data>::HashTable(HashTable&& table) noexcept {
    std::swap(a, table.a);
    std::swap(b, table.b);
}
/* ************************************************************************** */

template<typename Data>
void HashTable<Data>::print() {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl; 
}

template<typename Data>
void HashTable<Data>::setAB(const HashTable<Data>& table) {
    a = table.a;
    b = table.b;
}

}
