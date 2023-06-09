
#include <iostream>
#include <string>

class IPAddress {
public:
    IPAddress(const std::string& address) : ipAddress(address) {}
    IPAddress(const IPAddress& other) : ipAddress(other.ipAddress) {}
    virtual ~IPAddress() {}

    virtual void print() const {
        std::cout << ipAddress << std::endl;
    }

protected:
    std::string ipAddress;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(const std::string& address, bool correct)
        : IPAddress(address), isCorrect(correct) {}

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), isCorrect(other.isCorrect) {}

    void print() const override {
        IPAddress::print();
        std::cout << (isCorrect ? " - Correct" : " - Not Correct") << std::endl;
    }

private:
    bool isCorrect;
};

int main() {
    std::string address1, address2, address3;

    std::cout << "Enter the first IP address: ";
    std::cin >> address1;

    std::cout << "Enter the second IP address: ";
    std::cin >> address2;

    std::cout << "Enter the third IP address: ";
    std::cin >> address3;

    IPAddress ip1(address1);
    IPAddressChecked ipChecked1(address2, false);
    IPAddressChecked ipChecked2(address3, true);

    ip1.print();
    ipChecked1.print();
    ipChecked2.print();

    return 0;
}

