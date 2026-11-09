	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08133718 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813371C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813371E
	.align 2, 0
_08133718: .4byte 0x0000046D
_0813371C:
	movs r0, #0
_0813371E:
	cmp r0, #0
	beq _08133732
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08133732:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r5, #0
	str r5, [sp]
	mov r0, sp
	ldr r2, _0813377C @ =0x05000002
	bl CpuSet
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xff
	ble _0813378C
	ldr r3, _08133780 @ =FUN_08133820
	movs r2, #0x22
	ldr r0, _08133784 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08133788 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	b _08133816
	.align 2, 0
_0813377C: .4byte 0x05000002
_08133780: .4byte FUN_08133820
_08133784: .4byte 0x0000046D
_08133788: .4byte 0x0000046B
_0813378C:
	ldr r3, _081337A0 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0x1d
	bgt _081337A4
	movs r5, #1
	adds r0, r2, #0
	adds r0, #0xa
	b _081337AA
	.align 2, 0
_081337A0: .4byte 0x00000484
_081337A4:
	movs r5, #2
	adds r0, r2, #0
	adds r0, #0x28
_081337AA:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081337D0 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081337D4
	asrs r1, r0, #0xc
	b _081337DA
	.align 2, 0
_081337D0: .4byte gSineTable
_081337D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081337DA:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _081337F2
	asrs r2, r0, #0xc
	b _081337F8
_081337F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081337F8:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_081370f4
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x18
	movs r3, #0
	bl FUN_08136de4
_08133816:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
