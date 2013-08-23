send_bit(bit)
unsigned int bit;
{
  unsigned int carry;
  carry=cut&0x80;
  cut<<=1;
  if(bit) ++cut; /* set lsb */
  if(carry) {
    putchar(cut&0xff);
    cut=0x01;
  }
}
