set_point() {
  unsigned int d;
  hk=(hk+t[at])%HKSIZE;
  hv=(hv+t[at])%HVSIZE;
  d=(TSIZE+at-to)%TSIZE;
  while (d) {
    if(h[hk].v==hv) break;
    hks=hk;
    hvs=hv;
    backhash();
    --d;
  }
  zr=h[hk].z;
  or=h[hk].o;
#define ZP zt[d][zr][or]
  point=low+((high-low)*ZP.z)/ZP.s;
}


