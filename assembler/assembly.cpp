
#include <bits/stdc++.h>
using namespace std;

bool isValid(string y,int &value,int &sign)
{
	int j;
	string x="";
	for(j=0; j<y.size(); j++)
	{
		if(y.at(j)!=' ')
			break;
	}
	for(; j<y.size(); j++)
	{
		if(y.at(j)==' ')
			break;
		x+=y.at(j);
	}
	string t="";
	for(; j<y.size(); j++)
	{
		if(y.at(j)!=' ')
		{
			t+=y.at(j);
		}
	}
	if(!t.empty())
		return false;
	string s="";
	if(x.at(0)=='-')
	{
		 s="";
		sign=-1;
		for(int i=1; i<x.size(); i++)
		{
			if(x.at(i)-'0' >= 0 && x.at(i)-'0' <= 9)
			{
				s+= x.at(i);
				
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		sign=0;
		
		for(int i=0; i<x.size(); i++)
		{
			if(x.at(i)-'0' >= 0 && x.at(i)-'0' <= 9)
			{
				s+= x.at(i);

			}
			else
			{
				return false;
			}
		}
	}


	value = stoi(s);
	return true;

}


char flip(char c) {return (c == '0')? '1': '0';} 


string TwosComplement(string bin) 
{ 
	int n = bin.length(); 
	int i; 

	string ones, twos; 
	ones = twos = ""; 

	 
	for (i = 0; i < n; i++) 
		ones += flip(bin[i]); 

	twos = ones; 
	for (i = n - 1; i >= 0; i--) 
	{ 
		if (ones[i] == '1') 
			twos[i] = '0'; 
		else
		{ 
			twos[i] = '1'; 
			break; 
		} 
	} 

	if (i == -1) 
		twos = '1' + twos; 

	return twos; 
} 









// function to convert decimal to binary 
string decToBinary(int n, int bits) 
{ 
	string binaryNum=""; 

	 
	int i = 0; 
	while (n > 0) { 

		 
		char x = (n % 2)+ '0';
		binaryNum=x + binaryNum; 
		n = n / 2; 
		i++; 
	} 

	// printing binary array in reverse order 
	for (int j = bits-1; j >= i; j--) 
	{
		binaryNum = '0' + binaryNum;
	}

	return binaryNum; 
} 



/////////////////////////////// 38 instructions implemented  ////////////////////////////////

//ASSUMPTIONS

//TABS NOT ALLOWED
//Label or keyword (eg. main:) are considered to have address but are not considered to be executable instructions.
//lw, lb, sw and sb similar to immediate type instruction to work for. 
//for sll,srl and lui, rs is not mentioned so took it as 00000 acc. to qtspim
//sllv and srlv implemented like sllv $d, $s, $t and srlv $d, $s, $t



int main()
{
	ofstream myfile;
	myfile.open("output.o");		//Machine code file


	//Instruction mapped with opcode and function bits 

	map<string,pair<string,string>> m;

	


	// R-type instructions
	// opcode(6) rs(5) rt(5) rd(5) shftamt(5) function(6)
	
	pair<string,string> p;
	p.first="000000";
	p.second="100000";
	m["add"]=p;

	// Additional function pow is included with format 
	//      pow $rd, $rs, $rt <==> $rd = ($rs) ^ ($rt)
	p.first="000000";
	p.second="111111";
	m["power"]=p;

	p.first="000000";
	p.second="100010";
	m["sub"]=p;

	p.first="000000";
	p.second="100001";
	m["addu"]=p;

	p.first="000000";
	p.second="100011";
	m["subu"]=p;

	p.first="000000";
	p.second="011000";
	m["mult"]=p;

	p.first="000000";
	p.second="011001";
	m["multu"]=p;

	p.first="000000";
	p.second="011010";
	m["div"]=p;

	p.first="000000";
	p.second="011011";
	m["divu"]=p;

	p.first="000000";
	p.second="100100";
	m["and"]=p;

	p.first="000000";
	p.second="100101";
	m["or"]=p;

	p.first="000000";
	p.second="100110";
	m["xor"]=p;

	p.first="000000";
	p.second="100111";
	m["nor"]=p;

	p.first="000000";
	p.second="101010";
	m["slt"]=p;

	p.first="000000";
	p.second="100010";
	m["sub"]=p;

	p.first="000000";
	p.second="000000";
	m["sll"]=p;

	p.first="000000";
	p.second="000100";
	m["sllv"]=p;

	p.first="000000";
	p.second="000010";
	m["srl"]=p;

	p.first="000000";
	p.second="000110";
	m["srlv"]=p;

	p.first="000000";
	p.second="010000";
	m["mfhi"]=p;

	p.first="000000";
	p.second="010010";
	m["mflo"]=p;

	p.first="000000";
	p.second="010001";
	m["mthi"]=p;

	p.first="000000";
	p.second="010011";
	m["mtlo"]=p;

/////////////////////////////////////////////////////////////////////////////////////////////

	// I - type instructions.
	// opcode(6) rs(5) rt(5) imm(16)
	
	p.first="001000";
	p.second="imm";
	m["addi"]=p;

	p.first="001001";
	p.second="imm";
	m["addiu"]=p;

	p.first="001100";
	p.second="imm";
	m["andi"]=p;

	p.first="001101";
	p.second="imm";
	m["ori"]=p;

	p.first="001110";
	p.second="imm";
	m["xori"]=p;

	p.first="001111";
	p.second="imm";
	m["la"]=p;

	// load - store instructions
	// Instruction format -> lw $rt, $rs, offset <==> lw $rt, offset($rs)

	p.first="100011";
	p.second="imm";
	m["lw"]=p;

	p.first="101011";
	p.second="imm";
	m["sw"]=p;

	p.first="100000";
	p.second="imm";
	m["lb"]=p;

	p.first="101000";
	p.second="imm";
	m["sb"]=p;


/////////////////////////////////////////////////////////////////////////////////////////////

	//Branch instruction

	p.first="000100";
	p.second="branch";
	m["beq"]=p;

	p.first="000101";
	p.second="branch";
	m["bne"]=p;

/////////////////////////////////////////////////////////////////////////////////////////////

	// jump instruction

	p.first="000010";
	p.second="target";
	m["j"]=p;

	p.first="000011";
	p.second="target";
	m["jal"]=p;

	p.first="000000";
	p.second="target";
	m["jr"]=p;

/////////////////////////////////////////////////////////////////////////////////////////////

	// Registers mapped with their codes

	map<string ,string> mr;

	mr["$0"]="00000";
	mr["$at"]="00001";
	mr["$v0"]="00010";
	mr["$v1"]="00011";
	mr["$a0"]="00100";
	mr["$a1"]="00101";
	mr["$a2"]="00110";
	mr["$a3"]="00111";
	mr["$t0"]="01000";
	mr["$t1"]="01001";
	mr["$t2"]="01010";
	mr["$t3"]="01011";
	mr["$t4"]="01100";
	mr["$t5"]="01101";
	mr["$t6"]="01110";
	mr["$t7"]="01111";
	mr["$s0"]="10000";
	mr["$s1"]="10001";
	mr["$s2"]="10010";
	mr["$s3"]="10011";
	mr["$s4"]="10100";
	mr["$s5"]="10101";
	mr["$s6"]="10110";
	mr["$s7"]="10111";
	mr["$t8"]="11000";
	mr["$t9"]="11001";
	mr["$k0"]="11010";
	mr["$k1"]="11011";
	mr["$gp"]="11100";
	mr["$sp"]="11101";
	mr["$fp"]="11110";
	mr["$ra"]="11111";



/////////////////////////////////////////////////////////////////////////////////////////////

	// Set of valid words


	set<string> words;        
	
	words.insert(",");
	words.insert("#");     // support comment in .s file
	words.insert(" ");
	

	// valid numbers
	words.insert("1");
	words.insert("2");
	words.insert("3");
	words.insert("4");
	words.insert("5");
	words.insert("6");
	words.insert("7");
	words.insert("8");
	words.insert("9");
	words.insert("0");

	
	words.insert(":");
	words.insert(".data");
	words.insert(".text");
	words.insert("main:");
	words.insert(".space");
	words.insert(".word");
	words.insert("(");
	words.insert(")");


///////////////////////////////////////////////////////////////////////////////////////////	

	


	// Set of target words / label names for jump and branch instructions mapped with their addresses in the assembly code

	map <string,int> target;

	std::ifstream file("program.s"); //Test file
    std::string str;
    int count=-4; 					// Program Counter
    while (std::getline(file, str))	//Checking file one line at a time
    { 	
    	//Ignoring spaces
    	string dummy="";
    	int i;
        for(i=0; i<str.size(); i++)
        {
        	if(str.at(i)!=' ')
        	{
        		break;
        	}
        }
        //Reading first word
        for(; i<str.size(); i++)
        {
        	if(str.at(i)==' ' || str.at(i)==':')
        	{
        		break;
        	}
        	dummy+=str.at(i);
        }
        //Empty line or comment in .s file
        if(dummy.empty() || dummy.at(0)=='#')
        	continue;

        //Checking for valid labels

        count+=4;
        //Ignoring spaces
        string dummy2="";
        for(; i<str.size(); i++)
        {
        	if(str.at(i)!=' ')
        	{
        		break;
        	}
        }
        //Reading second word
        for(; i<str.size(); i++)
        {
        	if(str.at(i)==' ')
        	{
        		break;
        	}
        	dummy2+=str.at(i);
        }

		string dummy3="";
        //Ignoring spaces
        for(; i<str.size(); i++)
        {
        	if(str.at(i)!=' ')
        	{
        		break;
        	}
        }
        //Reading third word
        for(; i<str.size(); i++)
        {
        	if(str.at(i)==' ')
        	{
        		break;
        	}
        	dummy3+=str.at(i);
        }

        //Condition for valid label
        if(dummy2==":" && dummy3.empty())  //Anything after : results in error
        {
        	if(target.count(dummy))		 //More than one definition of a label is not allowed
        		target.erase(dummy);
        	else
        		target[dummy] = count;     // Label name mapped with address 
        }
    }























/////////////////////////////////////////////////////////////////////////////////////////////
	
	//Processing input.s file

	
    count=0;							//Input file line counter
    int valid_count=-4;					//Program counter
    std::ifstream file1("program.s");	//Input file
    while (std::getline(file1, str))	//Reading file one line at a time
    {
    	count++;
    	int i;
    	string dummy="";
    	//Ignoring spaces
        for(i=0; i<str.size(); i++)
        {
        	if(str.at(i)!=' ')
        	{
        		break;
        	}
        }
        //Reading first word
        for(; i<str.size(); i++)
        {
        	if(str.at(i)==' '||str.at(i)==':')
        	{
        		break;
        	}
        	dummy+=str.at(i);
        }

        // Bypassing comments and empty lines
        if(dummy.empty() || dummy.at(0)=='#')
        	continue;


        string error="";
        if(words.count(dummy))
        {
        	valid_count+=4;  		// lines with words like main: are skipped but program 
        							// counter is increased
        	continue;
        }
        // if first word is valid label
        if(target.count(dummy))
        {
        	//Ignoring spaces
        	for(; i<str.size(); i++)
        	{
        		if(str.at(i)!=' ')
        			break;
        	}
        	char colon=str.at(i);
        		i++;
        	for(; i<str.size(); i++)	//Error if anything present after :
        		error+=str.at(i);
        	if(!error.empty())			//Printing error
        		cout<< "error in line "<< count << " near "<<dummy <<endl;

        	valid_count+=4;  			//Increasing program counter by 4
        	continue;
        }

        if( !m.count(dummy) )
        {
        	//error due to invalid instruction
			cout<< "error in line "<< count << " near "<<dummy <<endl; 
			continue;
        }
        else   // Valid Instruction proceed further
        {

/////////////////////////////////////////////////////////////////////////////////////////////

        	//Opcode and function code corresponding to instruction
        	pair <string, string> tp = m[dummy];		 
        	valid_count+=4;								//Program counter
        	if(dummy=="jr")
        	{
    			string dummy2="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        // Register one reading
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ')
		        	{
		        		break;
		        	}
		        	dummy2+=str.at(i);
		        }

				

				string dummy3="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ')
		        	{
		        		break;
		        	}
		        	dummy3+=str.at(i);
		        }

		        if(dummy3.empty() && mr.count(dummy2))
		        {
		     
        			
        			stringstream ss; 
				    ss << hex << valid_count; 
				    string res = ss.str();
				    while(res.size() < 4)
				    {
				    	res = "0"+res;
				    } 
				    res = "0x" + res;
				    string shift_amount="00000";
				    string rt_rd = "0000000000"; //check 32 bit distribution of this instrn.

		        	m[dummy].second = "001000";	//jr different from jump
		        	string  ans=m[dummy].first +  mr[dummy2] + rt_rd +shift_amount + m[dummy].second;
			        myfile<<res;

		        	for(int p=0;p<ans.size();p++)
		        	{
		        		if(p%4==0)
		        			myfile<<" ";
		        		myfile<<ans.at(p);
		        	}

		        	myfile<<endl;
		        }
		        else
		        {
		        	cout<<"error in line "<<count<<" invalid register"<<endl;
		        }
    		}
    		else if(tp.second=="target")   // for jump instruction
    		{
    			//Ignoring spaces
		        string dummy2="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        //Reading label
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ')
		        	{
		        		break;
		        	}
		        	dummy2+=str.at(i);
		        }

				//Ignoring spaces
				string dummy3="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        //Reading empty string
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ')
		        	{
		        		break;
		        	}
		        	dummy3+=str.at(i);
		        }

		        if(dummy3.empty() && target.count(dummy2))   // Anything after target address throws error
		        {
		        	
	        		
        			// processing
        			//conversion of Program counter into Hexadecimal form
        			stringstream ss; 
				    ss << hex << valid_count; 
				    string res = ss.str();
				    while(res.size() < 4)    
				    {
				    	res = "0"+res;
				    } 
				    res = "0x" + res; 

				    int offset = target[dummy2];   //calculation of offset
				    
				    string bin = decToBinary(offset,26); //conversion of offset in binary

				    string  ans=m[dummy].first+bin;  //32 bit machine code
		        	myfile<<res;  //Prints P.C in .o file

		        	for(int p=0;p<ans.size();p++)
		        	{
		        		if(p%4==0)
		        			myfile<<" ";
		        		myfile<<ans.at(p); //prints Machine code in .o file in group of 4
		        	}

		        	myfile<<endl;
	        		

		        }
		        else
		        {
		        	//Invalid target address
		        	cout<<"error in line "<<count<<" invalid target adderess"<<endl;
		        }

    		}

/////////////////////////////////////////////////////////////////////////////////////////////

    		// la = lui instructions look similar to div and mul but are I-type
    		else if(dummy=="la")
    		{
    			//Ignoring spaces
    			string dummy2="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        //Reading register name
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy2+=str.at(i);
		        }
		        //Ignoring spaces
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        //checking for comma
		        char tcomma='?';
		        if(i<str.size())
		        {
		        	tcomma=str.at(i);
		        	i++;
		        }
		        //Ignoring spaces
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        // 2nd register
		        string dummy3="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy3+=str.at(i);
		        }
		        //Ignoring spaces
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        //Reading empty space
		        string dummy4="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		dummy4+= str.at(i);
		        		
		        	}

		        }
		        int temp,sign;
		        if(mr.count(dummy2) && isValid(dummy3,temp,sign) && tcomma==',' && dummy4.empty() ) //condition for valid la and lui instruction
		        			  //temp gives decimal euivalent of string
		        			  //sign gives sign of decimal number
		        {

		        	string bin = decToBinary(temp,16);	//conversion of imm value to binary

		        	stringstream ss; 
				    ss << hex << valid_count; 
				    string res = ss.str();
				    while(res.size() < 4)
				    {
				    	res = "0"+res;
				    } 
				    res = "0x" + res; 
				    
				    string rs="00000";

		        	string  ans=m[dummy].first + rs + mr[dummy2] +bin;
			        myfile<<res;

			        	for(int p=0;p<ans.size();p++)
			        	{
			        		if(p%4==0)
			        			myfile<<" ";
			        		myfile<<ans.at(p);
			        	}

			        	myfile<<endl;
		        }
		        else
		        {
		        	cout<<"error in line "<<count<<" due to invalid syntax"<<endl;
		        }
    		}

/////////////////////////////////////////////////////////////////////////////////////////////
    		// for I-type instructions
    		else if(tp.second=="imm")
    		{
    			string dummy2="";
    			//Ignoring spaces
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        //Reading first register
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy2+=str.at(i);
		        }
		        //Ignoring spaces
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        //Checking for comma
		        char tcomma='?';
		        if(i<str.size())
		        {
		        	tcomma=str.at(i);
		        	i++;
		        }
		        //Ignoring spaces
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        //Reading second register
		        string dummy3="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy3+=str.at(i);
		        }
		        //Ignoring spaces
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        //checking for comma
		        char tcomma1='?';
		        if(i<str.size())
		        {
		        	tcomma1=str.at(i);
		        	i++;
		        }

		        //Reading immediate value
				string dummy4="";
		        for(; i<str.size(); i++)
		        {
		        	dummy4+=str.at(i);
		        }

		        //isvalid will look into immediate value's validation
		        int temp=0;  // by reference to isvalid function
		        int sign=0;  // to check sign of immediate

		        //final condition for error checking
		        if(mr.count(dummy2) && mr.count(dummy3) && tcomma==',' && tcomma1==',' && isValid(dummy4,temp,sign))
		        {

		        	string bin = decToBinary(temp,16);
		        	if(sign == -1) //if negative immediate value, convert to two's complement
		        	{
		        		bin = TwosComplement(bin);
		        	}

		        	stringstream ss; 
				    ss << hex << valid_count; 
				    string res = ss.str();
				    while(res.size() < 4)
				    {
				    	res = "0"+res;
				    } 
				    res = "0x" + res; 
				    

		        	string  ans=m[dummy].first + mr[dummy3] + mr[dummy2] +bin;
			        myfile<<res;

		        	for(int p=0;p<ans.size();p++)
		        	{
		        		if(p%4==0)
		        			myfile<<" ";
		        		myfile<<ans.at(p);
		        	}

		        	myfile<<endl;


		        }
		        else
		        {
		        	cout<<"error in line "<<count<<" due to invalid syntax"<<endl;
		        }
    		}

/////////////////////////////////////////////////////////////////////////////////////////////
    		//For sll and srl instruction which are of R-type, structure is similar to I-type
    		else if(dummy == "sll" || dummy == "srl")
    		{
    			//checking for first register
    			string dummy2="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy2+=str.at(i);
		        }
		        
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        
		        char tcomma='?';
		        if(i<str.size())
		        {
		        	tcomma=str.at(i);
		        	i++;
		        }
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        

		        //2nd register
		        string dummy3="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy3+=str.at(i);
		        }
		        
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        
		        //checking for comma
		        char tcomma1='?';
		        if(i<str.size())
		        {
		        	tcomma1=str.at(i);
		        	i++;
		        }

		        //scanning for immediate value

				string dummy4="";
		        for(; i<str.size(); i++)
		        {
		        	dummy4+=str.at(i);
		        }
		        
		        //Final condition for error checking
		        int temp=0;  //by refernce to isvalid function
		        int sign=0;  // to check sign of input
		        
		        if(mr.count(dummy2) && mr.count(dummy3) && tcomma==',' && tcomma1==',' && isValid(dummy4,temp,sign))
		        {

		        	string bin = decToBinary(temp,5);
		        	if(sign == -1)
		        	{
		        		cout<<"error in line "<<count<<" due to negative shift_amount"<<endl;
		        		continue;
		        	}
		        

		        	stringstream ss; 
				    ss << hex << valid_count; 
				    string res = ss.str();
				    while(res.size() < 4)
				    {
				    	res = "0"+res;
				    } 
				    res = "0x" + res; 
				    
				    string rs="00000";

		        	
		        	string  ans=m[dummy].first + rs+  mr[dummy3] + mr[dummy2] +bin +m[dummy].second;
			        myfile<<res;

		        	for(int p=0;p<ans.size();p++)
		        	{
		        		if(p%4==0)
		        			myfile<<" ";
		        		myfile<<ans.at(p);
		        	}

		        	myfile<<endl;



				}
				else
				{
					cout<<"error in line "<<count<<" due to invalid syntax"<<endl;
				}





    		}
/////////////////////////////////////////////////////////////////////////////////////////////
    		//Branch type instructions
    		else if(tp.second=="branch")   
    		{
    			string dummy2="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy2+=str.at(i);
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        
		        //checking for comma
		        char tcomma='?';
		        if(i<str.size())
		        {
		        	tcomma=str.at(i);
		        	i++;
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }


		        //2nd register
		        string dummy3="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy3+=str.at(i);
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        
		        //checking for comma
		        char tcomma1='?';
		        if(i<str.size())
		        {
		        	tcomma1=str.at(i);
		        	i++;
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }

		        //Checking for target address similar to jump
		        string dummy4="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ')
		        	{
		        		break;
		        	}
		        	dummy4+=str.at(i);
		        }


		        //Rest of the string should be empty
		        string dummy5="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		dummy5+= str.at(i);
		        		
		        	}

		        }

		        //dummy5.at(0)=  # is also valid when the comment is at the end of the line.
		        // But not allowed in our design
		        if(mr.count(dummy2) && mr.count(dummy3) && tcomma==',' && tcomma1==',' && dummy5.empty() && target.count(dummy4))
		        {
		        	
		        	stringstream ss; 
				    ss << hex << valid_count; 
				    string res = ss.str();
				    while(res.size() < 4)
				    {
				    	res = "0"+res;
				    } 
				    res = "0x" + res; 

				    int offset = target[dummy4];  // calculation of offset
				    
				    string bin = decToBinary(offset,16);

		        	
		        	string  ans=m[dummy].first + mr[dummy2] + mr[dummy3] +bin;
			        myfile<<res;

		        	for(int p=0;p<ans.size();p++)
		        	{
		        		if(p%4==0)
		        			myfile<<" ";
		        		myfile<<ans.at(p);
		        	}

		        	myfile<<endl;
		        }
		        else
		        {
		        	cout<<"error in line "<<count<<" due to invalid syntax"<<endl;
		        }
    		}
/////////////////////////////////////////////////////////////////////////////////////////////
    		//checking for mult and div
    		else if(dummy=="mult" || dummy=="multu" || dummy == "div" || dummy == "divu")
    		{
    			string dummy2="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy2+=str.at(i);
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        
		        //checking for comma
		        char tcomma='?';
		        if(i<str.size())
		        {
		        	tcomma=str.at(i);
		        	i++;
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }


		        //2nd register
		        string dummy3="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy3+=str.at(i);
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }

		        string dummy4="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		dummy4+= str.at(i);
		        		
		        	}

		        }

		        if(mr.count(dummy2) && mr.count(dummy3) && tcomma==',' && dummy4.empty() )
		        {
		        	//processing div and mult instructions

		        	string shift_amount="0000000000"; //shift amount for mult and div
		        	stringstream ss; 
				    ss << hex << valid_count; 
				    string res = ss.str();
				    while(res.size() < 4)
				    {
				    	res = "0"+res;
				    } 
				    res = "0x" + res; 
				    

		        	
		        	string  ans=m[dummy].first + mr[dummy2] + mr[dummy3] +shift_amount + m[dummy].second;
			        myfile<<res;

		        	for(int p=0;p<ans.size();p++)
		        	{
		        		if(p%4==0)
		        			myfile<<" ";
		        		myfile<<ans.at(p);
		        	}

		        	myfile<<endl;
		        }
		        else
		        {
		        	cout<<"error in line "<<count<<" due to invalid syntax"<<endl;
		        }



    		}


    		//checking for mfhi and mflo whose syntax is similar to J type but it is R-type
    		else if(dummy == "mfhi" || dummy =="mflo" || dummy =="mthi" || dummy =="mtlo")
    		{
    			string dummy2="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        // Register one reading
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ')
		        	{
		        		break;
		        	}
		        	dummy2+=str.at(i);
		        }

				

				string dummy3="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ')
		        	{
		        		break;
		        	}
		        	dummy3+=str.at(i);
		        }

		        if(dummy3.empty() && mr.count(dummy2))
		        {
		     
        			
        			stringstream ss; 
				    ss << hex << valid_count; 
				    string res = ss.str();
				    while(res.size() < 4)
				    {
				    	res = "0"+res;
				    } 
				    res = "0x" + res;
				    string shift_amount="00000";
				    string rs_rt = "0000000000"; //check 32 bit distribution of this instrn.

		        	
		        	string  ans=m[dummy].first + rs_rt + mr[dummy2] +shift_amount + m[dummy].second;
			        myfile<<res;

		        	for(int p=0;p<ans.size();p++)
		        	{
		        		if(p%4==0)
		        			myfile<<" ";
		        		myfile<<ans.at(p);
		        	}

		        	myfile<<endl;
		        }
		        else
		        {
		        	cout<<"error in line "<<count<<" invalid register"<<endl;
		        }
    		}
/////////////////////////////////////////////////////////////////////////////////////////////
    		// R type instructions e.g add
    		else
    		{ 

    			string dummy2="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy2+=str.at(i);
		        }
		        // first register
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        
		        //checking for comma
		        char tcomma='?';
		        if(i<str.size())
		        {
		        	tcomma=str.at(i);
		        	i++;
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }


		        //2nd register
		        string dummy3="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ' ||str.at(i)==',')
		        	{
		        		break;
		        	}
		        	dummy3+=str.at(i);
		        }

		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }
		        
		        //checking for comma
		        char tcomma1='?';
		        if(i<str.size())
		        {
		        	tcomma1=str.at(i);
		        	i++;
		        }


		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		break;
		        	}
		        }


		        //3rd register
		        string dummy4="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)==' ')
		        	{
		        		break;
		        	}
		        	dummy4+=str.at(i);
		        }

		        //rest of the string should be empty
		        string dummy5="";
		        for(; i<str.size(); i++)
		        {
		        	if(str.at(i)!=' ')
		        	{
		        		dummy5+= str.at(i);
		        		
		        	}

		        }
		        
		        
		        if(mr.count(dummy2) && mr.count(dummy3) && tcomma==',' && tcomma1==',' && mr.count(dummy4) && dummy5.empty())
		        {
		        	string shift_amount="00000";
		        	stringstream ss; 
				    ss << hex << valid_count; 
				    string res = ss.str();
				    while(res.size() < 4)
				    {
				    	res = "0"+res;
				    } 
				    res = "0x" + res; 
				    

		        	
		        	string  ans=m[dummy].first + mr[dummy3] + mr[dummy4] +mr[dummy2]+shift_amount + m[dummy].second;
			        myfile<<res;

		        	for(int p=0;p<ans.size();p++)
		        	{
		        		if(p%4==0)
		        			myfile<<" ";
		        		myfile<<ans.at(p);
		        	}

		        	myfile<<endl;

		        	
		        }
		        else
		        {
		        	cout<<"error in line "<<count<<" due to invalid syntax"<<endl;
		        }
    		}

        }


    }

	

	
























}