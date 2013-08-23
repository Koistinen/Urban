int get_bit() {
  unsigned int carry;
  carry=cin&0x80;
  cin=(cin<<1)&0xff;
  if(cin) {
    return(carry);
  } else {
    cin=getchar();
    carry=cin&0x80;
    cin=(cin<<1)&0xff;
    ++cin;
    return(carry);
  }
}
