	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r4, r6
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081A1814 @ =0x00000EAC
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #2
	bhi _081A17F6
	adds r0, #1
	strb r0, [r1]
_081A17F6:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081A1864
	movs r1, #4
	ldr r2, _081A1818 @ =0x00000E48
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A181C
	movs r0, #1
	b _081A181E
	.align 2, 0
_081A1814: .4byte 0x00000EAC
_081A1818: .4byte 0x00000E48
_081A181C:
	movs r0, #0
_081A181E:
	adds r3, r0, #0
	cmp r3, #0
	bne _081A1864
	ldr r6, _081A1858 @ =0x00000EAC
	adds r5, r5, r6
	ldrb r0, [r5]
	cmp r0, #2
	bls _081A1864
	movs r1, #2
	movs r2, #6
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r3, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081A185C @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081A1860 @ =0x00000484
	adds r0, r4, r2
	str r3, [r0]
	adds r6, #3
	adds r1, r4, r6
	movs r0, #1
	strb r0, [r1]
	strb r3, [r5]
	b _081A1866
	.align 2, 0
_081A1858: .4byte 0x00000EAC
_081A185C: .4byte 0x0000046A
_081A1860: .4byte 0x00000484
_081A1864:
	movs r0, #1
_081A1866:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
