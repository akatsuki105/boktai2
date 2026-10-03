	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DA8A
	movs r0, #0
	strb r0, [r1]
_0804DA8A:
	ldr r0, _0804DABC @ =0x030057F0
	adds r4, r2, #0
	adds r4, #0x20
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldrh r0, [r0, #0x34]
	cmp r0, #0x46
	bne _0804DAC0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804DAB2
	adds r0, r2, #0
	adds r0, #0xc4
	bl _call_via_r1
_0804DAB2:
	ldrb r1, [r4]
	movs r0, #8
	bl rfu_clearSlot
	b _0804DADA
	.align 2, 0
_0804DABC: .4byte 0x030057F0
_0804DAC0:
	subs r0, #0x47
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0804DADA
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DADA
	bl _call_via_r0
_0804DADA:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
