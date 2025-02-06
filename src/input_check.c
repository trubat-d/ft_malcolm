#include "ft_malcolm.h"

int ret_free(int error, char **array, char *msg , char *value)
{
  if(error)
    fprintf(stderr, "%s (%s)\n", msg, value);
  for(int i = 0; array[i]; i++)
    free(array[i]);
  free(array);
      
  return error;
}

int check_mac(char *mac)
{
  int number_of_fields = 0;
  char **splitted_mac = ft_split(mac, ':');
  for(int i = 0; splitted_mac[i]; i++)
  {
    number_of_fields +=1;
    for(int j = 0; splitted_mac[i][j]; j++)
    {
      int check = 1;
      for(int k = 0; HEXA_CHARSET[k]; k++){
        if(splitted_mac[i][j] == HEXA_CHARSET[k])
        {
          check = 0;
          break;
        }
      }
      if(check == 1)
        return ret_free(1, splitted_mac, "ft_malcolm: Malformed mac address : ", mac);
    }
    int len = strlen(splitted_mac[i]);
    if(len > 2 || len <= 0)
      return ret_free(1, splitted_mac, "ft_malcolm: invalid mac address: ", mac);
  }
  if(number_of_fields != 6)
    return ret_free(1, splitted_mac, "ft_malcolm: Malformed mac address: ", mac);

  return ret_free(0, splitted_mac, "", "");
}

int check_ip(char *ip)
{
  int number_of_fields = 0;
  char **splitted_ip = ft_split(ip, '.');
  for(int i = 0; splitted_ip[i]; i++)
  {
    number_of_fields+=1;
    for(int j = 0; splitted_ip[i][j]; j++)
      if(!ft_isdigit(splitted_ip[i][j]))
        return ret_free(1, splitted_ip, "ft_malcolm: invalid IP address: ", ip);
    int number = ft_atoi(splitted_ip[i]);
    if(number < 0 || number >255)
      return ret_free(1, splitted_ip, "ft_malcolm: invalid IP value: ", splitted_ip[i]);
  }
  if(number_of_fields != 4)
    return ret_free(1, splitted_ip, "ft_malcolm: IP malformed: ", ip);
  return ret_free(0, splitted_ip,"", "");
}

int input_check(int ac, char **av)
{
    printf("Entered input check\n");
    int error_code = (ac != 5);
    if(error_code){
      fprintf(stderr,"Usage is:\n ./ft_malcolm <source_ip> <source_mac> <target_ip> <target_mac>\n");
      return error_code;
    }
    error_code = check_ip(av[1]) || check_mac(av[2]) || check_ip(av[3]) || check_mac(av[4]);
    return error_code;    
}