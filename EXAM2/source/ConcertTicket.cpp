#include "ConcertEvent.h"
#include "ConcertTicket.h"

/**
* Implements the leave method
*/
void ConcertTicket::leave() {
	ConcertEvent * actual_event = dynamic_cast<ConcertEvent *>(the_event); // down-cast base class to derived class
	actual_event->remove(me); // call ConcertEvent remove method to erase event goer identified by "me"
}