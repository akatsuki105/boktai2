	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #0x10]
	mov r7, sb
	movs r0, #0x48
	adds r0, r0, r7
	mov sl, r0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	bne _08032BD0
	b _08032D0E
_08032BD0:
	movs r0, #0
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_080298fc
	movs r0, #0x80
	adds r1, r7, #0
	adds r1, #0x4d
	strb r0, [r1]
	movs r2, #0xff
	movs r3, #3
	adds r0, r7, #0
	adds r0, #0xa0
	strb r3, [r0]
	ldrb r0, [r1]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r4, r7, #0
	adds r4, #0xa1
	strb r0, [r4]
	mov r5, sl
	ldrb r0, [r5, #5]
	adds r0, #0xa0
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	ands r0, r3
	lsls r0, r0, #0x1e
	movs r3, #0xc0
	lsls r3, r3, #0x18
	adds r0, r0, r3
	lsrs r0, r0, #0x18
	ands r0, r2
	lsrs r0, r0, #5
	adds r0, #3
	ands r1, r0
	strb r1, [r4]
	adds r0, r7, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032C40
	ldr r5, _08032C3C @ =0x00000824
	adds r0, r7, r5
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _08032C50
	movs r3, #0x1a
	b _08032C50
	.align 2, 0
_08032C3C: .4byte 0x00000824
_08032C40:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _08032C50
	movs r3, #0x1f
_08032C50:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r5, #0xb5
	lsls r5, r5, #2
	adds r2, r7, r5
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, sb
	bl FUN_08022d24
	adds r0, r7, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _08032C88
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r7, r2
	b _08032C96
_08032C88:
	ldr r0, _08032D24 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r7, r3
_08032C96:
	str r0, [r1]
	adds r0, r1, #0
	movs r5, #0xe7
	lsls r5, r5, #2
	adds r1, r7, r5
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_08029c74
	movs r0, #1
	ldr r2, _08032D28 @ =0x0000016B
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0x82
	lsls r3, r3, #5
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _08032CD2
	movs r1, #4
	ldr r0, _08032D2C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08032CD2
	ldrh r0, [r2]
	movs r1, #0
	bl FUN_082318ac
_08032CD2:
	mov r6, sl
	adds r6, #8
	movs r5, #0xc0
	lsls r5, r5, #6
	mov r8, r5
	movs r5, #0x40
	str r5, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r4, #0x80
	lsls r4, r4, #1
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r1, #3
	movs r2, #2
	mov r3, r8
	bl FUN_08015a90
	str r5, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r1, #5
	movs r2, #2
	mov r3, r8
	bl FUN_08015a90
_08032D0E:
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08032D30
	subs r0, r2, #4
	b _08032D32
	.align 2, 0
_08032D24: .4byte 0x03003584
_08032D28: .4byte 0x0000016B
_08032D2C: .4byte 0x03002BC0
_08032D30:
	movs r0, #0
_08032D32:
	strh r0, [r1]
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r1, r7, r5
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08032D48
	subs r0, r2, #4
	b _08032D4A
_08032D48:
	movs r0, #0
_08032D4A:
	strh r0, [r1]
	movs r2, #0xd
	mov r1, sb
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #3
	ldr r5, [sp, #0x10]
	ands r0, r5
	cmp r0, #0
	bne _08032D68
	adds r0, r7, #0
	bl FUN_0802991c
_08032D68:
	ldr r0, [sp, #0x10]
	cmp r0, #0xf
	bgt _08032DC2
	lsls r1, r0, #1
	movs r0, #0x2a
	mov r3, sl
	adds r3, #0x10
	mov r2, sl
	ldrb r6, [r2, #5]
	subs r4, r0, r1
	ldr r2, _08032D98 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r4, r0
	cmp r0, #0
	blt _08032D9C
	asrs r1, r0, #0xc
	b _08032DA2
	.align 2, 0
_08032D98: .4byte 0x085B0A08
_08032D9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08032DA2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08032DBA
	asrs r0, r0, #0xc
	b _08032DC0
_08032DBA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08032DC0:
	strh r0, [r3, #4]
_08032DC2:
	ldr r2, [sp, #0x10]
	cmp r2, #0x1e
	bne _08032DFE
	ldr r2, _08032E10 @ =FUN_0802e520
	movs r3, #1
	mov r0, sb
	adds r0, #0xa3
	movs r1, #0
	strb r3, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	ldr r3, _08032E14 @ =0x00001042
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _08032DFE
	movs r1, #4
	ldr r0, _08032E18 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08032DFE
	ldrh r0, [r2]
	movs r1, #0
	bl FUN_082318ac
_08032DFE:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032E10: .4byte FUN_0802e520
_08032E14: .4byte 0x00001042
_08032E18: .4byte 0x03002BC0
