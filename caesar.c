// Alexadner Torjyan 28 Period 1
// Design and implement a program, Caesar, that encrypts messages using Caesar’s cipher.
// CS50 week 2 problem set 2

using System;
using System.Text;
 
public class CaesarCipher
{
    // Code text
    public static StringBuilder encrypt(String text, int s)
    {
        StringBuilder result= new StringBuilder();
 
        for (int i=0; i<text.Length; i++)
        {
            if (char.IsUpper(text[i]))
            {
                char ch = (char)(((int)text[i] +
                                s - 65) % 26 + 65);
                result.Append(ch);
            }
            else
            {
                char ch = (char)(((int)text[i] +
                                s - 97) % 26 + 97);
                result.Append(ch);
            }
        }
        return result;
    }
 
    // Show 
    public static void Main(String[] args)
    {
        String text = "ATTACKATONCE";
        int s = 4;
        Console.WriteLine("Text : " + text);
        Console.WriteLine("Shift : " + s);
        Console.WriteLine("Cipher: " + encrypt(text, s));
    }
}
 
