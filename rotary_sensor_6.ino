int inputA = 7;
int inputB = 8;
int inputC = 5;
int inputD = 6;
int state, state0, state1, state2;
int current, current0, current1, current2;
int stateA, stateB, stateC, stateD;
int data;
int data1 = 0;
int data2 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(inputA, INPUT);
  pinMode(inputB, INPUT);
  pinMode(inputC, INPUT);
  pinMode(inputD, INPUT);
  //Serial.print("Initial: ");
  getState1();
  //Serial.print(state1);
  while (state1 == 1 || state1 == 2)
  {
    getState1();
    //Serial.print("flag 1");
  }
  if (state1 == 0)
  {
    current1 = 1;
  }
  else if (state1 == 3)
  {
    current1 = 5;
  }
  
  getState2();
  //Serial.print(" ");
  //Serial.println(state2);
  while (state2 == 1 || state2 == 2)
  {
    getState2();
    //Serial.println(state2);
  }
  if (state2 == 0)
  {
    current2 = 1;
  }
  else if (state2 == 3)
  {
    current2 = 5;
  }
}

void loop()
{
  getState1();
  current = current1;
  state = state1;
  data = data1;
  operate();
  current1 = current;
  state1 = state;
  data1 = data;

  getState2();
  current = current2;
  state = state2;
  data = data2;
  operate();
  current2 = current;
  state2 = state;
  data2 = data;
  
  Serial.print(data1);
  Serial.print(",");
  Serial.println(data2);
}

void getState1()
{
  stateA = digitalRead(inputA);
  stateB = digitalRead(inputB) << 1;
  state1 = stateA | stateB;
}

void getState2()
{
  stateC = digitalRead(inputC);
  stateD = digitalRead(inputD) << 1;
  state2 = stateC | stateD;
}

void operate()
{
  switch (current)
  {
    case 1: if (state == 0)
              current = 1;
            else if (state == 1)
              current = 2;
            else if (state == 2)
              current = 4;
            else if (state == 3)
              current = 5;
            break;
            
    case 2: if (state == 0)
              current = 1;
            else if (state == 1)
              current = 2;
            else if (state == 2)
              current = 1;
            else if (state == 3)
            {
              current = 3;
              //Serial.println("clockwise");
              data += 1;
            }
            break;
            
    case 3: if (state == 0)
              current = 1;
            else if (state == 1)
              current = 6;
            else if (state == 2)
              current = 8;
            else if (state == 3)
              current = 5;
            break;
            
    case 4: if (state == 0)
              current = 1;
            else if (state == 1)
              current = 1;
            else if (state == 2)
              current = 4;
            else if (state == 3)
              {
                current = 3;
                //Serial.println("anti-clockwise");
                data -= 1;
              }
            break;
            
    case 5: if (state == 0)
              current = 1;
            else if (state == 1)
              current = 6;
            else if (state == 2)
              current = 8;
            else if (state == 3)
              current = 5;
            break;
            
    case 6: if (state == 0)
              {
                current = 7;
                //Serial.println("anti-clockwise");
                data -= 1;
              }
            else if (state == 1)
              current = 6;
            else if (state == 2)
              current = 5;
            else if (state == 3)
              current = 5;
            break;
            
    case 7: if (state == 0)
              current = 1;
            else if (state == 1)
              current = 2;
            else if (state == 2)
              current = 4;
            else if (state == 3)
              current = 5;
            break;
            
    case 8: if (state == 0)
              {
                current = 7;
                //Serial.println("clockwise");
                data += 1;
              }
            else if (state == 1)
              current = 5;
            else if (state == 2)
              current = 8;
            else if (state == 3)
              current = 5;
            break;
    default : Serial.println("error");
  }
  
}
