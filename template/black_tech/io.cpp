// 将 stdio 解除绑定
// 在这之后不要混用 cout 和 printf 之类
std::ios::sync_with_stdio(false);
std::cin.tie(0);

//cin char, char[]
cin.ignore(); // ignore a char
cin.get();    // return -1(EOF)
cin.get(ch);  // return 0(EOF)
cin.get(字符数组, 字符个数n, 终止字符)     //读取 n-1 个，终止符保留在读入流中
cin.getline(字符数组, 字符个数n, 终止字符) //读取 n-1 个，终止符不保留

//cin string
getline(cin, str, 终止字符) //终止符不保留
