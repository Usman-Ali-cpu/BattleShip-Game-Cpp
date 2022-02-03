using System;

namespace _32._C_
{
    class Program
    {
        static void inputNumberGrade(int[] gradeArr, int grades) // function header, for taking inputs  grades from user 
        {
            string inputs; // input in string 
            for (int i = 0; i < grades; i++) // loop through for all grade values
            {
                Console.Write("Enter grades {0}: ", i + 1);
                inputs = Console.ReadLine(); // input grade in string 
                gradeArr[i] = Convert.ToInt32(inputs); // store in integer after conversion 
            }
        }
        static char gradeConversion(int grade) // function header for grade conversion 
        {
            char gr = 'F'; // grade to return 
            if (grade >= 90 && grade <= 100) // if grade is less than eqaul to 100 and greater thab equal to 90
            {

                gr = 'A'; // grade is A 
            }
            else if (grade >= 80 && grade <= 89) // if grade is less than eqaul to 89 and greater thab equal to 80
            {

                gr = 'B';
            }
            else if (grade >= 70 && grade <= 79) // if grade is less than eqaul to 79 and greater thab equal to 70
            {

                gr = 'C';
            }
            else if (grade >= 60 && grade <= 69) // if grade is less than eqaul to 69 and greater thab equal to 60
            {

                gr = 'D';
            }
            else if (grade < 60) // less than 60
            {

                gr = 'F'; // fail
            }
            return gr;// return grade

        }
        public static void Main(String[] args)
        {



            while (true)  // loop whole program 
            {
                string firstname;
                string lastname;
                Console.Write("Enter a first name : ");
                firstname = Console.ReadLine(); //take input firstname 
                Console.Write("Enter a last name : ");
                lastname = Console.ReadLine();  //take last  firstname 
                Console.WriteLine("Hello {0} {1} Welcome to the Grade Converter!", firstname, lastname);
                int grades;
                string inputs;
                Console.Write("Enter the number of grades you need to convert: ");
                inputs = Console.ReadLine(); // inputs number of grades want to convert 
                grades = Convert.ToInt32(inputs); // conversion of string to int 
                int[] gradeArr = new int[grades]; // allocating array of size grades of type int 
                inputNumberGrade(gradeArr, grades); // taking input in array 
                char[] charGrade = new char[grades]; // array of char to store letter grade 
                Console.WriteLine("Number of grades: {0}", grades);
                for (int i = 0; i < grades; i++)
                {
                    charGrade[i] = gradeConversion(gradeArr[i]); // getting letter grade fron number grade 
                    Console.WriteLine("A score of {0} is a {1} grade", gradeArr[i], charGrade[i]); // output grade on it 
                }

                double avr = 0;
                char avrChar;
                for (int i = 0; i < gradeArr.Length; i++)
                {
                    avr += gradeArr[i];
                }
                avr = avr / grades; // get average of all grade numbers 
                int g = Convert.ToInt32(avr); // from double to int 

                avrChar = gradeConversion(g); // get grade letter 
                Console.WriteLine("Average Grade: {0} , which is a {1} ", avr, avrChar);
                Console.Write("Do you have more grades : Y/N: ");
                string choice = Console.ReadLine(); // take choice to do again calculation 
                if (choice == "N" || choice == "n")
                {
                    break;
                    return;
                }

            }
        }
    }
}
