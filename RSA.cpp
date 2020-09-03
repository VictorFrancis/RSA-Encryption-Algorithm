#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

// Returns gcd of a and b
int gcd(int num1, int num2){

    int temp;

    while(1){

        temp=(num1%num2);

        if(temp==0){
          return num2;
        }

        num1=num2;
        num2=temp;
    }
}

int main(){
    // Two random prime numbers
    int p=37;
    int q=43;

    // First part of public key:
    int n=(p*q);

    // Finding other part of public key.
    // e stands for encrypt
    int e=575;
    int phi=(p-1)*(q-1);

    while(e<phi){
        // e must be co-prime to phi and
        // smaller than phi.
        if(gcd(e,phi)==1){

            break;
        }

        else{
            e++;
        }
    }

    // Private key (d stands for decrypt)
    // choosing d such that it satisfies
    // d*e = 1 + k * totient
    int k = 1;  // A constant value
    // d = (1 + (k*phi))/e;
    int d=71;
    // Message to be encrypted
    int message=130904230125;

    cout<<"Message data = "<<message;

    // Encryption c = (msg ^ e) % n
    int c=pow(message, e);
    c=fmod(c,n);
    cout<<"\nEncrypted data = "<<c;

    // Decryption m = (c ^ d) % n
    int m=pow(c, d);
    m=fmod(m, n);
    cout<<"\nOriginal Message Sent = "<<m;

    return 0;

    }
