	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	ldr r4, [sp, #0x30]
	ldr r5, [sp, #0x34]
	bl FUN_080cb8f8
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl FUN_080cb94c
	ldr r2, _080CBA48 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080CBA4C
	asrs r2, r0, #0xc
	b _080CBA52
	.align 2, 0
_080CBA48: .4byte 0x085B0A08
_080CBA4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CBA52:
	adds r0, r7, #0
	adds r0, #0xb0
	movs r1, #0
	strh r2, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r1, _080CBA7C @ =0x085B0A08
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080CBA80
	asrs r3, r0, #0xc
	b _080CBA86
	.align 2, 0
_080CBA7C: .4byte 0x085B0A08
_080CBA80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080CBA86:
	adds r0, r7, #0
	adds r0, #0xb4
	movs r2, #0
	strh r3, [r0]
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r1, r7, #0
	adds r1, #0xbc
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbe
	strh r2, [r0]
	movs r0, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
