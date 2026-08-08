	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	movs r6, #0
	ldr r0, _0821B878 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r5, #0
	adds r0, #0x22
	b _0821B8F6
	.align 2, 0
_0821B878: .4byte 0x03002B4C
_0821B87C:
	ldr r0, _0821B8A8 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #4
	beq _0821B8AC
	cmp r0, #5
	beq _0821B8D0
	b _0821B8EC
	.align 2, 0
_0821B8A8: .4byte 0x03002B4C
_0821B8AC:
	movs r1, #8
	ldrsh r0, [r4, r1]
	str r0, [r5, #0x58]
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	str r0, [r5, #0x64]
	movs r0, #5
	str r0, [r5, #0x6c]
	movs r0, #0
	str r0, [r5, #0x70]
	movs r0, #1
	str r0, [r5, #0x78]
	adds r0, r5, #0
	adds r0, #0x1c
	movs r1, #1
	bl FUN_08022488
	b _0821B8EC
_0821B8D0:
	movs r1, #8
	ldrsh r0, [r4, r1]
	str r0, [r5, #0x60]
	movs r0, #7
	str r0, [r5, #0x6c]
	movs r0, #0
	str r0, [r5, #0x70]
	movs r0, #1
	str r0, [r5, #0x78]
	adds r0, r5, #0
	adds r0, #0x1c
	movs r1, #1
	bl FUN_08022488
_0821B8EC:
	adds r6, #1
	ldr r0, _0821B908 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_0821B8F6:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	blt _0821B87C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821B908: .4byte 0x03002B4C
