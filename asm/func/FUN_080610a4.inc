	push {r4, r5, lr}
	adds r4, r0, #0
	bl CalcMaxHP
	ldr r1, _080610C8 @ =0x00000366
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #0x6c
	movs r1, #0
	bl FUN_0823174c
	cmp r0, #0
	beq _080610CC
	ldrh r1, [r5]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r4, r2
	b _080610F8
	.align 2, 0
_080610C8: .4byte 0x00000366
_080610CC:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _080610EC
	ldr r0, _080610E8 @ =0x030046A0
	ldr r0, [r0]
	ldrh r1, [r0, #0x38]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r4, r2
	b _080610F8
	.align 2, 0
_080610E8: .4byte 0x030046A0
_080610EC:
	ldr r0, _0806110C @ =0x030046A0
	ldr r0, [r0]
	ldrh r1, [r0, #0x28]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r4, r3
_080610F8:
	strh r1, [r0]
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r2, [r1]
	cmp r2, #0
	bne _08061110
	movs r0, #1
	b _0806111A
	.align 2, 0
_0806110C: .4byte 0x030046A0
_08061110:
	ldr r3, _08061140 @ =0x00000366
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r2, r0
	bls _0806111C
_0806111A:
	strh r0, [r1]
_0806111C:
	adds r0, r4, #0
	bl CalcMaxEne
	ldr r1, _08061144 @ =0x0000036A
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #0x65
	movs r1, #0
	bl FUN_0823174c
	cmp r0, #0
	beq _08061148
	ldrh r1, [r5]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r4, r2
	b _08061174
	.align 2, 0
_08061140: .4byte 0x00000366
_08061144: .4byte 0x0000036A
_08061148:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _08061168
	ldr r0, _08061164 @ =0x030046A0
	ldr r0, [r0]
	ldrh r1, [r0, #0x3a]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r4, r2
	b _08061174
	.align 2, 0
_08061164: .4byte 0x030046A0
_08061168:
	ldr r0, _08061190 @ =0x030046A0
	ldr r0, [r0]
	ldrh r1, [r0, #0x2c]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r0, r4, r3
_08061174:
	strh r1, [r0]
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, _08061194 @ =0x0000036A
	adds r0, r4, r1
	ldrh r1, [r0]
	ldrh r0, [r2]
	cmp r0, r1
	bls _0806118A
	strh r1, [r2]
_0806118A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08061190: .4byte 0x030046A0
_08061194: .4byte 0x0000036A
