//难点有二： 1.只在乎数字和字母  2. 大写A和小写a要判等。 记录两个算法

/* 1. 双向哨兵， 时间复杂度 o(n) 牛逼的地方在于不改写实现大小写比较 */
 bool isPalindrome(string s) {
        if (s.empty()) return true;
        
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isalnum(s[l])) {
              l++; continue;  
            } 
            if (!isalnum(s[r])) {
              r--; continue;  
            } 
            // ascII 码特性。 数字不影响， 刚好大写的 或一下 变成小写的。
            if ((s[l] | 0x20) != (s[r] | 0x20)) return false;
            l++; r--;
        }
        return true;
    }
    
/* 2. 基于c11语法， remove掉不在乎的， 直接revese了看一样吗。 基于string == 深度重载。 */
// 注意自定义函数的名字瞎写比较好，如果和重定义的重名，会不知道用哪个
//
static bool issmys(char c){
   return !isalnum(c);
}
bool isPalindrome(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
 //s.erase(remove_if(s.begin(), s.end(), ::isalnum), s.end()); 因为using namespace std 的关系， 必须这么写 
 // https://stackoverflow.com/questions/8364678/g-string-remove-if-error
    s.erase(remove_if(s.begin(), s.end(), issmys), s.end()); // 这里会不知道用哪个  本句是常见的组合拳， 能擦除string里你不想要的内容。
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}
