#include <iostream>
#include <vector>
#include <string>
#include <bitset>

class solution
{
  public:
    int singleNumber(const std::vector<int> & nums) {
        std::string acc = toString(nums[0]);
        for (size_t i = 1; i < nums.size(); i++)
            acc = general_xor(acc, toString(nums[i]));

        std::bitset<16> bin_result(acc);
        return int(bin_result.to_ulong());
    }

  private:
    std::string general_xor(const std::string & num1, const std::string & num2) {
        std::string result;
        for (size_t i = 0; i < num1.size(); i++) {
            int temp = (stoi(num1.substr(i,1))+stoi(num2.substr(i,1)))%3;
            result.append(std::to_string(temp));
        }
        return result;
    }

    std::string toString(int num) {
        std::bitset<16> bin(num);
        return bin.to_string();
    }
};

int main()
{
    std::vector<int> nums{1,1,1,2,3,3,3,4,5,5,4,4,5,2,2,6};

    solution soln;
    int singleNum = soln.singleNumber(nums);

    std::cout << "The single number is:\n";
    std::cout << singleNum << std::endl;
}
