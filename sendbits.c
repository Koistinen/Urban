send_bits() {
  unsigned int bit;
  if(((high^low)&0x8000)==0) {
#ifndef UN
    send_bit(bit=(high&0x8000));
#endif
    shift_bits();
#ifndef UN
    while(k>0) {
      send_bit(bit==0);
      --k;
    }
#endif
    while(((high^low)&0x8000)==0) {
#ifndef UN
      send_bit(high&0x8000);
#endif
      shift_bits();
    }
  }
  while((low&0x4000)&&((high&0x4000)==0)) {
    shift_bits();
#ifdef UN
    apoint^=0x8000;
#else
    ++k;
#endif
    low&=0x7fff;
    high|=0x8000;
  }
}




