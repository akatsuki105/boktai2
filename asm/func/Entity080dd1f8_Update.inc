	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r3, r7, #0
	adds r3, #0x38
	ldr r1, _080DD114 @ =0x00000F68
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DD14C
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080DD118 @ =0x030047A4
	ldr r1, _080DD11C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080DD14C
	movs r1, #4
	ldr r0, _080DD120 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080DD14C
	movs r6, #0
	ldr r2, _080DD114 @ =0x00000F68
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _080DD124 @ =0x085AD33C
	mov sb, r0
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r5, r7, r1
	adds r4, r3, #0
_080DD100:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080DD128
	movs r0, #1
	b _080DD12A
	.align 2, 0
_080DD114: .4byte 0x00000F68
_080DD118: .4byte 0x030047A4
_080DD11C: .4byte 0x030047A0
_080DD120: .4byte 0x03002BC0
_080DD124: .4byte 0x085AD33C
_080DD128:
	movs r0, #0
_080DD12A:
	cmp r0, #0
	beq _080DD13E
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sb
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_080DD13E:
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0xb
	ble _080DD100
_080DD14C:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
