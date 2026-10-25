	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D62F8 @ =0x0000057C
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D632A
	movs r4, #0
	ldr r2, _081D62F8 @ =0x0000057C
	adds r6, r5, r2
	ldr r0, _081D62FC @ =0x085AE104
	mov r8, r0
_081D62E8:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D6300
	movs r0, #1
	b _081D6302
	.align 2, 0
_081D62F8: .4byte 0x0000057C
_081D62FC: .4byte 0x085AE104
_081D6300:
	movs r0, #0
_081D6302:
	cmp r0, #0
	beq _081D6324
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D6324:
	adds r4, #1
	cmp r4, #3
	ble _081D62E8
_081D632A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
