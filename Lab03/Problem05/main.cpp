
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;


    class Computer{

            vector<int> registers;
            vector<int> memory;
            int instructionPointer;

    public:
        Computer()
                : registers(10, 0), memory(1000, 0), instructionPointer(0){}

        void read()
        {
            int counter = 0;
            for(string line; getline(cin, line) && !line.empty();)
            {
                memory[counter]  =stoi(line);
                ++counter;
            }
        }
        int run() 
        {
            int res = 0;
            
            while(true) {

                int d0;
                int d1;
                int d2;

                analyzeInstruction(memory[instructionPointer], d0, d1, d2);
                ++res; 

                if(d2 == 1 && d1 == 0 && d0 == 0) {
                    return res;
                }
                switch (d2)
                {
                    case 0: instruction0(d1, d0);
                    break;
                    case 2: instruction2(d1, d0);
                    break;
                    case 3: instruction3(d1,  d0);
                    break;
                    case 4: instruction4(d1, d0);
                    break;
                    case 5: instruction5(d1, d0);
                    break;
                    case 6: instruction6(d1, d0);
                    break;
                    case 7: instruction7(d1, d0);
                    break;
                    case 8: instruction8(d1, d0);
                    break;
                    case 9: instruction9(d1, d0); 
                    break;
                
                }
            }
        }

    void analyzeInstruction(int instruction, int &d0, int &d1, int &d2) 
        {
        d0 = instruction % 10;
        instruction /= 10;
        d1 = instruction % 10;
        instruction /= 10;
        d2 = instruction % 10;
        
        }


        void instruction2(int d1, int d0) {
            registers[d1] = d0;
            registers[d1] %= 1000;
            ++instructionPointer;
        }
         void instruction3(int d1, int d0) {
            registers[d1] += d0;
            registers[d1] %= 1000;

            ++instructionPointer;

        }
         void instruction4(int d1, int d0) {
            registers[d1] *= d0;
            registers[d1] %= 1000;
            ++instructionPointer;

        }
         void instruction5(int d1, int d0) {
            registers[d1] = registers[d0];
            ++instructionPointer;

        }
         void instruction6(int d1, int d0) {
            registers[d1] += registers[d0];
            registers[d1] %= 1000;
            ++instructionPointer;

        }
         void instruction7(int d1, int d0) {
            registers[d1] *= registers[d0];
            registers[d1] %= 1000;
            ++instructionPointer;

        }
         void instruction8(int d1, int d0) {
            registers[d1] = memory[registers[d0]];
            registers[d1] %= 1000;
            ++instructionPointer;

        }
         void instruction9(int d1, int d0) {
            memory[registers[d0]] = registers[d1];
            ++instructionPointer;

        }
         void instruction0(int d1, int d0) {
            if(registers[d0] != 0) {
                    instructionPointer = registers[d1];
                 }else{     
                    ++instructionPointer;
                 }
        }
    };

    int main() 
    {
        iostream::sync_with_stdio(false);

        int numTestCase;
        cin >> numTestCase >> ws;

        for(int test = 0; test < numTestCase; test++) {
                Computer comp;

                comp.read();
        
              cout << comp.run()<< endl;
        }
    }


