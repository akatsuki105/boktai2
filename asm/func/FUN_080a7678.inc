	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080A76C0 @ =0x030047A4
	ldr r1, _080A76C4 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _080A76EE
	adds r0, r4, #0
	bl FUN_080a7410
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _080A76C8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080A76CC
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080A76E4
	.align 2, 0
_080A76C0: .4byte 0x030047A4
_080A76C4: .4byte 0x030047A0
_080A76C8: .4byte 0x03002BE0
_080A76CC:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080A76F8 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080A76E4:
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080A76EE:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A76F8: .4byte 0x00001FFF
