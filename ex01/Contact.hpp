#ifndef CONTACT_HPP
 # define CONTACT_HPP

#include <iostream>
#include <string.h>

class Contact {
    private :
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phoneNb;
        static int  _selected;
        static int  _numberof;
    public :
        Contact(void);
        ~Contact(void);
        std::string getFirstName(int cut) const;
        std::string getLastName(int cut) const;
        std::string getNickName(int cut) const;
        std::string getPhoneNumber(int cut) const;;
        int         getSelected(void) const;
        int         setSelected(int nb);
        int         getNumberOf(void) const;
        int         setNumberOf(int nb);
        int         setFirstName(std::string first);
        int         setLastName(std::string last);
        int         setNickName(std::string nick);
        int         setPhoneNumber(std::string phone);
};

#endif
