	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	movs r4, #0
	ldr r7, _081F0AC8 @ =0x085AE518
_081F0AB8:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F0ACC
	movs r0, #1
	b _081F0ACE
	.align 2, 0
_081F0AC8: .4byte 0x085AE518
_081F0ACC:
	movs r0, #0
_081F0ACE:
	cmp r0, #0
	beq _081F0AF0
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081F0AF0:
	adds r4, #1
	cmp r4, #3
	ble _081F0AB8
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
