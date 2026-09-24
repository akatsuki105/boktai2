	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x18
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _081D2118
	movs r6, #0
	movs r0, #0x8b
	lsls r0, r0, #3
	adds r7, r1, r0
	ldr r3, _081D20E8 @ =0x085AE0C8
	mov r8, r3
	adds r5, r1, #0
	adds r5, #0x96
	adds r4, r2, #0
_081D20D6:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D20EC
	movs r0, #1
	b _081D20EE
	.align 2, 0
_081D20E8: .4byte 0x085AE0C8
_081D20EC:
	movs r0, #0
_081D20EE:
	cmp r0, #0
	beq _081D210E
	adds r0, r4, #0
	bl FUN_081d1aec
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D210E
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_081D210E:
	adds r5, #0x88
	adds r4, #0x88
	adds r6, #1
	cmp r6, #7
	ble _081D20D6
_081D2118:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
