/**************************************************************************
 * File: setSnake.c										  		  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:10/10/2021                            				      *
 * Date Modified: 17/10/2021                              				  *               
 * Purpose: Chase the player when player moves	  						  *
 **************************************************************************/
 
void setSnakeLocation( int* rowOfPlayer, int* colOfPlayer, char* playerCh, 
						int* rowOfEnemy, int* colOfEnemy, char** array)
{
	char space = ' ';
	
	
	if( *rowOfPlayer > *rowOfEnemy )
	{
		
		if( *colOfPlayer > *colOfEnemy )
		{
			
			if( ( *playerCh == '^' || *playerCh == '>' )
				&& ( array[*(rowOfEnemy)][*(colOfEnemy)+1] == space
				|| array[*(rowOfEnemy)][*(colOfEnemy)+1] == *playerCh )  )
			{
				
				array[*rowOfEnemy][*colOfEnemy] = space; 
				*colOfEnemy = *colOfEnemy + 1;
				
			}
			else
			{	
				if( ( *playerCh == 'v' || *playerCh == '<' )
					&& ( array[*(rowOfEnemy)+1][*(colOfEnemy)] == space
					|| array[*(rowOfEnemy)+1][*(colOfEnemy)] == *playerCh )  )
				{
					array[*rowOfEnemy][*colOfEnemy] = space; 
					*rowOfEnemy = *rowOfEnemy + 1;
				}
				
			}
			
		}
		else
		{
			if( *colOfPlayer < *colOfEnemy )
			{
				if( ( *playerCh == '^' || *playerCh == '>' || *playerCh == '<' )
					&& ( array[*(rowOfEnemy)][*(colOfEnemy)-1] == space
					|| array[*(rowOfEnemy)][*(colOfEnemy)-1] == *playerCh )  )
				{
					
					array[*rowOfEnemy][*colOfEnemy] = space; 
					*colOfEnemy = *colOfEnemy - 1;
					
				}
				else
				{
					if( *playerCh == 'v' && ( array[*(rowOfEnemy)+1][*(colOfEnemy)] == space
						|| array[*(rowOfEnemy)+1][*(colOfEnemy)] == *playerCh )  )
					{
						array[*rowOfEnemy][*colOfEnemy] = space; 
						*rowOfEnemy = *rowOfEnemy + 1;
					}
				}
			}
			else 	/* 	*colOfPlayer == *colOfEnemy  */
			{
				if( *playerCh == '>' && ( array[*(rowOfEnemy)][*(colOfEnemy)+1] == space
					|| array[*(rowOfEnemy)][*(colOfEnemy)+1] == *playerCh )  )
				{
					
					array[*rowOfEnemy][*colOfEnemy] = space; 
					*colOfEnemy = *colOfEnemy + 1;
					
				}
				else
				{
					if( *playerCh == '<' && ( array[*(rowOfEnemy)][*(colOfEnemy)-1] == space
						|| array[*(rowOfEnemy)][*(colOfEnemy)-1] == *playerCh )  )
					{
						
						array[*rowOfEnemy][*colOfEnemy] = space; 
						*colOfEnemy = *colOfEnemy - 1;
					}
					else
					{
						if( *playerCh == 'v' && ( array[*(rowOfEnemy)+1][*(colOfEnemy)] == space
							|| array[*(rowOfEnemy)+1][*(colOfEnemy)] == *playerCh )  )
						{
							array[*rowOfEnemy][*colOfEnemy] = space; 
							*rowOfEnemy = *rowOfEnemy + 1;
						}
						else
						{
							if( *playerCh == '^' && ( array[*(rowOfEnemy)+1][*(colOfEnemy)] == space
							|| array[*(rowOfEnemy)+1][*(colOfEnemy)] == *playerCh )  )
							{
								if( ( (*rowOfPlayer) - (*rowOfEnemy) ) != 1 )
								{
									array[*rowOfEnemy][*colOfEnemy] = space; 
									*rowOfEnemy = *rowOfEnemy + 1;
								}
								
							}
						}
					}
				}
			}
		}
		
	}
	else
	{
		if( *rowOfPlayer < *rowOfEnemy )
		{
			if( *colOfPlayer > *colOfEnemy )
			{
				if( *playerCh == '^' && ( array[*(rowOfEnemy)-1][*(colOfEnemy)] == space
					|| array[*(rowOfEnemy)-1][*(colOfEnemy)] == *playerCh )  )
				{
					array[*rowOfEnemy][*colOfEnemy] = space; 
					*rowOfEnemy = *rowOfEnemy - 1;
				}
				else
				{
					if( ( *playerCh == '<' || *playerCh == '>' || *playerCh == 'v' ) 
						&& ( array[*(rowOfEnemy)][*(colOfEnemy)+1] == space
						|| array[*(rowOfEnemy)][*(colOfEnemy)+1] == *playerCh )  )
					{
						array[*rowOfEnemy][*colOfEnemy] = space; 
						*colOfEnemy = *colOfEnemy + 1;
					}
				}
			}
			else
			{
				if( *colOfPlayer < *colOfEnemy )
				{
					if( *playerCh == '^' && ( array[*(rowOfEnemy)-1][*(colOfEnemy)] == space
						|| array[*(rowOfEnemy)-1][*(colOfEnemy)] == *playerCh )  )
					{
						array[*rowOfEnemy][*colOfEnemy] = space; 
						*rowOfEnemy = *rowOfEnemy - 1;
					}
					else
					{
						if( ( *playerCh == '<' || *playerCh == '>' || *playerCh == 'v' ) && 
						( array[*(rowOfEnemy)][*(colOfEnemy)-1] == space
						|| array[*(rowOfEnemy)][*(colOfEnemy)-1] == *playerCh )  )
						{
							array[*rowOfEnemy][*colOfEnemy] = space; 
							*colOfEnemy = *colOfEnemy - 1;
						}
					}
				}
				else  /* *colOfPlayer == *colOfEnemy */
				{
					if( *playerCh == '>' && ( array[*(rowOfEnemy)][*(colOfEnemy)+1] == space
						|| array[*(rowOfEnemy)][*(colOfEnemy)+1] == *playerCh )  )
					{
						
						array[*rowOfEnemy][*colOfEnemy] = space; 
						*colOfEnemy = *colOfEnemy + 1;
						
					}
					else
					{
						if( *playerCh == '<' && ( array[*(rowOfEnemy)][*(colOfEnemy)-1] == space
							|| array[*(rowOfEnemy)][*(colOfEnemy)-1] == *playerCh )  )
						{
							
							array[*rowOfEnemy][*colOfEnemy] = space; 
							*colOfEnemy = *colOfEnemy - 1;
						}
						else
						{
							if( *playerCh == '^' && ( array[*(rowOfEnemy)-1][*(colOfEnemy)] == space
								|| array[*(rowOfEnemy)-1][*(colOfEnemy)] == *playerCh )  )
							{
								array[*rowOfEnemy][*colOfEnemy] = space; 
								*rowOfEnemy = *rowOfEnemy - 1;
							}
							else
							{
								if( *playerCh == 'v' && ( array[*(rowOfEnemy)-1][*(colOfEnemy)] == space
									|| array[*(rowOfEnemy)-1][*(colOfEnemy)] == *playerCh )  )
								{
									if( ( (*rowOfEnemy) - (*rowOfPlayer)  ) != 1 )
									{
										array[*rowOfEnemy][*colOfEnemy] = space; 
										*rowOfEnemy = *rowOfEnemy - 1;
									}
									
								}
							}
						}
					}
				}
			}
		}
		else /*  *rowOfPlayer == *rowOfEnemy  */
		{
			if( *colOfPlayer > *colOfEnemy )
			{
				if( *playerCh == '^' && ( array[*(rowOfEnemy)-1][*(colOfEnemy)] == space
					|| array[*(rowOfEnemy)-1][*(colOfEnemy)] == *playerCh )  )
				{
					array[*rowOfEnemy][*colOfEnemy] = space; 
					*rowOfEnemy = *rowOfEnemy - 1;
				}
				else
				{
					if( *playerCh == 'v' && ( array[*(rowOfEnemy)+1][*(colOfEnemy)] == space
						|| array[*(rowOfEnemy)+1][*(colOfEnemy)] == *playerCh )  )
					{
						array[*rowOfEnemy][*colOfEnemy] = space; 
						*rowOfEnemy = *rowOfEnemy + 1;
					}
					else
					{
						if( *playerCh == '>' && ( array[*(rowOfEnemy)][*(colOfEnemy)+1] == space
							|| array[*(rowOfEnemy)][*(colOfEnemy)+1] == *playerCh )  )
						{
							
							array[*rowOfEnemy][*colOfEnemy] = space; 
							*colOfEnemy = *colOfEnemy + 1;
						}
						else
						{
							if( *playerCh == '<' && ( array[*(rowOfEnemy)][*(colOfEnemy)+1] == space
								||array[*(rowOfEnemy)][*(colOfEnemy)+1] == *playerCh )  )
							{
								if( ( (*colOfPlayer) - (*colOfEnemy)  ) != 1 )
								{
									array[*rowOfEnemy][*colOfEnemy] = space; 
									*colOfEnemy = *colOfEnemy + 1;
								}
							}
						}
					}
				}
			}
			else
			{
				if( *colOfPlayer < *colOfEnemy )
				{
					if( *playerCh == '^' && ( array[*(rowOfEnemy)-1][*(colOfEnemy)] == space 
						|| array[*(rowOfEnemy)-1][*(colOfEnemy)] == *playerCh  ) )
					{
						array[*rowOfEnemy][*colOfEnemy] = space; 
						*rowOfEnemy = *rowOfEnemy - 1;
					}
					else
					{
						if( *playerCh == 'v' && ( array[*(rowOfEnemy)+1][*(colOfEnemy)] == space
							|| array[*(rowOfEnemy)+1][*(colOfEnemy)] == *playerCh )  )
						{
							array[*rowOfEnemy][*colOfEnemy] = space; 
							*rowOfEnemy = *rowOfEnemy + 1;
						}
						else
						{
							if( *playerCh == '<' && ( array[*(rowOfEnemy)][*(colOfEnemy)-1] == space
								|| array[*(rowOfEnemy)][*(colOfEnemy)-1] == *playerCh )  )
							{
								
								array[*rowOfEnemy][*colOfEnemy] = space; 
								*colOfEnemy = *colOfEnemy - 1;
							}
							else
							{
								if( *playerCh == '>' && ( array[*(rowOfEnemy)][*(colOfEnemy)-1] == space 
									|| array[*(rowOfEnemy)][*(colOfEnemy)-1] == *playerCh )  )
								{
									if( ( (*colOfEnemy) - (*colOfPlayer)  ) != 1 )
									{
										array[*rowOfEnemy][*colOfEnemy] = space; 
										*colOfEnemy = *colOfEnemy - 1;
									}
								}
							}
						}
					}
				}
			}	
		}
	}						
}	