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

bool Publication::operator <(Publication *other) {
	return last_edition_datetime < other->last_edition_datetime;
}
