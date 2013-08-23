/* bitwise statistical compression */
#include <stdio.h>
#include "head.h"
#include "var.h"
#include "init.c"
#include "hash.c"
#include "setpoint.c"
#include "send.c"
#include "sendbits.c"
#include "sendbit.c"
#include "shift.c"
#include "backhash.c"
#include "flush.c"
#ifdef UN
#include "getbit.c"
#endif

main() {
  int c;
  unsigned char t0;
  init();
#ifdef UN
  while (apoint!=low) {
#else
  while (EOF!=(c=getchar())) {
#endif
    ++low; /* send no EOF */
    t[at]=t0=0x80;
    while (t0) {
      set_point();
#ifdef UN
      if(apoint>point){c=t0;}
      else {c=0;}
      sendb(c);
#else
      sendb(c&t0);
#endif
      hk=(HKSIZE+hk-t[at])%HKSIZE;
      hv=(HVSIZE+hv-t[at])%HVSIZE;
#ifdef UN
      if (c==0) t[at]^=t0;
      t0>>=1;
      t[at]|=t0;
#else
      t0>>=1;
      t[at]=(t[at]&c)|t0;
#endif
    }
    hk+=t[at];
    hv+=t[at];
    hash();
    at=(1+at)%TSIZE;
    if(at==to) backhash();
  }
  high=low; /* send EOF */
  send_bits();
  flush_bits();
}
