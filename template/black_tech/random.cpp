//srand() is not necessary
//range : [0, 99999999]
random_device rd;
uniform_int_distribution<int> dist(0, 99999999);
de(dist(rd));
