	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r7, r6, r0
	ldr r1, _081AB54C @ =0x00000CAA
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r4, r0, #1
	cmp r4, #0
	blt _081AB5AE
	movs r0, #1
	mov ip, r0
	movs r0, #0xd0
	muls r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x1c
	adds r5, r1, r7
	adds r0, #0xad
	adds r3, r0, r7
_081AB53E:
	ldrb r0, [r3]
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _081AB550
	movs r0, #1
	b _081AB552
	.align 2, 0
_081AB54C: .4byte 0x00000CAA
_081AB550:
	movs r0, #0
_081AB552:
	adds r2, r0, #0
	cmp r2, #0
	bne _081AB5A4
	ldrb r1, [r3]
	mov r0, ip
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _081AB59C @ =0x00000CBA
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r0, _081AB5A0 @ =0x00240004
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #0x10
	movs r2, #0x40
	movs r3, #0x2a
	bl Explosion_CreateWithAttrs
	movs r0, #0xd0
	muls r0, r4, r0
	adds r5, r7, r0
	movs r4, #7
_081AB58A:
	adds r0, r5, #0
	adds r0, #0x1c
	bl Salamander_ScatterSpark
	subs r4, #1
	cmp r4, #0
	bge _081AB58A
	movs r0, #1
	b _081AB5B0
	.align 2, 0
_081AB59C: .4byte 0x00000CBA
_081AB5A0: .4byte 0x00240004
_081AB5A4:
	subs r5, #0xd0
	subs r3, #0xd0
	subs r4, #1
	cmp r4, #0
	bge _081AB53E
_081AB5AE:
	movs r0, #0
_081AB5B0:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
