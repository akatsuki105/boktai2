	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x20
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _0805EB7C
	movs r0, #0
	strb r0, [r5, #2]
	movs r0, #2
	strh r0, [r4, #0x10]
	movs r0, #0xd8
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0805EB7C:
	ldr r0, [r5, #0x14]
	cmp r0, #5
	bne _0805EB86
	movs r0, #1
	b _0805EB8C
_0805EB86:
	cmp r0, #0xa
	bne _0805EB8E
	movs r0, #0
_0805EB8C:
	strh r0, [r4, #0x10]
_0805EB8E:
	ldr r1, [r5, #0x14]
	cmp r1, #9
	bhi _0805EBA2
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0805EBB4
	adds r1, r6, #0
	adds r1, #0x34
	b _0805EBB8
_0805EBA2:
	cmp r1, #0x13
	bhi _0805EBC0
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bhi _0805EBB4
	adds r1, r6, #0
	adds r1, #0x34
	b _0805EBB8
_0805EBB4:
	adds r1, r6, #0
	adds r1, #0x18
_0805EBB8:
	adds r0, r4, #0
	bl AuxSprite_SetGfxPtr
	b _0805EBCA
_0805EBC0:
	adds r1, r6, #0
	adds r1, #0x34
	adds r0, r4, #0
	bl AuxSprite_SetGfxPtr
_0805EBCA:
	ldr r0, [r5, #0x14]
	cmp r0, #0x1d
	bls _0805EBE8
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r4, #0
	bl AuxSprite_SetGfxPtr
	movs r0, #3
	movs r1, #0
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5, #2]
	str r1, [r5, #0x14]
	b _0805EBEC
_0805EBE8:
	adds r0, #1
	str r0, [r5, #0x14]
_0805EBEC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
