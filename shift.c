shift_bits() {
  low=(low<<1)&0xffff;
  high=(high<<1)&0xffff;
  ++high;
#ifdef UN
  apoint=(apoint<<1)&0xffff;
  if(get_bit()) ++apoint;
#endif
}
