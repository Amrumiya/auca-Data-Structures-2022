
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

        void check()
        {
            int counter = 0;
            for(string line; getline(cin, line) && !line.empty();)
            {
                memory[counter]  =stoi(line);
                ++counter;
            }
        }
        int GoThrough() 
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
                    case 0:  if(registers[d0] != 0) {
                    instructionPointer = registers[d1];
                     }else{++instructionPointer; }
                    break;
                    case 2: registers[d1] = d0;
                         registers[d1] %= 1000;
                        ++instructionPointer;
                    break;
                    case 3:  registers[d1] += d0;
                             registers[d1] %= 1000;
                             ++instructionPointer;
                    break;
                    case 4: registers[d1] *= d0;
                            registers[d1] %= 1000;
                             ++instructionPointer;
                    break;
                    case 5: registers[d1] = registers[d0];
                            ++instructionPointer;
                    break;
                    case 6: registers[d1] += registers[d0];
                            registers[d1] %= 1000;
                            ++instructionPointer;
                    break;
                    case 7: registers[d1] *= registers[d0];
                            registers[d1] %= 1000;
                            ++instructionPointer;
                    break;
                    case 8: registers[d1] = memory[registers[d0]];
                            registers[d1] %= 1000;
                            ++instructionPointer;
                    break;
                    case 9: memory[registers[d0]] = registers[d1];
                            ++instructionPointer;
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
    };

    int main() 
    {
        iostream::sync_with_stdio(false);

        int numTestCase;
        cin >> numTestCase >> ws;

        for(int i = 0; i < numTestCase; i++) {
                
                Computer comp;

                comp.check();
        
        cout << comp.GoThrough() << "\n";
        }
    }


