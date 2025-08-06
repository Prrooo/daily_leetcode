#include <algorithm>
#include<bits/stdc++.h>
#include <iterator>
using namespace std;
// less complex solution 
string addBinary(string a, string b) {
  string res;
  int carry=0;
  int i=a.length()-1;
  int j=b.length()-1;
  while (i >= 0 || j >= 0 || carry) {
    if (i >= 0) carry += a[i--] - '0';
    if (j >= 0) carry += b[j--] - '0';

    res+= carry % 2 + '0';
    carry /= 2;
  }
  reverse(begin(res),end(res));
  return res;
}

// my solution little complex time complexity O(n)
/*string addBinary(string a, string b){*/
/*  string ans="";*/
/*  int n1=a.size(),n2=b.size();*/
/*  int i=n1-1,j=n2-1;*/
/*  int carry=0;*/
/*  while(i>=0 && j>=0){*/
/*    int result=(a[i]-'0')+(b[j]-'0')+carry;*/
/*    if(result==1){*/
/*      ans='1'+ans;*/
/*      carry=0;*/
/*    }*/
/*    else if(result==2){*/
/*      ans='0'+ans;*/
/*      carry=1;*/
/*    }*/
/*    else if(result==3){*/
/*      ans='1'+ans;*/
/*      carry=1;*/
/*    }*/
/*    else{*/
/*      ans='0'+ans;*/
/*      carry=0;*/
/*    }*/
/*    i--,j--;*/
/*  }*/
/*  while(i>=0){*/
/*    int result=(a[i]-'0')+carry;*/
/*    if(result==1){*/
/*      ans='1'+ans;*/
/*      carry=0;*/
/*    }*/
/*    else if(result==2){*/
/*      ans='0'+ans;*/
/*      carry=1;*/
/*    }*/
/*    else{*/
/*      ans='0'+ans;*/
/*      carry=0;*/
/*    }*/
/*    i--;*/
/*  }*/
/*  while(j>=0){*/
/*    int result=(b[j]-'0')+carry;*/
/*    if(result==1){*/
/*      ans='1'+ans;*/
/*      carry=0;*/
/*    }*/
/*    else if(result==2){*/
/*      ans='0'+ans;*/
/*      carry=1;*/
/*    }*/
/*    else{*/
/*      ans='0'+ans;*/
/*      carry=0;*/
/*    }*/
/*    j--;*/
/*  }*/
/*  if(carry!=0){*/
/*    ans='1'+ans;*/
/*  }*/
/*  return ans;*/
/*}*/

int main(){
  string a,b;
  cin>>a>>b;
  cout<<addBinary(a,b);
  return 0;
}
