	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08225B48
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08225B44 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _08225B4A
	.align 2, 0
_08225B44: .4byte 0x00000F14
_08225B48:
	movs r0, #0
_08225B4A:
	cmp r0, #0
	beq _08225BF8
	ldr r0, _08225C2C @ =0x00000D9C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #0xf
	ands r0, r1
	subs r1, #0x10
	ands r0, r1
	str r0, [r2]
	ldr r1, _08225C30 @ =0x00000DA5
	adds r0, r6, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r2, _08225C34 @ =0x00000DA4
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _08225C38 @ =0x00000DBA
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0xa0
	strh r0, [r1]
	adds r2, #0xfa
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, _08225C3C @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_08013698
	adds r0, r6, #0
	bl FUN_08223984
	ldr r2, _08225C40 @ =0x00000DC8
	adds r0, r6, r2
	ldr r1, _08225C44 @ =0x00000117
	bl FUN_0822b20c
	ldr r0, _08225C48 @ =0x00000F16
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08225C4C @ =0x00000F18
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _08225BD4
	ldrb r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #3
	bne _08225BD4
	ldr r2, _08225C50 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r2, _08225C54 @ =0x00000F42
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08225C58 @ =0x00000DF2
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
_08225BD4:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _08225C5C @ =0x00000DE4
	adds r0, r6, r2
	adds r2, #0x50
	adds r1, r6, r2
	ldr r1, [r1]
	str r3, [sp]
	movs r2, #0
	movs r3, #4
	bl FUN_08236fac
_08225BF8:
	ldr r0, _08225C2C @ =0x00000D9C
	adds r5, r6, r0
	ldr r1, _08225C5C @ =0x00000DE4
	adds r4, r6, r1
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08225C60
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08225C68
	.align 2, 0
_08225C2C: .4byte 0x00000D9C
_08225C30: .4byte 0x00000DA5
_08225C34: .4byte 0x00000DA4
_08225C38: .4byte 0x00000DBA
_08225C3C: .4byte 0x00000DF4
_08225C40: .4byte 0x00000DC8
_08225C44: .4byte 0x00000117
_08225C48: .4byte 0x00000F16
_08225C4C: .4byte 0x00000F18
_08225C50: .4byte 0x00000DEC
_08225C54: .4byte 0x00000F42
_08225C58: .4byte 0x00000DF2
_08225C5C: .4byte 0x00000DE4
_08225C60:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08225C68:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08225C8C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08225C94
_08225C8C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08225C94:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08225CCC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08225D12
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08225CD6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08225CD0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08225CEC
	.align 2, 0
_08225CCC: .4byte 0x0000FFFF
_08225CD0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08225CEA
_08225CD6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08225CEA
	strh r1, [r4, #8]
	movs r2, #1
	b _08225CEC
_08225CEA:
	movs r2, #0
_08225CEC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08225D14
	movs r0, #1
	strb r0, [r4, #7]
	b _08225D14
_08225D12:
	movs r2, #0
_08225D14:
	ldr r1, _08225D38 @ =0x00000F14
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08225D3C @ =0x00000F0C
	adds r1, r6, r2
	ldr r2, [r1]
	cmp r2, #0
	beq _08225D30
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecById
_08225D30:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08225D38: .4byte 0x00000F14
_08225D3C: .4byte 0x00000F0C
