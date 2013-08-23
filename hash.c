hash() {
  hk=(AK*hk+BK)%HKSIZE;
  hv=(AV*hv+BV)%HVSIZE;
}
