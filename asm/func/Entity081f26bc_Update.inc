	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x1c
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _081F261C
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F25EC @ =0x030047A4
	ldr r1, _081F25F0 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081F261C
	movs r1, #4
	ldr r0, _081F25F4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081F261C
	adds r0, r4, #0
	bl FUN_081f17c8
	movs r7, #0
	ldr r0, _081F25F8 @ =0x085AE538
	mov r8, r0
	adds r6, r4, #0
	adds r6, #0x8a
_081F25DA:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r4, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _081F25FC
	movs r0, #1
	b _081F25FE
	.align 2, 0
_081F25EC: .4byte 0x030047A4
_081F25F0: .4byte 0x030047A0
_081F25F4: .4byte 0x03002BC0
_081F25F8: .4byte 0x085AE538
_081F25FC:
	movs r0, #0
_081F25FE:
	cmp r0, #0
	beq _081F2612
	ldrb r0, [r6]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
_081F2612:
	adds r6, #0x78
	adds r5, #0x78
	adds r7, #1
	cmp r7, #0x17
	ble _081F25DA
_081F261C:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
