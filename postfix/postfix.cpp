// postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <SFML/graphics.hpp>

static const char operators[] = "+-/*^";
double add(double arg1, double arg2) {
    return arg1 + arg2;
}
double sub(double arg1, double arg2) {
    return arg1 - arg2;
}
double div(double arg1, double arg2) {
    return arg1 / arg2;
}
double mult(double arg1, double arg2) {
    return arg1 * arg2;
}
double pow(double arg1, double arg2) {
    return powf(arg1, arg2);
}
double (*__func_oper[5])(double, double) = {add, sub, div, mult, pow};

int main()
{
    std::cout << "Hello World!\n";

    std::stack<double> In_Stack;

    std::string equation;
    std::cout << "give me a equation \n";
    std::getline(std::cin, equation);
    //sf::RenderWindow({ 800,800 }, "window");
    char temp_buff[100];
    size_t c_buffer = 0;//count buffer 
    double temp_val, temp_val2;

    for (auto iter: equation ) {
        if (In_Stack.size() <=1) {

            //std::cout << In_Stack.top();// this line breaks everything for some reason?? 
                
            return 1;
        }
        if ([&iter, &In_Stack, &temp_buff, &temp_val, &temp_val2, &c_buffer]() {
            for (int x = 0; x < 5; x++) {
                if (iter == operators[x]) {
                    system("pause");
                        //pop two elem off of stack, push result into stack
                        temp_val = In_Stack.top();
                        In_Stack.pop();
                        temp_val2 = In_Stack.top();
                        In_Stack.pop();
                        double t3 = __func_oper[x](temp_val, temp_val2);
                        std::cout << t3 << std::endl;
                        In_Stack.push(t3);

                    c_buffer = 0;
                    memset(temp_buff, ' ', 100);
                    return true;
                }
            }
            return false;
            }() == false) {
            if (iter == ' ') {
                //stop accumilating, push to stack 
                temp_buff[c_buffer + 1] = '\n';
                In_Stack.push((double)atof(temp_buff));
                c_buffer = 0;
                memset(temp_buff, ' ', 100);
            }
            else {

                temp_buff[c_buffer] = iter;
                c_buffer++;
                //else- 
            }
        }
    }



}
