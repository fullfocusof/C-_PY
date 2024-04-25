#include <iostream>
#include <string>

using namespace std;

string find_period(string sequence) 
{
    string temp = (sequence + sequence).substr(0, (sequence + sequence).size() - 1);
    int first_occurrence = temp.find(sequence, 1);
    if (first_occurrence == string::npos) return "0";
    else return sequence.substr(0, first_occurrence);
}

string addLargeNumbers(const string& num1, const string& num2) 
{
    string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) 
    {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() 
{
    string term1, term2;
    getline(cin, term1);
    getline(cin, term2);

    term1 = term1.substr(1, term1.find(')') - 1);
    term2 = term2.substr(1, term2.find(')') - 1);

    int shift = 0;
    string triple_term1 = term1 + term1 + term1;
    string triple_term2 = term2 + term2 + term2;
    string sum = addLargeNumbers(triple_term1, triple_term2);

    if (sum.length() == triple_term1.length()) cout << "(" << find_period(sum) << ")" << endl;
    else if (sum.length() > triple_term1.length()) 
    {
        string part_of_sequence = sum.substr(term1.length(), (sum.length() - 1) - (term1.length()));
        string period = find_period(part_of_sequence);
        if (period == "0")
        {
            while (period == "0")
            {
                shift++;
                part_of_sequence = sum.substr(term1.length() - shift, (sum.length() - 1 - shift) - (term1.length() - shift));
                period = find_period(part_of_sequence);

                if (period != "0")
                {
                    cout << "(" << period << ")" << sum.substr(sum.length() - 1 - shift) << endl;
                    break;
                }
            }
        }
        else cout << "(" << period << ")" << sum.substr(sum.length() - 1) << endl;
    }
    else cout << "(" << find_period(string(triple_term1.length() - sum.length(), '0') + sum) << ")" << endl;
}