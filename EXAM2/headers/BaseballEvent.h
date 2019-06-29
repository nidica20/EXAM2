#ifndef _BASEBALL_EVENT_H_
#define _BASEBALL_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "BaseballTicket.h"

// FIXME 2: Create BaseballEvent and BaseballTicket to for good baseball games!
// FIXME 2a: Create a function stretch so that the attendees can stand up an stretch for the 7th inning
// FIXME 3: Update EventFactory::factory() to allow it to be the ONLY method for creating a BaseballEvent
/**
* BaseballEvent is derived from Event
*/
class BaseballEvent : public Event
{
    private:
        std::list<std::string> stadium;
        std::string hometeam;
        std::string visitingteam;

        BaseballEvent(std::string home, std::string visiting)
        {
            //Store the home and visiting teams
            home = hometeam;
            visiting = visitingteam;
        }

        friend class EventFactory;

    public:
        BaseballTicket * add(std::string name)
        {
            stadium.push_front(name); //adds name to front of stadium
            std::list<std::string>::iterator front = stadium.begin(); //getting iterator to the front of the stadium
            return new BaseballTicket(this, front); ///creating new baseball ticket and returning it
        }

        void list()
        {
            //Lists or states the home team and visiting team participating in this Baseball Event
            std::cout << "The home team is: " << hometeam << "!" << std::endl;
            std::cout << "The visiting team is: " << visitingteam << "!" << std::endl;

            //Lists all the persons currently in the event iterating through it
            for (std::list<std::string>::iterator i= stadium.begin(); i != stadium.end(); i++)
		    {
			    std::cout << *i << std::endl;
			    i++;
		    }
        }

        void remove(std::list<std::string>::iterator it)
        {
            stadium.erase(it); //Ushers ask the person to leave if they are getting out of hand
        }

        void chant() //Baseball fans can chant
        {
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " says 'boom boom clap!'" << std::endl;
		}
	}

        void stretch() //7th inning stretch for baseball events, where all attendees stand up and stretch
        {
            for(std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++)
            {
                std::cout << '\t' << *i << " stands up and sings 'Take Me Out to the Ball Game!'" << std::endl;
            }
        }

};

#endif