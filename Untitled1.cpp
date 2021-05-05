for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
           new_arrary[i][j] == "";
        }
    }
int show_window(Square sq[][],int a,int b,int c,int d)
{
    int x1=a-1;
    int y1=b-1;
    int x2=c-1;
    int y2=d-1;
	std::string new_array[10][10];
// output outfile file
    new_arrary[x1][y1]=the_map[x1][y1];
    new_arrary[x2][y2]=the_map[x2][y2];

	std::string the_number[3];
    the_number[0]=the_map[x1][y1];
    the_number[1]=the_map[x2][y2];


 

// Print the board that is not judged after flipping
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(new_arrary[i][j]!="")
            {
                       sq[i][j].SetRect(potx,poty);
                       sq[i][j].GetRect();
                       sq[i][j].LoadImg(the_map[i][j],g_screen);}
            }
            else
                sq.Show(g_screen, potx,poty);

            
        }
    }

// Delay
    double start,stop;
    start=clock();

Sleep(5*1000);//Delay 5 seconds

    stop=clock();

// New line
   
// Determine whether the flipped cards are equal
    if(the_number[0]==the_number[1])
    {
        new_arrary[x1][y1]=the_map[x1][y1];
        new_arrary[x2][y2]=the_map[x2][y2];
    }
    else
    {
        new_arrary[x1][y1]="";
        new_arrary[x2][y2]="";
    }

// Print the flipped and judged card surface
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(new_arrary[i][j]==0)
                cout<<"*"<<"  ";
            else
                cout<<new_arrary[i][j]<<"  ";;
            if((j+1)%4==0)
            {
                cout<<endl;
                cout<<endl;
            }
        }
    }
    if(the_number[0]==the_number[1])
    {
        return 1;
    }
    else
        return 0;
}


