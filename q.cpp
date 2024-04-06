/*!**************************************************************************************************************************************************************************************************************************************************************
\file       q.cpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202
\par        Section:         RSE
\par        Tutorial:        Lab 3
\par        File created on: 26/01/2024
\brief      Convert English words into Pig Latin

\par        File information:
            This file is contains 1 function declaraction to called by main in q-driver.
            Functions:
            - std::string to_piglatin(std::string word);                                                                                                        // convert an english words into pig latin
*************************************************************************************************************************************************************************************************************************************************/
#include <iostream>    // or can use #include <string>

namespace hlp2 {
//###############################################################################################################################################################################################################################################
//===============================================================================================================================================================================================================================================
//|                                                                        FUNCTIONS SECTION                                                                                                                                                    |
//===============================================================================================================================================================================================================================================
    bool vowel_check(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); } // Check if the character is a vowel
    std::string shifted(std::string mod_word) { mod_word += mod_word[0]; mod_word.erase(0, 1); return mod_word;}                                                // move the first letter of the word to the back of the word   
                                //or can use  {          return mod_word.substr(1) + mod_word[0];              }
//===============================================================================================================================================================================================================================================
//|                                                       WORD CONVERSION FORM ENGLISH TO PIG LATIN SECTION                                                                                                                                     |
//===============================================================================================================================================================================================================================================
    std::string to_piglatin(std::string word) {                                                                                                                 // convert an english words into pig latin

        if(vowel_check(word[0])){ return word + "-yay"; }                                                                                                       // if the first letter of the word is a vowel 
        
        bool y_is_true =false;  for(size_t i=1; i<word.size();i++){ if(word[i] == 'y' || word[i] == 'Y'){ y_is_true = true; } }                                 // checking if there is a letter y after the first letter to treat is as a vowel 

        std::string copie = word;                                                                                                                               // making a copy of word to be modified
        for(size_t i=0; i< word.size();i++){                                                                                                                    // checking each letter in the word

            if(vowel_check(copie[0]) || ((copie[0] == 'y' || copie[0] == 'Y') && y_is_true == true )){ return copie+ "-ay"; }                                   // checking if the first letter of the word is a vowel 
                                                                                                                                                                // or if there is a letter y after the first letter to treat is as a vowel  
            else{ 
                if(copie[0] >= 65 && copie[0] <= 90){            copie[0] = copie[0] + 32;                                                                      // if the first letter is a uppercase convert it to lower case
                    
                    if(copie[1] >= 65 && copie[1] <= 90){        copie[1] = copie[1] + 32; }                                                                    // if the second letter is a uppercase convert it to lowercase
                    else if(copie[1] >= 97 && copie[1] <= 122){  copie[1] = copie[1] - 32; }                                                                    // if the second letter is a lowercase convert it to uppercase
                }   copie = shifted(copie);                                                                                                                     // move the first letter of the word to the back of the word 
            }
        } return word + "-way";                                                                                                                                 // default return to return word wit surfix "-way" if no vowels was found 
    }
//############################################################################################################################################################################################################################################
}

