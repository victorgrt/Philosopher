/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:20:54 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/15 15:58:43 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <pthread.h>
#include <unistd.h>

/*Race condition :              t1      t2	||	t1		t2
- read value of mails		Ex: 23		24	||	29		23
- incremente the value			23		24	||	29		30
- write it back to memory 		24		25	||	30		24
						 finish so 2nd thread time
						 
This is fine with 1 thread but with multiple this might
occure.
In the second case it's because the 23 is stocked in processeur
and reads it from it.
*/

/*Mutex:
Lock arround a part of a code to prevent race conditions.
Protect against another thread executing it at the same time.
If at anypoint the thing locked is executed, no one else can do it
in paralel.
Only needed if multiple threads would execute the same part of a code
that could mess things up.
*/

int mails = 0;
pthread_mutex_t mutex;

void*	routine()
{
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);

	}
	return (NULL);
}

int main(int ac, char **av)
{
    (void) ac;
    (void) av;

    pthread_t t1, t2;
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);

    if (pthread_create(&t1, NULL, &routine, NULL) != 0) //initialisation
		return (1); //there was an error
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (2);
    if (pthread_join(t1, NULL) != 0) //wait until it's finished askip
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);

	pthread_mutex_destroy(&mutex);

	printf("Number of mails : %d\n", mails);
    return (0);
}