#ifndef __INCLUDE_MFT_H__
#define __INCLUDE_MFT_H__

// Awesome https://boktaihacking.net/wiki/Master_file_table

struct mft_directory;

typedef u16 FileID;

typedef struct {
  u32 id;
  struct mft_directory* directory;
} mft_header;

// NOTE: This applies to all directories, EXCEPT for the script directory. That has its own format.
typedef struct mft_directory {
  u32 num_entries;
  u32 offset_to_id_array;    // Relative to the start of this struct
  u32 offset_to_file_array;  // Relative to the start of this struct
  u32 offset_to_first_file;  // Unused, ignorable. Relative to the start of this struct.

  FileID id_array[num_entries];
  u32 file_array[num_entries];  // Entries are relative to the start of this struct

  // File contents follow
} mft_directory;

#endif  // __INCLUDE_MFT_H__
