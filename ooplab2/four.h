#pragma onces

#include <string>
#include <iostream>

using namespace std;

class Four
{
    public:
    
        Four();
        Four(const size_t & n, unsigned char t = 0);
        Four(const std::initializer_list< unsigned char> &t);
        Four(const std::string &t);
        Four(const Four& other);
        Four(Four&& other) noexcept;

    
        Four assign(const Four& other);

        Four add(const Four& other);
        Four deduct(const Four& other);
        bool equal(const Four& other) const;
        bool greater(const Four &other) const;
        bool less(const Four &other) const;
        std::ostream& print(std::ostream& os);
        
        virtual ~Four() noexcept;
    
    private:
        size_t _size;
        unsigned char *_array;

};
