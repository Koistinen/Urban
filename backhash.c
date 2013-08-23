backhash() {
  unsigned int d;
  d=(TSIZE+at-to)%TSIZE;
  hk=(HKSIZE+hk-hd[d][t[to]].k)%HKSIZE;
  hv=(HVSIZE+hv-hd[d][t[to]].v)%HVSIZE;
  to=(1+to)%TSIZE;
}
