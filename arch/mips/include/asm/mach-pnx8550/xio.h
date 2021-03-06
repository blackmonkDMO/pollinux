/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * Copyright (C) 2005 Koninklijke Philips Electronics N.V.
 * All Rights Reserved.
 */

#ifndef __PNX8550_NAND_H
#define __PNX8550_NAND_H

#define PNX8550_NAND_BASE_ADDR   0x10000000
#define PNX8550_PCIXIO_BASE	 0xBBE40000

#define PNX8550_BASE10_ADDR      *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x050)
#define PNX8550_BASE14_ADDR      *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x054)
#define PNX8550_BASE18_ADDR      *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x058)

#define PNX8550_DMA_EXT_ADDR     *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x800)
#define PNX8550_DMA_INT_ADDR     *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x804)
#define PNX8550_DMA_TRANS_SIZE   *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x808)
#define PNX8550_DMA_CTRL         *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x80c)
#define PNX8550_XIO_CTRL         *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x810)
#define PNX8550_XIO_SEL0         *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x814)
#define PNX8550_XIO_SEL1         *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x818)
#define PNX8550_GPXIO_ADDR       *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x820)
#define PNX8550_GPXIO_WR         *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x824)
#define PNX8550_GPXIO_RD         *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x828)
#define PNX8550_GPXIO_CTRL       *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x82C)
#define PNX8550_XIO_FLASH_CTRL   *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0x830)
#define PNX8550_GPXIO_INT_STATUS *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0xfb0)
#define PNX8550_GPXIO_INT_ENABLE *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0xfb4)
#define PNX8550_GPXIO_INT_CLEAR  *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0xfb8)
#define PNX8550_DMA_INT_STATUS   *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0xfd0)
#define PNX8550_DMA_INT_ENABLE   *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0xfd4)
#define PNX8550_DMA_INT_CLEAR    *(volatile unsigned long *)(PNX8550_PCIXIO_BASE + 0xfd8)

#define PNX8550_XIO_CTRL_XIO_ACK     0x00000002

#define PNX8550_XIO_SEL_EN_16BIT    0x00800000
#define PNX8550_XIO_SEL_USE_ACK     0x00400000
#define PNX8550_XIO_SEL_REN_HIGH    0x00100000
#define PNX8550_XIO_SEL_REN_LOW     0x00040000
#define PNX8550_XIO_SEL_WEN_HIGH    0x00010000
#define PNX8550_XIO_SEL_WEN_LOW     0x00004000
#define PNX8550_XIO_SEL_WAIT        0x00000200
#define PNX8550_XIO_SEL_OFFSET      0x00000020
#define PNX8550_XIO_SEL_TYPE_68360  0x00000000
#define PNX8550_XIO_SEL_TYPE_NOR    0x00000008
#define PNX8550_XIO_SEL_TYPE_NAND   0x00000010
#define PNX8550_XIO_SEL_TYPE_IDE    0x00000018
#define PNX8550_XIO_SEL_SIZE_8MB    0x00000000
#define PNX8550_XIO_SEL_SIZE_16MB   0x00000002
#define PNX8550_XIO_SEL_SIZE_32MB   0x00000004
#define PNX8550_XIO_SEL_SIZE_64MB   0x00000006
#define PNX8550_XIO_SEL_ENAB        0x00000001

#define PNX8550_XIO_SEL_OFFSET_SHIFT 5
#define PNX8550_XIO_SEL_OFFSET_MASK  (0xf << PNX8550_XIO_SEL_OFFSET_SHIFT)

#define PNX8550_SEL_DEFAULT ((PNX8550_XIO_SEL_EN_16BIT)  | \
                              (PNX8550_XIO_SEL_REN_HIGH*0)| \
	                      (PNX8550_XIO_SEL_REN_LOW*2) | \
	                      (PNX8550_XIO_SEL_WEN_HIGH*0)| \
                              (PNX8550_XIO_SEL_WEN_LOW*2) | \
	                      (PNX8550_XIO_SEL_WAIT*4)    | \
			      (PNX8550_XIO_SEL_OFFSET*0)  | \
			      (PNX8550_XIO_SEL_TYPE_NAND) | \
			      (PNX8550_XIO_SEL_SIZE_32MB) | \
			      (PNX8550_XIO_SEL_ENAB))

#define PNX8550_GPXIO_PENDING        0x00000200
#define PNX8550_GPXIO_DONE           0x00000100
#define PNX8550_GPXIO_CLR_DONE       0x00000080
#define PNX8550_GPXIO_INIT           0x00000040
#define PNX8550_GPXIO_READ_CMD       0x00000010
#define PNX8550_GPXIO_BEN            0x0000000F

#define PNX8550_XIO_FLASH_64MB       0x00200000
#define PNX8550_XIO_FLASH_INC_DATA   0x00100000
#define PNX8550_XIO_FLASH_CMD_PH_SHIFT 18
#define PNX8550_XIO_FLASH_CMD_PH_MASK  (3 << PNX8550_XIO_FLASH_CMD_PH_SHIFT)
#define PNX8550_XIO_FLASH_CMD_PH(_x)   (((_x) << PNX8550_XIO_FLASH_CMD_PH_SHIFT) & PNX8550_XIO_FLASH_CMD_PH_MASK)


#define PNX8550_XIO_FLASH_ADR_PH_SHIFT 16
#define PNX8550_XIO_FLASH_ADR_PH_MASK  (3 << PNX8550_XIO_FLASH_ADR_PH_SHIFT)
#define PNX8550_XIO_FLASH_ADR_PH(_x)   (((_x) << PNX8550_XIO_FLASH_ADR_PH_SHIFT) & PNX8550_XIO_FLASH_ADR_PH_MASK)

#define PNX8550_XIO_FLASH_CMD_B_MASK   0x0000FF00
#define PNX8550_XIO_FLASH_CMD_B_SHIFT  8
#define PNX8550_XIO_FLASH_CMD_B(_x)     (((_x)<<PNX8550_XIO_FLASH_CMD_B_SHIFT) & PNX8550_XIO_FLASH_CMD_B_MASK)

#define PNX8550_XIO_FLASH_CMD_A_MASK   0x000000FF
#define PNX8550_XIO_FLASH_CMD_A_SHIFT  0
#define PNX8550_XIO_FLASH_CMD_A(_x)     ((_x) & PNX8550_XIO_FLASH_CMD_A_MASK)

#define PNX8550_XIO_INT_ACK          0x00004000
#define PNX8550_XIO_INT_COMPL        0x00002000
#define PNX8550_XIO_INT_NONSUP       0x00000200
#define PNX8550_XIO_INT_ABORT        0x00000004

#define PNX8550_DMA_CTRL_SINGLE_DATA 0x00000400
#define PNX8550_DMA_CTRL_SND2XIO     0x00000200
#define PNX8550_DMA_CTRL_FIX_ADDR    0x00000100
#define PNX8550_DMA_CTRL_BURST_8     0x00000000
#define PNX8550_DMA_CTRL_BURST_16    0x00000020
#define PNX8550_DMA_CTRL_BURST_32    0x00000040
#define PNX8550_DMA_CTRL_BURST_64    0x00000060
#define PNX8550_DMA_CTRL_BURST_128   0x00000080
#define PNX8550_DMA_CTRL_BURST_256   0x000000A0
#define PNX8550_DMA_CTRL_BURST_512   0x000000C0
#define PNX8550_DMA_CTRL_BURST_NORES 0x000000E0
#define PNX8550_DMA_CTRL_INIT_DMA    0x00000010
#define PNX8550_DMA_CTRL_CMD_TYPE    0x0000000F

/* see PCI system arch, page 100 for the full list: */
#define PNX8550_DMA_CTRL_PCI_CMD_READ    0x00000006
#define PNX8550_DMA_CTRL_PCI_CMD_WRITE   0x00000007

#define PNX8550_DMA_INT_ACK          0x00004000
#define PNX8550_DMA_INT_COMPL        0x00001000
#define PNX8550_DMA_INT_NONSUP       0x00000200
#define PNX8550_DMA_INT_ABORT        0x00000004

#endif
