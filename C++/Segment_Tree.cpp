#include <iostream>
#include <vector>

class SegmentT
{
  private:
    int n;
    std::vector <int> Tree;

  public:
    void Update(int ps, int x)
    {
      ps+= (n-1);
      Tree[ps] = x;

      for(int i = ps/2; i > 0; i/=2)
        Tree[i] = std::min(Tree[i*2],Tree[(i*2)+1]);

      return;
    }
    int Query(int left, int right)
    {
      left+= (n-1) , right+= (n-1);
      int ans = int(1<<30);  
      while(left <= right)
      {
        if(left&1)
        {
          ans = std::min(ans,Tree[left]);
          left++;
        }
        if(!(right&1))
        {
          ans = std::min(ans,Tree[right]);
          right--;
        }
        left/=2, right/=2;
      }
      return ans;
    }
    SegmentT(std::vector <int> aux)
    {
      this -> n = aux.size();
      Tree.resize(n*2);

      for(int i = n; i < (n*2); i++)
        this -> Tree[i] = aux[i-n];

      for(int i = n-1; i > 0; i--)
        this ->Tree[i] = std::min(this -> Tree[2*i],this -> Tree[(2*i)+1]);
    }	

};
int main()
{
  int n, x, a, b;
  bool flag = true;
  std::vector <int> vec;
  std::cout << "Size of Tree: ";
  std::cin >> n;
  std::cout << "\nValues : ";
  while(n--)
  {
    std::cin>>x;
    vec.push_back(x);
  }
  SegmentT A(vec);	
  std::cout << "\n" ;
  while(flag)
  {
    std::cout << "\n1 - Query ";
    std::cout << "\n2 - Update ";
    std::cout << "\n3 - Exit\n";
    std::cin >> x;

    switch(x)
    {
      case 1:
        std::cout <<"\nLeft index: ";
        std::cin >> a;
        std::cout <<"\nRight index: ";
        std::cin >> b; 
        std::cout <<"\nThe smallest term between this range is: " << A.Query(a,b);
      break;

      case 2:
        std::cout <<"\nIndex: ";
        std::cin >> a;
        std::cout <<"\nNew term: ";
        std::cin >> b;
        A.Update(a,b);
      break;

      default:
        flag = false;
    }
  }	
  return 0;
}
