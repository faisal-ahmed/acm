#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	//freopen ("text.txt","w",stdout);
	int block[30][30], b_num, p, p2, i, k;
	char comands[20], *ptr;

	scanf ("%d",&b_num);
	getchar();

	for (i = 0; i < b_num; i++)
	{
		block[i][0] = i;
		for (k = 1; k < 30; k++)
		{
			block[i][k] = -1;
		}
	}

	while (gets(comands))
	{
		if ( (strcmp (comands,"quit")) == 0 )
		break;
		else
		{
			int a, b, c, loop, loop1, check1, check2, check3, check4, d, z = 1, br = 0;
			
			ptr = strtok (comands," ");
			if ( (strncmp (ptr,"pile",4)) == 0)        //pile
			{
				ptr = strtok ('\0', " ");
				a = atoi (ptr);
				ptr = strtok ('\0', " ");
				if ( (strncmp (ptr,"onto",4)) == 0 )    //onto
				{
					ptr = strtok ('\0', " ");
					b = atoi (ptr);
					if ( a != b)
					{
						for ( check3 = 0; check3 < 25; check3++)
						{
							for ( check4 = 0; check4 < 30; check4++)
							{
								if ( block[check3][check4] == b)
								{
									br = 1;
									break;
								}
								else if ( block[check3][check4] == -1)
									break;
							}
							if (br)
							{
								br = 0;
								break;
							}
						}

						for ( loop = check4+1; loop < 30; loop++)
						{
							if (block[check3][loop] != -1)
							{
								c = block[check3][loop];
								block[c][0] = c;
								block[check3][loop] = -1;
							}
							else
								break;
						}

						for ( check1 = 0; check1 < 25; check1++)
						{
							for ( check2 = 0; check2 < 30; check2++)
							{
								if ( block[check1][check2] == a)
								{
									br = 1;
									break;
								}
								else if ( block[check1][check2] == -1)
									break;
							}
							if (br)
							{
								br = 0;
								break;
							}
						}
						
						z=1;
						if ( check1 != check3 )
						{
							for ( loop1 = check2; loop1 < 30; loop1++)
							{
								if (block[check1][loop1] != -1)
								{
									d = block[check1][loop1];
									block[check3][check4+z] = d;
									block[check1][loop1] = -1;
									z++;
								}
								else
									break;
							}
						}
					}
					else
						continue;
				}
				else                            // over
				{
					ptr = strtok ('\0', " ");
					b = atoi (ptr);
					if ( a != b)
					{
						for ( check3 = 0; check3 < 25; check3++)
						{
							for ( check4 = 0; check4 < 30; check4++)
							{
								if ( block[check3][check4] == b)
								{
									br = 1;
									break;
								}
								else if ( block[check3][check4] == -1)
									break;
							}
							if (br)
							{
								br = 0;
								break;
							}
						}

						for ( check1 = 0; check1 < 25; check1++)
						{
							for ( check2 = 0; check2 < 30; check2++)
							{
								if ( block[check1][check2] == a)
								{
									br = 1;
									break;
								}
								else if ( block[check1][check2] == -1)
									break;
							}
							if (br)
							{
								br = 0;
								break;
							}
						}

						if ( check1 != check3)
						{
							for ( loop1 = check2; loop1 < 30; loop1++)
							{
								if ( block[check1][loop1] != -1)
								{
									d = block[check1][loop1];
									for ( z = check4; z < 30; z++)
									{
										if ( block[check3][z] == -1)
										{
											block[check3][z] = d;
											block[check1][loop1] = -1;
											break;
										}
									}
								}
								else
									break;
							}
						}
					}
					else
						continue;
				}
			}
			else                      //move
			{
				ptr = strtok ('\0', " ");
				a = atoi (ptr);
				ptr = strtok ('\0', " ");
				if ( (strncmp (ptr,"onto",4)) == 0 )         //onto
				{
					ptr = strtok ('\0', " ");
					b = atoi (ptr);
					if ( a != b)
					{
						for ( check3 = 0; check3 < 25; check3++)
						{
							for ( check4 = 0; check4 < 30; check4++)
							{
								if ( block[check3][check4] == b)
								{
									br = 1;
									break;
								}
								else if ( block[check3][check4] == -1)
									break;
							}
							if (br)
							{
								br = 0;
								break;
							}
						}
						
						for ( loop = check4+1; loop < 30; loop++)
						{
							if (block[check3][loop] != -1)
							{
								c = block[check3][loop];
								block[c][0] = c;
								block[check3][loop] = -1;
							}
							else
								break;
						}
						
						for ( check1 = 0; check1 < 25; check1++)
						{
							for ( check2 = 0; check2 < 30; check2++)
							{
								if ( block[check1][check2] == a)
								{
									br = 1;
									break;
								}
								else if ( block[check1][check2] == -1)
									break;
							}
							if (br)
							{
								br = 0;
								break;
							}
						}
						
						if ( check1 != check3 )
						{
							for ( loop = check2+1; loop < 30; loop++)
							{
								if (block[check1][loop] != -1)
								{
									c = block[check1][loop];
									block[c][0] = c;
									block[check1][loop] = -1;
								}
								else
									break;
							}
							
							block[check3][check4+1] = block[check1][check2];
							block[check1][check2] = -1;
						}
					}
					else
						continue;
				}
				else               //over
				{
					ptr = strtok ('\0', " ");
					b = atoi (ptr);
					if ( a != b )
					{
						for ( check3 = 0; check3 < 25; check3++)
						{
							for ( check4 = 0; check4 < 30; check4++)
							{
								if ( block[check3][check4] == b)
								{
									br = 1;
									break;
								}
								else if ( block[check3][check4] == -1)
									break;
							}
							if (br)
							{
								br = 0;
								break;
							}
						}
						
						for ( check1 = 0; check1 < 25; check1++)
						{
							for ( check2 = 0; check2 < 30; check2++)
							{
								if ( block[check1][check2] == a)
								{
									br = 1;
									break;
								}
								else if ( block[check1][check2] == -1)
									break;
							}
							if (br)
							{
								br = 0;
								break;
							}
						}
						
						if ( check1 != check3 )
						{
							for ( loop = check2+1; loop < 30; loop++)
							{
								if (block[check1][loop] != -1)
								{
									c = block[check1][loop];
									block[c][0] = c;
									block[check1][loop] = -1;
								}
								else
									break;
							}

							for ( loop1 = 0; loop1 < 30; loop1++)
							{
								if ( block[check3][loop1] == -1)
								{
									block[check3][loop1] = block[check1][check2];
									block[check1][check2] = -1;
									break;
								}
							}
						}
					}
					else
						continue;
				}
			}
		}
	}

	for ( p = 0; p < b_num; p++)
	{
		printf ("%d:",p);
		for ( p2 = 0; p2 < 30; p2++)
		{
			if ( block[p][p2] != -1)
				printf (" %d",block[p][p2]);
			else
				break;
		}
		printf ("\n");
	}

	return 0;
}