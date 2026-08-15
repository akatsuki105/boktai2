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
	beq _08225D70
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08225D6C @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _08225D72
	.align 2, 0
_08225D6C: .4byte 0x00000F14
_08225D70:
	movs r0, #0
_08225D72:
	cmp r0, #0
	beq _08225E0C
	ldr r0, _08225E40 @ =0x00000D9C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08225E44 @ =0x00000DA5
	adds r0, r6, r1
	movs r1, #0x7f
	strb r1, [r0]
	ldr r2, _08225E48 @ =0x00000DA4
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08225E4C @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080136b4
	adds r0, r6, #0
	bl FUN_08223984
	ldr r2, _08225E50 @ =0x00000DC8
	adds r0, r6, r2
	ldr r1, _08225E54 @ =0x00000117
	bl FUN_0822b20c
	ldr r0, _08225E58 @ =0x00000F16
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08225E5C @ =0x00000F18
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _08225DE8
	ldrb r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #3
	bne _08225DE8
	ldr r2, _08225E60 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r2, _08225E64 @ =0x00000F42
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08225E68 @ =0x00000DF2
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
_08225DE8:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _08225E6C @ =0x00000DE4
	adds r0, r6, r2
	adds r2, #0x50
	adds r1, r6, r2
	ldr r1, [r1]
	str r3, [sp]
	movs r2, #0
	movs r3, #4
	bl FUN_08236fac
_08225E0C:
	ldr r0, _08225E40 @ =0x00000D9C
	adds r5, r6, r0
	ldr r1, _08225E6C @ =0x00000DE4
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
	beq _08225E70
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08225E78
	.align 2, 0
_08225E40: .4byte 0x00000D9C
_08225E44: .4byte 0x00000DA5
_08225E48: .4byte 0x00000DA4
_08225E4C: .4byte 0x00000DF4
_08225E50: .4byte 0x00000DC8
_08225E54: .4byte 0x00000117
_08225E58: .4byte 0x00000F16
_08225E5C: .4byte 0x00000F18
_08225E60: .4byte 0x00000DEC
_08225E64: .4byte 0x00000F42
_08225E68: .4byte 0x00000DF2
_08225E6C: .4byte 0x00000DE4
_08225E70:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08225E78:
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
	beq _08225E9C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08225EA4
_08225E9C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08225EA4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08225EDC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08225F22
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08225EE6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08225EE0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08225EFC
	.align 2, 0
_08225EDC: .4byte 0x0000FFFF
_08225EE0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08225EFA
_08225EE6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08225EFA
	strh r1, [r4, #8]
	movs r2, #1
	b _08225EFC
_08225EFA:
	movs r2, #0
_08225EFC:
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
	bne _08225F24
	movs r0, #1
	strb r0, [r4, #7]
	b _08225F24
_08225F22:
	movs r2, #0
_08225F24:
	ldr r1, _08225F48 @ =0x00000F14
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08225F4C @ =0x00000F0C
	adds r1, r6, r2
	ldr r2, [r1]
	cmp r2, #0
	beq _08225F40
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecById
_08225F40:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08225F48: .4byte 0x00000F14
_08225F4C: .4byte 0x00000F0C
