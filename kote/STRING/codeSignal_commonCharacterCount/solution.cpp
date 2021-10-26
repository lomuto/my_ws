int commonCharacterCount(string s1, string s2) {
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    int sum = 0;
    
    for(const auto& c : s1) {
        map1[c] = map1[c] + 1;
    }
    
    for(const auto& c : s2) {
        map2[c] = map2[c] + 1;
    }
    
    for(auto& it : map1) {
        sum += min(map1[it.first], map2[it.first]);
    }
    
    return sum;
}
