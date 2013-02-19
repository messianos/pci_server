// Includes
#include "Publication.h"

Publication::Publication() {
	content = "";
	creation_datetime = new Datetime(0);
	creator_user_name = "";
	description = "";
	id = "";
	is_anonymous = 0;
	last_edition_datetime = new Datetime(0);
}

Publication::~Publication() {
}

bool Publication::publicationComparator(Publication* first, Publication* second){
	return first->last_edition_datetime->timestamp > second->last_edition_datetime->timestamp;
}
