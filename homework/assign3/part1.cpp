#include <string>
#include <iostream>

class PersonData {
    protected:
        std::string m_first_name;
        std::string m_last_name;
        std::string m_address;
        std::string m_city;
        std::string m_state;
        int m_zipcode;
        long m_phonenumber;

    public:
        PersonData(
                std::string firstname, std::string lastname,
                std::string city, std::string state,
                std::string address, int zipcode,
                long phonenumber);
        void set_name(std::string firstname, std::string lastname);
        void set_address(std::string address);
        void set_city(std::string city);
        void set_state(std::string state);
        void set_zip(int zip);
        void set_phonenumber(long phonenumber);

        std::string get_name() const;
        std::string get_address() const;
        std::string get_city() const;
        std::string get_state() const;
        int get_zip() const;
        long get_phonenumber() const;
};

PersonData::PersonData(
        std::string firstname, std::string lastname,
        std::string address, std::string city,
        std::string state, int zipcode, 
        long phonenumber) {
    m_first_name = firstname;
    m_last_name = lastname;
    m_zipcode = zipcode;
    m_phonenumber = phonenumber;
    m_city = city;
    m_state = state;
    m_address = address;
}

void PersonData::set_name(std::string first, std::string last) {
    m_first_name = first;
    m_last_name = last;
}

void PersonData::set_address(std::string address) {
    m_address = address;
}

void PersonData::set_city(std::string city) {
    m_city = city;
}

void PersonData::set_state(std::string state) {
    m_state = state;
}

void PersonData::set_zip(int zip) {
    m_zipcode = zip;
}

void PersonData::set_phonenumber(long phonenumber) {
    m_phonenumber = phonenumber;
}

std::string PersonData::get_name() const {
    return m_first_name + " " + m_last_name;
}

std::string PersonData::get_address() const {
    return m_address;
}

std::string PersonData::get_city() const {
    return m_city;
}

std::string PersonData::get_state() const {
    return m_state;
}

int PersonData::get_zip() const {
    return m_zipcode;
}

long PersonData::get_phonenumber() const {
    return m_phonenumber;
}


class CustomerData : public PersonData {
    protected:
        int m_customer_number;
        bool m_mailing_list;
    public:
        CustomerData(
                std::string firstname, std::string lastname,
                std::string address, std::string city,
                std::string state, int zipcode,
                long phonenumber, int cust_num);
        void set_customer_num(int num);
        void set_mailing_list(bool value);
        int get_customer_num() const;
        bool get_mailing_list() const;
};

CustomerData::CustomerData(
        std::string firstname, std::string lastname,
        std::string address, std::string city,
        std::string state, int zipcode,
        long phonenumber, int cust_num) : 
    PersonData(
            firstname, lastname, 
            address, city, state,
            zipcode, phonenumber) {
    m_first_name = firstname;
    m_last_name = lastname;
    m_zipcode = zipcode;
    m_phonenumber = phonenumber;
    m_customer_number = cust_num;
    m_mailing_list = false;
    m_city = "";
    m_address = "";
    m_state = "";
}

void CustomerData::set_customer_num(int num) {
    m_customer_number = num;
}

void CustomerData::set_mailing_list(bool value) {
    m_mailing_list = value;
}

int CustomerData::get_customer_num() const {
    return m_customer_number;
}

bool CustomerData::get_mailing_list() const {
    return m_mailing_list;
}

int main() {
    CustomerData cust = CustomerData(
            "leo","khachatorians",
            "Poop McGoo Dr", "Hurr City",
            "Tennesse",
            91504, 8186666666,
            1337);
    std::cout << cust.get_name() << std::endl;
    std::cout << cust.get_zip() << std::endl;
    std::cout << cust.get_phonenumber() << std::endl;
    return 0;
}
