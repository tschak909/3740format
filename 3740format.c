/**
 * @brief Make 3740 format disk
 * @verbose 77 tracks, 26 sectors per track, 128 bytes/sector, 0xE5 fill byte, 256256 bytes total
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license gpl v. 3, see LICENSE.md for details
 */

#include <stdio.h>
#include <string.h>

#define FILL_BYTE 0xE5
#define RECORD_SIZE 128
#define NUM_SECTORS 2002

unsigned char record[RECORD_SIZE];

int main(int argc, char *argv[])
{
  FILE *fp;
  
  memset(record,FILL_BYTE,sizeof(record));

  if (argc<2)
    {
      printf("%s <name-of-new-image.img>\n",argv[0]);
      return 1;
    }

  fp = fopen(argv[1],"wb");

  for (int i=0;i<NUM_SECTORS;i++)
    fwrite(record,sizeof(unsigned char),RECORD_SIZE,fp);
  
  fclose(fp);
  
  return 0;
}
