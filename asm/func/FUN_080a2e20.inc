	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A2E94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A2E40
	ldr r0, _080A2E98 @ =0x0000036A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A2E40
	adds r0, #1
	strh r0, [r1]
_080A2E40:
	adds r0, r4, #0
	bl FUN_080a271c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A2E4E
	b _080A2F4C
_080A2E4E:
	ldr r1, _080A2E9C @ =0x00000369
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2EAC
	movs r2, #1
	ldr r0, _080A2EA0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _080A2E66
	b _080A2F86
_080A2E66:
	ldr r0, _080A2EA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, #0x13
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _080A2E76
	b _080A2F86
_080A2E76:
	cmp r0, #0x19
	bne _080A2E7C
	b _080A2F86
_080A2E7C:
	ldr r0, _080A2EA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080A2E8A
	b _080A2F86
_080A2E8A:
	movs r0, #0x92
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2F86
	.align 2, 0
_080A2E94: .4byte 0x030047A4
_080A2E98: .4byte 0x0000036A
_080A2E9C: .4byte 0x00000369
_080A2EA0: .4byte 0x03002BC0
_080A2EA4: .4byte 0x03002BE0
_080A2EA8: .4byte 0x030044E0
_080A2EAC:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #1
	beq _080A2EC2
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r5]
_080A2EC2:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2ED2
	adds r0, #1
	strh r0, [r1]
_080A2ED2:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2EE2
	adds r0, #2
	b _080A2EE4
_080A2EE2:
	movs r0, #0x18
_080A2EE4:
	strb r0, [r1]
	movs r2, #1
	ldr r0, _080A2F3C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F40 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F44 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2F86
	subs r1, #0x16
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A2F86
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #8
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x98
	adds r0, r2, #0
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A2F48 @ =FUN_080a3004
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A2F86
	.align 2, 0
_080A2F3C: .4byte 0x03002BC0
_080A2F40: .4byte 0x030044E0
_080A2F44: .4byte 0x03002BE0
_080A2F48: .4byte FUN_080a3004
_080A2F4C:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #0
	beq _080A2F5E
	ldr r0, _080A2F80 @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r5]
_080A2F5E:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2F6E
	subs r0, #1
	strh r0, [r1]
_080A2F6E:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bls _080A2F84
	subs r0, #2
	strb r0, [r1]
	b _080A2F86
	.align 2, 0
_080A2F80: .4byte 0x00000199
_080A2F84:
	strb r6, [r1]
_080A2F86:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2F9C
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2FB6
_080A2F9C:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2FB6:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2FD4
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A2FFC
_080A2FD4:
	cmp r0, #0
	beq _080A2FEC
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A2FFC
_080A2FEC:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A2FFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
