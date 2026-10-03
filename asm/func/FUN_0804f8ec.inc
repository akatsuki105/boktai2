	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804f820
	adds r2, r0, #0
	cmp r2, #0
	beq _0804F94A
	ldrb r0, [r4, #1]
	cmp r0, #5
	bhi _0804F942
	lsls r0, r0, #2
	ldr r1, _0804F90C @ =_0804F910
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F90C: .4byte _0804F910
_0804F910: @ jump table
	.4byte _0804F942 @ case 0
	.4byte _0804F928 @ case 1
	.4byte _0804F92C @ case 2
	.4byte _0804F930 @ case 3
	.4byte _0804F934 @ case 4
	.4byte _0804F938 @ case 5
_0804F928:
	movs r1, #1
	b _0804F93C
_0804F92C:
	movs r1, #4
	b _0804F93C
_0804F930:
	movs r1, #0x10
	b _0804F93C
_0804F934:
	movs r1, #0x40
	b _0804F93C
_0804F938:
	movs r1, #0x80
	lsls r1, r1, #1
_0804F93C:
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
_0804F942:
	adds r1, r2, #0
	adds r1, #0x2b
	movs r0, #1
	strb r0, [r1]
_0804F94A:
	pop {r4}
	pop {r0}
	bx r0
