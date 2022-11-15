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

    public :
        Contact(void);
        ~Contact(void);
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickName(void) const;
        std::string getPhoneNumber(void) const;
        int         setFirstName(std::string first);
        int         setLastName(std::string last);
        int         setNickName(std::string nick);
        int         setPhoneNumber(std::string phone);
};

#endif
