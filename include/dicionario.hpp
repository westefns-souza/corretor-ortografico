

template <class K, class V>
class Dicionario
{
public:
    Dicionario()
    {
        pairs.resize(500000);
    }

    void insert(const K &key, V value)
    {
        size_t index = hash(key) % pairs.size();

        Pair p;
        p.key = key;
        p.value = value;

        pairs[index] = p;
    }

    void remove(const K &key) {}

    bool has(const K &key)
    {
        size_t index = hash(key) % pairs.size();

        if (pairs[index].key == key)
        {
            return true;
        }

        return false;
    }

    V &get(const K &key)
    {
        size_t index = hash(key) % pairs.size();

        if (pairs[index].key == key)
        {
            return pairs[index].value;
        }

        V v;
        insert(key, v);

        return get(key);
    }

    V &operator[](const K &key)
    {
        return get(key);
    }

    size_t size() {
        return pairs.size();
    }

    void print()
    {
        size_t i = 0;
        for (auto &par : this->pairs)
        {
            if (par.key != "")
            {
                std::cout << i << ", " << par.key << std::endl;
                i++;
            }
        }
    }

private:
    struct Pair
    {
        K key;
        V value;
    };

    std::vector<Pair> pairs;

    size_t hash(const K &key)
    {
        size_t hashCode = 0;

        for (size_t i = 0; i < key.size(); ++i)
        {
            hashCode = (hashCode * 31) + static_cast<int>(key[i]);
        }

        return hashCode;
    }
};