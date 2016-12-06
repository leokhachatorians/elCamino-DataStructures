class Date {
    private:
        int month;
        int day;
        int year;
    public:
        Date(int=7, int=4, int=2005); // default values
        void set_date(int, int, int);
        int get_date();
        void show_date(void);
};

Date::Date(int mm, int dd, int yyyy) {
    month = mm;
    day = dd;
    year = yyyy;
}

int main() {
    Date d = new Date(3,1,2006);
}
