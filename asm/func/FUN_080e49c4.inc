	push {r4, lr}
	adds r4, r0, #0
	movs r2, #3
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_080eeee0
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E4A62
	ldr r0, _080E4A0C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080E4A10
	movs r0, #1
	b _080E4A12
	.align 2, 0
_080E4A0C: .4byte 0x030047A4
_080E4A10:
	movs r0, #0
_080E4A12:
	cmp r0, #0
	bne _080E4A4C
	ldr r1, _080E4A48 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080E4A44
	cmp r0, #0x12
	beq _080E4A44
	cmp r0, #0x13
	beq _080E4A44
	cmp r0, #9
	beq _080E4A44
	cmp r0, #0x11
	beq _080E4A44
	cmp r0, #0x14
	beq _080E4A44
	cmp r0, #0xe
	beq _080E4A44
	cmp r0, #0xb
	beq _080E4A44
	cmp r0, #0x17
	beq _080E4A44
	cmp r0, #0x16
	bne _080E4A4C
_080E4A44:
	movs r0, #1
	b _080E4A4E
	.align 2, 0
_080E4A48: .4byte 0x000001DF
_080E4A4C:
	movs r0, #0
_080E4A4E:
	cmp r0, #0
	beq _080E4A62
	movs r0, #0x80
	lsls r0, r0, #5
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080E4A62:
	pop {r4}
	pop {r0}
	bx r0
