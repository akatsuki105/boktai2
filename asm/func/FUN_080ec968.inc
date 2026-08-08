	push {r4, r5, r6, r7, lr}
	ldr r0, _080EC998 @ =0x03002C60
	ldr r5, [r0]
	ldr r4, [r5, #4]
	movs r6, #0
	cmp r4, #0
	beq _080EC9A6
	movs r7, #3
_080EC978:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EC992
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _080EC99C
_080EC992:
	ldr r5, [r5]
	ldr r4, [r5, #4]
	b _080EC9A2
	.align 2, 0
_080EC998: .4byte 0x03002C60
_080EC99C:
	ldr r5, [r5]
	ldr r4, [r5, #4]
	adds r6, #1
_080EC9A2:
	cmp r4, #0
	bne _080EC978
_080EC9A6:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
