#include "config.h"
#include <torrent/utils/log.h>

#include "input_event.h"

#include "display/attributes.h"

namespace input {

void
InputEvent::insert(torrent::Poll* p) {
  p->open(this);
  p->insert_read(this);
}

void
InputEvent::remove(torrent::Poll* p) {
  p->remove_read(this);
  p->close(this);
}

void
InputEvent::event_read() {
  int c;

  while ((c = getch()) != ERR)
{
lt_log_print(torrent::LOG_TORRENT_WARN, "key: %d", c);
    m_slotPressed(c);
    }
}

void
InputEvent::event_write() {
}

void
InputEvent::event_error() {
}

}
