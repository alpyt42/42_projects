/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:11:21 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/16 16:56:03 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*bef;
}	t_list;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
t_list	*ft_lstnew(int nbr);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
long	ft_atoi(char *str);
void	ft_clear_list(t_list *lst);
void	ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
void	swap(t_list *list, char c);
void	push(t_list **from_list, t_list **to_list, char c);
void	rotate(t_list *list, char c);
void	rev_rotate(t_list *list, char c);
int		istri(t_list *list);
void	algo_three_nbrs(t_list *list, char c);
void	algo_six_nbrs(t_list *lista, t_list *listb, int argc);
int		*idx(char *argv[], int argc);
void	algo_radx(t_list *lista, t_list *listb, int argc);
int		parse_args(int argc, char ***argv);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *left_str, char *buf);
int		*idx(char *argv[], int argc);
t_list	*ft_init(int *tab, int argc);
char	**ft_freeall(char **res, size_t args);

#endif