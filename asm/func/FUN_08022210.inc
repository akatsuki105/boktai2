	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x78
	movs r7, #0
	ldr r2, _08022260 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x7e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _080222A0
	mov r8, r2
_08022232:
	mov r1, r8
	ldr r0, [r1]
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
	ldrb r0, [r4, #6]
	cmp r0, #1
	beq _08022276
	cmp r0, #1
	bgt _08022264
	cmp r0, #0
	beq _0802226A
	b _0802228C
	.align 2, 0
_08022260: .4byte 0x03002B4C
_08022264:
	cmp r0, #2
	beq _08022282
	b _0802228C
_0802226A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080221b8
	b _0802228C
_08022276:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080221e0
	b _0802228C
_08022282:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080221fc
_0802228C:
	adds r7, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r5, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08022232
_080222A0:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
