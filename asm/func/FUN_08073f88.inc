	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrb r2, [r1]
	movs r6, #0x40
	cmp r2, #1
	bne _08073F9C
	movs r6, #0x30
_08073F9C:
	ldr r3, _08073FB0 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _08073FE6
	cmp r0, #1
	bgt _08073FB4
	cmp r0, #0
	beq _08073FBE
	b _080740A6
	.align 2, 0
_08073FB0: .4byte 0x0000037D
_08073FB4:
	cmp r0, #2
	beq _08073FFA
	cmp r0, #3
	beq _08074088
	b _080740A6
_08073FBE:
	ldrb r0, [r1]
	movs r1, #0x15
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _080740A6
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	adds r0, r5, #0
	bl FUN_080726b4
	b _080740A6
_08073FE6:
	ldrb r0, [r1]
	movs r1, #0x16
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080740A6
_08073FFA:
	ldr r1, _08074014 @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08074028
	cmp r2, #0
	bne _08074018
	movs r0, #0xe3
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0807401E
	.align 2, 0
_08074014: .4byte 0x0000037E
_08074018:
	ldr r0, _08074080 @ =0x0000038B
	bl PlaySound_082406e0
_0807401E:
	ldr r3, _08074084 @ =0x0000037E
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08074028:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	movs r1, #0x17
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_08060a24
	adds r6, r0, #0
	ldrb r0, [r4]
	cmp r0, #1
	bne _0807406E
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #2
	bne _0807406E
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807406E
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	bl Player_DarkDjangoSword_0806185c
_0807406E:
	cmp r6, #0
	beq _080740A6
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _080740A6
	.align 2, 0
_08074080: .4byte 0x0000038B
_08074084: .4byte 0x0000037E
_08074088:
	ldr r3, _080740AC @ =0x0000037E
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080740A6
	adds r0, r5, #0
	bl FUN_08072620
	adds r0, r5, #0
	bl FUN_080726b4
_080740A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080740AC: .4byte 0x0000037E
