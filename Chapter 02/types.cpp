int main()
{
    char a; // 8 bit
    signed char b;  // -127 to 128
    unsigned char c; // 0 to 128
    wchar_t d; // char guaranteed to hold machines any character.
    short e ;  // min 16 bit
    int f; // min 16 bit
    long g; //32 bit
    long long h ; //64 bit
    float i; // 6 significant
    double j; // 10 significant
    long double k; // 10 significant
    bool l; // true of false
    // Use unsigned when you know that data would be positive always.
    /* short is usually small to use int if large is required directly use long int instead of int as long and int are of same type
    Don't use plain char in arithmetic  if tiny integer is needed use signed char
    Use double for computations instead of float . Float doesn't have precision.
    */
}
