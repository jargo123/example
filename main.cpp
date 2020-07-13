#include <crypto++/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <crypto++/md5.h>
#include <crypto++/files.h>
#include <crypto++/hex.h>

#include <iostream>
#include <string>
#include <bitset>


// template<typename T>
void printBinaryDigest(byte (&value)[16]){

    for(int i=0;i<16;i++){
        std::bitset<8> a(value[i]);
        std::cout<<a.to_string()<<std::endl;
    }
}

void printBinary(std::string value){

    for (std::size_t i = 0; i < value.size(); ++i)
    {
        std::cout << std::bitset<8>(value.c_str()[i]) << std::endl;
    }

}

template<typename T>
void printBinaryOneLine(T value,bool delim){
    printBinary(value,"");
    if(delim){
        std::cout<<"\n"<<"---------------"<<std::endl;
    }else{
        std::cout<<std::endl;
    }
}

void printBinaryByLine(std::string value){
    printBinary(value);
    std::cout<<"---------------"<<std::endl;
}


int main(int argc, char* argv[]) {

    byte digest[ CryptoPP::Weak::MD5::DIGESTSIZE ];
    byte digest2[ CryptoPP::Weak::MD5::DIGESTSIZE ];
    byte digest3[ CryptoPP::Weak::MD5::DIGESTSIZE ];

    std::string message = "129";

    CryptoPP::Weak::MD5 hash;

    int count=0;

    hash.CalculateDigest( digest, (const byte*)message.c_str(), message.length() );

    // count+=1;

    for(int i=0;i<3333;i++){

        hash.CalculateDigest( digest2, digest, 16 );
        hash.CalculateDigest( digest3, digest2, 16 );
        hash.CalculateDigest( digest, digest3, 16 );

        // count+=3;
    }

    CryptoPP::HexEncoder encoder;
    std::string output;


    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();

    std::transform(output.begin(), output.end(), output.begin(), [](unsigned char c){ return std::tolower(c); });

    std::cout << output << std::endl;

    // printBinaryDigest(digest);

    std::wstring hashSTR(L"da8c2466069eac1b1f4d641f8cb02fed");


    std::cout<<hashSTR.length()<<std::endl;

    // unsigned char const* c =(unsigned char *) hashSTR.c_str();

    // byte digestIN[ CryptoPP::Weak::MD5::DIGESTSIZE ];

    // for (int i=0; i<16; i++) {
    // std::wstring byte = hashSTR.substr(i*2, 2);
    // // digest[i] = hextobin(byte);
    // }


    // int j=0;

    // for (int i=0;i<32;i++){

    //     digestIN[i]=(c[i]<<4)^c[i+1];

    //     if(i%2==0){
    //         j++;
    //     }

    // }

    // for(int i=0;i<16;i++){
    //     if(digestIN[i]==digest[i]){

    //     }else
    //     {
    //         std::cout<<"FALSE"<<std::endl;
    //         break;
    //     }

    // }




    // std::string decoded;
    // std::string encoded = "39"; //Hex, so would be 63 in decimal
    // CryptoPP::StringSource ss(encoded, true /*PumpAll*/,
    //     new CryptoPP::HexDecoder(
    //         new CryptoPP::StringSink(decoded) /*StringSink*/
    //     )/*HexDecoder*/
    // );/*StringSource*/

    std::string encoded = "da8c2466069eac1b1f4d641f8cb02fed";
    std::string decoded;

    CryptoPP::HexDecoder decoder;

    decoder.Attach( new CryptoPP::StringSink( decoded ) );
    decoder.Put( (byte*)encoded.data(), encoded.size() );
    decoder.MessageEnd();

    std::cout<<decoded<<std::endl;
    printBinaryByLine(decoded);



}