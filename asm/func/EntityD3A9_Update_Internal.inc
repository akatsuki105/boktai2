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
