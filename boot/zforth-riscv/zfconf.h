#ifndef zfconf
#define zfconf

/* Set to 1 to add tracing support for debugging and inspection. Requires the
 * zf_host_trace() function to be implemented. Adds about one kB to .text and
 * .rodata, dramatically reduces speed, but is very useful. Make sure to enable
 * tracing at run time when calling zf_init() or by setting the 'trace' user
 * variable to 1 */

#define ZF_ENABLE_TRACE 0


/* Set to 1 to add boundary checks to stack operations. Increases .text size
 * by approx 100 bytes */

#define ZF_ENABLE_BOUNDARY_CHECKS 1


/* Set to 1 to enable bootstrapping of the forth dictionary by adding the
 * primitives and user veriables. On small embedded systems you may choose to
 * leave this out and start by loading a cross-compiled dictionary instead.
 * Enabling adds a few hundred bytes to the .text and .rodata segments */
 
#define ZF_ENABLE_BOOTSTRAP 1


/* Set to 1 to enable typed access to memory. This allows memory read and write 
 * of signed and unsigned memory of 8, 16 and 32 bits width, as well as the zf_cell 
 * type. This adds a few hundred bytes of .text. Check the memaccess.zf file for
 * examples how to use these operations */

#define ZF_ENABLE_TYPED_MEM_ACCESS 0


/* Type to use for the basic cell, data stack and return stack. Choose a signed
 * integer type that suits your needs, or 'float' or 'double' if you need
 * floating point numbers */

typedef int32_t zf_cell;
#define ZF_CELL_FMT "%ld"


/* The type to use for pointers and adresses. 'unsigned int' is usually a good
 * choice for best performance and smallest code size */

typedef unsigned int zf_addr;
#define ZF_ADDR_FMT "%04x"


/* Memory region sizes: dictionary size is given in bytes, stack sizes are
 * number of elements of type zf_cell */

#define ZF_DICT_SIZE 4096
#define ZF_DSTACK_SIZE 32
#define ZF_RSTACK_SIZE 32

#endif
