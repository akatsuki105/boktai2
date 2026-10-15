	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A3BE4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A3BA6
	movs r0, #0x81
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A3BA6
	adds r0, #1
	strh r0, [r1]
_080A3BA6:
	adds r0, r4, #0
	bl Entity7C62_IsPlayerNear
	adds r5, r0, #0
	cmp r5, #0
	beq _080A3C44
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	beq _080A3BC4
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4, #0x1a]
_080A3BC4:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #7
	bhi _080A3BD4
	adds r0, r1, #1
	strh r0, [r6]
_080A3BD4:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x16
	bhi _080A3BE8
	adds r0, #2
	b _080A3BEA
	.align 2, 0
_080A3BE4: .4byte 0x030047A4
_080A3BE8:
	movs r0, #0x18
_080A3BEA:
	strh r0, [r1]
	movs r2, #1
	ldr r0, _080A3C34 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A3C7A
	ldr r0, _080A3C38 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A3C7A
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A3C7A
	movs r0, #8
	strh r0, [r6]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, _080A3C3C @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A3C40 @ =Entity7C62_UpdateActivated
	adds r0, r4, #0
	bl Entity7C62_SetUpdateCallback
	b _080A3C7A
	.align 2, 0
_080A3C34: .4byte 0x03002BC0
_080A3C38: .4byte 0x030044E0
_080A3C3C: .4byte 0x03002BE0
_080A3C40: .4byte Entity7C62_UpdateActivated
_080A3C44:
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _080A3C52
	ldr r0, _080A3C74 @ =0x00000199
	bl PlaySound_082406e0
	strb r5, [r4, #0x1a]
_080A3C52:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _080A3C62
	subs r0, r1, #1
	strh r0, [r6]
_080A3C62:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #2
	bls _080A3C78
	subs r0, #2
	strh r0, [r1]
	b _080A3C7A
	.align 2, 0
_080A3C74: .4byte 0x00000199
_080A3C78:
	strh r5, [r1]
_080A3C7A:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r0, [r2]
	cmp r0, #0
	bne _080A3C90
	ldr r0, [r4, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x64]
	b _080A3CAA
_080A3C90:
	ldr r0, [r4, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0xae
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x82
	strh r0, [r1]
_080A3CAA:
	ldrh r0, [r6]
	cmp r0, #7
	bls _080A3CC2
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A3CE6
_080A3CC2:
	cmp r0, #0
	beq _080A3CD8
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A3CE6
_080A3CD8:
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A3CE6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
