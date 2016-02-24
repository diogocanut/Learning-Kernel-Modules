/* Praticando passagem de parametros, criação de variável, init.h e module.h. */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>


/* delcarando liscença e author */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("knute");

/* variaveis */

static int param1 = 420;
static char *param2 = "use-linux";
static int param[3] = {6,6,6};
static int meu_argc = 0;


/* passando as variaveis como parametro */

module_param(param1, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(param1, "inteiro");
module_param(param2, charp, 0000);
MODULE_PARM_DESC(param2, "string");
/* parametro especifico para array */

module_param_array(param, int, &meu_argc, 0000);
MODULE_PARM_DESC(param, "array de tamanho 3");

/* init e uma funcao que funciona como a main, porem e dividida em init e exit */

static int __init knute_init(void){
      
  int i;
  printk(KERN_INFO "Parametro 1: %d\n" ,param1);
  printk(KERN_INFO "Parametro 2: %s\n" ,param2);
     


  printk(KERN_INFO "Foram inseridos %d argumentos no param3\n" ,meu_argc);
  for(i=0; i < (sizeof param / sizeof (int)); i++){
    printk(KERN_INFO "Parametro 3[%d]: %d\n" ,i,param[i]);
  }

  return 0;

}


static void __exit knute_exit(void){
  printk(KERN_INFO "exiting...\n");

}

module_init(knute_init);
module_exit(knute_exit);
