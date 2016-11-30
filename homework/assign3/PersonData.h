#include <string>

class PersonData {
    private:
        std::string m_last_name;
        std::string m_first_name;
        std::string m_address;
        std::string m_city;
        std::string m_state;
        int m_zipcode;
        int m_phone;

    public:
        void set_name(std::string firstname, std::string lastname);
        void set_address(std::string address);
        void set_city(std::string city);
        void set_state(std::string state);
        void set_zip(int zip);
        void set_phone(int phone);

        void get_name() const;
        void get_address() const;
        void get_city() const;
        void get_state() const;
        void get_zip() const;
        void get_phone() const;
};
