	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c0ae4
FUN_080c0ae4: @ 0x080C0AE4
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b00
FUN_080c0b00: @ 0x080C0B00
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl PlaySound_08240718
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b1c
FUN_080c0b1c: @ 0x080C0B1C
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl sound_08240264
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b38
FUN_080c0b38: @ 0x080C0B38
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_08240360
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b54
FUN_080c0b54: @ 0x080C0B54
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082403d0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b70
FUN_080c0b70: @ 0x080C0B70
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl sound_fadeout_08240440
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0b8c
FUN_080c0b8c: @ 0x080C0B8C
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082404b0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0ba8
FUN_080c0ba8: @ 0x080C0BA8
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082404fc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0bc4
FUN_080c0bc4: @ 0x080C0BC4
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_08240568
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0be0
FUN_080c0be0: @ 0x080C0BE0
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082405c0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityD3A9_Update_Internal
EntityD3A9_Update_Internal: @ 0x080C0BFC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x1c
	movs r7, #0
	ldr r1, _080C0C14 @ =0x03002B4C
	ldr r2, [r1]
	adds r2, #0x24
	adds r1, r6, #0
	adds r1, #0x22
	b _080C0CF8
	.align 2, 0
_080C0C14: .4byte 0x03002B4C
_080C0C18:
	ldr r0, _080C0C48 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r1, [r4, #6]
	cmp r1, #9
	bhi _080C0CEE
	lsls r0, r1, #2
	ldr r1, _080C0C4C @ =_080C0C50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C0C48: .4byte 0x03002B4C
_080C0C4C: .4byte _080C0C50
_080C0C50: @ jump table
	.4byte _080C0C78 @ case 0
	.4byte _080C0C84 @ case 1
	.4byte _080C0C90 @ case 2
	.4byte _080C0C9C @ case 3
	.4byte _080C0CA8 @ case 4
	.4byte _080C0CB4 @ case 5
	.4byte _080C0CC0 @ case 6
	.4byte _080C0CCC @ case 7
	.4byte _080C0CD8 @ case 8
	.4byte _080C0CE4 @ case 9
_080C0C78:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0ae4
	b _080C0CEE
_080C0C84:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b00
	b _080C0CEE
_080C0C90:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b1c
	b _080C0CEE
_080C0C9C:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b38
	b _080C0CEE
_080C0CA8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b54
	b _080C0CEE
_080C0CB4:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b70
	b _080C0CEE
_080C0CC0:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0b8c
	b _080C0CEE
_080C0CCC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0ba8
	b _080C0CEE
_080C0CD8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0bc4
	b _080C0CEE
_080C0CE4:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080c0be0
_080C0CEE:
	adds r7, #1
	ldr r1, _080C0D08 @ =0x03002B4C
	ldr r2, [r1]
	adds r2, #0x24
	adds r1, r5, #6
_080C0CF8:
	ldrb r2, [r2]
	adds r1, r1, r2
	ldrb r1, [r1]
	cmp r7, r1
	blt _080C0C18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C0D08: .4byte 0x03002B4C

	thumb_func_start EntityD3A9_Update
EntityD3A9_Update: @ 0x080C0D0C
	.byte 0x00, 0xB5, 0xFF, 0xF7
	.byte 0x75, 0xFF, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start EntityD3A9_Destroy
EntityD3A9_Destroy: @ 0x080C0D18
  movs r0, #0
  bx lr

	thumb_func_start EntityD3A9_Init
EntityD3A9_Init: @ 0x080C0D1C
	push {lr}
	adds r0, #0x1c
	movs r2, #8
	bl FUN_080223f4
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start EntityD3A9_Create
EntityD3A9_Create: @ 0x080C0D2C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xb
	movs r1, #0x50
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C0D64
	ldr r1, _080C0D5C @ =EntityD3A9_Update
	ldr r2, _080C0D60 @ =EntityD3A9_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityD3A9_Init
	cmp r0, #0
	bge _080C0D64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C0D66
	.align 2, 0
_080C0D5C: .4byte EntityD3A9_Update
_080C0D60: .4byte EntityD3A9_Destroy
_080C0D64:
	adds r0, r4, #0
_080C0D66:
	pop {r4, r5}
	pop {r1}
	bx r1

