/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squareroot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:59:08 by jkuusist          #+#    #+#             */
/*   Updated: 2019/12/02 13:13:04 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long floorSqrt(unsigned long long x)
{
	unsigned long long start;
	unsigned long long end;
	unsigned long long ans;
	unsigned long long mid;

	if(!x || x > 18446744073709551615U)
		return (0);
	if (x == 0 || x == 1)
       return (x);
	start = 1; 
	end = x;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (mid*mid == x)
            return mid;
        if (mid*mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
			end = mid - 1;
    }
    return ans;
}
