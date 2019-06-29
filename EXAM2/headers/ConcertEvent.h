#ifndef _CONCERT_EVENT_H_
#define _CONCERT_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "ConcertTicket.h"

class ConcertEvent : public Event {
    private:
        std::list<std::string> venue; // 
        std::string name; //name of band that is headlining the concert
        std::string opening_act; //name of opening act that performs before main band

        ConcertEvent(std::string band_name, std::string opening_band)
        {
            //Constructor that stores names of bands playing
            name = band_name;
            opening_act = opening_band;
        }

        friend class EventFactory;
    
    public:
        //Adds person into event
        ConcertTicket * add(std::string name)
        {
            venue.push_front(name); //adds name to front of venue
            std::list<std::string>::iterator front = venue.begin(); //getting iterator to the front of the venue
            return new ConcertTicket(this, front); //create new concert ticket and return it
        }

        void list()
        {
            //Shows who is playing at the event and lists all persons in the event by iterating through it.
            std::cout << "The band playing tonight is: " << name << " and the opening act is: " << opening_act << "!" << std::endl;
            for (std::list<std::string>::iterator i= venue.begin(); i != venue.end(); i++)
		    {   
			    std::cout << *i << std::endl;
			    i++;
		    }
        }

        void remove(std::list<std::string>::iterator it)
        {
            venue.erase(it); //Security asks the pereson to leave if they are not obeying rules or are being too rowdy
        }

        void chant() //Concert attendees can chant along with the music the band is playing
        {
		for (std::list<std::string>::iterator i = venue.begin(); i != venue.end(); i++) {
			std::cout << '\t' << *i << " says 'boom boom clap!'" << std::endl;
		}
	}

        void jump() //special behavior; when lead singer of band encourages audience to jump along to beat of song during instrumental
        {
            for(std::list<std::string>::iterator i = venue.begin(); i != venue.end(); i++)
            {
                std::cout << '\t' << *i << " jumps to the beat of the music as main singer says 'jump! jump! jump!'" << std::endl;
            }
        }
};

#endif