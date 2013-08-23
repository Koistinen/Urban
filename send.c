sendb(c)
int c;
{
  int d;
  d=(at+TSIZE-to)%TSIZE;
  if(h[hk].v!=hv){
    h[hk].v=hv;
    h[hk].z=0;
    h[hk].o=0;
  }
  if(c) {
    if(zt[d][zr][or].s>60000) {
      zt[d][zr][or].s>>=1;
      zt[d][zr][or].z>>=1;
      if(zt[d][zr][or].z==0) zt[d][zr][or].z=1;
    }
    ++zt[d][zr][or].s;
#ifdef UN
    send_bit(1);
#endif
    low=point+1;
    if(++h[hk].o==MAXCOUNT) {
      h[hk].o=MAXCOUNT>>1;
      h[hk].z>>=1;
    }
    if(hks!=HKSIZE) {
      h[hks].v=hvs;
      if(h[hk].z==0) {h[hks].o=h[hk].o;}
      else {h[hks].o=1;}
      h[hks].z=0;
  /*    hk=hks;
      hv=hvs;
      to=(to+TSIZE-1)%TSIZE;
*/
      hks=HKSIZE;
    }
  }else {
    ++zt[d][zr][or].s;
    if(zt[d][zr][or].s>60000) {
      zt[d][zr][or].s>>=1;
      zt[d][zr][or].z>>=1;
    }
    ++zt[d][zr][or].z;
#ifdef UN
    send_bit(0);
#endif
    high=point;
    if(++h[hk].z==MAXCOUNT) {
      h[hk].z=MAXCOUNT>>1;
      h[hk].o>>=1;
    }
    if(hks!=HKSIZE) {
      h[hks].v=hvs;
      h[hks].o=0;
      if(h[hk].o==0) {h[hks].z=h[hk].z;}
      else {h[hks].z=1;}
/*      hk=hks;
      hv=hvs;
      to=(to+TSIZE-1)%TSIZE;
*/
      hks=HKSIZE;
    }
  }
  send_bits();
}
