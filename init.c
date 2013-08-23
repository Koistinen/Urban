init() {
  unsigned int i,z,o,z1,s1;
  unsigned int c,d;
  cin=0;
  cut=0x01;
  for(i=16;i>0;--i) shift_bits();
  at=to=0;
  for(i=0;i<HKSIZE;++i) {
    h[i].v=0;
    h[i].z=0;
    h[i].o=0;
  }
  for(z=0;z<MAXCOUNT;++z)
    for(o=0;o<MAXCOUNT;++o) {
      z1=z;s1=z+o;
      if(z==0) {
	z1=1;
	s1=2;
	for(i=o;i>0;--i) {
	  s1=2*s1-1;
	  if(s1>1000) break;
	}
      } else if (o==0) {
	z1=2;
	for(i=z;i>0;--i) {
	  z1=2*z1-1;
	  if(z1>1000) break;
	}
	s1=z1--;
      }
      for(d=0;d<TSIZE;++d) {
	zt[d][z][o].z=z1;
	zt[d][z][o].s=s1;
      }
    }
  for (c=0;c<256;++c) {
    hk=c;
    hv=c;
    hash();
    for(i=1;i<=TSIZE;++i) {
      hd[i%TSIZE][c].k=hk;
      hd[i%TSIZE][c].v=hv;
      hk=(AK*hk)%HKSIZE;
      hv=(AV*hv)%HVSIZE;
    }
  }
  hk=hv=0;
  hks=HKSIZE;
}
