# 入力

## 空白区切りの２つの文字列の入力を string 型で受け取る

```cpp
char buffer[255];
string s,t;

scanf("%s",buffer);
s = buffer;

scanf("%s",buffer);
t = buffer;
```

```cpp
vector<int> inpurtVector(int n){
  int buf;
  vector<int> v;
  for(int i=0;i<n;i++){
    scanf("%d",&buf);
    v.push_back(buf);
  }
}
```
