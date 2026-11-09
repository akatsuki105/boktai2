	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r5, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r3, #2
	ldrsh r0, [r1, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r2, r2, r0
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r2, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r6, r0
	ble _081786A6
	movs r6, #0xff
	b _081786B0
_081786A6:
	cmp r6, #0x80
	ble _081786AE
	movs r6, #0x7f
	b _081786B0
_081786AE:
	movs r6, #0x3f
_081786B0:
	movs r2, #0
	mov ip, r2
	ldr r3, _081786E4 @ =0x00001012
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	bge _08178794
	ldr r2, _081786E8 @ =gSineTable
	mov sl, r2
	movs r7, #0
	movs r3, #0xcb
	lsls r3, r3, #3
	mov sb, r3
	ldr r0, _081786EC @ =0x030046B8
	mov r8, r0
_081786D0:
	adds r0, r7, r5
	add r0, sb
	adds r0, #0xfd
	ldrb r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _081786F0
	movs r0, #1
	b _081786F2
	.align 2, 0
_081786E4: .4byte 0x00001012
_081786E8: .4byte gSineTable
_081786EC: .4byte 0x030046B8
_081786F0:
	movs r0, #0
_081786F2:
	cmp r0, #0
	beq _0817877E
	adds r0, r7, r5
	add r0, sb
	adds r0, #0xfd
	ldrb r0, [r0]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0817870A
	movs r0, #1
	b _0817870C
_0817870A:
	movs r0, #0
_0817870C:
	cmp r0, #0
	bne _0817877E
	mov r3, r8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _08178748 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _0817874C @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	adds r2, r7, r5
	ldr r0, _08178750 @ =0x0000076C
	adds r2, r2, r0
	ands r3, r6
	movs r4, #0xc
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08178754
	asrs r1, r0, #0xc
	b _0817875A
	.align 2, 0
_08178748: .4byte 0x000003FF
_0817874C: .4byte 0x0203B400
_08178750: .4byte 0x0000076C
_08178754:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817875A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08178776
	asrs r0, r0, #0xc
	b _0817877C
_08178776:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0817877C:
	strh r0, [r2, #4]
_0817877E:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	movs r1, #1
	add ip, r1
	ldr r2, _081787A4 @ =0x00001012
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp ip, r0
	blt _081786D0
_08178794:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081787A4: .4byte 0x00001012
