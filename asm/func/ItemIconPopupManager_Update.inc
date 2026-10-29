	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r5, #0
	ldr r1, _08017668 @ =0x085AA92C
	mov r8, r1
	adds r4, r7, #0
	adds r4, #0x40
	adds r6, r7, #0
	adds r6, #0x3c
_0801762E:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r7, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _08017652
	ldrb r1, [r4]
	cmp r1, #6
	bhi _08017652
	adds r0, r1, #0
	lsls r0, r0, #2
	add r0, r8
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl _call_via_r3
_08017652:
	adds r4, #0x84
	adds r6, #0x84
	adds r5, #1
	cmp r5, #7
	ble _0801762E
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017668: .4byte 0x085AA92C
