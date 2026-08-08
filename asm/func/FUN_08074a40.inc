	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r1, _08074A60 @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _08074A54
	b _08074C9A
_08074A54:
	lsls r0, r0, #2
	ldr r1, _08074A64 @ =_08074A68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08074A60: .4byte 0x0000037D
_08074A64: .4byte _08074A68
_08074A68: @ jump table
	.4byte _08074A88 @ case 0
	.4byte _08074B40 @ case 1
	.4byte _08074B80 @ case 2
	.4byte _08074BB0 @ case 3
	.4byte _08074BF8 @ case 4
	.4byte _08074C14 @ case 5
	.4byte _08074C68 @ case 6
	.4byte _08074C9A @ case 7
_08074A88:
	ldr r2, _08074AAC @ =0x0000037E
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #1
	bls _08074AE0
	ldr r3, _08074AB0 @ =0x000004A9
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0xba
	lsls r1, r1, #2
	adds r2, r6, r1
	ldrb r1, [r2]
	cmp r0, r1
	bge _08074AB4
	subs r0, r1, #1
	b _08074AB6
	.align 2, 0
_08074AAC: .4byte 0x0000037E
_08074AB0: .4byte 0x000004A9
_08074AB4:
	adds r0, r1, #1
_08074AB6:
	movs r1, #7
	ands r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	bl FUN_080609dc
	ldr r2, _08074AD8 @ =0x000002E6
	adds r1, r6, r2
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	ldr r3, _08074ADC @ =0x0000037E
	adds r0, r6, r3
	strh r2, [r0]
	b _08074AE4
	.align 2, 0
_08074AD8: .4byte 0x000002E6
_08074ADC: .4byte 0x0000037E
_08074AE0:
	adds r0, #1
	strh r0, [r1]
_08074AE4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0x36
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r1, [r0]
	ldr r3, _08074B20 @ =0x000004A9
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _08074B14
	b _08074C9A
_08074B14:
	cmp r1, #1
	bne _08074B24
	adds r2, #0x95
	adds r0, r6, r2
	strb r1, [r0]
	b _08074C9A
	.align 2, 0
_08074B20: .4byte 0x000004A9
_08074B24:
	cmp r1, #3
	bne _08074B34
	ldr r3, _08074B30 @ =0x0000037D
	adds r1, r6, r3
	movs r0, #6
	b _08074C98
	.align 2, 0
_08074B30: .4byte 0x0000037D
_08074B34:
	ldr r0, _08074B3C @ =0x0000037D
	adds r1, r6, r0
	movs r0, #4
	b _08074C98
	.align 2, 0
_08074B3C: .4byte 0x0000037D
_08074B40:
	ldr r1, _08074B74 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08074B78 @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	movs r1, #0x34
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08074B6C
	b _08074C9A
_08074B6C:
	ldr r0, _08074B7C @ =0x0000037D
	adds r1, r6, r0
	movs r0, #2
	b _08074C98
	.align 2, 0
_08074B74: .4byte 0x000002E6
_08074B78: .4byte 0x000002E7
_08074B7C: .4byte 0x0000037D
_08074B80:
	ldr r1, _08074BA8 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08074BAC @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	movs r1, #0x35
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _08074C9A
	.align 2, 0
_08074BA8: .4byte 0x000002E6
_08074BAC: .4byte 0x000002E7
_08074BB0:
	ldr r0, _08074BE8 @ =0x000002E6
	adds r4, r6, r0
	movs r5, #0
	strb r5, [r4]
	ldr r1, _08074BEC @ =0x000002E7
	adds r0, r6, r1
	strb r5, [r0]
	subs r1, #0xe6
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074C9A
	adds r0, r6, #0
	bl FUN_080609dc
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	ldr r2, _08074BF0 @ =0x0000037D
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08074BF4 @ =0x0000037E
	adds r0, r6, r3
	strh r5, [r0]
	b _08074C9A
	.align 2, 0
_08074BE8: .4byte 0x000002E6
_08074BEC: .4byte 0x000002E7
_08074BF0: .4byte 0x0000037D
_08074BF4: .4byte 0x0000037E
_08074BF8:
	ldr r0, _08074C0C @ =0x000002E6
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08074C10 @ =0x000002E7
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	b _08074C76
	.align 2, 0
_08074C0C: .4byte 0x000002E6
_08074C10: .4byte 0x000002E7
_08074C14:
	ldr r2, _08074C58 @ =0x000002E6
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	ldr r3, _08074C5C @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0x38
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074C9A
	ldr r2, _08074C60 @ =0x000004A7
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08074C9A
	ldr r3, _08074C64 @ =0x0000037D
	adds r1, r6, r3
	b _08074C96
	.align 2, 0
_08074C58: .4byte 0x000002E6
_08074C5C: .4byte 0x000002E7
_08074C60: .4byte 0x000004A7
_08074C64: .4byte 0x0000037D
_08074C68:
	ldr r1, _08074CAC @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08074CB0 @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_08074C76:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	movs r1, #0x37
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08074C9A
	ldr r0, _08074CB4 @ =0x0000037D
	adds r1, r6, r0
_08074C96:
	movs r0, #7
_08074C98:
	strb r0, [r1]
_08074C9A:
	ldr r2, _08074CB8 @ =0x000004AC
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #7
	bhi _08074CBC
	adds r7, r0, #0
	movs r0, #8
	subs r5, r0, r7
	b _08074CC6
	.align 2, 0
_08074CAC: .4byte 0x000002E6
_08074CB0: .4byte 0x000002E7
_08074CB4: .4byte 0x0000037D
_08074CB8: .4byte 0x000004AC
_08074CBC:
	ldrb r1, [r1]
	movs r0, #0x10
	subs r7, r0, r1
	adds r5, r1, #0
	subs r5, #8
_08074CC6:
	lsls r1, r7, #4
	subs r1, r1, r7
	lsls r1, r1, #1
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	subs r0, r0, r5
	adds r1, r1, r0
	asrs r3, r1, #3
	movs r0, #0xd
	mov r8, r0
	mov r0, r8
	muls r0, r7, r0
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r4, r2, #2
	adds r0, r0, r4
	asrs r0, r0, #3
	movs r1, #0xb0
	lsls r1, r1, #6
	mov ip, r1
	lsls r0, r0, #5
	orrs r0, r1
	orrs r0, r3
	ldr r3, _08074D74 @ =0x000002AE
	adds r1, r6, r3
	strh r0, [r1]
	lsls r0, r7, #5
	subs r0, r0, r7
	lsls r2, r2, #3
	adds r2, r2, r5
	adds r0, r0, r2
	asrs r3, r0, #3
	lsls r0, r7, #3
	adds r0, r0, r7
	lsls r0, r0, #1
	adds r0, r0, r4
	asrs r0, r0, #3
	lsls r0, r0, #5
	mov r1, ip
	orrs r0, r1
	orrs r0, r3
	movs r2, #0xac
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	adds r1, r7, r5
	lsls r0, r1, #5
	subs r0, r0, r1
	asrs r3, r0, #3
	movs r0, #0x16
	muls r0, r7, r0
	mov r1, r8
	muls r1, r5, r1
	adds r0, r0, r1
	asrs r0, r0, #3
	lsls r0, r0, #5
	mov r1, ip
	orrs r0, r1
	orrs r0, r3
	adds r2, #0xe
	adds r1, r6, r2
	strh r0, [r1]
	ldr r3, _08074D78 @ =0x000004AC
	adds r1, r6, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _08074D5A
	movs r0, #0
	strb r0, [r1]
_08074D5A:
	ldr r3, _08074D7C @ =0x03002B80
	ldrh r0, [r3]
	cmp r0, #0
	beq _08074D86
	ldr r2, _08074D80 @ =0x03002B78
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _08074D84
	subs r0, #1
	strh r0, [r2]
	b _08074D86
	.align 2, 0
_08074D74: .4byte 0x000002AE
_08074D78: .4byte 0x000004AC
_08074D7C: .4byte 0x03002B80
_08074D80: .4byte 0x03002B78
_08074D84:
	strh r1, [r3]
_08074D86:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
